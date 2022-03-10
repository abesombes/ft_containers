/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 09:59:19 by abesombes         #+#    #+#             */
/*   Updated: 2022/03/10 16:42:46 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include <memory>
#include <iostream>
#include <cstddef>
#include <limits>
#include <algorithm>
#include "iterators/bidirectional_iterator.hpp"
// #include "iterators/rev_bidirectional_iterator.hpp"
#include <cstddef>
#include <stdexcept>
#include "utils/enable_if.hpp"
#include "utils/is_integral.hpp"
#include "utils/const_or_not.hpp"
#include "utils/less.hpp"

namespace ft{

template <class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<pair<const Key,T> > 
class map {

    public:
                typedef ft::pair<const Key, T> value_type;
                typedef Key key_type;
                typedef T   mapped_type;
                typedef Compare key_compare;
                typedef Alloc allocator_type;
                typedef typename allocator_type::reference reference;
                typedef typename allocator_type::const_reference const_reference;
                typedef typename allocator_type::pointer pointer;
                typedef typename allocator_type::const_pointer const_pointer;
                typedef typename value_type::bidirectional_iterator iterator;
                typedef typename value_type::bidirectional_const_iterator const_iterator;
                typedef typename value_type::rev_bidirectional_iterator reverse_iterator;
                typedef typename value_type::rev_bidirectional_const_iterator const_reverse_iterator;
                // typedef typename iterator_traits<iterator>::difference_type difference_type;
                typedef typename ptrdiff_t difference_type;
                typedef size_t size_type;

                typedef typename Alloc::template rebind<_node>::other node_allocator;

                node_allocator _mem_node_alloc;
                Alloc          _pair_alloc;

                
                /*
                ----------------------------------------------------------------------------------------------------
                Member functions
                ----------------------------------------------------------------------------------------------------
                (constructor) - Construct map (public member function )
                (destructor) - Map destructor (public member function )
                operator= - Copy container content (public member function )

                ----------------------------------------------------------------------------------------------------
                Iterators:
                ----------------------------------------------------------------------------------------------------
                begin - Return iterator to beginning (public member function )
                end - Return iterator to end (public member function )
                rbegin - Return reverse iterator to reverse beginning (public member function )
                rend - Return reverse iterator to reverse end (public member function )

                ----------------------------------------------------------------------------------------------------
                Capacity:
                ----------------------------------------------------------------------------------------------------
                empty - Test whether container is empty (public member function )
                size - Return size (public member function )
                max_size - Return maximum size (public member function )

                ----------------------------------------------------------------------------------------------------
                Element access:
                ----------------------------------------------------------------------------------------------------
                operator[] - Access element (public member function )

                ----------------------------------------------------------------------------------------------------
                Modifiers:
                ----------------------------------------------------------------------------------------------------
                insert - Insert elements (public member function )
                erase - Erase elements (public member function )
                swap - Swap content (public member function )
                clear - Clear content (public member function )

                ----------------------------------------------------------------------------------------------------
                Observers:
                ----------------------------------------------------------------------------------------------------
                key_comp - Return key comparison object (public member function )
                value_comp - Return value comparison object (public member function )
                
                ----------------------------------------------------------------------------------------------------
                Operations:
                ----------------------------------------------------------------------------------------------------
                find - Get iterator to element (public member function )
                count - Count elements with a specific key (public member function )
                lower_bound - Return iterator to lower bound (public member function )
                upper_bound - Return iterator to upper bound (public member function )
                equal_range - Get range of equal elements (public member function )
                
                ----------------------------------------------------------------------------------------------------
                Allocator:
                ----------------------------------------------------------------------------------------------------
                get_allocator - Get allocator (public member function )
                
                */

    private:
    
    
};

}

#endif