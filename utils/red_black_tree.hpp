/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:48:33 by abesombes         #+#    #+#             */
/*   Updated: 2022/03/01 19:22:16 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP
#define RED 0
#define BLACK 1
#define DOUBLE_BLACK 2
#include <iostream>
#include "less.hpp"
#include "node.hpp"

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

template <class Key, class T, class Compare = less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
class RBTree {
    
    public:          

                typedef Node<const Key, T, Compare, Alloc>	Node;
                typedef Key									key_type;
                typedef T									mapped_type;
                typedef ft::pair<const Key, T>				value_type;
                typedef std::size_t							size_type;
                
    private:
                Node*                               _root;
                Node*                               _nil;
                size_t                              _size;
                Compare                             _cmp;
                Alloc                               _valueAlloc;
                std::allocator<Node>                _nodeAlloc;
                
   
    public:
                

                /*
                ----------------------------------------------------------------------------------------------------
                RBTree - Default Constructor
                ----------------------------------------------------------------------------------------------------
                Constructs an empty red-black tree.
                */
               
                RBTree(): _root(NULL), _size(0), _cmp(Compare()), _valueAlloc(Alloc()) 
                {
                    _nodeAlloc = std::allocator<Node>(); // it builds the std::allocator for the type <Node> each time
                    initializeNil();
                    _root = _nil;
                }

                /*
                ----------------------------------------------------------------------------------------------------
                RBTree - Copy Constructor
                ----------------------------------------------------------------------------------------------------
                */

                RBTree(const RBTree &src)
                {
                    _root = src._root;
                    initializeNil();
                    _size = src._size;
                    _cmp = src._cmp;
                    _valueAlloc = src._valueAlloc;
                    _nodeAlloc = src._nodeAlloc;
                }

                ~RBTree(void) {
                    clear();
                    nodeDelete(_nil); // destruction of the last node > nil.
                    _nil = NULL;
                }

                void nodeDelete(Node *node)
                {
                    _valueAlloc.destroy(&node->value);
                    _nodeAlloc.deallocate(node, 1);
                }

                void loopDeleteNode(Node *node)
                {
                    if (!node->left->isNil())
                        loopDeleteNode(node->left);
                    if (!node->right->isNil())
                        loopDeleteNode(node->right);
                    nodeDelete(node);
                    _size--;
                }
                
                void clear(void)
                {
                    if (!_root->left->isNil())
                        loopDeleteNode(_root->left);
                    if (!_root->right->isNil())
                        loopDeleteNode(_root->right);
                    if (!_root->isNil())
                    {
                        nodeDelete(_root);
                        _size--;
                        _root = _nil;
                    }
                }
            
                Node* getRoot(){ return _root; }
                
                void setRoot(Node &node){ _root = node; }
                
                void swapNodeColor(Node &nodeA, Node &nodeB)
                {
                    int tmp_color = nodeA.color;
                    nodeA.setColor(nodeB->getColor);
                    nodeB.setColor(tmp_color);
                }

                void initializeNil(void)
                {
                    value_type  nilValue = ft::make_pair(Key(), T());
                    
                    _nil = newNode(nilValue);
                    _nil->color = BLACK;
                    _nil->parent = this->_nil;
                    _nil->left = this->_nil;
                    _nil->right = this->_nil;
                }

                Node* newNode(const value_type &value)
                {
                    Node *newNode = _nodeAlloc.allocate(1);
                    
                    _valueAlloc.construct(&newNode->value, value);
                    newNode->left = _nil;
                    newNode->right = _nil;
                    newNode->parent = _nil;
                    newNode->color = RED;
                    return newNode;
                }

                Node* BSTInsert(Node* root, Node* node)
                {
                    if (root->isNil())
                    {
                        node->setColor(BLACK);
                        return (node);
                    }
                    if (root->getKey() > node->getKey())
                    {
                        root->left = BSTInsert(root->left, node);
                        root->left->parent = root;
                    }
                    else if (root->getKey() < node->getKey())
                    {
                        root->right = BSTInsert(root->right, node);
                        root->right->parent = root;  
                    }
                    // if not root, insert by default as a RED leaf
                    node->setColor(RED);
                    return root;
                }

                void insertValue(const value_type &value)
                {
                    Node* new_Node = newNode(value);
                    // std::cout << "new_Node: " << new_Node->getColor() << std::endl;
                    this->_root = BSTInsert(this->_root, new_Node);
                    std::cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    std::cout << "+++++++++++++ ANNOUNCEMENT: NEW VALUE ADDED - " << value.first << " +++++++++++++" << std::endl;
                    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
                    // this->printRBT();
                    // _root = fixInsertion(this->_root, new_Node);
                    // std::cout << "_root: " << _root->getColor() << std::endl;
                    if (_root->getColor() == RED)
                        _root->setColor(BLACK);
                }

                Node* getMaxValueNode(Node *root)
                {
                    if(root == NULL)
                        return NULL;
                    else if (root->right==NULL)
                        return root;
                    else
                        return getMaxValueNode(root->right);
                }

                Node* getMinValueNode(Node* node)
                {
                    Node* current = node;
                
                    /* loop down to find the leftmost leaf */
                    while (current && current->left != NULL)
                        current = current->left;
                
                    return current;
                }

                Node* getGrandParent(Node* node)
                {
                    if (node && node->parent)
                        return (node->parent->parent);
                    else
                        return NULL;
                }
                
                Node* getIOSuccessor(Node* node)
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

                Node* getIOPredecessor(Node* node)
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

                Node* deleteNode(Node* node, Key key)
                {
                    if (!node)
                        return NULL;
                    std::cout << "\n==== NODE DELETE: " << key << " ====" << std::endl;
                    Node* TargetNode = searchNode(node, key);
                    Node* Parent = node->parent;
                    Node* Parent_SubTree = NULL;
                    Node* Sibling = NULL;
                    Node* ret = NULL;
                    if (TargetNode)
                    {
                        if (isLeaf(TargetNode) && TargetNode->getColor() == RED)
                        {
                            std::cout << "==== TargetNode is a Red Leaf ====" << std::endl;
                            removeParentLink(TargetNode);
                            delete TargetNode;
                        }
                        else if (isLeaf(TargetNode) && TargetNode->isBlack())
                        {
                            std::cout << "==== TargetNode is a Black Leaf ====" << std::endl;
                            TargetNode->data = Key();
                            TargetNode->value = T();
                            TargetNode->setColor(DOUBLE_BLACK);
                            std::cout << "TargetNode: " << TargetNode->data << std::endl;
                            std::cout << "Sibling: " << (getSibling(TargetNode)? getSibling(TargetNode)->data : -1) << std::endl;
                            std::cout << "TargetNode->hasBSibling()? " << TargetNode->hasBSibling() << std::endl;
                            std::cout << "TargetNode->isLeftChild()? " << TargetNode->isLeftChild() << std::endl;
                            std::cout << "TargetNode->hasRRNephew()? " << TargetNode->hasRRNephew() << std::endl;
                            if (TargetNode->isDBlack() && TargetNode->hasRSibling())
                            {
                                std::cout << "\n==== RIGHT ROTATION 702 on " << TargetNode->parent->data << " ====" << std::endl;
                                ret = TargetNode->parent->rightRotate(_root, TargetNode->parent);
                                if (ret)
                                    _root = ret;
                                TargetNode->parent->swapChildParentColors();
                                Node* TN = TargetNode;
                                if (TN && TN->isDBlack() && getSibling(TN) && getSibling(TN)->isBlack() && TN->hasTwoBlackNephews())
                                {
                                    std::cout << "\n==== PUSH BLACKNESS UP on " << TN->data << " level - line 710 ====" << std::endl;
                                    TN->pushBlacknessUp();
                                    TN = TN->parent;
                                }  
                                removeParentLink(TargetNode);
                                delete TargetNode;
                            }
                            else if (TargetNode->isDBlack() && TargetNode->hasBSibling() && TargetNode->hasTwoBlackNephews())
                            {
                                std::cout << "\n==== PUSH BLACKNESS UP on " << TargetNode->data << " level - line 745 ====" << std::endl;
                                TargetNode->pushBlacknessUp();
                                _root->printNodeSubTree();
                                Node* TN = TargetNode->parent;
                                if (TN && TN->isDBlack() && getSibling(TN) && getSibling(TN)->isBlack() && TN->hasTwoBlackNephews())
                                {
                                    std::cout << "\n==== PUSH BLACKNESS UP on " << TN->data << " level - line 751 ====" << std::endl;
                                    TN->pushBlacknessUp();
                                    TN = TN->parent;
                                }  
                                removeParentLink(TargetNode);
                                delete TargetNode; 
                            }
                            else if (getSibling(TargetNode) && getSibling(TargetNode)->isBlack() && TargetNode->isLeftChild() && TargetNode->isDBlack() && ((getRightNephew(TargetNode) && getRightNephew(TargetNode)->isBlack()) || !getRightNephew(TargetNode)))
                            {
                                std::cout << "\n==== RIGHT LEFT ROTATION 656 on " << TargetNode->parent->data << " ====" << std::endl;
                                ret = TargetNode->parent->rightleftRotate(_root, TargetNode->parent);
                                if (ret)
                                    _root = ret;
                                std::cout << "TargetNode->parent: " << TargetNode->parent->data << std::endl;
                                std::cout << "\n==== RECOLORING on " << TargetNode->parent->parent->data << " ====" << std::endl;
                                // Sibling = getSibling(TargetNode->parent);
                                // Sibling->setColor(RED);
                                TargetNode->parent->parent->setColor(BLACK);
                                removeParentLink(TargetNode);
                                delete TargetNode; 
                            }
                            else if (TargetNode->isDBlack() && TargetNode->hasBSibling() && TargetNode->isLeftChild() && TargetNode->hasRRNephew())
                            {
                                getSibling(TargetNode)->swapChildParentColors();
                                Node* FarNephew = TargetNode->getFarNephew();
                                std::cout << "\n==== LEFT ROTATION 672 on " << TargetNode->parent->data << " ====" << std::endl;
                                std::cout << "_root: " << _root->data << " Parent: " << (Parent? Parent->data : 0) << std::endl;
                                ret = TargetNode->parent->leftRotate(_root, TargetNode->parent);
                                if (ret)
                                    _root = ret;
                                // std::cout << "\n==== PUSH BLACKNESS DOWN on " << TargetNode->parent->data << " level - line 672 ====" << std::endl;
                                // TargetNode->parent->pushBlacknessDown(TargetNode->parent);
                                std::cout << "\n==== RECOLORING on " << TargetNode->parent->parent->right->data << " ====" << std::endl;
                                // if (TargetNode->parent->parent->right)
                                //     TargetNode->parent->parent->right->setColor(BLACK);
                                // if (TargetNode->parent->parent->left)
                                //     TargetNode->parent->parent->left->setColor(BLACK);
                                // TargetNode->parent->parent->setColor(RED);
                                // TargetNode->parent->right->right->setColor(BLACK); // does not work
                                FarNephew->setColor(BLACK);
                                removeParentLink(TargetNode);
                                delete TargetNode; 
                            }
                            else if (TargetNode->isDBlack() && TargetNode->hasBSibling() && TargetNode->isRightChild() && TargetNode->hasLBNephew())
                            {
                                std::cout << "\n==== LEFT RIGHT ROTATION 706 on " << TargetNode->parent->data << " ====" << std::endl;
                                ret = TargetNode->parent->leftrightRotate(_root, TargetNode->parent);
                                if (ret)
                                    _root = ret;
                                std::cout << "TargetNode->parent: " << TargetNode->parent->data << std::endl;
                                std::cout << "\n==== RECOLORING on " << TargetNode->parent->parent->data << " ====" << std::endl;
                                // node->pushBlacknessDown(TargetNode->parent);
                                Sibling = TargetNode->parent;
                                Sibling->setColor(BLACK);
                                //TargetNode->parent->parent->setColor(BLACK);
                                removeParentLink(TargetNode);
                                delete TargetNode; 
                            }
                            else if (TargetNode->isDBlack() && TargetNode->hasBSibling() && TargetNode->isRightChild() && TargetNode->hasLRNephew())
                            {
                                std::cout << "\n==== RIGHT ROTATION 726 on " << TargetNode->parent->data << " ====" << std::endl;
                                ret = TargetNode->parent->rightRotate(_root, TargetNode->parent);
                                if (ret)
                                    _root = ret;
                                std::cout << "TargetNode->parent: " << TargetNode->parent->data << std::endl;
                                std::cout << "\n==== RECOLORING on " << TargetNode->parent->parent->data << " ====" << std::endl;
                                Sibling = TargetNode->parent;
                                Sibling->setColor(BLACK);
                                Sibling->parent->setColor(RED);
                                getSibling(Sibling)->setColor(BLACK);
                                removeParentLink(TargetNode);
                                delete TargetNode; 
                            }
                        }
                        else if (TargetNode->hasLRChildren(TargetNode))
                        {
                            std::cout << "\n==== TargetNode has two children line 770 ====\n" << std::endl;
                            Node* Replacer = getMaxValueNode(TargetNode->left);
                            std::cout << "I am here 772: TargetNode = " << TargetNode->data << " - Replacer (Max Value of Left Subtree) = " << Replacer->data << std::endl;
                            TargetNode->data = Replacer->data;
                            TargetNode->value = Replacer->value;
                            if (TargetNode && Replacer->left)
                            {
                                TargetNode->left = Replacer->left;
                                Replacer->left->parent = TargetNode;
                            }
                            if (Replacer->isBlack() && Replacer->left)
                                Replacer->left->setColor(BLACK);
                            std::cout << "I am here 782: TargetNode = " << TargetNode->data << " - Replacer = " << Replacer->data << std::endl;
                            std::cout << "Sibling of former " << Replacer->data << " (now DOUBLE BLACK NULL LEAF): " << (getSibling(Replacer) ? getSibling(Replacer)->data : -1) << std::endl;
                            // std::cout << "replacer: " << Replacer->data << " - color: " << Replacer->color << " - parent: " << Replacer->parent->data << std::endl;
                            if (Replacer->isBlack())
                            {
                                std::cout << "I am here: line 787" << std::endl;
                                Replacer->data = Key();
                                Replacer->value = T();
                                Replacer->setColor(DOUBLE_BLACK);
                                Sibling = getSibling(Replacer);
                                if (Sibling && Sibling->isBlack() && Replacer->isRightChild() && Replacer->hasLBNephew())
                                {
                                    std::cout << "\n==== LEFT RIGHT ROTATION 723 on " << Replacer->parent->data << " ====" << std::endl;
                                    ret = Replacer->parent->leftrightRotate(_root, Replacer->parent);
                                    if (ret)
                                        _root = ret;
                                    Sibling->setColor(BLACK);
                                    Sibling->parent->setColor(BLACK);
                                    removeParentLink(Replacer);
                                    delete Replacer;
                                }
                                else if (Sibling && Sibling->isBlack() && Replacer->isLeftChild() && Replacer->hasRRNephew())
                                {
                                    std::cout << "\n==== LEFT ROTATION 788 on " << Replacer->parent->data << " ====" << std::endl;
                                    ret = Replacer->parent->leftRotate(_root, Replacer->parent);
                                    if (ret)
                                        _root = ret;
                                    std::cout << "REPLACERRRRRRR line 809: " << Replacer->data << std::endl;
                                    Replacer->pushBlacknessDown(Replacer);
                                    // Sibling->setColor(BLACK);
                                    // Sibling->parent->setColor(BLACK);
                                    // std::cout << "Sibling: " << Sibling->data << std::endl;
                                    // Sibling->right->setColor(BLACK);
                                    removeParentLink(Replacer);
                                    delete Replacer;
                                }
                                
                                while (getSibling(Replacer) && getSibling(Replacer)->isBlack() && Replacer->hasTwoBlackNephews())
                                {
                                    std::cout << "\n==== PUSH BLACKNESS UP on " << Replacer->data << " level - line 704 ====" << std::endl;
                                    Replacer->pushBlacknessUp();
                                    _root->printNodeSubTree();
                                    std::cout << "TargetNode: " << TargetNode->data << " - color = " << TargetNode->getColor() << std::endl;
                                    Sibling = getSibling(TargetNode);
                                    int flag_pushblackness_up = 0;
                                    std::cout << "TargetNode: " << TargetNode->data << " - getSibling(TargetNode): " << getSibling(TargetNode)->data << " - color = " << getSibling(TargetNode)->getColor() << std::endl;
                                    while (TargetNode->isDBlack() && TargetNode->hasBSibling() && TargetNode->hasTwoBlackNephews())
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
                                    if (TargetNode->isLeftChild() && Sibling->isBlack() && TargetNode->hasRBNephew())
                                    {
                                        std::cout << "\n==== RIGHT ROTATION 750 on " << Sibling->data << " ====" << std::endl;
                                        ret = Sibling->rightRotate(_root, Sibling);
                                        if (ret)
                                            _root = ret;
                                        Sibling->setColor(RED);
                                        Sibling->parent->setColor(BLACK);
                                        Sibling = getSibling(TargetNode);
                                        // std::cout << "TargetNode: " << TargetNode->data << " - color = "  << TargetNode->getColor() << " - isLeftChild? " << TargetNode->isLeftChild() << " and Sibling: " << Sibling->data << " - color = " << Sibling->getColor() << " - isRightChild? " << Sibling->isRightChild() << " - RightNephew: " << getRightNephew(TargetNode)->data << " - isRed? " << getRightNephew(TargetNode)->isRed() << std::endl;
                                        if (TargetNode->isDBlack() && Sibling->isBlack() && TargetNode->isLeftChild() && Sibling->isRightChild() && TargetNode->hasRRNephew())
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
                                    else if (TargetNode->isLeftChild() && Sibling->isBlack() && TargetNode->hasRRNephew())
                                    {
                                        std::cout << "\n==== LEFT ROTATION 849 on " << TargetNode->parent->data << " ====" << std::endl;
                                        ret = TargetNode->parent->leftRotate(_root, TargetNode->parent);
                                        if (ret)
                                            _root = ret;
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
                            else
                            {
                                std::cout << "I am here: line 721" << std::endl;
                                Parent_SubTree = Replacer->parent;
                                removeParentLink(Replacer);
                                delete Replacer;
                            }
                            
                            if (Replacer->isDBlack() && Replacer->isRightChild() && getSibling(Replacer) && getSibling(Replacer)->isLeftChild() && getSibling(Replacer)->isRed())
                            {
                                std::cout << "\n==== RIGHT ROTATION 757 on " << Replacer->parent->data << " ====" << std::endl;
                                ret = Replacer->parent->rightRotate(_root, Replacer->parent);
                                if (ret)
                                    _root = ret;
                                std::cout << "\n==== RECOLORING on " << Replacer->parent->data << " ====" << std::endl; 
                                Replacer->parent->setColor(RED);
                                Replacer->parent->parent->setColor(BLACK);
                            }
                            else if (Replacer->isDBlack() && Replacer->isLeftChild() && getSibling(Replacer) && getSibling(Replacer)->isRightChild() && getSibling(Replacer)->isRed())
                            {
                                std::cout << "\n==== LEFT ROTATION 765 on " << Replacer->parent->data << " ====" << std::endl;
                                ret = Replacer->parent->leftRotate(_root, Replacer->parent);
                                if (ret)
                                    _root = ret;
                                std::cout << "\n==== RECOLORING on " << Replacer->parent->data << " ====" << std::endl;
                                // Replacer->parent->swapChildParentColors();
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
                            else if (Replacer->isDBlack() && Replacer->isLeftChild() && Replacer->hasRRNephew())
                            {
                                std::cout << "\n==== LEFT 957 on " << Replacer->parent->data << " ====" << std::endl;
                                ret = Replacer->parent->leftRotate(_root, Replacer->parent);
                                if (ret)
                                    _root = ret;
                                Replacer->pushBlacknessDown(Replacer);
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
                    if (_root->isRed() || _root->isDBlack())
                        _root->setColor(BLACK);
                    return (TargetNode ? TargetNode : NULL);
                }

                void printRBT()
                {
                    if (this->_root)
                    {
                        std::cout << std::endl << std::endl << std::endl;
                        std::cout << "============= ROOT ============\nParent = " << (_root->parent? _root->parent->getKey() : 0)<< " - " << _root->getKey() << " - " << _root->getMapped() << " - " << (_root->getColor() == RED? "Red" : _root->getColor() == DOUBLE_BLACK? "Double Black": "Black") << std::endl;
                        if (!_root->left->isNil())
                            _root->left->printNode('l', _root);
                        if (!_root->right->isNil())
                            _root->right->printNode('r', _root);
                    }
                }
};

};


#endif