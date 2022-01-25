/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_random_access_iterator.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 17:05:11 by abesombe          #+#    #+#             */
/*   Updated: 2022/01/25 14:36:46 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REV_RANDOM_ACCESS_ITERATOR_HPP
#define REV_RANDOM_ACCESS_ITERATOR_HPP

namespace ft{

#include "iterator_traits.hpp"
#include <cstddef>
#include <iostream>

template <typename T>
class rev_random_access_iterator
{
    public:
            typedef rev_random_access_iterator      self_type;
            typedef T                           value_type;
            typedef T&                          reference;
            typedef T*                          pointer;
            typedef ft::random_access_iterator_tag  iterator_category;
            typedef ptrdiff_t                   difference_type;

            rev_random_access_iterator( void ): _val(NULL){};
            explicit rev_random_access_iterator(pointer val): _val(val){};
            rev_random_access_iterator( rev_random_access_iterator const &src ): _val(src._val){};
            rev_random_access_iterator &operator=(rev_random_access_iterator const &rhs){ this->_val = rhs._val; return (*this); };
            virtual ~rev_random_access_iterator(){};
            self_type &operator++(){ _val--; return (*this);};
            self_type operator++(T){ self_type tmp = *this; --(*this); return tmp; };
            self_type &operator--(){ _val++; return (*this);};
            self_type operator--(T){ self_type tmp = *this; ++*this; return tmp; };
            bool operator==(self_type const & rhs) const { 
                // if (compatible(rhs))
                    return _val == rhs._val; 
            };
            bool operator!=(self_type const & rhs) const { 
                return !(*this == rhs); 
            };
            reference operator*() const { return (*_val); };
            pointer operator->() const { return (_val); };
            self_type operator+(difference_type offset) const { return static_cast<self_type>(_val - offset); };
            self_type operator-(difference_type offset) const { return static_cast<self_type>(_val + offset); };
            difference_type operator-(self_type const &rhs) const { return (_val - rhs._val); };
            bool operator<(self_type const &rhs) const {                 
                // if (compatible(rhs))
                    return (_val < rhs._val);  
            };  
            bool operator>(self_type const &rhs) const { return (*this > rhs); };  
            bool operator<=(self_type const & rhs) const { return !(*this < rhs); };
            bool operator>=(self_type const & rhs) const { return !(rhs < *this); };
            self_type & operator+=( difference_type const offset) { _val -= offset; return (*this); };
            self_type & operator-=( difference_type const offset) { _val += offset; return (*this); };
            value_type & operator[]( difference_type const offset ) { return (*(*this - offset)); };
            value_type const & operator[]( difference_type const offset ) const { return (*(*this - offset)); };
    
    private:
            T*      _val;
            bool compatible(self_type const &other) const { return (_val == other._val); };
};

}
#endif