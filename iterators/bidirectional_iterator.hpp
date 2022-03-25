/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:30:34 by abesombes         #+#    #+#             */
/*   Updated: 2022/03/25 18:22:53 by abesombe         ###   ########.fr       */
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
			typedef bidirectional_iterator			    								iterator;
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
            bidirectional_iterator &operator=(bidirectional_iterator const &rhs){ this->_node = rhs.getNode(); return (*this); };
            virtual ~bidirectional_iterator(){};
            Node *getNode( void ) const { return _node;}
            
            operator    bidirectional_iterator<Key, T, Compare, true>() const
            {
                return bidirectional_iterator<Key, T, Compare, true>(_node);
            }

            operator    bidirectional_iterator<Key, T, Compare, false>() const
            {
                return bidirectional_iterator<Key, T, Compare, false>(_node);
            }
            
            iterator &operator++()
            { 
                Node *tmp = _node->getSuccessor();
                
                _node = tmp;
                return (*this);
            };
            
            iterator operator++(int)
            { 
                iterator tmp_it(*this);
                
                ++(*this);
                return (tmp_it);
            };

            iterator &operator--()
            { 
                Node *tmp = _node->getPredecessor();
                
                _node = tmp;
                return (*this);
            };
            
            iterator operator--(int)
            { 
                iterator tmp_it(*this);
                
                --(*this);
                return (tmp_it);
            };

            bool operator==(iterator const & rhs) const { 
                    return (_node == rhs.getNode()); 
            };
            bool operator!=(iterator const & rhs) const { 
                    return !(_node == rhs.getNode()); 
            };
            reference operator*() const { return (this->_node->getValue()); };
            pointer operator->() const { return (&this->_node->getValue()); };
        
    
};


}

#endif