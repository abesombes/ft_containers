/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_bidirectional_iterator.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 09:58:22 by abesombe          #+#    #+#             */
/*   Updated: 2022/03/15 12:33:22 by abesombe         ###   ########.fr       */
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
                
                // if (tmp->isNil())
                if (_node->isSentinel())
                {
                    _node = _node->left;
                    return (*this);
                }
                if (tmp->isSentinel())
                {
                    _node = tmp->getPredecessor()->getPredecessor();
                    return (*this);
                }
                _node = tmp;
                return (*this);
            };
            
            self_type operator--(int)
            { 
                self_type tmp_it(*this);
                
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