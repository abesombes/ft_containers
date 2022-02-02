/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:16:54 by abesombe          #+#    #+#             */
/*   Updated: 2022/02/02 14:19:13 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
#define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft{

template <typename InputIterator1, typename InputIterator2>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
InputIterator2 first2, InputIterator2 last2)
{
    while (first1!=last1)
    {
        if (first2==last2 || *first2<*first1) return false; // is v2 shorter in size than v1 or the elem of v2 < elem v1? if yes return false
        else if (*first1<*first2) return true; // otherwise if elem of v2 > elem of v1, return true 
        ++first1; ++first2; // otherwise, it means v2 is large enough to provide an element at this point and this elem is strictly equal to v1's element.
    }
    return (first2!=last2); // we checked all elements so far > they are all equal. Now the last point to check is to see if v2 is larger in size than v1
}

}

#endif