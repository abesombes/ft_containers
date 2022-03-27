/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 09:59:19 by abesombes         #+#    #+#             */
/*   Updated: 2022/03/27 16:21:31 by abesombe         ###   ########.fr       */
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
#include "utils/lexicographical_compare.hpp"
#include "utils/pair.hpp"

namespace ft{

	template <class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
	class map {

		public:
					typedef ft::pair<const Key, T>										value_type;
					typedef Key															key_type;
					typedef T															mapped_type;
					typedef Compare														key_compare;
					typedef Alloc                   									allocator_type;
					typedef Node<const Key, T, Compare, Alloc>							node_type;
					typedef typename allocator_type::reference 							reference;
					typedef typename allocator_type::const_reference 					const_reference;
					typedef typename allocator_type::pointer 							pointer;
					typedef typename allocator_type::const_pointer 						const_pointer;
					typedef bidirectional_iterator<const Key, T, Compare>				iterator;
					typedef bidirectional_iterator<const Key, T, Compare, true> 		const_iterator;
					typedef rev_bidirectional_iterator<const Key, T, Compare>			reverse_iterator;
					typedef rev_bidirectional_iterator<const Key, T, Compare, true> 	const_reverse_iterator;
					typedef ptrdiff_t 													difference_type;
					typedef size_t 														size_type;
					typedef typename Alloc::template rebind<node_type>::other 			node_allocator;
					typedef	RBTree<const Key, T, Compare, Alloc> 						RBTree;
					
					
		private:
					key_compare 	_cmp;
					node_allocator 	_mem_node_alloc;
					Alloc          	_pair_alloc;
					RBTree			_RBTree;

		public:
      			class value_compare: public std::binary_function<value_type, value_type, bool>
      			{
					friend class map<Key, T, Compare, Alloc>;
      				protected:
								key_compare comp;
								value_compare(key_compare c) : comp(c) { }

      				public:
								bool operator()(const value_type& lhs, const value_type& rhs) const { return comp(lhs.first, rhs.first); }
      			};

		public:
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
					Constructs a container with a copy of each of the elements in src.
                    */
				   
					map (const map& src): _cmp(src._cmp), _mem_node_alloc(src._mem_node_alloc), _pair_alloc(src._pair_alloc)
					{
						this->insert(src.begin(), src.end());
					};

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

					~map(){
						_RBTree.clear();
                    	_RBTree.deleteNode(_RBTree.getNil());
                    	_RBTree.deleteNode(_RBTree.getSentinel());
					};

					/*
                    ----------------------------------------------------------------------------------------------------
                    Operator()
                    ----------------------------------------------------------------------------------------------------
                    */

					map	&operator=( const map& rhs )
					{
						this->_cmp = rhs._cmp;
						this->_pair_alloc = rhs._pair_alloc;
						clear();
						insert(rhs.begin(), rhs.end());
						return *this;
					}

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

					iterator begin() { return (size()? iterator(_RBTree.getSentinel()->left) : iterator(_RBTree.getNil())); };
					const_iterator begin() const { return (size()? const_iterator(_RBTree.getSentinel()->left) : const_iterator(_RBTree.getNil())); };

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

					iterator end() { return (size() ? iterator(_RBTree.getSentinel()) : iterator(_RBTree.getNil())); };
					const_iterator end() const { return (size() ? const_iterator(_RBTree.getSentinel()) : const_iterator(_RBTree.getNil())); };

				   	/*
                    ----------------------------------------------------------------------------------------------------
                    RBEGIN - Return reverse iterator to reverse beginning
                    ----------------------------------------------------------------------------------------------------
					Returns a reverse iterator pointing to the last element in the container (i.e., its reverse 
					beginning). Reverse iterators iterate backwards: increasing them moves them towards the beginning of
					the container. rbegin points to the element preceding the one that would be pointed to by member end.
                    */

					reverse_iterator rbegin() { return (reverse_iterator(_RBTree.getSentinel()->right)); };
					const_reverse_iterator rbegin() const { return (const_reverse_iterator(_RBTree.getSentinel()->right)); };

