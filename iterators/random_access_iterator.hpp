/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:30:34 by abesombes         #+#    #+#             */
/*   Updated: 2022/01/08 00:38:08 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator_traits.hpp"
#include <cstddef>

template <typename T, size_t const Size>
class random_access_iterator
{
    public:
            typedef random_access_iterator      self_type;
            typedef T                           value_type;
            typedef T&                          reference;
            typedef T*                          pointer;
            typedef random_access_iterator_tag  iterator_category;
            typedef ptrdiff_t                   difference_type;
            random_access_iterator( void ): _val(nullptr){};
            explicit random_access_iterator(pointer val): _val(val){};
            random_access_iterator( random_access_iterator const &src ): _val(src._val){};
            random_access_iterator &operator=(random_access_iterator const &rhs){ this._val = rhs._val; return (*this); };
            virtual ~random_access_iterator(){};
            self_type &operator++(){ _elem++; return (*this);};
            self_type operator++(T){ self_type tmp = *this; ++*this; return tmp; };
            self_type &operator--(){ _elem--; return (*this);};
            self_type operator--(T){ self_type tmp = *this; --*this; return tmp; };
            bool operator==(self_type const & rhs) const { 
                if (compatible(rhs))
                    return _val == rhs._val; 
            };
            bool operator!=(self_type const & rhs) const { 
                return !(*this == rhs); 
            };
            reference operator*() const { return (*_elem); };
            reference operator->() const { return (_elem); };
            self_type operator+(difference_type offset) const { return (_val + offset); };
            self_type operator-(difference_type offset) const { return (_val - offset); };
            difference_type operator-(self_type const &rhs) const { return (_val - rhs._val); };
            bool operator<(self_type const &rhs) const {                 
                if (compatible(rhs))
                    return (_val < rhs._val);  
            };  
            bool operator>(self_type const &rhs) const { return (other < *this); };  
            
    
    private:
            T*      _val;
            bool compatible(self_type const &other) const { return (ptr == other.ptr); };
}

#endif