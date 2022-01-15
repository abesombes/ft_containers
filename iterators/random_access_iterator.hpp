/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:30:34 by abesombes         #+#    #+#             */
/*   Updated: 2022/01/15 18:21:30 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

namespace ft{

#include "iterator_traits.hpp"
#include <cstddef>

class random_access_iterator_tag {};

template <typename T>
class random_access_iterator
{
    public:
            typedef random_access_iterator      self_type;
            typedef T                           value_type;
            typedef T&                          reference;
            typedef T*                          pointer;
            typedef random_access_iterator_tag  iterator_category;
            typedef ptrdiff_t                   difference_type;
            random_access_iterator( void ): _val(NULL){};
            explicit random_access_iterator(pointer val): _val(val){};
            random_access_iterator( random_access_iterator const &src ): _val(src._val){};
            random_access_iterator &operator=(random_access_iterator const &rhs){ this->_val = rhs._val; return (*this); };
            virtual ~random_access_iterator(){};
            self_type &operator++(){ _val++; return (*this);};
            self_type operator++(T){ self_type tmp = *this; ++*this; return tmp; };
            self_type &operator--(){ _val--; return (*this);};
            self_type operator--(T){ self_type tmp = *this; --*this; return tmp; };
            bool operator==(self_type const & rhs) const { 
                // if (compatible(rhs))
                    return _val == rhs._val; 
            };
            bool operator!=(self_type const & rhs) const { 
                return !(*this == rhs); 
            };
            reference operator*() const { return (*_val); };
            reference operator->() const { return (_val); };
            self_type operator+(difference_type offset) const { return (_val + offset); };
            self_type operator-(difference_type offset) const { return (_val - offset); };
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

}
#endif