/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:34:35 by abesombes         #+#    #+#             */
/*   Updated: 2022/03/06 15:17:30 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include "less.hpp"
#include "pair.hpp"

#define RED 0
#define BLACK 1
#define DOUBLE_BLACK 2

namespace ft{

template <class Key, class T, class Compare = less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > > 
class Node {

    public:

            typedef const Key			key_type;
            typedef T					mapped_type;
            typedef ft::pair<const Key, T>	value_type;
            typedef std::size_t			size_type;

            value_type                  value;
            Node                        *parent;
            Node                        *left;
            Node                        *right;
            int                         color;
            
            Node(void): parent(NULL), left(NULL), right(NULL), color(RED) {
                value.first = Key();
                value.second = T();
            };      
            
            Node(value_type &val): value(val), parent(NULL), left(NULL), right(NULL), color(RED){};
            
            ~Node(void){};

            Node& operator=(const Node &rhs)
            {
                parent = rhs.parent;
                left = rhs.left;
                right = rhs.right;
                color = rhs.color;
            }

            bool isNil(void) const{
                return (parent == this);
            }
            
            /* -------------------- Basic Getters ---------------------- */

            value_type& getValue(void) { return (value); }
            const value_type& getValue(void) const{ return (value); }
            const key_type& getKey(void) const { return value.first; }
            mapped_type getMapped(void) { return value.second; }
            const mapped_type getMapped(void) const { return value.second; }

            /* -------------------- Color Functions ---------------------- */

            void setColor(int color) { this->color = color;}
            
            int getColor() { return (color);}

            int isRed(void) { return (getColor() == RED);}
            int isBlack(void) { return (getColor() == BLACK);}
            int isDBlack(void) { return (getColor() == DOUBLE_BLACK);}
            
            int doubleRed(void)
            {
                // -1 no parent, 0 no double red, l double red child-parent
                if (!parent)
                    return (-1);
                if (parent && getColor() == RED && this->parent->getColor() == RED)
                    return 1;
                return 0;
            }
            
            void swapChildParentColors(void)
            {
                if (this->parent)
                {
                    int parent_color = this->parent->getColor();
                    this->parent->setColor(this->getColor());
                    this->setColor(parent_color);
                }
            }
            


            /* -------------------- Family Members Getters ---------------------- */

            Node* getGrandParent( void )
            {
                if (parent)
                    return (parent->parent);
                else
                    return this;
            }

            Node* getUncle( void )
            {
                Node* GrandParent = this->getGrandParent();                
                if (GrandParent->isNil())
                    return (this);
                if (GrandParent->left == this->parent)
                    return (GrandParent->right);
                if (GrandParent->right == this->parent)
                    return (GrandParent->left);
                return this;
            }

            Node* getSibling( void )
            {
                if (!parent->isNil() && parent->left == this)
                    return (parent->right);
                else if (!parent->isNil() && parent->right == this)
                    return (parent->left);
                return (this);
            }

            Node* getLNephew( void )
            {
                if (parent && parent->left == this)
                    return (parent->right->left);
                else if (parent && parent->right == this)
                    return (parent->left->left);
                return (this);
            }

            Node* getRNephew( void )
            {
                if (parent && parent->left == this)
                    return (parent->right->right);
                else if (parent && parent->right == this)
                    return (parent->left->right);
                return (this);
            }

            Node* getFarNephew(void)
            {
                Node* Sibling = getSibling();
                if (Sibling != this)
                {
                    if (isLChild())
                        return (Sibling->right);
                    else if (isRChild())
                        return (Sibling->left);
                }
                return (this);
            }

            /* -------------------- Node Structures ---------------------- */

            int isLeftRightChild(void)
            {
                // -1 not child, 0 left child, l right child
                if (this->parent && this->parent->left == this)
                    return 0;
                if (this->parent && this->parent->right == this)
                    return 1;
                return (-1);
            }
            int hasNoChild(void) { return (left->isNil() && right->isNil()); }
            
            int hasLRChildren(void) { return (!left->isNil() && !right->isNil()); }

            int isLChild(void) { return (!parent->isNil() && parent->left == this); }

            int isRChild(void) { return (!parent->isNil() && parent->right == this); }

            int hasBSibling(void) { return (getSibling() != this && getSibling()->isBlack()); }

            int hasRSibling(void) { return (getSibling() != this && getSibling()->isRed()); }

            int hasLBNephew(void) { return (getLNephew() != this && getLNephew()->isBlack()); }
            
            int hasRBNephew(void) { return (getRNephew() != this && getRNephew()->isBlack()); }

            int hasBNephews(void) { return (hasRBNephew() && hasLBNephew()); }

            int hasLRNephew(void) { return (getLNephew() != this && getLNephew()->isRed()); }

            int hasRRNephew(void) { return (getRNephew() != this && getRNephew()->isRed()); }

            int isLeftRightCase(void)
            {
                // -1 no parent (root) or no grandparent, 0 LeftRight Case, 1 RightLeft Case, 2 LeftLeft Case, 3 RightRight Case
                if (this->isLeftRightChild() == 1 && this->parent->isLeftRightChild() == 0)
                    return 0;
                if (this->isLeftRightChild() == 0 && this->parent->isLeftRightChild() == 1)
                    return 1;
                if (this->isLeftRightChild() == 0 && this->parent->isLeftRightChild() == 0)
                    return 2;   
                if (this->isLeftRightChild() == 1 && this->parent->isLeftRightChild() == 1)
                    return 3;
                return (-1);
            }
            
            /* ----------------------------------------------------------- */

            bool isLeaf(void) { return (!isNil() && left->isNil() && right->isNil()); }

            bool isRedLeaf(void) { return (!isNil() && left->isNil() && right->isNil() && isRed());}

            bool isBlackLeaf(void) { return (!isNil() && left->isNil() && right->isNil() && isBlack()); }
            
            void printNode(char relative_pos, Node* parent)
            {
                std::cout << (relative_pos == 'r' ? "Right of " : "Left of ") << parent->getKey() << " - " << "Parent = " << this->parent->getKey() << " - " << this->getKey() << " - " << this->getMapped() << " - " << (this->getColor() == RED? "Red" : this->getColor() == DOUBLE_BLACK? "Double Black": "Black") << std::endl; 
                if (!left->isNil())
                    left->printNode('l', this);
                if (!right->isNil())
                    right->printNode('r', this);    
            }

            void printNodeSubTree()
            {
                std::cout << std::endl << std::endl << std::endl;
                std::cout << this->getKey() << " - " << this->getMapped() << " - " << (this->getColor() == RED? "Red" : this->getColor() == DOUBLE_BLACK? "Double Black": "Black") << std::endl;
                if (!this->left->isNil())
                    this->left->printNode('l', this);
                if (!this->right->isNil())
                    this->right->printNode('r', this);
            }
            
