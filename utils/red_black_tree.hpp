/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:48:33 by abesombes         #+#    #+#             */
/*   Updated: 2022/02/10 10:49:17 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP
#define BLACK 0
#define RED 1
#define DOUBLE_BLACK 2
#define newline std::cout<<endl;
#include <iostream>


/*
--------------------------------------------------
Rules That Every Red-Black Tree Follows: 
--------------------------------------------------

1. Every node has a colour either red or black.
2. The root of the tree is always black.
3. There are no two adjacent red nodes (A red node cannot have a red parent or red child).
4. Every path from a node (including root) to any of its descendants NULL nodes has the same number of black nodes.
5. All leaf nodes are black nodes.
*/

namespace ft{


template <class Key, class T>    
class Node {

    public:
            Key data; // holds the key value
            T   value; // holds the mapped value
            Node *parent; // pointer to the parent
            Node *left; // pointer to left child
            Node *right; // pointer to right child
            int color; // RED (1) -> Red, BLACK (0) -> Black
            
            Node(Key data, T value): data(data), value(value), parent(NULL), left(NULL), right(NULL), color(RED){};
            Node(Key data, T value, int color): data(data), value(value), parent(NULL), left(NULL), right(NULL), color(color){}
            void setColor(int color) { this->color = color;}
            int getColor() { return (color);}
            Key &getData() { return (data); }
            void setData (Key &data) { this->data = data; }
            T &getValue() { return (value); }
            void setValue(T value) { this->value = value; }
            Node<Key, T>* getGrandParent( void )
            {
                if (this->parent)
                    return (this->parent->parent);
                else
                    return NULL;
            }
            Node<Key, T>* getUncle( void )
            {
                Node<Key, T> *GrandParent = this->getGrandParent();                
                if (GrandParent == NULL)
                    return NULL;
                if (GrandParent->left == this->parent)
                    return (GrandParent->right);
                if (GrandParent->right == this->parent)
                    return (GrandParent->left);
                return NULL;
            }

            int isLeftRightChild(Node<Key, T>* node)
            {
                // -1 not child, 0 left child, l right child
                if (!node)
                    return (-1);
                if (node && node->parent && node->parent->left == node)
                    return 0;
                if (node && node->parent && node->parent->right == node)
                    return 1;
                return  (-1);
            }

            int isInnerChild(Node<Key, T>* node)
            {
                // -1 no child, 0 outer child, 1 inner child
                if (!node)
                    return (-1);
                if (node && isLeftRightChild(node) == 0 && isLeftRightChild(node->parent) == 1)
                    return 1;
                if (node && isLeftRightChild(node) == 1 && isLeftRightChild(node->parent) == 0)
                    return 1;
                return (0);
            }

            void printNodeSubTree()
            {
                std::cout << std::endl << std::endl << std::endl;
                std::cout << this->getData() << " - " << this->getValue() << " - " << (this->getColor()? "Red" : "Black") << std::endl;
                if (this->left)
                    this->left->printNode('l', this);
                if (this->right)
                    this->right->printNode('r', this);
            }
            
            Node<Key, T>* leftRotate(Node<Key, T>* root, Node<Key, T>* node)
            {
                if (node == NULL)
                    return (NULL);
                Key tmp_key;
                T   tmp_value;
                int tmp_color;
                Node<Key, T>* save_root;
                Node<Key, T>* save_child_left = NULL;
                if (node == root)
                {
                    save_root = &(*root);
                    root = node->right;
                    if (node->right->left)
                        save_child_left = &(*node->right->left);
                    root->left = save_root;
                    root->left->parent = root;
                    if (node->right->left)
                        root->left->right = save_child_left;
                    return (root);
                }
                else if (node != root)
                {
                    if (node->left)
                    {
                        tmp_key = node->left->data;
                        node->left->data = node->data;
                        node->data = tmp_key;
                        tmp_value = node->left->value;
                        node->left->value = node->value;
                        node->value = tmp_value;
                        tmp_color = node->left->color;
                        node->left->color = node->color;
                        node->color = tmp_color;
                        node->right = node->left;
                        node->left = NULL;
                    }
                    else if (node->right && node->right->right)
                    {
                        Node<Key, T>* save_node = &(*node);
                        Node<Key, T>* save_parent_node = &(*node->parent);
                        Node<Key, T>* save_node_right_right = &(*node->right->right);                    
                        node = node->right; // je remplace 18 par 25
                        save_parent_node->right = node;
                        node->left = save_node;
                        node->left->left = NULL; // je mets NULL dans le right de 18
                        node->left->right = NULL; // je mets NULL dans le right de 18
                        node->right = save_node_right_right; // je mets a droite de 25 le 40
                        save_node_right_right->parent = node; // je mets 25 comme parent de 40            
                        node->parent = save_parent_node; // je mets dans le parent de 25 le 17
                    }
                    else if (node->right)
                    {
                        tmp_key = node->right->data;
                        node->right->data = node->data;
                        node->data = tmp_key;
                        tmp_value = node->right->value;
                        node->right->value = node->value;
                        node->value = tmp_value;
                        tmp_color = node->right->color;
                        node->right->color = node->color;
                        node->color = tmp_color;
                        node->left = node->right;
                        node->right = NULL;
                    }
                }
                return (NULL);
            }

