/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:00:43 by abesombes         #+#    #+#             */
/*   Updated: 2022/01/08 18:58:14 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

namespace ft{

#include "random_access_iterator.hpp"

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
                typedef std::random_access_iterator_tag iterator_category; // attention a rechanger en enlevant std::
                typedef T                          value_type;
                typedef ptrdiff_t                  difference_type;
                typedef T*                         pointer;
                typedef T&                         reference;
};

}

#endif