//             Node<Key, T>* getGrandParent( void )
//             {
//                 if (this->parent)
//                     return (this->parent->parent);
//                 else
//                     return NULL;
//             }


//             Node<Key, T>* getFarNephew(void)
//             {
//                 Node<Key, T>* Sibling = getSibling(this);
//                 if (Sibling)
//                 {
//                     if (this->isLeftChild())
//                         return (Sibling->right);
//                     else if (this->isRightChild())
//                         return (Sibling->left);
//                 }
//                 return NULL;
//             }

//             Node<Key, T>* getNearNephew(void)
//             {
//                 Node<Key, T>* Sibling = getSibling(this);
//                 if (Sibling)
//                 {
//                     if (this->isLeftChild())
//                         return (Sibling->left);
//                     else if (this->isRightChild())
//                         return (Sibling->right);
//                 }
//                 return NULL;
//             }

//             int hasLRChildren(void)
//             {
//                 return (node && node->left && node->right? 1 : 0);
//             }

//             int hasNoChild(void)
//             {
//                 return (!this->left && !this->right);
//             }
            
//             int hasBlackLChild(void)
//             {
//                 return ((this->left && this->left->isBlack()) || !this->left);
//             }

//             int hasBlackRChild(void)
//             {
//                 return ((this->right && this->right->isBlack()) || !this->right);
//             }
            
//             int hasNoRightChild(void)
//             {
//                 return (!this->right);
//             }

//             int hasBSibling(void)
//             {
//                 return (getSibling(this) && getSibling(this)->isBlack());
//             }

//             int hasRSibling(void)
//             {
//                 return (getSibling(this) && getSibling(this)->isRed());
//             }

