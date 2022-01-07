/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:25:50 by abesombe          #+#    #+#             */
/*   Updated: 2022/01/07 15:40:31 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <iostream>
#include <cstddef>

namespace ft{

template <class T, class Alloc = std::allocator<T> >
class Vector {
    typedef T value_type;
    typedef Alloc allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
    typedef typename ft::vector_iterator<T, false> iterator;
    typedef typename ft::vector_iterator<T, true> const_iterator;
    typedef typename ft::vector_iterator<T, false> reverse_iterator;
    typedef typename ft::vector_iterator<T, true> const_reverse_iterator;
    typedef typename ptrdiff_t difference_type;
    typedef typename size_t size_type;

    
    
}


}


#endif