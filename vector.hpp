/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:25:50 by abesombe          #+#    #+#             */
/*   Updated: 2022/01/13 23:20:15 by abesombe         ###   ########.fr       */
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
                    iterator end() { return iterator(_arr + _size); };
                    const_iterator begin() const { return const_iterator(_arr); };
                    const_iterator end() const { return const_iterator(_arr + _size); };

                    /******************* VECTOR - CONSTRUCTORS *********************/

                    explicit Vector(const allocator_type& alloc = allocator_type()): _alloc(alloc), _arr(NULL), _size(0), _capacity(0) {};

                    /**
                    *  @brief  Creates a %vector with copies of an exemplar element.
                    *  @param  n  The number of elements to initially create.
                    *  @param  value  An element to copy.
                    *  @param  a  An allocator.
                    *
                    *  This constructor fills the %vector with @a n copies of @a value.
                    */

                    explicit Vector(size_type n, const value_type& value, const allocator_type& alloc = allocator_type()): _alloc(alloc), _size(n), _capacity(n)
                    {
                        _arr = _alloc.allocate(_capacity);
                        for (size_t i = 0; i < _size; i++)
                            _alloc.construct(&_arr[i], value);
                    }

                    Vector(Vector const &src): _alloc(src._alloc), _size(src._size), _capacity(src._capacity)
                    {
                        _arr = _alloc.allocate(_capacity);
                        for (size_t i = 0; i < _size; i++)
                            _alloc.construct(&_arr[i], src._arc[i]);
                    }

                    /******************* VECTOR - DESTRUCTORS *********************/

                    ~Vector(){
                        for (size_t i = 0; i < _size; i++)
                            _alloc.destroy(&_arr[i]);
                        _alloc.deallocate(_arr, this->_capacity);
                    };


                    /******************* VECTOR - OPERATOR OVERLOAD = - ASSIGNATION *********************/

                    Vector& operator= (const Vector& rhs)
                    {
                        Vector tmp(rhs);
                        this->swap(tmp);
                        return (*this);
                    }

                    /******************* VECTOR - OPERATOR OVERLOAD [] - AT *********************/
                    
                    const_reference operator[] (size_type n) const
                    {
                        return (_arr[n]);
                    }

                    /******************* VECTOR - ELEMENT ACCESS FUNCTIONS *********************/

                    const_reference at (size_type n) const
                    {
                        try
                        {
                            if (n < 0 || n > _size - 1)
                                throw std::out_of_range("Out of Range error");
                        }
                        catch (const std::out_of_range& e) {
                            std::cerr << "\nVector: " << e.what() << '\n';
                        }
                        return (_arr[n]);
                    }

                    const_reference front() const
                    {
                        return (_arr[0]);
                    }

                    const_reference back() const
                    {
                        return (_arr[_size - 1]);
                    }

                    /******************* VECTOR - CAPACITY FUNCTIONS *********************/
                    
                    size_type size() const { return (_size); };

                    size_type max_size() const{
                        return ((size_t)(-1) / sizeof(T));
                    }
                    
                    void clear()
                    {
                        // erase(begin(), end());
                    }
                    
                    void push_back(T data)
                    {
                        if (_size == _capacity)
                        {
                            T* tmp = new T[2 * _capacity];
                            size_t i;
                            for (i = 0; i < _capacity; i++)
                                tmp[i] = _arr[i];
                            delete[] _arr;
                            _capacity *= 2;
                            tmp[i] = data;
                            _arr = tmp;
                            _size++;
                        }
                        else
                        {
                            _arr[_size] = data;
                            _size++;
                        }
                    }

                    void pop_back()
                    {
                        _size--;
                        _alloc.destroy(&_arr[_size]);
                    }

                    /******************* VECTOR - MODIFIERS FUNCTIONS *********************/
                    
                    void swap (Vector& other)
                    {
                        swap(this->_arr, other._arr);
                        swap(this->_size, other._size);
                        swap(this->_capacity,other._capacity);
                    }
                    
            
        private:
                    allocator_type  _alloc;
                    pointer         _arr;
                    size_t          _size;
                    size_t          _capacity;
    };


}


#endif