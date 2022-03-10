/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:48:33 by abesombes         #+#    #+#             */
/*   Updated: 2022/03/10 01:05:00 by abesombes        ###   ########.fr       */
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
                    deleteNode(_nil);
                    _nil = NULL;
                }

                void deleteNode(Node *node)
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
                    deleteNode(node);
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
                        deleteNode(_root);
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
                    if (!_cmp(root->getKey(), node->getKey()))
                    {
                        root->left = BSTInsert(root->left, node);
                        root->left->parent = root;
                    }
                    else if (_cmp(root->getKey(), node->getKey()))
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
                    _root = fixInsertion(this->_root, new_Node);
                    // std::cout << "_root: " << _root->getColor() << std::endl;
                    if (_root->getColor() == RED)
                        _root->setColor(BLACK);
                }

                Node* getMaxValueNode(Node *root)
                {
                    if(root->isNil())
                        return _nil;
                    else if (root->right->isNil())
                        return root;
                    else
                        return getMaxValueNode(root->right);
                }

                Node* getMinValueNode(Node* root)
                {
                    Node* current = root;
                
                    /* loop down to find the leftmost leaf */
                    while (current && current->left != NULL)
                        current = current->left;
                
                    return current;
                }

                // Node* getGrandParent(Node* node)
                // {
                //     if (node && node->parent)
                //         return (node->parent->parent);
                //     else
                //         return _nil;
                // }

                /* -------------------- PushBlackness Functions ---------------------- */

                void pushBlacknessDown(Node* node)
                {
                    Node* Parent = node->parent;
                    Node* GrandParent = node->getGrandParent();
                    Node* Uncle = node->getUncle();
                    std::cout << "\n==== PUSH THE BLACKNESS DOWN FROM GP ====" << std::endl;
                    if (GrandParent->getColor() == BLACK)
                    {
                        Uncle->setColor(BLACK);
                        Parent->setColor(BLACK);
                        GrandParent->setColor(RED);
                    }
                }
                
                void pushBlacknessUp(Node* node)
                {
                    Node* Parent = node->parent;
                    Node* Sibling = node->getSibling();
                    std::cout << "\n==== PUSH THE BLACKNESS UP: " << node->getKey() << " - " << Parent->getKey() << " - " << Sibling->getKey() << " ====" << std::endl;
                    node->setColor(std::max(node->getColor() - 1, 0));
                    if (Parent)
                        Parent->setColor(Parent->getColor() + 1);
                    if (Sibling)
                        Sibling->setColor(std::max(Sibling->getColor() - 1, 0));                
                }

                /* -------------------- Link 2 Nodes --------------------------------------- */           

                void link(Node *nodeParent, Node* nodeChild, int side)
                {
                    if (nodeParent != nodeChild)
                    {
                        if (side == 1)
                            nodeParent->left = nodeChild;
                        else if (side == 2)
                            nodeParent->right = nodeChild;
                        if (!nodeChild->isNil())
                            nodeChild->parent = nodeParent;
                    }
               }


                /* -------------------- Node Rotations --------------------------------------- */

                // leftRotate = 1, rightRotate = 2 , leftrightRotate = 3, rightleftRotate = 4

                Node* rotate(Node *root, Node* node, int r)
                {
                    Node* Seed = &(*node->parent); // Seed is the node above the considered trio of nodes
                    int flag_lr = (node->isLeftRightChild() ? 1 : 0);
                    Node* Head = &(*node); // GrandParent in the chain of 3 nodes
                    Node* RChild = &(*node->right);
                    Node* LChild = &(*node->left);
                    Node* RLChild = &(*node->right->left);
                    Node* LRChild = &(*node->left->right);
                    Node* RLRChild = &(*node->right->left->right);
                    Node* RLLChild = &(*node->right->left->left);
                    Node* LRRChild = &(*node->left->right->right);
                    Node* LRLChild = &(*node->left->right->left);                    
                    int flag_root = (node == root? 1 : 0);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
                    node = (r == 1 ? RChild : (r == 2 ? LChild : (r == 3 ? LRChild : (r == 4 ? RLChild : node))));
                    
                    if (flag_lr && !flag_root)
                        Seed->right = node;
                    else if (!flag_root)
                        Seed->left = node;                        
                    if (!Seed->isNil())
                        node->parent = Seed;
                    link(node, Head, (r == 1 || r == 4 ? 1: 2));
                    if (r == 3)
                        link(node, LChild, 1);
                    if (r == 4)
                        link(node, RChild, 2);
                    if (r == 1)
                        link(node->left, RLChild, 2);
                    if (r == 2)
                        link(node->right, LRChild, 1);
                    if (r == 3)
                    {
                        link(node->left, LRLChild, 2);
                        link(node->right, LRRChild, 1);  
                    }
                    if (r == 4)
                    {
                        link(node->left, RLLChild, 2);
                        link(node->right, RLRChild, 1);  
                    }                 
                    if (flag_root)
                        node->parent = _nil;
                    return (flag_root? node: NULL);
                }

                
                
            /* ----------------------------------------------------------- */

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

                void removeParentLink(Node* node)
                {
                    Node* Parent = node->parent;          
                    if (!Parent->isNil() && Parent->left == node)
                        Parent->left = _nil;
                    else if (!Parent->isNil() && Parent->right == node)
                        Parent->right = _nil;
                }

                // FIXING INSERTION PROBLEMS IN REGARD TO RBT RULES
                // if RED leaf's parent is BLACK, then no problem, we should already comply to RBT standards.
                // if RED leat's parent is RED, then we check parent's sibling (called uncle). If uncle is RED as well
                // then we change parent and uncle's colors to BLACK.
                // 0 LeftRight Case, 1 RightLeft Case, 2 LeftLeft Case, 3 RightRight Case

                Node* fixInsertion(Node* root, Node* node)
                {

                    Node* Parent = node->parent;
                    Node* Uncle = node->getUncle();
                    Node* ret = NULL;
                    root->printNodeSubTree();
                    std::cout << "\nTrying to fix node " << node->getKey() << std::endl;
                    if (!node->parent->isNil())
                    {
                        std::cout << "Node Shape: " << node->isLeftRightCase() << std::endl;
                        std::cout << "0 = LeftRight Case\n1 = RightLeft Case\n2 = LeftLeft Case\n3 = RightRight Case" << std::endl;
                        // root->printNodeSubTree();
                        std::cout << "Uncle: " << Uncle->isRed() << std::endl;
                        if (node->doubleRed() && Uncle != node && Uncle->isRed())
                        {            
                            pushBlacknessDown(node);
                            ret = fixInsertion(root, node->parent->parent);
                        }
                        else if (node->doubleRed() && node->isLeftRightCase() == 0)
                        {
                            std::cout << "\n==== LEFT RIGHT ROTATION 292 on " << Parent->parent->getKey() << " ====" << std::endl;
                            ret = rotate(root, Parent->parent, 3);
                            std::cout << "\n==== RECOLORING on " << node->getKey() << " ====" << std::endl;
                            node->setColor(BLACK);
                            node->right->setColor(RED);
                        }   
                        else if (node->doubleRed() && node->isLeftRightCase() == 1)
                        {
                            std::cout << "\n==== RIGHT LEFT ROTATION 300 on " << Parent->parent->getKey() << " ====" << std::endl;
                            ret = rotate(root, Parent->parent, 4);
                            std::cout << "\n==== RECOLORING on " << node->getKey() << " ====" << std::endl;    
                            node->setColor(BLACK);
                            node->left->setColor(RED);  
                        }
                        else if (node->doubleRed() && node->isLeftRightCase() == 2)
                        {
                            std::cout << "\n==== RIGHT ROTATION 308 on " << Parent->parent->getKey() << " ====" << std::endl;
                            ret = rotate(root, Parent->parent, 2);
                            std::cout << "\n==== RECOLORING on " << node->getKey() << " ====" << std::endl;    
                            node->parent->setColor(BLACK);
                            node->parent->right->setColor(RED);  
                        }
                        else if (node->doubleRed() && node->isLeftRightCase() == 3)
                        {
                            std::cout << "\n==== LEFT ROTATION 316 on " << Parent->parent->getKey() << " ====" << std::endl;
                            // ret = leftRotate(root, Parent->parent);
                            ret = rotate(root, Parent->parent, 1);
                            std::cout << "\n==== RECOLORING on " << node->getKey() << " ====" << std::endl; 
                            node->parent->setColor(BLACK);
                            node->parent->left->setColor(RED);
                        }
                        if (ret)
                        {
                            std::cout<<"Root updated" << std::endl;
                            root = ret;
                        }
                        root->printNodeSubTree();
                    }
                    std::cout << "current node: " << node->getKey() << std::endl;
                    std::cout << "parent node: " << node->parent->getKey() << std::endl;
                    std::cout << "GP node: " << node->parent->parent->getKey() << std::endl;
                    if (!node->parent->isNil() && !node->parent->parent->isNil() && node->parent->parent != root && node->parent->parent->doubleRed() == 1)
                    {
                        std::cout << "ALERT : DOUBLE RED AFTER FIX REQUIRES ANOTHER FIX" << std::endl;
                        ret = fixInsertion(root, node->parent->parent);
                        if (ret)
                            root = ret;
                        std::cout << "SPECIAL MESSAGE ==== node: " << node->getKey() << " - node->parent: " << node->parent->getKey() << std::endl;  
                    }
                    return (root);
                }

                Node* searchNode(Node* node, Key key)
                {
                    if (node->isNil() || key == node->getKey())
                        return node;
                    if (_cmp(node->getKey(), key))
                        return (searchNode(node->right, key));
                    else
                        return (searchNode(node->left, key));
                }

                void fixDB(Node *TN)
                {
                    Node* ret = NULL;
                    std::cout << "TN: " << TN->getKey() << " - color: " << TN->getColor() << " - TN->parent: " << TN->parent->getKey() << " - LNephew: " << TN->parent->right->left->getKey()<< " - RNephew: " << TN->parent->right->right->getKey() << " - Sibling manuel: " << TN->parent->right->getKey() << " - color = " << TN->parent->right->getColor() << " - hasBSibling? " << TN->hasBSibling() << " - hasBNephews? " << TN->hasBNephews() << std::endl;
                    if (!TN->isNil() && TN->isDBlack())
                    {
                        if (TN->hasBSibling())
                        {
                            if (TN->hasBNephews())
                            {
                                std::cout << "\n==== PUSH BLACKNESS UP 467 on " << TN->getKey() << " level - line 751 ====" << std::endl;
                                pushBlacknessUp(TN);
                            }
                            else if (TN->isLChild() && TN->hasRBNephew())
                            {
                                std::cout << "\n==== RIGHT LEFT ROTATION 475 on " << TN->parent->getKey() << " ====" << std::endl;
                                ret = rotate(_root, TN->parent, 4);
                                std::cout << "TN: " << TN->getKey() << " - TN->parent: " << TN->parent->getKey() << " - color = " << TN->parent->getColor() << " - TN->parent->parent: " << TN->parent->parent->getKey() << " - color = " << TN->parent->parent->getColor() << std::endl;
                                if (TN->parent->isRed() && TN->parent->parent->isRed() && TN->getUncle()->isBlack())
                                {
                                    TN->parent->setColor(BLACK);
                                    TN->parent->parent->setColor(RED);
                                    TN->getUncle()->setColor(BLACK);
                                    TN->setColor(BLACK);
                                }
                                else
                                {
                                    TN->setColor(BLACK);
                                    TN->parent->parent->setColor(BLACK);
                                    TN->getUncle()->setColor(BLACK);
                                }
                                if (ret)
                                    _root = ret;
                            }
                            else if (TN->isLChild() && TN->hasRRNephew())
                            {
                                std::cout << "\n==== LEFT ROTATION 496 on " << TN->parent->getKey() << " ====" << std::endl;
                                ret = rotate(_root, TN->parent, 1);
                                std::cout << "TN: " << TN->getKey() << " - TN->parent: " << TN->parent->getKey() << std::endl;
                                TN->setColor(BLACK);
                                if (TN->parent->isRed() && TN->parent->parent->isBlack() && TN->getUncle()->isRed())
                                {
                                    TN->parent->setColor(BLACK);
                                    TN->parent->parent->setColor(RED);
                                    TN->getUncle()->setColor(BLACK);
                                }
                                else if (TN->parent->isBlack() && TN->parent->parent->isBlack())
                                    TN->getUncle()->setColor(BLACK);
                                if (ret)
                                    _root = ret;
                            }
                            else if (TN->isRChild() && TN->hasLBNephew())
                            {
                                if (TN->parent->isBlack())
                                    TN->getRNephew()->setColor(BLACK);
                                std::cout << "\n==== LEFT RIGHT ROTATION 481 on " << TN->parent->getKey() << " ====" << std::endl;
                                ret = rotate(_root, TN->parent, 3);
                                TN->setColor(BLACK);
                                TN->parent->setColor(BLACK);
                                TN->getUncle()->setColor(BLACK);

                                std::cout << "TN->parent->parent: " << TN->parent->parent->getKey() << "color = " << TN->parent->parent->getColor() << "\n";
                                if (ret)
                                    _root = ret;
                                // std::cout << "\n==== LEFT ROTATION 521 on " << TN->parent->getKey() << " ====" << std::endl;
                                // ret = rotate(_root, TN->parent, 1);
                                // std::cout << "TN: " << TN->getKey() << " - TN->parent: " << TN->parent->getKey() << std::endl;
                                // TN->setColor(BLACK);
                                // if (TN->parent->isRed() && TN->parent->parent->isBlack() && TN->getUncle()->isRed())
                                // {
                                //     TN->parent->setColor(BLACK);
                                //     TN->parent->parent->setColor(RED);
                                //     TN->getUncle()->setColor(BLACK);
                                // }
                                // else if (TN->parent->isBlack() && TN->parent->parent->isBlack())
                                //     TN->getUncle()->setColor(BLACK);
                                // if (ret)
                                //     _root = ret;
                                // fixDB(TN);
                            }
                            else if (TN->isRChild() && TN->hasLRNephew())
                            {
                                std::cout << "\n==== RIGHT ROTATION 494 on " << TN->parent->getKey() << " ====" << std::endl;
                                ret = rotate(_root, TN->parent, 2);

                                if (TN->parent->isRed() && TN->parent->parent->isBlack() && TN->getUncle()->isRed())
                                {
                                    TN->parent->parent->setColor(RED);
                                    TN->parent->setColor(BLACK);
                                    TN->getUncle()->setColor(BLACK);
                                }
                                else if (TN->parent->isBlack() && TN->parent->parent->isBlack())
                                {
                                    TN->getUncle()->setColor(BLACK);
                                    TN->setColor(BLACK);
                                }
                                std::cout << "TN: " << TN->getKey() << " - Color = " << TN->getColor() << " - TN->parent: " << TN->parent->getKey() << " - Color = " << TN->parent->getColor() << std::endl;
                                if (ret)
                                    _root = ret;
                            }
                            fixDB(TN->parent);
                        }
                        else if (TN->hasRSibling())
                        {
                            // std::cout << "\n==== LEFT RIGHT ROTATION 532 on " << TN->parent->getKey() << " ====" << std::endl;
                            // ret = rotate(_root, TN->parent, 3);
                            // std::cout << "TN: " << TN->getKey() << std::endl;
                            // if (TN->parent->isRed() && TN->getUncle()->isRed() && TN->parent->parent->isBlack())
                            // {
                            //     TN->parent->parent->setColor(RED);
                            //     TN->parent->setColor(BLACK);
                            //     TN->getUncle()->setColor(BLACK);
                            // }
                            // if (ret)
                            //     _root = ret;
                            if (TN->isLChild())
                            {
                                std::cout << "\n==== LEFT ROTATION 508 on " << TN->parent->getKey() << " ====" << std::endl;
                                ret = rotate(_root, TN->parent, 1);
                                std::cout << "TN: " << TN->getKey() << std::endl;
                                if (TN->isDBlack() && TN->parent->isBlack() && TN->parent->parent->isRed())
                                {
                                    TN->parent->setColor(RED);
                                    TN->parent->parent->setColor(BLACK);
                                }
                                else
                                {
                                    TN->getSibling()->setColor(RED);
                                    TN->parent->parent->setColor(BLACK);
                                }
                            }
                            else if (TN->isRChild())
                            {
                                std::cout << "\n==== RIGHT ROTATION 571 on " << TN->parent->getKey() << " ====" << std::endl;
                                if (TN->getSibling()->isRed())
                                {
                                    TN->parent->setColor(RED);
                                    TN->getSibling()->setColor(BLACK);
                                }
                                ret = rotate(_root, TN->parent, 2);

                                if (TN->parent->isRed() && TN->parent->parent->isBlack() && TN->getUncle()->isRed())
                                {
                                    TN->parent->parent->setColor(RED);
                                    TN->parent->setColor(BLACK);
                                    TN->getUncle()->setColor(BLACK);
                                }
                                else if (TN->parent->isBlack() && TN->parent->parent->isBlack())
                                    TN->getUncle()->setColor(BLACK);
                                else if (TN->parent->isBlack() && TN->parent->parent->isRed())
                                {
                                    TN->parent->setColor(RED);
                                }
                            }
                            if (ret)
                                _root = ret;
                            fixDB(TN);
                        }
                    }
                }

                Node* removeNode(Node* node, Key key)
                {
                    std::cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
                    std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
                    std::cout << " !!!!!! KEY OF THE NODE TO REMOVE: " << key << " !!!!!!!!" << std::endl;
                    std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
                    std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
                    Node* TargetNode = searchNode(node, key);
                    std::cout << "Node Color : " << TargetNode->getColor() << std::endl;
                    std::cout << "Leaf? " << TargetNode->isLeaf() << std::endl;
                    Node* Parent = TargetNode->parent;
                    // Node* Parent_SubTree = NULL;
                    Node* Sibling = NULL;
                    Node* ret = NULL;
                    if (!TargetNode->isNil())
                    {
                        if (TargetNode->isRedLeaf())
                        {
                            std::cout << "==== TargetNode is a Red Leaf ====" << std::endl;
                            removeParentLink(TargetNode);
                            deleteNode(TargetNode);
                        }
                        else if (TargetNode->isBlackLeaf())
                        {
                            std::cout << "==== TargetNode is a Black Leaf ====" << std::endl;
                            if (TargetNode == _root)
                            {
                                _root = _nil;
                                removeParentLink(TargetNode);
                                deleteNode(TargetNode);
                            }
                            else
                            {
                                TargetNode->setColor(DOUBLE_BLACK);
                                std::cout << "Creation du NULL LEAF DOUBLE BLACK 603" << std::endl;
                                std::cout << "TargetNode: " << TargetNode->getKey() << std::endl;
                                if (TargetNode->hasRSibling())
                                {
                                    std::cout << "==== TargetNode has a Red Sibling ====" << std::endl;
                                    // TargetNode->setColor(DOUBLE_BLACK);
                                    // std::cout << "Creation du NULL LEAF DOUBLE BLACK 609" << std::endl;
                                    fixDB(TargetNode);
                                    removeParentLink(TargetNode);
                                    deleteNode(TargetNode);
                                }
                                else if (TargetNode->hasBSibling())
                                {
                                    if (TargetNode->isRChild())
                                    {
                                        if (TargetNode->hasBNephews())
                                        {
                                            std::cout << "==== Right Child TargetNode has 2 Black Nephews ====" << std::endl;
                                            std::cout << "\n==== PUSH BLACKNESS UP on " << TargetNode->getKey() << " level - line 745 ====" << std::endl;
                                            pushBlacknessUp(TargetNode);
                                            _root->printNodeSubTree();
                                            fixDB(TargetNode->parent);
                                        }
                                        else if (TargetNode->hasLBNephew())
                                        {
                                            std::cout << "==== TargetNode has a left Black Nephew ====" << std::endl;
                                            std::cout << "\n==== LEFT RIGHT ROTATION 706 on " << TargetNode->parent->getKey() << " ====" << std::endl;
                                            std::cout << "RNephew: " << TargetNode->getRNephew()->getKey() << " - color = " << TargetNode->getRNephew()->getColor() << " - has RRNephew? " << TargetNode->hasRRNephew() << "\n";
                                            if (TargetNode->hasRRNephew())
                                                TargetNode->getRNephew()->setColor(BLACK);  
                                            ret = rotate(_root, TargetNode->parent, 3);
                                            if (ret)
                                                _root = ret;
                                            std::cout << "TargetNode->parent: " << TargetNode->parent->getKey() << std::endl;
                                            std::cout << "\n==== RECOLORING on " << TargetNode->parent->parent->getKey() << " ====" << std::endl;
                                            Sibling = TargetNode->parent;
                                            Sibling->setColor(BLACK);
                                        }
                                        else if (TargetNode->hasLRNephew())
                                        {
                                            std::cout << "==== TargetNode has a left Red Nephew ====" << std::endl;
                                            std::cout << "\n==== RIGHT ROTATION 599 on " << TargetNode->parent->getKey() << " ====" << std::endl;
                                            if (TargetNode->parent->isRed())
                                                TargetNode->parent->setColor(BLACK);
                                            if (TargetNode->getSibling()->isBlack())
                                                TargetNode->getSibling()->setColor(RED);
                                            ret = rotate(_root, TargetNode->parent, 2);
                                            if (ret)
                                                _root = ret;
                                            std::cout << "TargetNode->parent: " << TargetNode->parent->getKey() << std::endl;
                                            std::cout << "\n==== RECOLORING on " << TargetNode->parent->parent->getKey() << " ====" << std::endl;
                                            // Sibling = TargetNode->parent;
                                            // Sibling->setColor(BLACK);
                                            
                                            TargetNode->getUncle()->setColor(BLACK);
                                            //TargetNode->parent->parent->setColor(RED);
                                            TargetNode->setColor(BLACK);
                                        }
                                        removeParentLink(TargetNode);
                                        deleteNode(TargetNode);
                                    }
                                    else if (TargetNode->isLChild())
                                    {
                                        if (TargetNode->hasBNephews())
                                        {
                                            std::cout << "==== Left Child TargetNode has 2 Black Nephews ====" << std::endl;
                                            std::cout << "\n==== PUSH BLACKNESS2 UP on " << TargetNode->getKey() << " level - line 745 ====" << std::endl;
                                            pushBlacknessUp(TargetNode);
                                            _root->printNodeSubTree();
                                            fixDB(TargetNode->parent);
                                            removeParentLink(TargetNode);
                                            deleteNode(TargetNode);
                                        }
                                        else if (TargetNode->hasRRNephew())
                                        {
                                            std::cout << "==== Left Child TargetNode has a Red Right Nephew ====" << std::endl;
                                            TargetNode->getSibling()->swapChildParentColors();
                                            Node* FarNephew = TargetNode->getFarNephew();
                                            std::cout << "\n==== LEFT ROTATION 672 on " << TargetNode->parent->getKey() << " ====" << std::endl;
                                            std::cout << "_root: " << _root->getKey() << " Parent: " << (Parent? Parent->getKey() : 0) << std::endl;
                                            ret = rotate(_root, TargetNode->parent, 1);
                                            if (ret)
                                                _root = ret;
                                            std::cout << "\n==== RECOLORING on " << TargetNode->parent->parent->right->getKey() << " ====" << std::endl;
                                            FarNephew->setColor(BLACK);
                                            removeParentLink(TargetNode);
                                            deleteNode(TargetNode);
                                        }
                                        else if (TargetNode->hasRBNephew())
                                        {
                                            std::cout << "==== Left Child TargetNode has a Black Right Nephew ====" << std::endl;
                                            TargetNode->getSibling()->swapChildParentColors();
                                            Node* FarNephew = TargetNode->getFarNephew();
                                            std::cout << "\n==== RIGHT LEFT ROTATION 581 on " << TargetNode->parent->getKey() << " ====" << std::endl;
                                            std::cout << "_root: " << _root->getKey() << " Parent: " << (Parent? Parent->getKey() : 0) << std::endl;
                                            ret = rotate(_root, TargetNode->parent, 4);
                                            if (ret)
                                                _root = ret;
                                            std::cout << "\n==== RECOLORING on " << TargetNode->parent->parent->right->getKey() << " ====" << std::endl;
                                            TargetNode->parent->parent->right->setColor(BLACK);
                                            FarNephew->setColor(BLACK);
                                            removeParentLink(TargetNode);
                                            deleteNode(TargetNode);
                                        }
                                    }
                                }
                            }
                        }
                        else if (TargetNode->hasChildren())
                        {
                            std::cout << "\n==== TargetNode has 2 Children ====\n" << std::endl;
                            Node* Replacer = getMaxValueNode(TargetNode->left); // warning: 2 cases - Replacer is Red or Black - if Replacer is Black, we replace it by a DBlack
                            std::cout << "I am here 584: TargetNode = " << TargetNode->getKey() << " - Replacer (Max Value of Left Subtree) = " << Replacer->getKey() << std::endl;
                            int tn_side = TargetNode->isLeftRightChild();
                            int rp_side = Replacer->isLeftRightChild();
                            int save_tn_color = TargetNode->getColor(); //??? TO BE RECHECKED
                            int save_rp_color = Replacer->getColor();
                            Node* Replacer_Parent = Replacer->parent;
                            Node* Replacer_Left = Replacer->left;
                            int check_RP_equal_TN = (Replacer_Parent == TargetNode);
                            if (TargetNode != _root)
                            {
                                link(Parent, Replacer, tn_side + 1); // replugging the Replacer to the seed Parent (higher plug)
                                Replacer->setColor(save_tn_color);
                                link(Replacer, TargetNode->right, 2); // lower right plug
                                // link(Replacer, Replacer_Parent, 1); // lower left plug???
                                link(Replacer, TargetNode->left, 1);
                            }
                            else 
                            {
                                _root = Replacer;
                                Replacer->parent = _nil;
                                link(Replacer, TargetNode->right, 2); // lower right plug
                                link(Replacer, TargetNode->left, 1); // lower left plug???
                            }
                            // TargetNode is replaced by Replacer and Replacer is replaced by TargetNode in the tree (position swap)
                            std::cout << "save_rp_color: " << save_rp_color << std::endl;
                            // if the Replacer has a left Child, it is important to replug this left Child to Replacer Parent
                            std::cout << "Replacer_Parent: " << Replacer_Parent->getKey() << " - Replacer_Left: " << Replacer_Left->getKey() << std::endl;
                            if (!Replacer_Left->isNil() && !Replacer_Parent->isNil())
                            {
                                std::cout << "Coming here 677" << std::endl;
                                if (!check_RP_equal_TN)
                                    link(Replacer_Parent, Replacer_Left, rp_side + 1);
                                else
                                    link(Replacer, Replacer_Left, rp_side + 1);
                                Replacer_Left->setColor(BLACK);
                            }
                            else
                            {
                                if (save_rp_color == BLACK)
                                {
                                    // 2 cases here: either the Replacer has a Child or no. If yes, we add +1 to the color of this Child (thus maybe creating a DB)
                                    if (Replacer_Parent != TargetNode)
                                        link(Replacer_Parent, TargetNode, rp_side + 1);
                                    else
                                        link(Replacer, TargetNode, rp_side + 1);
                                    TargetNode->setColor(DOUBLE_BLACK);
                                    std::cout << "Creation du NULL LEAF DOUBLE BLACK" << std::endl;
                                    fixDB(TargetNode);
                                }
                                else if (save_rp_color == RED)
                                    link(Replacer_Parent, TargetNode, 2);
                            }
                            removeParentLink(TargetNode);
                            deleteNode(TargetNode);
                        }
                        else if (TargetNode->hasNoRChild())
                        {
                            std::cout << "==== TargetNode " << TargetNode->getKey() << " has No Right Child ====" << std::endl;
                            if (TargetNode == _root)
                            {
                                _root = TargetNode->left;
                                _root->parent = _nil;
                            }
                            else
                            {
                                link(TargetNode->parent, TargetNode->left, TargetNode->isRChild() + 1);
                                TargetNode->left->setColor(TargetNode->getColor());
                            }
                            removeParentLink(TargetNode);
                            deleteNode(TargetNode);
                        }
                        else if (TargetNode->hasNoLChild())
                        {
                            std::cout << "==== TargetNode " << TargetNode->getKey() << " has No Left Child ====" << std::endl;
                            if (TargetNode == _root)
                            {
                                _root = TargetNode->right;
                                _root->parent = _nil;
                            }
                            else
                            {
                                link(TargetNode->parent, TargetNode->right, TargetNode->isRChild() + 1);
                                TargetNode->right->setColor(TargetNode->getColor());
                            }
                            removeParentLink(TargetNode);
                            deleteNode(TargetNode);
                        }
                    }
                    if (!_root->isBlack())
                        _root->setColor(BLACK);
                    printRBT();
                    return TargetNode;
                    // return (!TargetNode->isNil() ? TargetNode : _nil);
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