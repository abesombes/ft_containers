/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_or_not.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:47:40 by abesombes         #+#    #+#             */
/*   Updated: 2022/01/27 11:53:43 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_OR_NOT_HPP
#define CONST_OR_NOT_HPP

namespace ft{

   template <bool flag, typename isTrue, typename isFalse>
   struct const_or_not {};

   template <typename isTrue, typename isFalse>
   struct const_or_not<true, isTrue, isFalse> {
       typedef isTrue type;     
   };

   template <typename isTrue, typename isFalse>
   struct const_or_not<false, isTrue, isFalse> {
      typedef isFalse type;
   };
}

#endif