				    /*
                    ----------------------------------------------------------------------------------------------------
                    REND - Return reverse iterator to reverse end
                    ----------------------------------------------------------------------------------------------------
					Returns a reverse iterator pointing to the theoretical element right before the first element in the
					map container (which is considered its reverse end). The range between map::rbegin and map::rend 
					contains all the elements of the container (in reverse order).
                    */
				   	reverse_iterator rend() { return (reverse_iterator(_RBTree.getSentinel())); };
					const_reverse_iterator rend() const { return (const_reverse_iterator(_RBTree.getSentinel())); };

	   				   				
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
                    EMPTY - Test whether container is empty
                    ----------------------------------------------------------------------------------------------------
					Returns whether the map container is empty (i.e. whether its size is 0).
					This function does not modify the container in any way. To clear the content of a map container, see
					map::clear.
                    */

				   	bool empty() const { return (!_RBTree.getSize()); };

				   	/*
                    ----------------------------------------------------------------------------------------------------
                    SIZE - Return container size
                    ----------------------------------------------------------------------------------------------------
					Returns the number of elements in the map container.
                    */

					size_type size() const { return (_RBTree.getSize()); };


				   	/*
                    ----------------------------------------------------------------------------------------------------
                    MAX_SIZE - Return maximum size
                    ----------------------------------------------------------------------------------------------------
					Returns the maximum number of elements that the map container can hold. This is the maximum 
					potential size the container can reach due to known system or library implementation limitations, 
					but the container is by no means guaranteed to be able to reach that size: it can still fail to 
					allocate storage at any point before that size is reached.
                    */
				   
					size_type max_size() const { return (_mem_node_alloc.max_size()); };


				    /*
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    Map: Element Access
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    */

				   	/*
                    ----------------------------------------------------------------------------------------------------
                    Operator[] Overload - Access element
                    ----------------------------------------------------------------------------------------------------
                    If k matches the key of an element in the container, the function returns a reference to its mapped 
					value. If k does not match the key of any element in the container, the function inserts a new 
					element with that key and returns a reference to its mapped value. Notice that this always increases
					the container size by one, even if no mapped value is assigned to the element (the element is 
					constructed using its default constructor). A similar member function, map::at, has the same 
					behavior when an element with the key exists, but throws an exception when it does not.
                    */

					mapped_type& operator[] (const key_type& key) { return((*((this->insert(ft::make_pair(key,mapped_type()))).first)).second); };
					

				    /*
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    Map: Modifiers
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    */


				   	/*
                    ----------------------------------------------------------------------------------------------------
                    INSERT - Insert elements
                    ----------------------------------------------------------------------------------------------------
					Extends the container by inserting new elements, effectively increasing the container size by the 
					number of elements inserted. Because element keys in a map are unique, the insertion operation 
					checks whether each inserted element has a key equivalent to the one of an element already in the 
					container, and if so, the element is not inserted, returning an iterator to this existing element 
					(if the function returns a value). An alternative way to insert elements in a map is by using member
					function map::operator[]. Internally, map containers keep all their elements sorted by their key 
					following the criterion specified by its comparison object. The elements are always inserted in its
					respective position following this ordering.                    
					*/

					ft::pair<iterator,bool> insert (const value_type& val)
					{
						bool 			wasInserted = false;
						iterator		inserted = _RBTree.insertValue(val, wasInserted);

						return (ft::make_pair(iterator(inserted), wasInserted));
					}


					iterator insert (iterator position, const value_type& val)
					{
						bool 			wasInserted = false;
						(void)position;
						iterator		inserted = _RBTree.insertValue(val, wasInserted);

						return (inserted);
					}
					
					template <class InputIterator>
					void insert (InputIterator first, InputIterator last)
					{
						bool 			wasInserted = false;
						while (first != last)
							_RBTree.insertValue(*first++, wasInserted);
					}

				   	/*
                    ----------------------------------------------------------------------------------------------------
                    erase - Erase elements
                    ----------------------------------------------------------------------------------------------------
                    Removes from the map container either a single element or a range of elements ([first,last)).
					This effectively reduces the container size by the number of elements removed, which are destroyed.
                	*/

