/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 09:54:29 by abesombes         #+#    #+#             */
/*   Updated: 2022/01/23 10:32:30 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF
#define ENABLE_IF

namespace ft{

template <bool B>
struct enable_if {};

template <>
struct enable_if<true> { typedef int type; };

}

#endif