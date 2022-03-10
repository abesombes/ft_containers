/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:30:34 by abesombes         #+#    #+#             */
/*   Updated: 2022/03/10 17:45:10 by abesombe         ###   ########.fr       */
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
            typedef bidirectional_iterator                          self_type;
            typedef typename const_or_not<B, const T&, T&>::type    reference;
            typedef typename const_or_not<B, const T*, T*>::type    pointer;
            typedef ft::bidirectional_iterator_tag                  iterator_category;
            typedef ptrdiff_t                                       difference_type;
            typedef T*                                              elem_pointer;

            typedef Node<const Key, T, Compare>	                    Node;
            typedef Node*                                           NodePtr;
            typedef Key									            key_type;
            typedef Compare                                         key_compare;
            typedef T									            mapped_type;
            typedef ft::pair<const Key, T>				            value_type;
            typedef std::size_t							            size_type;
                
    private:

            NodePtr _node;
            bool    _is_end;
            
    public:        
            bidirectional_iterator( Node* node = NULL, bool is_end = false ): _node(node), _is_end(is_end){};
            bidirectional_iterator( bidirectional_iterator<Key, T, Compare, B> const &src ): _node(src.getNode()), _is_end(src._is_end){};
            bidirectional_iterator &operator=(bidirectional_iterator const &rhs){ this->_node = rhs._node; this->_is_end = rhs._is_end; return (*this); };
            virtual ~bidirectional_iterator(){};
            Node *getNode( void ) { return _node;}
            
            self_type &operator++()
            { 
                Node *tmp = _node->getSuccessor();
                if (!tmp)
                    _is_end = true;
                else
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
                if (!tmp)
                    _is_end = true;
                else
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
                    return _val == rhs._val; 
            };
            bool operator!=(self_type const & rhs) const { 
                return !(*this == rhs); 
            };
            reference operator*() const { return (this->_node->getValue()); };
            pointer operator->() const { return (&this->_node->getValue()); };
        
    
};


}

#endif