					void erase (iterator position)
					{
						_RBTree.removeNode(position.getNode(), position.getNode()->value.first);
					}
					
					size_type erase (const key_type& key)
					{
						return((_RBTree.removeNode(_RBTree.searchNode(_RBTree.getRoot(), key), key)));
					}

					void erase (iterator first, iterator last)
					{
						while (first != last)
							erase(first++);
					}

					/*
                    ----------------------------------------------------------------------------------------------------
                    swap - Swap content
                    ----------------------------------------------------------------------------------------------------
					Exchanges the content of the container by the content of x, which is another map of the same type. 
					Sizes may differ. After the call to this member function, the elements in this container are those 
					which were in x before the call, and the elements of x are those which were in this. All iterators, 
					references and pointers remain valid for the swapped objects. Notice that a non-member function 
					exists with the same name, swap, overloading that algorithm with an optimization that behaves like 
					this member function.
                	*/

					void swap (map& rhs)
					{
						node_allocator 	_tmp_mem_node_alloc = rhs._mem_node_alloc;
						Alloc          	_tmp_pair_alloc = rhs._pair_alloc;

						rhs._mem_node_alloc = this->_mem_node_alloc;
						rhs._pair_alloc = this->_pair_alloc;
						_mem_node_alloc = _tmp_mem_node_alloc;
						_pair_alloc = _tmp_pair_alloc;
						_RBTree.swap(rhs._RBTree);
					}

					/*
                    ----------------------------------------------------------------------------------------------------
                    clear - Clear content
                    ----------------------------------------------------------------------------------------------------
					Removes all elem from the map container (which are destroyed), leaving the container with size of 0.
                	*/

					void clear() { _RBTree.clear(); };

				    /*
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    Map: Observers
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    */

				   	/*
                    ----------------------------------------------------------------------------------------------------
                    key_comp - Return key comparison object
                    ----------------------------------------------------------------------------------------------------
                    Returns a copy of the comparison object used by the container to compare keys.

					The comparison object of a map object is set on construction. Its type (member key_compare) is the 
					third template parameter of the map template. By default, this is a less object, which returns the 
					same as operator<. This object determines the order of the elements in the container: it is a 
					function pointer or a function object that takes two arguments of the same type as the element keys, 
					and returns true if the first argument is considered to go before the second in the strict weak 
					ordering it defines, and false otherwise. Two keys are considered equivalent if key_comp returns 
					false reflexively (i.e., no matter the order in which the keys are passed as arguments).
                	*/
				
				   	key_compare key_comp() const { return (key_compare()); };

				   	/*
                    ----------------------------------------------------------------------------------------------------
                    value_comp - Return value comparison object
                    ----------------------------------------------------------------------------------------------------
					Returns a comparison object that can be used to compare two elements to get whether the key of the 
					first one goes before the second. The arguments taken by this function object are of member type 
					value_type (defined in map as an alias of pair<const key_type,mapped_type>), but the mapped_type 
					part of the value is not taken into consideration in this comparison. The comparison object returned
					is an object of the member type map::value_compare, which is a nested class that uses the internal 
					comparison object to generate the appropriate comparison functional class.
                	*/
				
					value_compare value_comp() const { return value_compare(key_comp()); };

				    /*
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    Map: Operations
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    */
				   
   				   	/*
                    ----------------------------------------------------------------------------------------------------
                    find - Get iterator to element
                    ----------------------------------------------------------------------------------------------------
					Searches the container for an element with a key equivalent to k and returns an iterator to it if 
					found, otherwise it returns an iterator to map::end. Two keys are considered equivalent if the 
					container's comparison object returns false reflexively (i.e., no matter the order in which the 
					elements are passed as arguments). Another member function, map::count, can be used to just check 
					whether a particular key exists.
                	*/
				
					iterator find (const key_type& key)
					{
						node_type* tmp = _RBTree.searchNode(_RBTree.getRoot(), key);
						if (tmp->isNil())
							return (iterator(_RBTree.getNil()));
						else
							return (iterator(_RBTree.searchNode(_RBTree.getRoot(), key)));
					}
					
