/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:48:33 by abesombes         #+#    #+#             */
/*   Updated: 2022/03/28 11:41:02 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP
#define RED 0
#define BLACK 1
#define DOUBLE_BLACK 2
#define SENTINEL 3
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

                typedef Node<const Key, T, Compare, Alloc>	                            Node;
                typedef Key									                            key_type;
                typedef T									                            mapped_type;
                typedef ft::pair<const Key, T>				                            value_type;
                typedef std::size_t							                            size_type;
                typedef typename Alloc::template rebind<Node>::other 			        node_allocator;
                
    private:
                Node*                               _root;
                Node*                               _nil;
                Node*                               _sentinel;
                size_t                              _size;
                Compare                             _cmp;
                Alloc                               _valueAlloc;
                node_allocator                      _nodeAlloc;
                
   
    public:
                

                /*
                ----------------------------------------------------------------------------------------------------
                RBTree - Default Constructor
                ----------------------------------------------------------------------------------------------------
                Constructs an empty red-black tree.
                */
               
                RBTree(): _root(NULL), _size(0), _cmp(Compare()), _valueAlloc(Alloc()) 
                {
                    _nodeAlloc = node_allocator(); 
                    initializeNil();
                    initializeSentinel();
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
                    _nil = src._nil;
                    _sentinel = src._sentinel;
                    _size = src._size;
                    _cmp = src._cmp;
                    _valueAlloc = src._valueAlloc;
                    _nodeAlloc = src._nodeAlloc;
                }

                ~RBTree(void) {}

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
                    if (node)
                    {
                        deleteNode(node);
                        node = NULL;
                        _size--;
                    }
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
                    _sentinel->left = _sentinel;
                    _sentinel->right = _sentinel;
                }
            
                Node* getRoot() const { return _root; }
        
                Node* getNil() const { return _nil; }
                
                Node* getSentinel() const { return _sentinel; }

                size_t getSize() const { return _size; }
                
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
                
                void initializeSentinel(void)
                {
                    value_type  nilValue = ft::make_pair(Key(), T());
                    
                    _sentinel = newNode(nilValue);
                    _sentinel->color = SENTINEL;
                    _sentinel->parent = _sentinel;
                    _sentinel->left = _sentinel;
                    _sentinel->right = _sentinel;
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


                Node* BSTInsert(Node* node, bool &successful_insertion)
                {
                    Node *tmp = _root;
                    Node *Parent = _root;
                    int lrflag = 0;
                    if (_size == 0)
                    {
                        _sentinel->left = node;
                        node->left = _sentinel;
                        _sentinel->right = node;
                        node->right = _sentinel; 
                        _size++;
                        node->setBlack();
                        successful_insertion = true;
                        _root = node;
                    }
                    else
                    {
                        while (!tmp->isNil())
                        {
                            Parent = tmp;
                            
                            if (_cmp(node->getKey(), tmp->getKey()))
                            {
                                tmp = tmp->left;
                                lrflag = 1;
                            }
                            else if (_cmp(tmp->getKey(), node->getKey()))
                            {
                                tmp = tmp->right;
                                lrflag = 2;
                            }
                            else
                                return (tmp);
                        }
                        if (tmp->isNil())
                        {
                            node->setRed();
                            _size++;
                            link(Parent, node, lrflag);
                            successful_insertion = true;
                            if (_cmp(node->getValue().first, _sentinel->left->getValue().first))
                            {
                                _sentinel->left = node;
                                node->left = _sentinel;
                            }
                            else if (_cmp(_sentinel->right->getValue().first, node->getValue().first))
                            {
                                _sentinel->right = node;
                                node->right = _sentinel; 
                            }
                        }
                    }
                    return (tmp);
                }

                Node* insertValue(const value_type &value, bool &wasInserted)
                {
                    Node* new_Node = newNode(value);
                    Node *ret = BSTInsert(new_Node, wasInserted);
 
                    if (_size > 1)
                        _root = fixInsertion(this->_root, new_Node);
                    if (_root->isRed())
                        _root->setBlack();
                    if (!wasInserted)
                    {
                        deleteNode(new_Node);
                        return (ret);
                    }
                    return (new_Node);
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
                
                    while (current && !current->left->isNil())
                        current = current->left;
                
                    return current;
                }

                /* -------------------- PushBlackness Functions ---------------------- */

                void pushBlacknessDown(Node* node)
                {
                    Node* Parent = node->parent;
                    Node* GrandParent = node->getGrandParent();
                    Node* Uncle = node->getUncle();

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

                    if (!node->parent->isNil())
                    {
                        if (node->doubleRed() && Uncle != node && Uncle->isRed())
                        {            
                            pushBlacknessDown(node);
                            ret = fixInsertion(root, node->parent->parent);
                        }
                        else if (node->doubleRed() && node->isLeftRightCase() == 0)
                        {
                            ret = rotate(root, Parent->parent, 3);
                            node->setColor(BLACK);
                            node->right->setColor(RED);
                        }   
                        else if (node->doubleRed() && node->isLeftRightCase() == 1)
                        {
                            ret = rotate(root, Parent->parent, 4); 
                            node->setColor(BLACK);
                            node->left->setColor(RED);  
                        }
                        else if (node->doubleRed() && node->isLeftRightCase() == 2)
                        {
                            ret = rotate(root, Parent->parent, 2);   
                            node->parent->setColor(BLACK);
                            node->parent->right->setColor(RED);  
                        }
                        else if (node->doubleRed() && node->isLeftRightCase() == 3)
                        {
                            ret = rotate(root, Parent->parent, 1);
                            node->parent->setColor(BLACK);
                            node->parent->left->setColor(RED);
                        }
                        if (ret)
                        {
                            ret->setBlack();
                            root = ret;
                        }
                    }
                    if (!node->parent->isNil() && !node->parent->parent->isNil() && node->parent->parent != root && node->parent->parent->doubleRed() == 1)
                    {
                        ret = fixInsertion(root, node->parent->parent);
                        if (ret)
                            root = ret;
                    }
                    return (root);
                }

                Node* const searchNode(Node* node, Key key) const
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
                    if (!TN->isNil() && TN->isDBlack())
                    {
                        if (TN->hasBSibling())
                        {
                            if (TN->hasBNephews())
                                pushBlacknessUp(TN);
                            else if (TN->isLChild() && TN->hasRBNephew())
                            {
                                ret = rotate(_root, TN->parent, 4);
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
                                ret = rotate(_root, TN->parent, 1);
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
                                ret = rotate(_root, TN->parent, 3);
                                TN->setColor(BLACK);
                                TN->parent->setColor(BLACK);
                                TN->getUncle()->setColor(BLACK);

                                if (ret)
                                    _root = ret;
                            }
                            else if (TN->isRChild() && TN->hasLRNephew())
                            {
                                ret = rotate(_root, TN->parent, 2);

                                if (TN->parent->isRed() && TN->parent->parent->isBlack() && TN->getUncle()->isRed())
                                {
                                    TN->parent->parent->setColor(RED);
                                    TN->parent->setColor(BLACK);
                                    TN->getUncle()->setColor(BLACK);
                                    TN->setColor(BLACK);
                                }
                                else if (TN->parent->isBlack() && TN->parent->parent->isBlack())
                                {
                                    TN->getUncle()->setColor(BLACK);
                                    TN->setColor(BLACK);
                                }
                                if (ret)
                                    _root = ret;
                            }
                            fixDB(TN->parent);
                        }
                        else if (TN->hasRSibling())
                        {
                            if (TN->isLChild())
                            {
                                ret = rotate(_root, TN->parent, 1);
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

                bool removeNode(Node* node, Key key)
                {
                    int flag_lsentinel = 0;
                    int flag_rsentinel = 0;
                    bool found_node = false;
                    Node* TargetNode = searchNode(node, key);
                    if (!TargetNode->isNil())
                    {
                        _size--;
                        found_node = true;
                    }
                    if (TargetNode == _sentinel->left)
                        flag_lsentinel = 1;
                    else if (TargetNode == _sentinel->right)
                        flag_rsentinel = 1;
                    Node* Parent = TargetNode->parent;
                    Node* Sibling = NULL;
                    Node* ret = NULL;
                    if (!TargetNode->isNil())
                    {
                        if (TargetNode->isRedLeaf())
                        {
                            removeParentLink(TargetNode);
                            deleteNode(TargetNode);
                        }
                        else if (TargetNode->isBlackLeaf())
                        {
                            if (TargetNode == _root)
                            {
                                _root = _nil;
                                removeParentLink(TargetNode);
                                deleteNode(TargetNode);
                            }
                            else
                            {
                                TargetNode->setColor(DOUBLE_BLACK);
                                if (TargetNode->hasRSibling())
                                {
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
                                            pushBlacknessUp(TargetNode);
                                            fixDB(TargetNode->parent);
                                        }
                                        else if (TargetNode->hasLBNephew())
                                        {
                                            if (TargetNode->parent->isRed() && TargetNode->getSibling()->isBlack() && TargetNode->getRNephew()->isRed())
                                                TargetNode->parent->setColor(BLACK);                                             
                                            else
                                                if (TargetNode->hasRRNephew())
                                                    TargetNode->getRNephew()->setColor(BLACK);
                                            TargetNode->setColor(BLACK);
                                            ret = rotate(_root, TargetNode->parent, 3);
                                            if (ret)
                                                _root = ret;
                                            Sibling = TargetNode->parent;
                                        }
                                        else if (TargetNode->hasLRNephew())
                                        {
                                            if (TargetNode->parent->isBlack() && TargetNode->getSibling()->isBlack() && TargetNode->hasLRNephew())
                                            {
                                                TargetNode->setColor(BLACK);
                                                TargetNode->getLNephew()->setColor(BLACK);
                                            }
                                            else
                                            {
                                                if (TargetNode->parent->isRed())
                                                    TargetNode->parent->setColor(BLACK);
                                                if (TargetNode->getSibling()->isBlack())
                                                    TargetNode->getSibling()->setColor(RED);
                                            }
                                            ret = rotate(_root, TargetNode->parent, 2);
                                            if (ret)
                                                _root = ret;
                                            
                                            TargetNode->getUncle()->setColor(BLACK);
                                            TargetNode->setColor(BLACK);
                                        }
                                        removeParentLink(TargetNode);
                                        deleteNode(TargetNode);
                                    }
                                    else if (TargetNode->isLChild())
                                    {
                                        if (TargetNode->hasBNephews())
                                        {
                                            pushBlacknessUp(TargetNode);
                                            fixDB(TargetNode->parent);
                                            removeParentLink(TargetNode);
                                            deleteNode(TargetNode);
                                        }
                                        else if (TargetNode->hasRRNephew())
                                        {
                                            TargetNode->getSibling()->swapChildParentColors();
                                            Node* FarNephew = TargetNode->getFarNephew();
                                            ret = rotate(_root, TargetNode->parent, 1);
                                            if (ret)
                                                _root = ret;
                                            FarNephew->setColor(BLACK);
                                            removeParentLink(TargetNode);
                                            deleteNode(TargetNode);
                                        }
                                        else if (TargetNode->hasRBNephew())
                                        {
                                            if (TargetNode->hasLRNephew())
                                            {
                                                TargetNode->getLNephew()->setColor(BLACK);
                                                TargetNode->getSibling()->setColor(RED);
                                            }
                                            Node* FarNephew = TargetNode->getFarNephew();
                                            ret = rotate(_root, TargetNode->parent, 4);
                                            if (ret)
                                                _root = ret;
                                            if (TargetNode->parent->isRed() && TargetNode->getUncle()->isRed() && TargetNode->parent->parent->isBlack())
                                            {
                                                TargetNode->setColor(BLACK);
                                                TargetNode->parent->setColor(BLACK);
                                                TargetNode->getUncle()->setColor(BLACK);
                                                TargetNode->parent->parent->setColor(RED);
                                            }
                                            else
                                            {
                                                TargetNode->parent->parent->right->setColor(BLACK);
                                                FarNephew->setColor(BLACK);
                                            }
                                            removeParentLink(TargetNode);
                                            deleteNode(TargetNode);
                                        }
                                    }
                                }
                            }
                        }
                        else if (TargetNode->hasChildren())
                        {
                            Node* Replacer = getMaxValueNode(TargetNode->left);
                            int tn_side = TargetNode->isLeftRightChild();
                            int rp_side = Replacer->isLeftRightChild();
                            int save_tn_color = TargetNode->getColor();
                            int save_rp_color = Replacer->getColor();
                            Node* Replacer_Parent = Replacer->parent;
                            Node* Replacer_Left = Replacer->left;
                            int check_RP_equal_TN = (Replacer_Parent == TargetNode);
                            if (TargetNode != _root)
                            {
                                link(Parent, Replacer, tn_side + 1);
                                Replacer->setColor(save_tn_color);
                                link(Replacer, TargetNode->right, 2);
                                link(Replacer, TargetNode->left, 1);
                            }
                            else 
                            {
                                _root = Replacer;
                                Replacer->parent = _nil;
                                link(Replacer, TargetNode->right, 2);
                                link(Replacer, TargetNode->left, 1);
                            }

                            if (!Replacer_Left->isNil() && !Replacer_Parent->isNil())
                            {
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
                                    if (Replacer_Parent != TargetNode)
                                        link(Replacer_Parent, TargetNode, rp_side + 1);
                                    else
                                        link(Replacer, TargetNode, rp_side + 1);
                                    TargetNode->setColor(DOUBLE_BLACK);
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

                    if (flag_lsentinel)
                    {
                        Node *tmp_min = getMinValueNode(_root);
                        _sentinel->left = tmp_min;
                        tmp_min->left = _sentinel;
                    }
                    if (flag_rsentinel)
                    {
                        Node *tmp_max = getMaxValueNode(_root);
                        _sentinel->right = tmp_max;
                        tmp_max->right = _sentinel;
                    }
                    return found_node;
                }
                
                void printRBT()
                {
                    if (this->_root)
                    {
                        std::cout << "============= ROOT ============\nParent = " << (_root->parent? _root->parent->getKey() : 0)<< " - " << _root->getKey() << " - " << _root->getMapped() << " - " << (_root->getColor() == RED? "Red" : _root->getColor() == DOUBLE_BLACK? "Double Black": "Black") << std::endl;
                        if (!_root->left->isNil() || (_root->left->isNil() && _root->left->isSentinel()))
                            _root->left->printNode('l', _root);
                        if (!_root->right->isNil() || (_root->right->isNil() && _root->right->isSentinel()))
                            _root->right->printNode('r', _root);
                    }
                }

                void swap(RBTree &rhs)
                {
                    Node*                               tmp_root = _root;
                    Node*                               tmp_nil = _nil;
                    Node*                               tmp_sentinel = _sentinel;
                    size_t                              tmp_size = _size;
                    Compare                             tmp_cmp = _cmp;
                    Alloc                               tmp_valueAlloc = _valueAlloc;
                    node_allocator                      tmp_nodeAlloc = _nodeAlloc;

                    _root = rhs._root;
                    _nil = rhs._nil;
                    _sentinel = rhs._sentinel;
                    _size = rhs._size;
                    _cmp = rhs._cmp;
                    _valueAlloc = rhs._valueAlloc;
                    _nodeAlloc = rhs._nodeAlloc;
                    rhs._root = tmp_root;
                    rhs._nil = tmp_nil;
                    rhs._sentinel = tmp_sentinel;
                    rhs._size = tmp_size;
                    rhs._cmp = tmp_cmp;
                    rhs._valueAlloc = tmp_valueAlloc;
                    rhs._nodeAlloc = tmp_nodeAlloc;
                }
};

};


#endif