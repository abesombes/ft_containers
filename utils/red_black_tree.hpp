/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:48:33 by abesombes         #+#    #+#             */
/*   Updated: 2022/02/11 20:10:00 by abesombes        ###   ########.fr       */
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

            int doubleRed(Node<Key, T>* node)
            {
                // -1 no parent, 0 no double red, l double red child-parent
                if (!node || !node->parent)
                    return (-1);
                if (node && node->parent && node->getColor() == RED && node->parent->getColor() == RED)
                    return 1;
                return 0;
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

            int isLeftRightCase(Node<Key, T>* node)
            {
                // -1 no parent or no grandparent, 0 LeftRight Case, 1 RightLeft Case, 2 LeftLeft Case, 3 RightRight Case
                if (!node)
                    return (-1);
                if (node && isLeftRightChild(node) == 1 && isLeftRightChild(node->parent) == 0)
                    return 0;
                if (node && isLeftRightChild(node) == 0 && isLeftRightChild(node->parent) == 1)
                    return 1;
                if (node && isLeftRightChild(node) == 0 && isLeftRightChild(node->parent) == 0)
                    return 2;   
                if (node && isLeftRightChild(node) == 1 && isLeftRightChild(node->parent) == 1)
                    return 3;
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
            
            Node<Key, T>* leftRotate(Node<Key, T>* root, Node<Key, T>* node) // Right Right Case ONLY
            {
                if (node == NULL)
                    return (NULL);
                Node<Key, T>* snode = &(*node); // GrandParent in the chain of 3 nodes
                Node<Key, T>* RightChild = (node->right? &(*node->right) : NULL);
                Node<Key, T>* RightLeftChild = (node->right? &(*node->right->left) : NULL);
                int flag_root = (node == root? 1 : 0);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
                node = RightChild;
                node->left = snode;
                node->left->right = RightLeftChild;
                RightLeftChild->parent = node->left->right;
                return (flag_root? node: NULL);
            }

            Node<Key, T>* rightRotate(Node<Key, T>* root, Node<Key, T>* node) // Left Left Case ONLY
            {
                if (node == NULL)
                    return (NULL);
                Node<Key, T>* snode = &(*node); // GrandParent in the chain of 3 nodes
                Node<Key, T>* LeftChild = (node->left? &(*node->left) : NULL);
                Node<Key, T>* LeftRightChild = (node->left? &(*node->left->right) : NULL);
                int flag_root = (node == root? 1 : 0);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
                node = LeftChild;
                node->right = snode;
                node->right->left = LeftRightChild;
                LeftRightChild->parent = node->right->left;
                return (flag_root? node: NULL);
            }

            Node<Key, T>* leftrightRotate(Node<Key, T>* root, Node<Key, T>* node) // Left Right Case ONLY
            {
                if (node == NULL)
                    return (NULL);
                Node<Key, T>* snode = &(*node); // GrandParent in the chain of 3 nodes
                Node<Key, T>* LChild = (node->left? &(*node->left) : NULL);
                Node<Key, T>* LRChild = (node->left? &(*node->left->right) : NULL);
                Node<Key, T>* LRLChild = (node->left->right? &(*node->left->right->left) : NULL);
                Node<Key, T>* LRRChild = (node->left->right? &(*node->left->right->right) : NULL);
                
                int flag_root = (node == root? 1 : 0);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
                node = LRChild;
                node->left = LChild;
                LChild->parent = node;
                node->right = snode;
                snode->parent = node;
                node->left->right = LRLChild;
                LRLChild->parent = node->left->right;
                node->right->left = LRRChild;
                LRRChild->parent = node->right->left;
                return (flag_root? node: NULL);
            }

            Node<Key, T>* rightleftRotate(Node<Key, T>* root, Node<Key, T>* node) // Right Left Case ONLY
            {
                if (node == NULL)
                    return (NULL);
                Node<Key, T>* snode = &(*node); // GrandParent in the chain of 3 nodes
                Node<Key, T>* RChild = (node->right? &(*node->right) : NULL);
                Node<Key, T>* RLChild = (node->right? &(*node->right->left) : NULL);
                Node<Key, T>* RLLChild = (node->right->left? &(*node->right->left->left) : NULL);
                Node<Key, T>* RLRChild = (node->right->left? &(*node->right->left->right) : NULL);
                
                int flag_root = (node == root? 1 : 0);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
                node = RLChild;
                node->left = snode;
                snode->parent = node;
                node->right = RChild;
                RChild->parent = node;
                node->left->right = (RLLChild? RLLChild : NULL);
                if (RLLChild)
                    RLLChild->parent = node->left->right;
                node->right->left = (RLRChild ? RLRChild : NULL);
                if (RLRChild)
                    RLRChild->parent = node->right->left;
                return (flag_root? node: NULL);
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
    return root;
}

template <class Key, class T>
Node<Key, T>* fixInsertion(Node<Key, T>* root, Node<Key, T>* node)
{
    // FIXING INSERTION PROBLEMS IN REGARD TO RBT RULES
    // if RED leaf's parent is BLACK, then no problem, we should already comply to RBT standards.
    // if RED leat's parent is RED, then we check parent's sibling (called uncle). If uncle is RED as well
    // then we change parent and uncle's colors to BLACK.
    
    Node<Key, T>* Parent = node->parent;
    Node<Key, T>* ret = NULL;
    std::cout << "\nTrying to fix node " << node->data << std::endl;
    if (node->parent)
    {
        if (node->doubleRed(node) && node->isInnerChild(node) == 0)
        {
            std::cout << "\n==== LEFT RIGHT ROTATION 235 on " << Parent->parent->data << " ====" << std::endl;
            ret = Parent->parent->leftrightRotate(root, Parent->parent);
        }   
        else if (node->doubleRed(node) && node->isInnerChild(node) == 1)
        {
            std::cout << "\n==== RIGHT LEFT ROTATION 240 on " << Parent->parent->data << " ====" << std::endl;
            ret = Parent->parent->rightleftRotate(root, Parent->parent);
            std::cout << "\n==== RECOLORING on " << node->data << " ====" << std::endl;    
            node->setColor(BLACK);
            node->left->setColor(RED);  
        }
        if (ret)
            root = ret;
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
                    std::cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << "+++++++++++++ ANNOUNCEMENT: NEW VALUE ADDED - " << data << " +++++++++++++" << std::endl;
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    this->printRBT();
                    this->_root = fixInsertion(this->_root, newNode);
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