//             int hasLBNephew(void)
//             {
//                 if ((getLeftNephew(this) && getLeftNephew(this)->isBlack()) || !getLeftNephew(this))
//                     return (1);
//                 return (0);
//             }
            
//             int hasRBNephew(void)
//             {
//                 if ((getRightNephew(this) && getRightNephew(this)->isBlack()) || !getRightNephew(this))
//                     return (1);
//                 return (0);
//             }

//             int hasLRNephew(void)
//             {
//                 if (getLeftNephew(this) && getLeftNephew(this)->isRed())
//                     return (1);
//                 return (0);
//             }

//             int hasRRNephew(void)
//             {
//                 if (getRightNephew(this) && getRightNephew(this)->isRed())
//                     return (1);
//                 return (0);
//             }

//             int hasTwoBlackNephews(void)
//             {
//                 Node<Key, T> *Sibling= getSibling(this);      
//                 if (Sibling)
//                     return (Sibling->hasNoChild() || (Sibling->hasBlackLChild() && !Sibling->right) || (Sibling->hasBlackRChild() && !Sibling->left) || (Sibling->hasBlackLChild() && Sibling->hasBlackRChild()));
//                 return (0);
//             }

//             int isLeftRightChild(void)
//             {
//                 // -1 not child, 0 left child, l right child
//                 if (!node)
//                     return (-1);
//                 if (node && node->parent && node->parent->left == node)
//                     return 0;
//                 if (node && node->parent && node->parent->right == node)
//                     return 1;
//                 return  (-1);
//             }
            
//             int isLeftChild(void)
//             {
//                 // 1 Left Child, 0 no parent or Right Child
//                 if (this->parent && this->parent->left == this)
//                     return 1;
//                 return  (0);
//             }

//             int isRightChild(void)
//             {
//                 // 1 Right Child, 0 no parent or Left Child
//                 if (this->parent && this->parent->right == this)
//                     return 1;
//                 return  (0);
//             }
            
//             int isLeftRightChild(void)
//             {
//                 // -1 not child, 0 left child, l right child
//                 if (this->parent && this->parent->left == this)
//                     return 0;
//                 if (this && this->parent && this->parent->right == this)
//                     return 1;
//                 return  (-1);
//             }

//             int doubleRed(void)
//             {
//                 // -1 no parent, 0 no double red, l double red child-parent
//                 if (!parent)
//                     return (-1);
//                 if (parent && getColor() == RED && this->parent->getColor() == RED)
//                     return 1;
//                 return 0;
//             }

//             int isInnerChild(void)
//             {
//                 // -1 no child, 0 outer child, 1 inner child
//                 if (!node)
//                     return (-1);
//                 if (node && isLeftRightChild(node) == 0 && isLeftRightChild(node->parent) == 1)
//                     return 1;
//                 if (node && isLeftRightChild(node) == 1 && isLeftRightChild(node->parent) == 0)
//                     return 1;
//                 return (0);
//             }

//             int isLeftRightCase(void)
//             {
//                 // -1 no parent or no grandparent, 0 LeftRight Case, 1 RightLeft Case, 2 LeftLeft Case, 3 RightRight Case
//                 if (!node)
//                     return (-1);
//                 if (node && isLeftRightChild(node) == 1 && isLeftRightChild(node->parent) == 0)
//                     return 0;
//                 if (node && isLeftRightChild(node) == 0 && isLeftRightChild(node->parent) == 1)
//                     return 1;
//                 if (node && isLeftRightChild(node) == 0 && isLeftRightChild(node->parent) == 0)
//                     return 2;   
//                 if (node && isLeftRightChild(node) == 1 && isLeftRightChild(node->parent) == 1)
//                     return 3;
//                 return (0);
//             }