					const_iterator find (const key_type& key) const
					{
						node_type* tmp = _RBTree.searchNode(_RBTree.getRoot(), key);
						if (tmp->isNil())
							return (const_iterator(_RBTree.getNil()));
						else
							return (const_iterator(_RBTree.searchNode(_RBTree.getRoot(), key)));				
					}

				   	/*
                    ----------------------------------------------------------------------------------------------------
                    count - Count elements with a specific key
                    ----------------------------------------------------------------------------------------------------
					Searches the container for elements with a key equivalent to k and returns the number of matches.
					Because all elements in a map container are unique, the function can only return 1 (if the element 
					is found) or zero (otherwise). Two keys are considered equivalent if the container's comparison 
					object returns false reflexively (i.e., no matter the order in which the keys are passed as 
					arguments).
                	*/
				
					size_type count (const key_type& key) const
					{
						return(_RBTree.searchNode(_RBTree.getRoot(), key)->isNil() ? 0 : 1);
					}

				   	/*
                    ----------------------------------------------------------------------------------------------------
                    lower_bound - Return iterator to lower bound
                    ----------------------------------------------------------------------------------------------------
					Returns an iterator pointing to the first element in the container whose key is not considered to go
					before k (i.e., either it is equivalent or goes after). The function uses its internal comparison 
					object (key_comp) to determine this, returning an iterator to the first element for which 
					key_comp(element_key,k) would return false. If the map class is instantiated with the default 
					comparison type (less), the function returns an iterator to the first element whose key is not less 
					than the argument key. A similar member function, upper_bound, has the same behavior as lower_bound, 
					except in the case that the map contains an element with a key equivalent to k: In this case, 
					lower_bound returns an iterator pointing to that element, whereas upper_bound returns an iterator 
					pointing to the next element.
                	*/
				
					iterator lower_bound (const key_type& key)
					{
						iterator beg = this->begin();
						iterator end = this->end();

						if (this->_cmp(key, beg->first) || (!_cmp(beg->first, key) && !_cmp(key, beg->first)))
							return (beg);
						beg++;
						while (beg != end && _cmp(beg->first, key))
							beg++;
						return (beg);
					}
					
					const_iterator lower_bound (const key_type& key) const
					{
						const_iterator beg = this->begin();
						const_iterator end = this->end();
			
						if (this->_cmp(key, beg->first) || (!_cmp(beg->first, key) && !_cmp(key, beg->first)))
							return (beg);
						beg++;
						while (beg != end && _cmp(beg->first, key))
							beg++;
						return (beg);
					}

				   	/*
                    ----------------------------------------------------------------------------------------------------
                    upper_bound - Return iterator to upper bound
                    ----------------------------------------------------------------------------------------------------
					Returns an iterator pointing to the first element in the container whose key is considered to go 
					after k. The function uses its internal comparison object (key_comp) to determine this, returning an
					iterator to the first element for which key_comp(k,element_key) would return true. If the map class 
					is instantiated with the default comparison type (less), the function returns an iterator to the 
					first element whose key is greater than k. A similar member function, lower_bound, has the same 
					behavior as upper_bound, except in the case that the map contains an element with a key equivalent 
					to k: In this case lower_bound returns an iterator pointing to that element, whereas upper_bound 
					returns an iterator pointing to the next element.
                	*/
				
					iterator upper_bound (const key_type& key)
					{
						iterator beg = this->begin();
						iterator end = this->end();

						if (this->_cmp(key, beg->first))
							return (beg);
						beg++;
						while (beg != end && (_cmp(beg->first, key) || (!_cmp(beg->first, key) && !_cmp(key, beg->first))))
							beg++;
						return (beg);
					}
					
					const_iterator upper_bound (const key_type& key) const
					{
						const_iterator beg = this->begin();
						const_iterator end = this->end();

						if (this->_cmp(key, beg->first))
							return (beg);
						beg++;
						while (beg != end && (_cmp(beg->first, key) || (!_cmp(beg->first, key) && !_cmp(key, beg->first))))
							beg++;
						return (beg);
					}



