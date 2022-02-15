/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:48:33 by abesombes         #+#    #+#             */
/*   Updated: 2022/02/15 14:33:43 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP
#define RED 0
#define BLACK 1
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
            int color; // RED (0) -> Red, BLACK (1) -> Black, DOUBLE_BLACK (2) -> Double Black
            
            Node(Key data, T value): data(data), value(value), parent(NULL), left(NULL), right(NULL), color(RED){};
            Node(Key data, T value, int color): data(data), value(value), parent(NULL), left(NULL), right(NULL), color(color){}
            void setColor(int color) { this->color = color;}
            int getColor() { return (color);}
            Key &getData() { return (data); }
            void setData (Key &data) { this->data = data; }
            T &getValue() { return (value); }
            void setValue(T value) { this->value = value; }
            int isRed(void) { return (getColor() == RED);}
            int isBlack(void) { return (getColor() == BLACK);}
            int isDBlack(void) { return (getColor() == DOUBLE_BLACK);}
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

            int hasLRChildren(Node<Key, T>* node)
            {
                return (node && node->left && node->right? 1 : 0);
            }

            int hasNoChild(void)
            {
                return (!this->left && !this->right);
            }
            
            int hasBlackLChild(void)
            {
                return ((this->left && this->left->isBlack()) || !this->left);
            }

            int hasBlackRChild(void)
            {
                return ((this->right && this->right->isBlack()) || !this->right);
            }
            
            int hasNoRightChild(void)
            {
                return (!this->right);
            }

            int hasTwoBlackNephews(void)
            {
                Node<Key, T> *Sibling= getSibling(this);      
                if (Sibling)
                    return (Sibling->hasNoChild() || (Sibling->hasBlackLChild() && !Sibling->right) || (Sibling->hasBlackRChild() && !Sibling->left) || (Sibling->hasBlackLChild() && Sibling->hasBlackRChild()));
                return (0);
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
            
            int isLeftChild(void)
            {
                // 1 Left Child, 0 no parent or Right Child
                if (this->parent && this->parent->left == this)
                    return 1;
                return  (0);
            }

            int isRightChild(void)
            {
                // 1 Right Child, 0 no parent or Left Child
                if (this->parent && this->parent->right == this)
                    return 1;
                return  (0);
            }
            
            int isLeftRightChild(void)
            {
                // -1 not child, 0 left child, l right child
                if (this->parent && this->parent->left == this)
                    return 0;
                if (this && this->parent && this->parent->right == this)
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
                std::cout << this->getData() << " - " << this->getValue() << " - " << (this->getColor() == RED? "Red" : this->getColor() == DOUBLE_BLACK? "Double Black": "Black") << std::endl;
                if (this->left)
                    this->left->printNode('l', this);
                if (this->right)
                    this->right->printNode('r', this);
            }
            
            void pushBlacknessDown(Node<Key, T>* node)
            {
                Node<Key, T>* Parent = node->parent;
                Node<Key, T>* GrandParent = node->getGrandParent();
                Node<Key, T>* Uncle = node->getUncle();
                std::cout << "\n==== PUSH THE BLACKNESS DOWN FROM GP ====" << std::endl;
                if (GrandParent->getColor() == BLACK)
                {
                    Uncle->setColor(BLACK);
                    Parent->setColor(BLACK);
                    GrandParent->setColor(RED);
                }
            }
            
            void pushBlacknessUp(void)
            {
                Node<Key, T>* Parent = parent;
                Node<Key, T>* Sibling = getSibling(this);
                std::cout << "\n==== PUSH THE BLACKNESS UP: " << this->data << " - " << Parent->data << " - " << Sibling->data << " ====" << std::endl;
                setColor(std::max(getColor() - 1, 0));
                if (Parent)
                    Parent->setColor(Parent->getColor() + 1);
                if (Sibling)
                    Sibling->setColor(std::max(Sibling->getColor() - 1, 0));                
            }
            
            Node<Key, T>* leftRotate(Node<Key, T>* root, Node<Key, T>* node) // Right Right Case ONLY
            {
                if (node == NULL)
                    return (NULL);
                Node<Key, T>* Parent = &(*node->parent);
                int flag_lr = (isLeftRightChild(node) ? 1 : 0);
                Node<Key, T>* snode = &(*node); // GrandParent in the chain of 3 nodes
                Node<Key, T>* RightChild = (node->right? &(*node->right) : NULL);
                Node<Key, T>* RightLeftChild = (node->right? &(*node->right->left) : NULL);
                int flag_root = (node == root? 1 : 0);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
                node = RightChild;
                std::cout << "I am here 160\n";
                if (flag_lr && !flag_root)
                    Parent->right = node;
                else if (!flag_root)
                    Parent->left = node;
                if (Parent)
                    node->parent = Parent;
                node->left = snode;
                snode->parent = node;
                node->left->right = RightLeftChild;
                if (RightLeftChild)
                    RightLeftChild->parent = node->left;
                if (flag_root)
                    node->parent = NULL;
                return (flag_root? node: NULL);
            }

            Node<Key, T>* rightRotate(Node<Key, T>* root, Node<Key, T>* node) // Left Left Case ONLY
            {
                if (node == NULL)
                    return (NULL);
                Node<Key, T>* Parent = &(*node->parent);
                int flag_lr = (isLeftRightChild(node) ? 1 : 0);
                Node<Key, T>* snode = &(*node); // GrandParent in the chain of 3 nodes
                Node<Key, T>* LeftChild = (node->left? &(*node->left) : NULL);
                Node<Key, T>* LRChild = (node->left? &(*node->left->right) : NULL);
                int flag_root = (node == root? 1 : 0);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
                node = LeftChild;
                if (flag_lr && !flag_root)
                    Parent->right = node;
                else if (!flag_root)
                    Parent->left = node;
                if (Parent)
                    node->parent = Parent;
                node->right = snode;
                snode->parent = node;
                node->right->left = LRChild;
                if (LRChild)
                    LRChild->parent = node->right;
                if (flag_root)
                    node->parent = NULL;
                return (flag_root? node: NULL);
            }

            Node<Key, T>* leftrightRotate(Node<Key, T>* root, Node<Key, T>* node) // Left Right Case ONLY
            {
                std::cout << "I am here 156\n" << std::endl;
                if (node == NULL)
                    return (NULL);
                Node<Key, T>* Parent = &(*node->parent);
                int flag_lr = (isLeftRightChild(node) ? 1 : 0);
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
                if (flag_lr && !flag_root)
                    Parent->right = node;
                else if (!flag_root)
                    Parent->left = node;
                if (Parent)
                    node->parent = Parent;
                node->left->right = LRLChild;
                if (LRLChild)
                    LRLChild->parent = node->left;
                node->right->left = LRRChild;
                if (LRRChild)
                    LRRChild->parent = node->right;
                if (flag_root)
                    node->parent = NULL;
                return (flag_root? node: NULL);
            }

            Node<Key, T>* rightleftRotate(Node<Key, T>* root, Node<Key, T>* node) // Right Left Case ONLY
            {
                if (node == NULL)
                    return (NULL);
                Node<Key, T>* Parent = &(*(node->parent));
                // std::cout << "1er passage ---  node: "<< node->data << " - node->parent: " << (node->parent? node->parent->data : 0) << " - Parent: " << (Parent != NULL ? Parent->value : std::string()) << std::endl;
                int flag_lr = (isLeftRightChild(node) ? 1 : 0);
                Node<Key, T>* snode = &(*node); // GrandParent in the chain of 3 nodes
                Node<Key, T>* RChild = (node->right? &(*node->right) : NULL);
                Node<Key, T>* RLChild = (node->right? &(*node->right->left) : NULL);
                Node<Key, T>* RLLChild = (node->right->left? &(*node->right->left->left) : NULL);
                Node<Key, T>* RLRChild = (node->right->left? &(*node->right->left->right) : NULL);
                int flag_root = (node == root? 1 : 0);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
                node = RLChild;
                if (flag_lr && !flag_root)
                    Parent->right = node;
                else if (!flag_root)
                    Parent->left = node;
                if (Parent)
                    node->parent = Parent;
                // std::cout << "node 264: "<< node->data << " - node->parent: " << node->parent->data << " - Parent: " << (Parent != NULL ? Parent->value : std::string()) << std::endl;
                node->left = snode;
                snode->parent = node;
                node->right = RChild;
                RChild->parent = node;
                node->left->right = RLLChild;
                if (RLLChild)
                    RLLChild->parent = node->left;
                node->right->left = RLRChild;
                if (RLRChild)
                    RLRChild->parent = node->right;
                if (flag_root)
                    node->parent = NULL;
                return (flag_root? node: NULL);
            }


            void printNode(char relative_pos, Node<Key, T>* parent)
            {
                std::cout << (relative_pos == 'r' ? "Right of " : "Left of ") << parent->data << " - " << "Parent = " << this->parent->getData() << " - " << this->getData() << " - " << this->getValue() << " - " << (this->getColor() == RED? "Red" : this->getColor() == DOUBLE_BLACK? "Double Black": "Black") << std::endl; 
                if (left)
                    left->printNode('l', this);
                if (right)
                    right->printNode('r', this);    
            }
            
};

template <class Key, class T>  
void removeParentLink(Node<Key, T>* node)
{
    Node<Key, T> *Parent = node->parent;          
    if (Parent && Parent->left == node)
        Parent->left = NULL;
    else if (Parent && Parent->right == node)
        Parent->right = NULL;
}

template <class Key, class T>  
int isLeaf(Node<Key, T>* node)
{
    return (node && node->left == NULL && node->right == NULL);
}

template <class Key, class T>  
Node<Key, T>* getSibling(Node<Key, T>* node)
{
    // std::cout << "line 378 - node: " << node->data << " - node->parent: " << node->parent->data << std::endl;
    if (node && node->parent && node->parent->left == node)
        return (node->parent->right);
    else if (node && node->parent && node->parent->right == node)
        return (node->parent->left);
    return (NULL);
}

template <class Key, class T>  
Node<Key, T>* getLeftNephew(Node<Key, T>* node)
{
    if (node && node->parent && node->parent->left == node)
        return (node->parent->right->left);
    else if (node && node->parent && node->parent->right == node)
        return (node->parent->left->left);
    return (NULL);
}

template <class Key, class T>  
Node<Key, T>* getRightNephew(Node<Key, T>* node)
{
    if (node && node->parent && node->parent->left == node)
        return (node->parent->right->right);
    else if (node && node->parent && node->parent->right == node)
        return (node->parent->left->right);
    return (NULL);
}


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
    // 0 LeftRight Case, 1 RightLeft Case, 2 LeftLeft Case, 3 RightRight Case
    Node<Key, T>* Parent = node->parent;
    // Node<Key, T>* GrandParent = node->getGrandParent();
    Node<Key, T>* Uncle = node->getUncle();
    Node<Key, T>* ret = NULL;
    std::cout << "\nTrying to fix node " << node->data << std::endl;
    if (node->parent)
    {
        std::cout << "Node Shape: " << node->isLeftRightCase(node) << std::endl;
        std::cout << "0 = LeftRight Case\n1 = RightLeft Case\n2 = LeftLeft Case\n3 = RightRight Case" << std::endl;
        if (node->doubleRed(node) && Uncle && Uncle->getColor() == RED)
        {            
            node->pushBlacknessDown(node);
            ret = fixInsertion(root, node->parent->parent);
        }
        else if (node->doubleRed(node) && node->isLeftRightCase(node) == 0)
        {
            std::cout << "\n==== LEFT RIGHT ROTATION 292 on " << Parent->parent->data << " ====" << std::endl;
            ret = Parent->parent->leftrightRotate(root, Parent->parent);
            std::cout << "\n==== RECOLORING on " << node->data << " ====" << std::endl;    
            node->setColor(BLACK);
            node->right->setColor(RED);
        }   
        else if (node->doubleRed(node) && node->isLeftRightCase(node) == 1)
        {
            std::cout << "\n==== RIGHT LEFT ROTATION 300 on " << Parent->parent->data << " ====" << std::endl;
            ret = Parent->parent->rightleftRotate(root, Parent->parent);
            std::cout << "\n==== RECOLORING on " << node->data << " ====" << std::endl;    
            node->setColor(BLACK);
            node->left->setColor(RED);  
        }
        else if (node->doubleRed(node) && node->isLeftRightCase(node) == 2)
        {
            std::cout << "\n==== RIGHT ROTATION 308 on " << Parent->parent->data << " ====" << std::endl;
            ret = Parent->parent->rightRotate(root, Parent->parent);
            std::cout << "\n==== RECOLORING on " << node->data << " ====" << std::endl;    
            node->parent->setColor(BLACK);
            node->parent->right->setColor(RED);  
        }
        else if (node->doubleRed(node) && node->isLeftRightCase(node) == 3)
        {
            std::cout << "\n==== LEFT ROTATION 316 on " << Parent->parent->data << " ====" << std::endl;
            ret = Parent->parent->leftRotate(root, Parent->parent);
            std::cout << "\n==== RECOLORING on " << node->data << " ====" << std::endl; 
            node->parent->setColor(BLACK);
            node->parent->left->setColor(RED);
        }
        if (ret)
            root = ret;
        root->printNodeSubTree();
    }
    std::cout << "current node: " << node->data << std::endl;
    if (node->parent && node->parent->parent && node->parent->parent != root && node->parent->parent->doubleRed(node->parent->parent))
    {
        std::cout << "ALERT : DOUBLE RED AFTER FIX REQUIRES ANOTHER FIX" << std::endl;
        ret = fixInsertion(root, node->parent->parent);
        if (ret)
            root = ret;
        std::cout << "SPECIAL MESSAGE ==== node: " << node->data << " - node->parent: " << node->parent->data << std::endl;  
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
                    std::cout << "newNode: " << newNode->getColor() << std::endl;
                    this->_root = BSTInsert(this->_root, newNode);
                    std::cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << "+++++++++++++ ANNOUNCEMENT: NEW VALUE ADDED - " << data << " +++++++++++++" << std::endl;
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    this->printRBT();
                    _root = fixInsertion(this->_root, newNode);
                    std::cout << "_root: " << _root->getColor() << std::endl;
                    if (_root->getColor() == RED)
                        _root->setColor(BLACK);
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

                Node<Key, T>* deleteNode(Node<Key, T>* node, Key key)
                {
                    if (!node)
                        return NULL;
                    std::cout << "\n==== NODE DELETE: " << key << " ====" << std::endl;
                    Node<Key, T>* TargetNode = searchNode(node, key);
                    Node<Key, T>* Parent = node->parent;
                    Node<Key, T>* Parent_SubTree = NULL;
                    Node<Key, T>* Sibling = NULL;
                    Node<Key, T>* ret = NULL;
                    if (TargetNode)
                    {
                        if (isLeaf(TargetNode) && TargetNode->getColor() == RED)
                        {
                            std::cout << "Specific Case: Red Leaf" << std::endl;
                            removeParentLink(TargetNode);
                            delete TargetNode;
                        }
                        else if (isLeaf(TargetNode) && TargetNode->getColor() == BLACK)
                        {
                            std::cout << "==== TargetNode is a Black Leaf ====" << std::endl;
                            TargetNode->data = Key();
                            TargetNode->value = T();
                            TargetNode->setColor(DOUBLE_BLACK);
                            std::cout << "Sibling: " << (getSibling(TargetNode)? getSibling(TargetNode)->data : -1) << std::endl;
                            if (getSibling(TargetNode) && getSibling(TargetNode)->isBlack() && TargetNode->hasTwoBlackNephews())
                            {
                                std::cout << "\n==== PUSH BLACKNESS UP on " << TargetNode->data << " level - line 660 ====" << std::endl;
                                TargetNode->pushBlacknessUp();
                                _root->printNodeSubTree();
                                removeParentLink(TargetNode);
                                delete TargetNode; 
                            }
                            else if (getSibling(TargetNode) && getSibling(TargetNode)->isBlack() && TargetNode->isLeftChild() && TargetNode->isDBlack() && ((getRightNephew(TargetNode) && getRightNephew(TargetNode)->isBlack()) || !getRightNephew(TargetNode)))
                            {
                                std::cout << "\n==== RIGHT LEFT ROTATION 656 on " << TargetNode->parent->data << " ====" << std::endl;
                                ret = TargetNode->parent->rightleftRotate(_root, TargetNode->parent);
                                std::cout << "TargetNode->parent: " << TargetNode->parent->data << std::endl;
                                std::cout << "\n==== RECOLORING on " << TargetNode->parent->parent->data << " ====" << std::endl;
                                // Sibling = getSibling(TargetNode->parent);
                                // Sibling->setColor(RED);
                                TargetNode->parent->parent->setColor(BLACK);
                                removeParentLink(TargetNode);
                                delete TargetNode; 
                            }
                            else if (getSibling(TargetNode) && getSibling(TargetNode)->getColor() == BLACK && TargetNode->isLeftChild() && TargetNode->getColor() == DOUBLE_BLACK && getRightNephew(TargetNode) && getRightNephew(TargetNode)->isRed())
                            {
                                std::cout << "\n==== LEFT ROTATION 672 on " << TargetNode->parent->data << " ====" << std::endl;
                                std::cout << "_root: " << _root->data << " Parent: " << (Parent? Parent->data : 0) << std::endl;
                                ret = TargetNode->parent->leftRotate(_root, TargetNode->parent);
                                // std::cout << "\n==== PUSH BLACKNESS DOWN on " << TargetNode->parent->data << " level - line 672 ====" << std::endl;
                                // TargetNode->parent->pushBlacknessDown(TargetNode->parent);
                                std::cout << "\n==== RECOLORING on " << TargetNode->parent->parent->right->data << " ====" << std::endl;
                                if (TargetNode->parent->parent->right)
                                    TargetNode->parent->parent->right->setColor(BLACK);
                                if (TargetNode->parent->parent->left)
                                    TargetNode->parent->parent->left->setColor(BLACK);
                                TargetNode->parent->parent->setColor(RED);
                                
                                if (TargetNode->isLeftRightChild(TargetNode) == 0)
                                    TargetNode->parent->left = NULL;
                                else if (TargetNode->isLeftRightChild(TargetNode) == 1)
                                    TargetNode->parent->right = NULL;
                                delete TargetNode;
                            }
                        }
                        else if (TargetNode->hasLRChildren(TargetNode))
                        {
                            std::cout << "\n==== TargetNode has two children ====\n" << std::endl;
                            Node<Key, T>* Replacer = getMaxValueNode(TargetNode->left);
                            std::cout << "I am here 671: TargetNode = " << TargetNode->data << " - Replacer (Max Value of Left Subtree) = " << Replacer->data << std::endl;
                            TargetNode->data = Replacer->data;
                            TargetNode->value = Replacer->value;
                            if (TargetNode && Replacer->left)
                            {
                                TargetNode->left = Replacer->left;
                                Replacer->left->parent = TargetNode;
                            }
                            if (Replacer->isBlack() && Replacer->left)
                                Replacer->left->setColor(BLACK);
                            std::cout << "I am here 681: TargetNode = " << TargetNode->data << " - Replacer = " << Replacer->data << std::endl;
                            std::cout << "Sibling of former " << Replacer->data << " (now DOUBLE BLACK NULL LEAF): " << (getSibling(Replacer) ? getSibling(Replacer)->data : -1) << std::endl;
                            if (Replacer->isBlack())
                            {
                                std::cout << "I am here: line 685" << std::endl;
                                Replacer->data = Key();
                                Replacer->value = T();
                                Replacer->setColor(DOUBLE_BLACK);
                                while (getSibling(Replacer) && getSibling(Replacer)->isBlack() && Replacer->hasTwoBlackNephews())
                                {
                                    std::cout << "\n==== PUSH BLACKNESS UP on " << Replacer->data << " level - line 704 ====" << std::endl;
                                    Replacer->pushBlacknessUp();
                                    _root->printNodeSubTree();
                                    std::cout << "TargetNode: " << TargetNode->data << " - color = " << TargetNode->getColor() << std::endl;
                                    Sibling = getSibling(TargetNode);
                                    int flag_pushblackness_up = 0;
                                    std::cout << "TargetNode: " << TargetNode->data << " - getSibling(TargetNode): " << getSibling(TargetNode)->data << " - color = " << getSibling(TargetNode)->getColor() << std::endl;
                                    while (getSibling(TargetNode) && getSibling(TargetNode)->isBlack() && TargetNode->hasTwoBlackNephews())
                                    {
                                        std::cout << "\n==== PUSH BLACKNESS UP on " << TargetNode->data << " level - line 712 ====" << std::endl;
                                        TargetNode->pushBlacknessUp();
                                        _root->printNodeSubTree();
                                        std::cout << "TargetNode: " << TargetNode->data << " - color = " << TargetNode->getColor() << std::endl;
                                        TargetNode = TargetNode->parent;
                                        flag_pushblackness_up = 1;
                                    }
                                    if (flag_pushblackness_up)
                                        continue;
                                    if (TargetNode->isLeftChild() && Sibling->isBlack() && getRightNephew(TargetNode) && getRightNephew(TargetNode)->isBlack())
                                    {
                                        std::cout << "\n==== RIGHT ROTATION 723 on " << Sibling->data << " ====" << std::endl;
                                        ret = Sibling->rightRotate(_root, Sibling);
                                        Sibling->setColor(RED);
                                        Sibling->parent->setColor(BLACK);
                                        Sibling = getSibling(TargetNode);
                                        // std::cout << "TargetNode: " << TargetNode->data << " - color = "  << TargetNode->getColor() << " - isLeftChild? " << TargetNode->isLeftChild() << " and Sibling: " << Sibling->data << " - color = " << Sibling->getColor() << " - isRightChild? " << Sibling->isRightChild() << " - RightNephew: " << getRightNephew(TargetNode)->data << " - isRed? " << getRightNephew(TargetNode)->isRed() << std::endl;
                                        if (TargetNode->isDBlack() && Sibling->isBlack() && TargetNode->isLeftChild() && Sibling->isRightChild() && getRightNephew(TargetNode)->isRed())
                                        {
                                            std::cout << "\n==== LEFT ROTATION 731 on " << TargetNode->parent->data << " ====" << std::endl;
                                            ret = TargetNode->parent->leftRotate(_root, TargetNode->parent);
                                            std::cout << "\n==== RECOLORING on " << TargetNode->data << " ====" << std::endl; 
                                            TargetNode->setColor(BLACK);
                                            TargetNode->parent->setColor(BLACK);
                                            getSibling(TargetNode->parent)->setColor(BLACK);
                                            TargetNode->parent->parent->setColor(RED);
                                            Parent_SubTree = Replacer->parent;
                                            removeParentLink(Replacer);
                                            delete Replacer;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                std::cout << "I am here: line 721" << std::endl;
                                Parent_SubTree = Replacer->parent;
                                removeParentLink(Replacer);
                                delete Replacer;
                            }
                            std::cout << "I am here: line 725" << std::endl;
                            if (Replacer->isDBlack() && Replacer->isRightChild() && getSibling(Replacer) && getSibling(Replacer)->isLeftChild() && getSibling(Replacer)->isRed())
                            {
                                std::cout << "\n==== RIGHT ROTATION 757 on " << Replacer->parent->data << " ====" << std::endl;
                                ret = Replacer->parent->rightRotate(_root, Replacer->parent);
                                std::cout << "\n==== RECOLORING on " << Replacer->parent->data << " ====" << std::endl; 
                                Replacer->parent->setColor(RED);
                                Replacer->parent->parent->setColor(BLACK);
                            }
                            else if (Replacer->isDBlack() && Replacer->isLeftChild() && getSibling(Replacer) && getSibling(Replacer)->isRightChild() && getSibling(Replacer)->isRed())
                            {
                                std::cout << "\n==== LEFT ROTATION 765 on " << Replacer->parent->data << " ====" << std::endl;
                                ret = Replacer->parent->leftRotate(_root, Replacer->parent);
                                std::cout << "\n==== RECOLORING on " << Replacer->parent->data << " ====" << std::endl; 
                                Replacer->parent->setColor(RED);
                                Replacer->parent->parent->setColor(BLACK);
                            }
                            std::cout << "Replacer: " << Replacer->data << " - " << Replacer->getColor() << std::endl;
                            if (Replacer->isDBlack() && Replacer->hasTwoBlackNephews())
                            {
                                std::cout << "\n==== PUSH BLACKNESS UP on " << Replacer->data << " level ====" << std::endl;
                                getSibling(Replacer)->pushBlacknessUp();
                                Parent_SubTree = Replacer->parent;
                                removeParentLink(Replacer);
                                delete Replacer;
                            }
                            else if (Replacer && Replacer->isBlack() && Replacer->data == 0)
                            {
                                Parent_SubTree = Replacer->parent;
                                removeParentLink(Replacer);
                                delete Replacer;
                            }

                            while (Parent_SubTree && Parent_SubTree != _root && !Parent_SubTree->isDBlack())
                                Parent_SubTree = Parent_SubTree->parent;
                            if (Parent_SubTree && Parent_SubTree != _root && Parent_SubTree->isDBlack() && getSibling(Parent_SubTree) && getSibling(Parent_SubTree)->isBlack() && Parent_SubTree->hasTwoBlackNephews())
                            {
                                std::cout << "\n==== PUSH BLACKNESS UP on " << Parent_SubTree->data << " level - line 783 ====" << std::endl;
                                Parent_SubTree->pushBlacknessUp();
                                _root->printNodeSubTree();
                            }
                        }
                        else if (TargetNode->hasNoRightChild())
                        {
                            TargetNode->parent->right = TargetNode->left;
                            TargetNode->left->parent = TargetNode->parent;
                            TargetNode->left->setColor(TargetNode->getColor());
                            removeParentLink(TargetNode);
                            delete TargetNode;
                        }
                    }
                    return (TargetNode ? TargetNode : NULL);
                }

                void printRBT()
                {
                    if (this->_root)
                    {
                        std::cout << std::endl << std::endl << std::endl;
                        std::cout << "============= ROOT ============\nParent = " << (_root->parent? _root->parent->getData() : 0)<< " - " << _root->getData() << " - " << _root->getValue() << " - " << (_root->getColor() == RED? "Red" : _root->getColor() == DOUBLE_BLACK? "Double Black": "Black") << std::endl;
                        if (_root->left)
                            _root->left->printNode('l', _root);
                        if (_root->right)
                            _root->right->printNode('r', _root);
                    }
                }
};

}


#endif