/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:25:50 by abesombe          #+#    #+#             */
/*   Updated: 2022/01/09 20:38:25 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <iostream>
#include <cstddef>
#include "iterators/random_access_iterator.hpp"

// typedef typename ft::vector_iterator<T, false> iterator;
// typedef typename ft::vector_iterator<T, true> const_iterator;
// typedef typename ft::vector_iterator<T, false> reverse_iterator;
// typedef typename ft::vector_iterator<T, true> const_reverse_iterator;

namespace ft{
#include <cstddef>
    template <class T, class Alloc = std::allocator<T> >
    class Vector {

        public:
                    typedef T value_type;
                    typedef Alloc allocator_type;
                    typedef typename allocator_type::reference reference;
                    typedef typename allocator_type::const_reference const_reference;
                    typedef typename allocator_type::pointer pointer;
                    typedef typename allocator_type::const_pointer const_pointer;
                    typedef ptrdiff_t difference_type;

                    typedef size_t size_type;
                    typedef random_access_iterator<value_type> iterator;
                    typedef random_access_iterator<const value_type> const_iterator;
                    iterator begin() { return iterator(_arr); };
                    iterator end() { return iterator(_arr + _current); };
                    const_iterator begin() const { return const_iterator(_arr); };
                    const_iterator end() const { return const_iterator(_arr + _current); };

                    /******************* VECTOR - CONSTRUCTORS *********************/

                    explicit Vector(const allocator_type& alloc = allocator_type()): _alloc(alloc), _arr(NULL), _current(0), _capacity(0) {};

                    /**
                    *  @brief  Creates a %vector with copies of an exemplar element.
                    *  @param  n  The number of elements to initially create.
                    *  @param  value  An element to copy.
                    *  @param  a  An allocator.
                    *
                    *  This constructor fills the %vector with @a __n copies of @a __value.
                    */

                    explicit Vector(size_type n, const value_type& value, const allocator_type& alloc = allocator_type()): _alloc(alloc), _current(n), _capacity(n)
                    {
                        _arr = _alloc.allocate(_capacity);
                        for (size_t i = 0; i < _current; i++)
                            _alloc.construct(&_arr[i], value);
                    }

                    Vector(Vector const &src): _alloc(src._alloc), _current(src._current), _capacity(src._capacity)
                    {
                        _arr = _alloc.allocate(_capacity);
                        for (size_t i = 0; i < _current; i++)
                            _alloc.construct(&_arr[i], src._arc[i]);
                    }

                    /******************* VECTOR - DESTRUCTORS *********************/

                    ~Vector(){
                        for (size_t i = 0; i < _current; i++)
                            _alloc.destroy(&_arr[i]);
                        _alloc.deallocate(_arr, this->_capacity);
                    };


                    /******************* VECTOR - OPERATOR OVERLOAD *********************/
                    const_reference operator[] (size_type n) const
                    {
                        return (_arr[n]);
                    }
                    
                    void clear()
                    {
                        // erase(begin(), end());
                    }
                    
                    void push_back(T data)
                    {
                        if (_current == _capacity)
                        {
                            T* tmp = new T[2 * _capacity];
                            size_t i;
                            for (i = 0; i < _capacity; i++)
                                tmp[i] = _arr[i];
                            delete[] _arr;
                            _capacity *= 2;
                            tmp[i] = data;
                            _arr = tmp;
                            _current++;
                        }
                        else
                        {
                            _arr[_current] = data;
                            _current++;
                        }
                    }
            
        private:
                    allocator_type  _alloc;
                    pointer         _arr;
                    size_t          _current;
                    size_t          _capacity;
    };


}


#endif