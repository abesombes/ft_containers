/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:30:34 by abesombes         #+#    #+#             */
/*   Updated: 2022/03/25 12:49:49 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP
#include "iterator_traits.hpp"
#include "../utils/const_or_not.hpp"
#include <cstddef>
#include <iostream>

namespace ft{

template <typename T, bool B>
class random_access_iterator
{
    public:
            typedef random_access_iterator                          self_type;
            typedef T                                               value_type;
            typedef typename const_or_not<B, const T&, T&>::type    reference;
            typedef typename const_or_not<B, const T*, T*>::type    pointer;
            typedef ft::random_access_iterator_tag                  iterator_category;
            typedef ptrdiff_t                                       difference_type;
            typedef T*                                              elem_pointer;

            random_access_iterator( void ): _val(NULL){};
            explicit random_access_iterator(elem_pointer val): _val(val){};
            elem_pointer getVal() const { return _val; };
            
            // random_access_iterator( random_access_iterator<T, true> const &src ): _val(src.getVal()){}; // useful to convert implicitly const to non_const
            random_access_iterator( random_access_iterator<T, false> const &src ): _val(src.getVal()){};
            random_access_iterator &operator=(random_access_iterator const &rhs){ this->_val = rhs._val; return (*this); };
            virtual ~random_access_iterator(){};
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
            reference operator*() const { return (*_val); };
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
    
    private:
            T*      _val;
            bool compatible(self_type const &other) const { return (_val == other._val); };
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