            Node<Key, T>* rightRotate(/*Node<Key, T>* root, */Node<Key, T>* node)
            {
                if (node == NULL)
                    return (NULL);
                Node<Key, T> *Parent = node->parent;
                Node<Key, T> *GrandParent = node->getGrandParent();
                if (node->parent && GrandParent)
                {
                    
                    if (isLeftRightChild(Parent) == 1) // Parent is a right child of GrandParent
                    {
                        if (isLeftRightChild(node) == 0)
                            Parent->left = NULL;
                        else if (isLeftRightChild(node) == 1)
                            Parent->right = NULL;
                        node->right = Parent;
                        GrandParent->right = node;
                        node->parent = GrandParent;
                        Parent->parent = node;
                    }
                }
                return (NULL);
            }

            void printNode(char relative_pos, Node<Key, T>* parent)
            {
                std::cout << (relative_pos == 'r' ? "Right of " : "Left of ") << parent->data << " - " << this->getData() << " - " << this->getValue() << " - " << (this->getColor() ? "Red" : "Black") << std::endl; 
                if (left)
                    left->printNode('l', this);
                if (right)
                    right->printNode('r', this);    
            }
            
};

// We consider a BST as a linked list of Nodes.
template <class Key, class T>  
Node<Key, T>* BSTInsert(Node<Key, T>* root, Node<Key, T>* node)
{
    if (root == NULL)
    {
        node->setColor(BLACK);
        return (node);
    }
    if (root->getData() > node->getData())
    {
        root->left = BSTInsert(root->left, node);
        root->left->parent = root;
    }
    else if (root->getData() < node->getData())
    {
        root->right = BSTInsert(root->right, node);
        root->right->parent = root;  
    }
    // if not root, insert by default as a RED leaf
    node->setColor(RED);
    // // FIXING INSERTION PROBLEMS IN REGARD TO RBT RULES
    // // if RED leaf's parent is BLACK, then no problem, we should already comply to RBT standards.
    // // if RED leat's parent is RED, then we check parent's sibling (called uncle). If uncle is RED as well
    // // then we change parent and uncle's colors to BLACK.
    
    // Node<Key, T>* Parent = node->parent;
    // if (Parent->getColor() == RED)
    // {
    //     if (Parent->parent)
    //     {
    //         Node<Key, T>* Uncle = node->getUncle();
    //         if (Uncle && Uncle->getColor() == RED)
    //         {
    //             Uncle->setColor(BLACK);
    //             Parent->setColor(BLACK);
    //             // Parent->parent->setColor(RED);
    //         }
    //         else if (!Uncle)
    //         {
    //             // Need for a Left Rotation then Right Rotation then Recoloring
    //             // std::cout << "current Node: " << node->data << std::endl;
    //             // std::cout << "Launching LeftRotate" << std::endl;
    //             Parent->leftRotate(Parent);
    //             // std::cout << node->data << std::endl;
    //             node->parent->rightRotate(node->parent);
    //             node->parent->setColor(BLACK);
    //             node->parent->right->setColor(RED);

    //         }
    //     }
    // }
    return root;
}

template <class Key, class T>
Node<Key, T>* fixInsertion(Node<Key, T>* root,Node<Key, T>* node)
{
    // FIXING INSERTION PROBLEMS IN REGARD TO RBT RULES
    // if RED leaf's parent is BLACK, then no problem, we should already comply to RBT standards.
    // if RED leat's parent is RED, then we check parent's sibling (called uncle). If uncle is RED as well
    // then we change parent and uncle's colors to BLACK.
    
    Node<Key, T>* Parent = node->parent;
    Node<Key, T>* ret;
    // Node<Key, T>* final_root = root;
    if (Parent && Parent->getColor() == RED)
    {
        if (Parent->parent)
        {
            Node<Key, T>* Uncle = node->getUncle();
            if (Uncle && Uncle->getColor() == RED && Parent->parent == root)
            {
                std::cout << "\n==== RECOLORING OPERATION ====" << std::endl << "RED UNCLE & GRANDPARENT==ROOT\n" << "Recoloring Uncle to BLACK\n&& Parent to BLACK" << std::endl;
                Uncle->setColor(BLACK);
                Parent->setColor(BLACK);
                // Parent->parent->setColor(RED);
            }
            else if (Uncle && Uncle->getColor() == RED && Parent->parent != root)
            {
                std::cout << "\n==== RECOLORING OPERATION ====" << std::endl << "RED UNCLE & GRANDPARENT!=ROOT\n" <<"Recoloring Uncle to BLACK\n&& Parent to BLACK" << std::endl;
                Uncle->setColor(BLACK);
                Parent->setColor(BLACK);
                Parent->parent->setColor(RED);
                std::cout << "PPP = " << node->parent->parent->parent->data << " - PP = " << node->parent->parent->data << " - PPP->color = " << node->parent->parent->parent->getColor() << " vs PP->color = " << node->parent->parent->getColor() << std::endl;
                if (node->parent->parent->parent->getColor() == RED && node->parent->parent->getColor() == RED)
                {
                    std::cout << "needs another fixing after recoloring - root is " << root->data << std::endl;
                    ret = fixInsertion(root, node->parent->parent);
                    if (ret != NULL)
                        root = ret;
                    // node = node->parent;
                    // std::exit(0);
                }
            }
            else if (Uncle && Uncle->getColor() == BLACK)
            {
                    std::cout << "\n==== LEFT ROTATION 309 on " << Parent->parent->data << " ====" << std::endl;
                    ret = Parent->leftRotate(root, Parent->parent);

                    if (ret != NULL)
                    {
                        root = ret;
                        std::cout << "\n==== RECOLORING OPERATION ====" << std::endl << "NEW ROOT TO BE COLORED IN BLACK\nCHILDREN COLORED IN RED\n"  << std::endl;
                        root->setColor(BLACK);
                        root->left->setColor(RED);
                    }
            }
            else if (!Uncle)
            {
                // 2 different cases : inner child, outer child
                // Inner child requires a Left Rotation then Right Rotation then Recoloring (or opposite) ? or Left Left Rotation and Recoloring?
                // Outer child requires a Left Rotation and Recoloring (or opposite)
                if (node->isInnerChild(node) == 1)
                {
                    root->printNodeSubTree();
                    std::cout << "\n==== LEFT ROTATION 329 on " << Parent->data << " ====" << std::endl;
                    ret = Parent->leftRotate(root, Parent);
                    if (ret != NULL)
                        root = ret;
                    root->printNodeSubTree();
                    std::cout << "CRITICAL MOMENT: " << node->data << std::endl;
                    if (node->isInnerChild(node) == 0)
                    {
                        if (node->parent->left == node)
                        {
                            std::cout << "\n==== RIGHT ROTATION 339 on " << node->parent->data << " ====" << std::endl;
                            node->parent->rightRotate(node->parent);
                            // if (ret != NULL)
                            //     root = ret;
                        }
                        else if (node->parent->right == node)
                        {
                            std::cout << "\n==== LEFT ROTATION 346 on " << node->parent->parent->data << " ====" << std::endl;
                            ret = node->parent->parent->leftRotate(root, node->parent->parent);
                            if (ret != NULL)
                                root = ret;
                        }    
                        // root->printNodeSubTree();
                        std::cout << "\n==== RECOLORING OPERATION ====" << std::endl << "Recoloring new parent to BLACK\n&& new son to RED (RR)" << std::endl;
                        node->parent->setColor(BLACK);
                        if (node->parent->right)
                            node->parent->right->setColor(RED);
                        if (node->parent->left)                        
                            node->parent->left->setColor(RED); 
                    }
                    else if (node->isInnerChild(node) == 1)
                    {
                        std::cout << "\n==== RIGHT ROTATION 358 on " << node->parent->data << " ====" << std::endl;
                        ret = node->parent->rightRotate(node->parent);
                        if (ret != NULL)
                            root = ret;
                        root->printNodeSubTree();
                        std::cout << "\n==== RECOLORING OPERATION ====" << std::endl << "NO UNCLE - INNER CHILD\n" << "Recoloring new parent to BLACK\n&& new right son to RED (RR)" << std::endl;
                        node->parent->setColor(BLACK);
                        node->parent->right->setColor(RED);
                    }
                }
                else if (node->isInnerChild(node) == 0)
                {
                    std::cout << "\n==== LEFT ROTATION 370 on " << Parent->parent->data << " ====" << std::endl;
                    ret = Parent->leftRotate(root, Parent->parent);
                    if (ret != NULL)
                        root = ret;
                    std::cout << "\n==== RECOLORING OPERATION ====" << std::endl << "NO UNCLE - OUTER CHILD\n" << "Recoloring new parent to BLACK\n&& new right son (cousin) to RED (RR)" << std::endl;
                    std::cout << "current node: " << node->data << std::endl;
                    std::cout << "current node->parent: " << node->parent->data << std::endl;
                    std::cout << "current node->parent->parent: " << node->parent->parent->data << std::endl;
                    std::cout << "current node->parent->parent->parent: " << node->parent->parent->parent->data << std::endl;
                    std::cout << "current node->parent->right: " << node->parent->right->data << std::endl;
                    std::cout << "current node->parent->left: " << (node->parent->left? node->parent->left->data : 0) << std::endl;
                    // node->parent->parent->parent->printNodeSubTree();
                    node->parent->left->setColor(RED);
                    node->parent->setColor(BLACK);
                }
            }
        }
    }
    return (root);
}

template <class Key, class T>  
Node<Key, T>* searchNode(Node<Key, T>* node, Key key)
{
    if (node == NULL || key == node->data)
        return node;
    if (key > node->data)
        return (searchNode(node->right, key));
    else
        return (searchNode(node->left, key));
}

template <class Key, class T>  
class RBTree {
    