//             void printNodeSubTree()
//             {
//                 std::cout << std::endl << std::endl << std::endl;
//                 std::cout << this->getData() << " - " << this->getValue() << " - " << (this->getColor() == RED? "Red" : this->getColor() == DOUBLE_BLACK? "Double Black": "Black") << std::endl;
//                 if (this->left)
//                     this->left->printNode('l', this);
//                 if (this->right)
//                     this->right->printNode('r', this);
//             }
            

            
//             Node<Key, T>* leftRotate(Node<Key, T>* root, Node<Key, T>* node) // Right Right Case ONLY
//             {
//                 if (node == NULL)
//                     return (NULL);
//                 Node<Key, T>* Parent = &(*node->parent);
//                 int flag_lr = (isLeftRightChild(node) ? 1 : 0);
//                 Node<Key, T>* snode = &(*node); // GrandParent in the chain of 3 nodes
//                 Node<Key, T>* RightChild = (node->right? &(*node->right) : NULL);
//                 Node<Key, T>* RightLeftChild = (node->right? &(*node->right->left) : NULL);
//                 int flag_root = (node == root? 1 : 0);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
//                 node = RightChild;
//                 std::cout << "I am here 160\n";
//                 if (flag_lr && !flag_root)
//                     Parent->right = node;
//                 else if (!flag_root)
//                     Parent->left = node;
//                 if (Parent)
//                     node->parent = Parent;endif
//                     node->parent = NULL;
//                 return (flag_root? node: NULL);
//             }

//             Node<Key, T>* rightRotate(Node<Key, T>* root, Node<Key, T>* node) // Left Left Case ONLY
//             {
//                 if (node == NULL)
//                     return (NULL);
//                 Node<Key, T>* Parent = &(*node->parent);
//                 int flag_lr = (isLeftRightChild(node) ? 1 : 0);
//                 Node<Key, T>* snode = &(*node); // GrandParent in the chain of 3 nodes
//                 Node<Key, T>* LeftChild = (node->left? &(*node->left) : NULL);
//                 Node<Key, T>* LRChild = (node->left? &(*node->left->right) : NULL);
//                 int flag_root = (node == root? 1 : 0);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
//                 node = LeftChild;
//                 if (flag_lr && !flag_root)
//                     Parent->right = node;
//                 else if (!flag_root)
//                     Parent->left = node;
//                 if (Parent)
//                     node->parent = Parent;
//                 node->right = snode;
//                 snode->parent = node;
//                 node->right->left = LRChild;
//                 if (LRChild)
//                     LRChild->parent = node->right;
//                 if (flag_root)
//                     node->parent = NULL;
//                 return (flag_root? node: NULL);
//             }

//             Node<Key, T>* leftrightRotate(Node<Key, T>* root, Node<Key, T>* node) // Left Right Case ONLY
//             {
//                 std::cout << "I am here 156\n" << std::endl;
//                 if (node == NULL)
//                     return (NULL);
//                 Node<Key, T>* Parent = &(*node->parent);
//                 int flag_lr = (isLeftRightChild(node) ? 1 : 0);
//                 Node<Key, T>* snode = &(*node); // GrandParent in the chain of 3 nodes
//                 Node<Key, T>* LChild = (node->left? &(*node->left) : NULL);
//                 Node<Key, T>* LRChild = (node->left? &(*node->left->right) : NULL);
//                 Node<Key, T>* LRLChild = (node->left->right? &(*node->left->right->left) : NULL);
//                 Node<Key, T>* LRRChild = (node->left->right? &(*node->left->right->right) : NULL);
                
//                 int flag_root = (node == root? 1 : 0);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
//                 node = LRChild;
//                 node->left = LChild;
//                 LChild->parent = node;
//                 node->right = snode;
//                 snode->parent = node;
//                 if (flag_lr && !flag_root)
//                     Parent->right = node;
//                 else if (!flag_root)
//                     Parent->left = node;
//                 if (Parent)
//                     node->parent = Parent;
//                 node->left->right = LRLChild;
//                 if (LRLChild)
//                     LRLChild->parent = node->left;
//                 node->right->left = LRRChild;
//                 if (LRRChild)
//                     LRRChild->parent = node->right;
//                 if (flag_root)
//                     node->parent = NULL;
//                 return (flag_root? node: NULL);
//             }

