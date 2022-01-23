/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 10:03:34 by abesombes         #+#    #+#             */
/*   Updated: 2022/01/23 10:34:10 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

namespace ft{

template <typename T>
struct is_integral { static const bool value = false; };

template <>
struct is_integral<bool> { static const bool value = true; };

template <>
struct is_integral<char> { static const bool value = true; };

template <>
struct is_integral<wchar_t> { static const bool value = true; };

template <>
struct is_integral<short> { static const bool value = true; };

template <>
struct is_integral<int> { static const bool value = true; };

template <>
struct is_integral<long> { static const bool value = true; };

template <>
struct is_integral<long long> { static const bool value = true; };

template <>
struct is_integral<unsigned short> { static const bool value = true; };

template <>
struct is_integral<unsigned int> { static const bool value = true; };

template <>
struct is_integral<unsigned long> { static const bool value = true; };

template <>
struct is_integral<unsigned long long> { static const bool value = true; };

}

#endif