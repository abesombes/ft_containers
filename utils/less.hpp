/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:16:43 by abesombes         #+#    #+#             */
/*   Updated: 2022/03/10 22:35:20 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LESS_HPP
#define LESS_HPP

namespace ft{
    
    template <typename T> 
    struct less
    {
        bool operator() (const T& lhs, const T& rhs) const { return (lhs < rhs); }
    };
    
}

#endif