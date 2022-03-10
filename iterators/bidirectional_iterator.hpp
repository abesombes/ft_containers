/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:30:34 by abesombes         #+#    #+#             */
/*   Updated: 2022/03/10 16:33:28 by abesombe         ###   ########.fr       */
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
            self_type &operator++(){ _val++; return (*this);};
            self_type operator++(int){ self_type tmp = *this; ++(*this); return tmp; };
            self_type &operator--(){ _val--; return (*this);};
            self_type operator--(int){ self_type tmp = *this; --*this; return tmp; };
            bool operator==(self_type const & rhs) const { 
                // if (compatible(rhs))
                    return _val == rhs._val; 
            };
            bool operator!=(self_type const & rhs) const { 
                return !(*this == rhs); 
            };
            reference operator*() const { return (this->getValue); };
            pointer operator->() const { return (_val); };
            self_type operator+(difference_type offset) const { return static_cast<self_type>(_val + offset); };
            self_type operator-(difference_type offset) const { return static_cast<self_type>(_val - offset); };
            difference_type operator-(self_type const &rhs) const { return (_val - rhs._val); };
            bool operator<(self_type const &rhs) const {                 
                // if (compatible(rhs))
                    return (_val < rhs._val);  
            };  
            bool operator>(self_type const &rhs) const { return (rhs < *this); };  
            bool operator<=(self_type const & rhs) const { return !(rhs < *this); };
            bool operator>=(self_type const & rhs) const { return !(*this < rhs); };
            self_type & operator+=( difference_type const offset) { _val += offset; return (*this); };
            self_type & operator-=( difference_type const offset) { _val -= offset; return (*this); };
            value_type & operator[]( difference_type const offset ) { return (*(*this + offset)); };
            value_type const & operator[]( difference_type const offset ) const { return (*(*this + offset)); };
    
};

//enables implicit conversion from const to non_const

template <class T>
bool operator==(const random_access_iterator<T, false>& lhs, const random_access_iterator<T, true>& rhs)
{
    return (lhs.getVal() == rhs.getVal());
}
template <class T>
bool operator==(const random_access_iterator<T, true>& lhs, const random_access_iterator<T, false>& rhs)
{
    return (lhs.getVal() == rhs.getVal());
}

template <class T>
bool operator!=(const random_access_iterator<T, false>& lhs, const random_access_iterator<T, true>& rhs)
{
    return (lhs.getVal() != rhs.getVal());
}
template <class T>
bool operator!=(const random_access_iterator<T, true>& lhs, const random_access_iterator<T, false>& rhs)
{
    return (lhs.getVal() != rhs.getVal());
}

template <class T>
bool operator<(const random_access_iterator<T, false>& lhs, const random_access_iterator<T, true>& rhs)
{
    return !(lhs.getVal() >= rhs.getVal());
}
template <class T>
bool operator<(const random_access_iterator<T, true>& lhs, const random_access_iterator<T, false>& rhs)
{
    return !(lhs.getVal() >= rhs.getVal());
}

template <class T>
bool operator<=(const random_access_iterator<T, false>& lhs, const random_access_iterator<T, true>& rhs)
{
    return !(lhs.getVal() > rhs.getVal());
}
template <class T>
bool operator<=(const random_access_iterator<T, true>& lhs, const random_access_iterator<T, false>& rhs)
{
    return !(lhs.getVal() > rhs.getVal());
}

template <class T>
bool operator>(const random_access_iterator<T, false>& lhs, const random_access_iterator<T, true>& rhs)
{
    return !(lhs.getVal() <= rhs.getVal());
}
template <class T>
bool operator>(const random_access_iterator<T, true>& lhs, const random_access_iterator<T, false>& rhs)
{
    return !(lhs.getVal() <= rhs.getVal());
}

template <class T>
bool operator>=(const random_access_iterator<T, false>& lhs, const random_access_iterator<T, true>& rhs)
{
    return !(lhs.getVal() < rhs.getVal());
}
template <class T>
bool operator>=(const random_access_iterator<T, true>& lhs, const random_access_iterator<T, false>& rhs)
{
    return !(lhs.getVal() < rhs.getVal());
}

template <typename T, bool B>
random_access_iterator<T, B> operator+(ptrdiff_t offset, random_access_iterator<T, B> it) { return static_cast<random_access_iterator<T, B> >(it.getVal() + offset); };

template <typename T, bool B>
random_access_iterator<T, B> operator-(ptrdiff_t offset, random_access_iterator<T, B> it) { return static_cast<random_access_iterator<T, B> >(it.getVal() - offset); };

}

#endif