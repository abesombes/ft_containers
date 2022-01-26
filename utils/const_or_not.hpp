/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_or_not.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:47:40 by abesombes         #+#    #+#             */
/*   Updated: 2022/01/27 00:19:32 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_OR_NOT_HPP
#define CONST_OR_NOT_HPP

namespace ft{

   template <bool flag, typename isFalse, typename isTrue>
   struct const_or_not {};

   template <typename isFalse, typename isTrue>
   struct const_or_not<true, isFalse, isTrue> {
      typedef isFalse type;
   };

   template <typename isFalse, typename isTrue>
   struct const_or_not<false, isFalse, isTrue> {
      typedef isTrue type;
   };
}

#endif