/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_bidirectional_iterator.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 09:58:22 by abesombe          #+#    #+#             */
/*   Updated: 2022/03/17 16:37:36 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REV_BIDIRECTIONAL_ITERATOR_HPP
#define REV_BIDIRECTIONAL_ITERATOR_HPP
#include "iterator_traits.hpp"
#include "../utils/const_or_not.hpp"
#include "../utils/less.hpp"
#include "../utils/node.hpp"
#include <cstddef>
#include <iostream>

namespace ft{

template <class Key, class T, class Compare = less<Key>, bool B = false>
class rev_bidirectional_iterator
{

    public:
            typedef ft::pair<const Key, T>				                                value_type;
            typedef rev_bidirectional_iterator                                          self_type;
            typedef rev_bidirectional_iterator                                          reverse_iterator;
            typedef typename const_or_not<B, const value_type&, value_type&>::type		reference;
            typedef typename const_or_not<B, const value_type*, value_type*>::type		pointer;
            typedef ft::bidirectional_iterator_tag                                      iterator_category;
            typedef ptrdiff_t                                                           difference_type;
            typedef T*                                                                  elem_pointer;
            typedef bidirectional_iterator<const Key, T, Compare, B>                    iterator;

            typedef Node<const Key, T, Compare>	                        Node;
            typedef Node*                                               NodePtr;
            typedef Key									                key_type;
            typedef Compare                                             key_compare;
            typedef T									                mapped_type;
            typedef std::size_t							                size_type;
                
    private:

            NodePtr _node;
            
    public:        
            rev_bidirectional_iterator( Node* node = NULL): _node(node){};
            rev_bidirectional_iterator( rev_bidirectional_iterator<Key, T, Compare, B> const &src ): _node(src.getNode()) {};
            reverse_iterator &operator=(rev_bidirectional_iterator const &rhs){ this->_node = rhs._node; return (*this); };
            virtual ~rev_bidirectional_iterator(){};
            Node *getNode( void ) const { return _node;}

            iterator base( void ) const
            {
                rev_bidirectional_iterator tmp(*this); // on cree un tmp rev iterator pour ne pas bouger le rev_iterator initial

                --tmp;
                return (iterator(tmp.getNode()));
            }

            reverse_iterator &operator++()
            { 
                Node *tmp = _node->getPredecessor();
                // std::cout << "isOrphan? " << _node->isOrphan() << std::endl;
                if (!_node->isOrphan())
                    _node = tmp;
                return (*this);
            };
            
            
            self_type operator++(int)
            { 
                self_type tmp_it(*this);
                
                ++(*this);
                return (tmp_it);
            };

            self_type &operator--()
            { 
                Node *tmp = _node->getSuccessor();
                
                std::cout << "isOrphan? " << _node->isOrphan() << std::endl;
                // std::cout << "_node before: " << _node->getKey() << std::endl;
                // std::cout << "The Tree has only 2 Elem? " << _node->isTwoElemTree() << std::endl;
                if (!_node->isOrphan())
                {
                    if (_node->isSentinel())
                    {
                        std::cout << "line 94\n";
                        _node = _node->left;
                        return (*this);
                    }
                    if (_node->isTwoElemTree() && tmp->isSentinel())
                    {
                        std::cout << "line 99" << std::endl;
                        _node = tmp;
                        return (*this);
                    }
                    if (tmp->isSentinel())
                    {
                        std::cout << "line 106\n";
                        _node = tmp->getPredecessor()->getPredecessor();
                        return (*this);
                    }
                    std::cout << "line 110\n";
                    _node = tmp;
                }
                std::cout << "line 112\n";
                // std::cout << "_node after: " << _node->getKey() << std::endl;
                return (*this);
            };
            
            self_type operator--(int)
            { 
                self_type tmp_it(*this);
                // std::cout << "size: " << _node->RBT_size() << std::endl;
                // if (_node->RBT_size() != 1)
                // std::cout << "isOrphan? " << _node->isOrphan() << std::endl;
                --(*this);
                return (tmp_it);
            };
            
            bool operator==(self_type const & rhs) const { 
                    return (_node == rhs.getNode()); 
            };
            bool operator!=(self_type const & rhs) const { 
                    return !(_node == rhs.getNode()); 
            };
            
            reference operator*() const { return (this->_node->getValue()); };
            pointer operator->() const { return (&this->_node->getValue()); };
        
    
};


}

#endif