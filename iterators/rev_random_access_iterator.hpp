/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_random_access_iterator.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:05:11 by abesombe          #+#    #+#             */
/*   Updated: 2022/01/28 23:49:16 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REV_RANDOM_ACCESS_ITERATOR_HPP
#define REV_RANDOM_ACCESS_ITERATOR_HPP
#include "iterator_traits.hpp"
#include "../utils/const_or_not.hpp"
#include "random_access_iterator.hpp"
#include <cstddef>
#include <iostream>

namespace ft{

template <typename T, bool B>
class rev_random_access_iterator
{
    public:
            typedef rev_random_access_iterator                      self_type;
            typedef random_access_iterator<T, B>                    iterator;
            typedef T                                               value_type;
            typedef typename const_or_not<B, const T&, T&>::type    reference;
            typedef typename const_or_not<B, const T*, T*>::type    pointer;
            typedef ft::random_access_iterator_tag                  iterator_category;
            typedef ptrdiff_t                                       difference_type;
            typedef T*                                              elem_pointer;

            rev_random_access_iterator( void ): _val(NULL){};
            elem_pointer getVal() const { return _val; };
            explicit rev_random_access_iterator(elem_pointer val): _val(val){};
            explicit rev_random_access_iterator (iterator it): _val(it.getVal() - 1) {}
            iterator base() const { return (iterator(&(*(_val + 1)))); };
            rev_random_access_iterator( rev_random_access_iterator<T, true> const &src ): _val(src.getVal()){};
            rev_random_access_iterator( rev_random_access_iterator<T, false> const &src ): _val(src.getVal()){};
            rev_random_access_iterator &operator=(rev_random_access_iterator<T, false> const &rhs){ this->_val = rhs.getVal(); return (*this); };
            virtual ~rev_random_access_iterator(){};
            self_type &operator++(){ _val--; return (*this);};
            self_type operator++(int){ self_type tmp = *this; ++(*this); return tmp; };
            self_type &operator--(){ _val++; return (*this);};
            self_type operator--(int){ self_type tmp = *this; --(*this); return tmp; };
            bool operator==(self_type const & rhs) const { return _val == rhs._val; };
            bool operator!=(self_type const & rhs) const { return !(*this == rhs); };
            reference operator*() const { return (*_val); };
            pointer operator->() const { return (_val); };
            self_type operator+(difference_type offset) const { return static_cast<self_type>(_val - offset); };
            self_type operator-(difference_type offset) const { return static_cast<self_type>(_val + offset); };
            difference_type operator-(self_type &rhs) const { return (rhs._val - _val); };
            difference_type operator-(self_type const &rhs) const { return (rhs._val - _val); };
            bool operator<(self_type const &rhs) const { return (_val > rhs.getVal()); };  
            bool operator>(self_type const &rhs) const { return (_val < rhs.getVal()); };  
            bool operator<=(self_type const & rhs) const { return (_val >= rhs.getVal()); };
            bool operator>=(self_type const & rhs) const { return (_val <= rhs.getVal()); };
            self_type & operator+=( difference_type const offset) { _val -= offset; return (*this); };
            self_type & operator-=( difference_type const offset) { _val += offset; return (*this); };
            value_type & operator[]( difference_type const offset ) { return (*(*this + offset)); };
            value_type const & operator[]( difference_type const offset ) const { return (*(*this + offset)); };
    
    private:
            T*      _val;
            bool compatible(self_type const &other) const { return (_val == other._val); };
};

template <typename T, bool B>
rev_random_access_iterator<T, B> operator+(ptrdiff_t offset, rev_random_access_iterator<T, B> it) { return static_cast<rev_random_access_iterator<T, B> >(it.getVal() - offset); };


template <typename T, bool B>
rev_random_access_iterator<T, B> operator-(ptrdiff_t offset, rev_random_access_iterator<T, B> it) { return static_cast<rev_random_access_iterator<T, B> >(it.getVal() + offset); };

// template <typename T, bool B>
// rev_random_access_iterator<T, B> operator-(rev_random_access_iterator<T, B> ita, rev_random_access_iterator<T, B> itb) { return static_cast<rev_random_access_iterator<T, B> >(ita.getVal() + itb.getVal()); };
// template <typename T, bool B>
// bool operator< (const rev_random_access_iterator<T, B>& lhs, const rev_random_access_iterator<T, B>& rhs)
// {
//     return (lhs.getVal() > rhs.getVal());
// }


}
#endif