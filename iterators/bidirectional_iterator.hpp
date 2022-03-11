/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:30:34 by abesombes         #+#    #+#             */
/*   Updated: 2022/03/11 23:55:34 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP
#include "iterator_traits.hpp"
#include "../utils/const_or_not.hpp"
#include "../utils/less.hpp"
#include "../utils/node.hpp"
#include <cstddef>
#include <iostream>

namespace ft{

template <class Key, class T, class Compare = less<Key>, bool B = false>
class bidirectional_iterator
{

    public:
            typedef ft::pair<const Key, T>												value_type;
            typedef bidirectional_iterator												self_type;
			typedef bidirectional_iterator												iterator;
            typedef typename const_or_not<B, const value_type&, value_type&>::type		reference;
            typedef typename const_or_not<B, const value_type*, value_type*>::type		pointer;
            typedef ft::bidirectional_iterator_tag										iterator_category;
            typedef ptrdiff_t															difference_type;
            typedef T*																	elem_pointer;

            typedef Node<const Key, T, Compare>											Node;
            typedef Node*																NodePtr;
            typedef Key																	key_type;
            typedef Compare																key_compare;
            typedef T																	mapped_type;
            typedef std::size_t															size_type;
                
    private:

            NodePtr _node;
            
    public:        
            bidirectional_iterator( Node* node = NULL): _node(node){};
            bidirectional_iterator( bidirectional_iterator<Key, T, Compare, B> const &src ): _node(src.getNode()) {};
            bidirectional_iterator &operator=(bidirectional_iterator<const Key, T, Compare> const &rhs){ this->_node = rhs.getNode(); return (*this); };
            virtual ~bidirectional_iterator(){};
            Node *getNode( void ) const { return _node;}
            
            self_type &operator++()
            { 
                Node *tmp = _node->getSuccessor();
                
                if (tmp->isSentinel())
                    _node = tmp;
                return (*this);
            };
            
            self_type operator++(int)
            { 
                self_type tmp_it(*this);
                
                ++(*this);
                return (*tmp_it);
            };

            self_type &operator--()
            { 
                Node *tmp = _node->getPredecessor();
                
                if (!tmp->isSentinel())
                    _node = tmp;
                return (*this);
            };
            
            self_type operator--(int)
            { 
                self_type tmp_it(*this);
                
                --(*this);
                return (*tmp_it);
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