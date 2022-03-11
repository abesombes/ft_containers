/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 09:59:19 by abesombes         #+#    #+#             */
/*   Updated: 2022/03/11 18:15:37 by abesombe         ###   ########.fr       */
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
#include "iterators/rev_bidirectional_iterator.hpp"
#include <cstddef>
#include <stdexcept>
#include "utils/enable_if.hpp"
#include "utils/is_integral.hpp"
#include "utils/const_or_not.hpp"
#include "utils/less.hpp"
#include "utils/node.hpp"
#include "utils/red_black_tree.hpp"

namespace ft{

	template <class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
	class map {

		public:
					typedef ft::pair<const Key, T>									value_type;
					typedef Key														key_type;
					typedef T														mapped_type;
					typedef Compare													key_compare;
					typedef Alloc                   								allocator_type;
					typedef Node<const Key, T, Compare, Alloc>						node_type;
					typedef typename allocator_type::reference 						reference;
					typedef typename allocator_type::const_reference 				const_reference;
					typedef typename allocator_type::pointer 						pointer;
					typedef typename allocator_type::const_pointer 					const_pointer;
					typedef typename value_type::bidirectional_iterator 			iterator;
					typedef typename value_type::bidirectional_const_iterator 		const_iterator;
					typedef typename value_type::rev_bidirectional_iterator 		reverse_iterator;
					typedef typename value_type::rev_bidirectional_const_iterator 	const_reverse_iterator;
					typedef ptrdiff_t 												difference_type;
					typedef size_t 													size_type;
					typedef typename Alloc::template rebind<node_type>::other 		node_allocator;
					typedef	RBTree<const Key, T, Compare, Alloc> 					RBTree;
					
					
		private:
					key_compare 	_cmp;
					node_allocator 	_mem_node_alloc;
					Alloc          	_pair_alloc;
					RBTree			_RBTree;

					// typedef typename iterator_traits<iterator>::difference_type difference_type;
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

                    /*
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    Map: Constructors
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    */

				   	/*
                    ----------------------------------------------------------------------------------------------------
                    Map: Default Constructor
                    ----------------------------------------------------------------------------------------------------
					Constructs an empty container, with no elements.
                    */
				   	
					explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _cmp(comp), _pair_alloc(alloc) {}
				   	
					/*
                    ----------------------------------------------------------------------------------------------------
                    Map: Range Constructor
                    ----------------------------------------------------------------------------------------------------
					Constructs a container with as many elements as the range [first,last), with each element 
					constructed from its corresponding element in that range.
                    */

					template <class InputIterator>
					map (InputIterator first, InputIterator last,
						const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type()): _cmp(comp), _pair_alloc(alloc) { this->insert(first, last); };


				   	/*
                    ----------------------------------------------------------------------------------------------------
                    Map: Copy Constructor
                    ----------------------------------------------------------------------------------------------------
					Constructs a container with a copy of each of the elements in x.
                    */
				   
					map (const map& x);


                    /*
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    Map: Destructor
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    */

				   	/*
                    ----------------------------------------------------------------------------------------------------
                    Map: Destructor
                    ----------------------------------------------------------------------------------------------------
					Destroys the container object.
					This destroys all container elements, and deallocates all the storage capacity allocated by the map 
					container using its allocator.
                    */		

					~map(){};
				   		   
                    /*
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    Map: Iterators
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    */

				   	/*
                    ----------------------------------------------------------------------------------------------------
                    BEGIN - Return iterator to beginning
                    ----------------------------------------------------------------------------------------------------
                    Returns an iterator referring to the first element in the map container. Because map containers keep
					their elements ordered at all times, begin points to the element that goes first following the 
					container's sorting criterion. If the container is empty, the returned iterator value shall not be 
					dereferenced.
                    */

					iterator begin() { return (iterator(_RBTree->_sentinel->left)); };
					const_iterator begin() const { return (iterator(_RBTree->_sentinel->left)); };

				   	/*
                    ----------------------------------------------------------------------------------------------------
                    END - Return iterator to end
                    ----------------------------------------------------------------------------------------------------
                    Returns an iterator referring to the past-the-end element in the map container.
					The past-the-end element is the theoretical element that would follow the last element in the map 
					container. It does not point to any element, and thus shall not be dereferenced. Because the ranges 
					used by functions of the standard library do not include the element pointed by their closing 
					iterator, this function is often used in combination with map::begin to specify a range including 
					all the elements in the container. If the container is empty, this function returns the same as 
					map::begin.
                    */

					iterator end() { return (iterator(_RBTree->_sentinel->right)); };
					const_iterator end() const { return (iterator(_RBTree->_sentinel->right)); };

				   	/*
                    ----------------------------------------------------------------------------------------------------
                    RBEGIN - Return reverse iterator to reverse beginning
                    ----------------------------------------------------------------------------------------------------
					Returns a reverse iterator pointing to the last element in the container (i.e., its reverse 
					beginning). Reverse iterators iterate backwards: increasing them moves them towards the beginning of
					the container. rbegin points to the element preceding the one that would be pointed to by member end.
                    */

					reverse_iterator rbegin() { return (reverse_iterator(_RBTree->_sentinel->right)); };
					const_reverse_iterator rbegin() const { return (reverse_iterator(_RBTree->_sentinel->right)); };

				    /*
                    ----------------------------------------------------------------------------------------------------
                    REND - Return reverse iterator to reverse end
                    ----------------------------------------------------------------------------------------------------
					Returns a reverse iterator pointing to the theoretical element right before the first element in the
					map container (which is considered its reverse end). The range between map::rbegin and map::rend 
					contains all the elements of the container (in reverse order).
                    */
				   	reverse_iterator rend() { return (reverse_iterator(_RBTree->_sentinel)); };
					const_reverse_iterator rend() const { return (reverse_iterator(_RBTree->_sentinel)); };

	   				   				
                    /*
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    Map: Capacity Functions
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    */

				   	/*
                    ----------------------------------------------------------------------------------------------------
                    SIZE - Change Return container size
                    ----------------------------------------------------------------------------------------------------
                    Returns the number of elements in the map container.
                    */
		
				   	size_type size() const { return (_RBTree->getSize()); };

		
	};

}

#endif