    private:
                Node<Key, T>* _root;

    protected:
                
    
    public:          
                RBTree(): _root(NULL){};
                RBTree(Key data){
                    _root = new Node<Key, T>(data);
                    _root->setColor(BLACK); 
                };
                
                Node<Key, T>* getRoot(){ return _root;};
                
                void setRoot(Node<Key, T> &node){ this->_root = node; };
                
                void swapNodeColor(Node<Key, T> &nodeA, Node<Key, T> &nodeB)
                {
                    int tmp_color = nodeA.color;
                    nodeA.setColor(nodeB->getColor);
                    nodeB.setColor(tmp_color);
                }

                void insertNode(Key data, T value)
                {
                    Node<Key, T>* newNode = new Node<Key, T>(data, value);
                    
                    this->_root = BSTInsert(this->_root, newNode);
                    this->_root= fixInsertion(this->_root, newNode);
                }

                Node<Key, T>* getMaxValueNode(Node<Key, T> *root)
                {
                    if(root == NULL)
                        return NULL;
                    else if (root->right==NULL)
                        return root;
                    else
                        return getMaxValueNode(root->right);
                }

                Node<Key, T>* getMinValueNode(Node<Key, T>* node)
                {
                    Node<Key, T>* current = node;
                
                    /* loop down to find the leftmost leaf */
                    while (current && current->left != NULL)
                        current = current->left;
                
                    return current;
                }
                
