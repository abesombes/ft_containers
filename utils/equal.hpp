/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:57:00 by abesombe          #+#    #+#             */
/*   Updated: 2022/03/27 17:59:30 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL
#define EQUAL

namespace ft {

    template <class InputIterator1, class InputIterator2>
    bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
    {
    while (first1!=last1) {
        if (!(*first1 == *first2))
        return false;
        ++first1; ++first2;
    }
    return true;
    }

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal (InputIterator1 first1, InputIterator1 last1,
                InputIterator2 first2, BinaryPredicate pred)
    {
        while (first1!=last1) {
        if (!pred(*first1 == *first2))
        return false;
        ++first1; ++first2;
    }
    return true;
        
    }

}

#endif