				   	/*
                    ----------------------------------------------------------------------------------------------------
                    equal_range - Get range of equal elements
                    ----------------------------------------------------------------------------------------------------
					Returns the bounds of a range that includes all the elements in the container which have a key 
					equivalent to k. Because the elements in a map container have unique keys, the range returned will 
					contain a single element at most. If no matches are found, the range returned has a length of zero, 
					with both iterators pointing to the first element that has a key considered to go after k according
					to the container's internal comparison object (key_comp). Two keys are considered equivalent if the 
					container's comparison object returns false reflexively (i.e., no matter the order in which the keys
					are passed as arguments).
                	*/
					
					ft::pair<const_iterator, const_iterator> equal_range (const key_type& key) const
					{
						// const_iterator beg = this->begin();
						// const_iterator end = this->end();

						// if (this->_cmp(key, beg->first))
						// 	return (ft::make_pair(beg, ++beg));
						// beg++;
						// while (beg != end && _cmp(beg->first, key))
						// 	beg++;
						// if (!(!_cmp(beg->first, key) && !_cmp(key, beg->first)))
						// 	return (ft::make_pair(beg, beg));
						// return (ft::make_pair(beg, ++beg));
						const_iterator lb = lower_bound(key);
						const_iterator ub = upper_bound(key);
						return (ft::make_pair(lb, ub));
					}

					ft::pair<iterator,iterator> equal_range (const key_type& key)
					{
						// iterator beg = this->begin();
						// iterator end = this->end();

						// if (this->_cmp(key, beg->first))
						// 	return (ft::make_pair(beg, ++beg));
						// beg++;
						// while (beg != end && _cmp(beg->first, key))
						// 	beg++;
						// if (!(!_cmp(beg->first, key) && !_cmp(key, beg->first)))
						// 	return (ft::make_pair(beg, beg));
						// return (ft::make_pair(beg, ++beg));
						iterator lb = lower_bound(key);
						iterator ub = upper_bound(key);
						return (ft::make_pair(lb, ub));
					}

				    /*
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    Map: Allocator
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    */

				   	/*
                    ----------------------------------------------------------------------------------------------------
                    get_allocator - Get allocator
                    ----------------------------------------------------------------------------------------------------
					Returns a copy of the allocator object associated with the map.	
                	*/
				
					allocator_type get_allocator() const { return (_pair_alloc); };

					RBTree getRBTree() {return _RBTree; };

                    // friend bool operator==(const map &lhs, const map &rhs)
                    //     { return (lhs.size() == rhs.size()
                    //         && std::equal(lhs.begin(), lhs.end(), rhs.begin())); }

					friend bool	operator==( const map &lhs, const map &rhs )
					{
						iterator	lhs_it = lhs.begin();
						iterator	lhs_ite = lhs.end();
						iterator	rhs_it = rhs.begin();
						iterator	rhs_ite = rhs.end();

						while (lhs_it != lhs_ite && rhs_it != rhs_ite)
						{
							if (lhs_it->second != rhs_it->second)
								return false;
							lhs_it++;
							rhs_it++;
						}
						if (lhs_it != lhs_ite || rhs_it != rhs_ite)
							return false;
						return true;
					}

					friend bool operator<(const map& lhs, const map &rhs)
                    { return ft::lexicographical_compare(lhs.begin(), lhs.end(),
                                    rhs.begin(), rhs.end()); }

                    /// Based on operator==
                    friend bool operator!=(const map& lhs, const map &rhs)
                    { return (!(lhs == rhs)); }

                    /// Based on operator<
                    friend bool operator>(const map &lhs, const map &rhs)
                    { return (rhs < lhs); }

                    /// Based on operator<
                    friend bool operator<=(const map &lhs, const map &rhs)
                    { return !(rhs < lhs); }

                    /// Based on operator<
                    friend bool operator>=(const map &lhs, const map &rhs)
                    { return !(lhs < rhs); }

					friend void	swap( map &rhs, map &lhs ) { lhs.swap(rhs); }
		
	};

}

#endif