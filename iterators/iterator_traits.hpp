/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:00:43 by abesombes         #+#    #+#             */
/*   Updated: 2022/03/10 13:59:12 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

namespace ft{

#include "random_access_iterator.hpp"

// struct bidirectional_iterator_tag : forward_iterator_tag {};
// struct random_access_iterator_tag : bidirectional_iterator_tag {};

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};

template <class Iterator>
struct iterator_traits {
    public: 
                typedef typename Iterator::iterator_category iterator_category;
                typedef typename Iterator::value_type        value_type;
                typedef typename Iterator::difference_type   difference_type;
                typedef typename Iterator::pointer           pointer;
                typedef typename Iterator::reference         reference;
};

template <class T>
struct iterator_traits<T*> {
    public: 
                typedef ft::random_access_iterator_tag iterator_category;
                typedef T                          value_type;
                typedef ptrdiff_t                  difference_type;
                typedef T*                         pointer;
                typedef T&                         reference;
};

template <class T>
struct iterator_traits<const T *>
{
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef const T *pointer;
    typedef const T &reference;
    typedef ft::random_access_iterator_tag iterator_category;
};

}

#endif