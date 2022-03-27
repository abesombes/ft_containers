/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:34:35 by abesombes         #+#    #+#             */
/*   Updated: 2022/03/27 18:27:56 by abesombe         ###   ########.fr       */
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
#define SENTINEL 3

namespace ft{

template <class Key, class T, class Compare = less<Key>, class Alloc = std::allocator<pair<const Key,T> > > 
class Node {

    public:

            typedef const Key			    key_type;
            typedef T					    mapped_type;
            typedef ft::pair<const Key, T>	value_type;
            typedef std::size_t			    size_type;

            value_type                      value;
            Node                            *parent;
            Node                            *left;
            Node                            *right;
            int                             color;
            
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
                return (parent == this || getColor() == SENTINEL);
            }

            bool isSentinel(void) const{
                return (getColor() == SENTINEL);
            }
            
            /* -------------------- Basic Getters ---------------------- */

            value_type& getValue(void) { return (value); }
            const value_type& getValue(void) const{ return (value); }
            const key_type& getKey(void) const { return value.first; }
            mapped_type getMapped(void) { return value.second; }
            const mapped_type getMapped(void) const { return value.second; }

            /* -------------------- Color Functions ---------------------- */

            void setColor(int color) { this->color = color;}
            void setRed(void) { this->color = RED;}
            void setBlack(void) { this->color = BLACK;}
            void setDBlack(void) { this->color = DOUBLE_BLACK;}            
            
            int getColor() const { return (color);}

            int isRed(void) { return (getColor() == RED);}
            int isBlack(void) { return (getColor() == BLACK);}
            int isDBlack(void) { return (getColor() == DOUBLE_BLACK);}
            
            int doubleRed(void)
            {
                // -1 no parent, 0 no double red, l double red child-parent
                if (parent->isNil())
                    return (-1);
                if (!parent->isNil() && isRed() && parent->isRed())
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
                if (!parent->isNil() && parent->left == this)
                    return (parent->right->left);
                else if (!parent->isNil() && parent->right == this)
                    return (parent->left->left);
                return (this);
            }

            Node* getRNephew( void )
            {
                if (!parent->isNil() && parent->left == this)
                    return (parent->right->right);
                else if (!parent->isNil() && parent->right == this)
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

            Node* getRoot(void)
            {
                if (this->isNil() || parent == this)
                    return (this);
                Node* Parent = this->parent;
                Node* tmp = this;
                while (Parent != tmp && !Parent->isNil())
                {
                    tmp = tmp->parent;
                    Parent = Parent->parent;
                }
                return (tmp);
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

            int hasNoLChild(void) { return (left->isNil()); }            
            
            int hasNoRChild(void) { return (right->isNil()); }
            
            int hasChildren(void) { return (!left->isNil() && !right->isNil()); }

            int isLChild(void) { return (!parent->isNil() && parent->left == this); }

            int isRChild(void) { return (!parent->isNil() && parent->right == this); }

            int hasBSibling(void) { return (getSibling() != this && getSibling()->isBlack()); }

            int hasRSibling(void) { return (getSibling() != this && getSibling()->isRed()); }

            int hasLBNephew(void) { return (getLNephew() != this && (getLNephew()->isBlack() || getLNephew()->isNil())); }
            
            int hasRBNephew(void) { return (getRNephew() != this && (getRNephew()->isBlack() || getRNephew()->isNil())); }

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
            

            Node* getSuccessor( void )
            {        
                Node* Successor = this;
                
                if (!right->isNil())
                    return (right->getTreeMin());
                else if (right->isNil())
                {
                    if (right->isSentinel())
                       return (Successor->right);

                    while (!Successor->isNil())
                    {
                        if (Successor->isLChild())
                            return (Successor->parent);
                        Successor = Successor->parent;
                    }
                }
                return (Successor);
            }

            Node* getPredecessor( void )
            {
                Node* Predecessor = this;
                
                if (this->isSentinel())
                    return(right);
                if (!left->isNil())
                    return (left->getTreeMax());
                if (left->isNil())
                {
                    if (left->isSentinel())
                        return (Predecessor->left);
                    while (!Predecessor->isNil())
                    {
                        if (Predecessor->isRChild())
                            return (Predecessor->parent);
                        Predecessor = Predecessor->parent;
                    }
                    return (Predecessor->parent);
                }
                return (Predecessor->parent);
            }

            bool isOrphan()
            {
                    return ((left == right && left->isSentinel()) || (left == right && !left->isNil()) || (left == right && parent->isNil()));
            }
            
            bool isTwoElemTree()
            {
                    return (this->getPredecessor()->getPredecessor() == this->getSuccessor() || this->getPredecessor() == this->getSuccessor()->getSuccessor());
            }

            Node* getTreeMax( void )
            {
                Node* TreeMax = this; 
                
                while (!TreeMax->right->isNil())
                    TreeMax = TreeMax->right;

                return (TreeMax);
            }

            Node* getTreeMin( void )
            {
                Node* TreeMin = this;
            
                while (!TreeMin->left->isNil())
                    TreeMin = TreeMin->left;
            
                return (TreeMin);
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

    };
}

#endif