//             Node<Key, T>* rightleftRotate(Node<Key, T>* root, Node<Key, T>* node) // Right Left Case ONLY
//             {
//                 if (node == NULL)
//                     return (NULL);
//                 Node<Key, T>* Parent = &(*(node->parent));
//                 // std::cout << "1er passage ---  node: "<< node->data << " - node->parent: " << (node->parent? node->parent->data : 0) << " - Parent: " << (Parent != NULL ? Parent->value : std::string()) << std::endl;
//                 int flag_lr = (isLeftRightChild(node) ? 1 : 0);
//                 Node<Key, T>* snode = &(*node); // GrandParent in the chain of 3 nodes
//                 Node<Key, T>* RChild = (node->right? &(*node->right) : NULL);
//                 Node<Key, T>* RLChild = (node->right? &(*node->right->left) : NULL);
//                 Node<Key, T>* RLLChild = (node->right->left? &(*node->right->left->left) : NULL);
//                 Node<Key, T>* RLRChild = (node->right->left? &(*node->right->left->right) : NULL);
//                 int flag_root = (node == root? 1 : 0);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
//                 node = RLChild;
//                 if (flag_lr && !flag_root)
//                     Parent->right = node;
//                 else if (!flag_root)
//                     Parent->left = node;
//                 if (Parent)
//                     node->parent = Parent;
//                 // std::cout << "node 264: "<< node->data << " - node->parent: " << node->parent->data << " - Parent: " << (Parent != NULL ? Parent->value : std::string()) << std::endl;
//                 node->left = snode;
//                 snode->parent = node;
//                 node->right = RChild;
//                 RChild->parent = node;
//                 node->left->right = RLLChild;
//                 if (RLLChild)
//                     RLLChild->parent = node->left;
//                 node->right->left = RLRChild;
//                 if (RLRChild)
//                     RLRChild->parent = node->right;
//                 if (flag_root)
//                     node->parent = NULL;
//                 return (flag_root? node: NULL);
//             }


//             void printNode(char relative_pos, Node<Key, T>* parent)
//             {
//                 std::cout << (relative_pos == 'r' ? "Right of " : "Left of ") << parent->data << " - " << "Parent = " << this->parent->getData() << " - " << this->getData() << " - " << this->getValue() << " - " << (this->getColor() == RED? "Red" : this->getColor() == DOUBLE_BLACK? "Double Black": "Black") << std::endl; 
//                 if (left)
//                     left->printNode('l', this);
//                 if (right)
//                     right->printNode('r', this);    
//             }
            
// };

// template <class Key, class T>  
// void removeParentLink(Node<Key, T>* node)
// {
//     Node<Key, T> *Parent = node->parent;          
//     if (Parent && Parent->left == node)
//         Parent->left = NULL;
//     else if (Parent && Parent->right == node)
//         Parent->right = NULL;
// }

// template <class Key, class T>  
// int isLeaf(Node<Key, T>* node)
// {
//     return (node && node->left == NULL && node->right == NULL);
// }

// template <class Key, class T>  
// Node<Key, T>* getSibling(Node<Key, T>* node)
// {
//     // std::cout << "line 378 - node: " << node->data << " - node->parent: " << node->parent->data << std::endl;
//     if (node && node->parent && node->parent->left == node)
//         return (node->parent->right);
//     else if (node && node->parent && node->parent->right == node)
//         return (node->parent->left);
//     return (NULL);
// }

// template <class Key, class T>  
// Node<Key, T>* getLeftNephew(Node<Key, T>* node)
// {
//     if (node && node->parent && node->parent->left == node)
//         return (node->parent->right->left);
//     else if (node && node->parent && node->parent->right == node)
//         return (node->parent->left->left);
//     return (NULL);
// }

// template <class Key, class T>  
// Node<Key, T>* getRightNephew(Node<Key, T>* node)
// {
//     if (node && node->parent && node->parent->left == node)
//         return (node->parent->right->right);
//     else if (node && node->parent && node->parent->right == node)
//         return (node->parent->left->right);
//     return (NULL);
// }


// template <class Key, class T>  
// Node<Key, T>* BSTInsert(Node<Key, T>* root, Node<Key, T>* node)
// {
//     if (root == NULL)
//     {
//         node->setColor(BLACK);
//         return (node);
//     }
//     if (root->getData() > node->getData())
//     {
//         root->left = BSTInsert(root->left, node);
//         root->left->parent = root;
//     }
//     else if (root->getData() < node->getData())
//     {
//         root->right = BSTInsert(root->right, node);
//         root->right->parent = root;  
//     }
//     // if not root, insert by default as a RED leaf
//     node->setColor(RED);
//     return root;
// }