                Node<Key, T>* getGrandParent(Node<Key, T>* node)
                {
                    if (node && node->parent)
                        return (node->parent->parent);
                    else
                        return NULL;
                }

                Node<Key, T>* getUncle(Node<Key, T>* node)
                {
                    Node<Key, T> *GrandParent = getGrandParent(node);                
                    if (GrandParent == NULL)
                        return NULL;
                    if (GrandParent->left == node->parent)
                        return (GrandParent->right);
                    if (GrandParent->right == node->parent)
                        return (GrandParent->left);
                    return NULL;
                }
                
                Node<Key, T>* getIOSuccessor(Node<Key, T>* node)
                {        
                    if (node == NULL)
                        return NULL;
                    if (node->right)
                        return (getMinValueNode(node->right));
                    if (!node->right)
                    {
                        while (node->parent && node->parent->left != node)
                            node = node->parent;
                        if (node->parent == _root && node->parent->left == node)
                            return (node->parent);
                        if (node->parent == _root && node->parent->left != node)
                            return (NULL);
                        return (node->parent);
                    }
                    return NULL;
                }

                Node<Key, T>* getIOPredecessor(Node<Key, T>* node)
                {          
                    if (node == NULL)
                        return NULL;
                    if (node->left)
                        return (getMaxValueNode(node->left));
                    if (!node->left)
                    {
                        while (node->parent && node->parent->right != node)
                            node = node->parent;
                        if (node->parent == _root && node->parent->right == node)
                            return (node->parent);
                        if (node->parent == _root)
                            return (NULL);
                        return (node->parent);
                    }
                    return NULL;
                }