// template <class Key, class T>
// Node<Key, T>* fixInsertion(Node<Key, T>* root, Node<Key, T>* node)
// {
//     // FIXING INSERTION PROBLEMS IN REGARD TO RBT RULES
//     // if RED leaf's parent is BLACK, then no problem, we should already comply to RBT standards.
//     // if RED leat's parent is RED, then we check parent's sibling (called uncle). If uncle is RED as well
//     // then we change parent and uncle's colors to BLACK.
//     // 0 LeftRight Case, 1 RightLeft Case, 2 LeftLeft Case, 3 RightRight Case
//     Node<Key, T>* Parent = node->parent;
//     // Node<Key, T>* GrandParent = node->getGrandParent();
//     Node<Key, T>* Uncle = node->getUncle();
//     Node<Key, T>* ret = NULL;
//     std::cout << "\nTrying to fix node " << node->data << std::endl;
//     if (node->parent)
//     {
//         std::cout << "Node Shape: " << node->isLeftRightCase(node) << std::endl;
//         std::cout << "0 = LeftRight Case\n1 = RightLeft Case\n2 = LeftLeft Case\n3 = RightRight Case" << std::endl;
//         if (node->doubleRed(node) && Uncle && Uncle->getColor() == RED)
//         {            
//             node->pushBlacknessDown(node);
//             ret = fixInsertion(root, node->parent->parent);
//         }
//         else if (node->doubleRed(node) && node->isLeftRightCase(node) == 0)
//         {
//             std::cout << "\n==== LEFT RIGHT ROTATION 292 on " << Parent->parent->data << " ====" << std::endl;
//             ret = Parent->parent->leftrightRotate(root, Parent->parent);
//             std::cout << "\n==== RECOLORING on " << node->data << " ====" << std::endl;    
//             node->setColor(BLACK);
//             node->right->setColor(RED);
//         }   
//         else if (node->doubleRed(node) && node->isLeftRightCase(node) == 1)
//         {
//             std::cout << "\n==== RIGHT LEFT ROTATION 300 on " << Parent->parent->data << " ====" << std::endl;
//             ret = Parent->parent->rightleftRotate(root, Parent->parent);
//             std::cout << "\n==== RECOLORING on " << node->data << " ====" << std::endl;    
//             node->setColor(BLACK);
//             node->left->setColor(RED);  
//         }
//         else if (node->doubleRed(node) && node->isLeftRightCase(node) == 2)
//         {
//             std::cout << "\n==== RIGHT ROTATION 308 on " << Parent->parent->data << " ====" << std::endl;
//             ret = Parent->parent->rightRotate(root, Parent->parent);
//             std::cout << "\n==== RECOLORING on " << node->data << " ====" << std::endl;    
//             node->parent->setColor(BLACK);
//             node->parent->right->setColor(RED);  
//         }
//         else if (node->doubleRed(node) && node->isLeftRightCase(node) == 3)
//         {
//             std::cout << "\n==== LEFT ROTATION 316 on " << Parent->parent->data << " ====" << std::endl;
//             ret = Parent->parent->leftRotate(root, Parent->parent);
//             std::cout << "\n==== RECOLORING on " << node->data << " ====" << std::endl; 
//             node->parent->setColor(BLACK);
//             node->parent->left->setColor(RED);
//         }
//         if (ret)
//             root = ret;
//         root->printNodeSubTree();
//     }
//     std::cout << "current node: " << node->data << std::endl;
//     if (node->parent && node->parent->parent && node->parent->parent != root && node->parent->parent->doubleRed(node->parent->parent))
//     {
//         std::cout << "ALERT : DOUBLE RED AFTER FIX REQUIRES ANOTHER FIX" << std::endl;
//         ret = fixInsertion(root, node->parent->parent);
//         if (ret)
//             root = ret;
//         std::cout << "SPECIAL MESSAGE ==== node: " << node->data << " - node->parent: " << node->parent->data << std::endl;  
//     }
//     return (root);
// }

// template <class Key, class T>  
// Node<Key, T>* searchNode(Node<Key, T>* node, Key key)
// {
//     if (node == NULL || key == node->data)
//         return node;
//     if (key > node->data)
//         return (searchNode(node->right, key));
//     else
//         return (searchNode(node->left, key));
// }

};
}

#endif