                Node<Key, T>* NodeDelete(Node<Key, T>* node, Key key)
                {
                    
                    Node<Key, T>* NodeToDelete = searchNode(node, key);
                    if (NodeToDelete)
                    {
                        Node<Key, T>* NodeParent = NodeToDelete->parent;
                        if (!NodeToDelete->right && !NodeToDelete->left)
                        {
                            if (NodeToDelete->parent->left == NodeToDelete)
                                NodeToDelete->parent->left = NULL;
                            else if (NodeToDelete->parent->right == NodeToDelete)
                                NodeToDelete->parent->right = NULL;
                            delete(NodeToDelete);
                            return (NodeParent);
                        }
                        if (!NodeToDelete->right || !NodeToDelete->left)
                        {
                            Node<Key, T>* NodeSurvivor= (!NodeToDelete->right ? NodeToDelete->left: NodeToDelete->right);
                            if (NodeToDelete->parent->left == NodeToDelete)
                            {
                                NodeSurvivor->parent = NodeToDelete->parent;
                                NodeToDelete->parent->left = NodeSurvivor;
                            }
                            else if (NodeToDelete->parent->right == NodeToDelete)
                            {
                                NodeSurvivor->parent = NodeToDelete->parent;
                                NodeToDelete->parent->right = NodeSurvivor;
                            }
                            delete(NodeToDelete);
                            return (NodeParent);
                        }
                        if (NodeToDelete->right && NodeToDelete->left)
                        {
                            // std::cout << "NodeToDelete: " << NodeToDelete->data << std::endl;
                            Node<Key, T>* IOSuccessor = getIOSuccessor(NodeToDelete);
                            // std::cout << "successor: " << InOrderSuccessor->data << std::endl;
                            NodeToDelete->data = IOSuccessor->data;
                            NodeToDelete->value = IOSuccessor->value;               
                            // Update a faire des liens de l'ancien InOrderSuccessor qui va etre detruit. On branche ses childrens avec son parent.
                            if (IOSuccessor->parent)
                            {
                                Node<Key, T>* IOSParent = IOSuccessor->parent;
                                if (IOSuccessor->right)
                                    IOSParent->left = IOSuccessor->right;
                            }
                            delete(IOSuccessor);
                            return (NodeToDelete);
                        }
                    }
                    return (NodeToDelete ? NodeToDelete : NULL);
                }

                void printRBT()
                {
                    if (this->_root)
                    {
                        std::cout << std::endl << std::endl << std::endl;
                        std::cout << _root->getData() << " - " << _root->getValue() << " - " << (_root->getColor()? "Red" : "Black") << std::endl;
                        if (_root->left)
                            _root->left->printNode('l', _root);
                        if (_root->right)
                            _root->right->printNode('r', _root);
                    }
                }
};

}


#endif