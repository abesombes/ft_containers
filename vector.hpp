/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:25:50 by abesombe          #+#    #+#             */
/*   Updated: 2022/01/14 23:56:39 by abesombe         ###   ########.fr       */
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
                        // size_t max_size = -1;
                        // return (max_size / sizeof(T));
                        return (std::numeric_limits<size_t>::max() / sizeof(T));z   
                    }
                    
                    /**
                    *  @brief  Resizes the Vector to the specified number of elements.
                    *  @param  new_size Number of elements the Vector should contain.
                    *  @param  val Data with which new elements should be populated.
                    *
                    *  This function will resize the Vector to the specified
                    *  number of elements.  If the number is smaller than the
                    *  Vector's current size the Vector is truncated, otherwise
                    *  the Vector is extended and new elements are populated with
                    *  given data.
                    */
                    
                    void resize (size_type new_size, value_type val = value_type()){
                        if (new_size > _capacity)
                            reallocate_Vector(new_size);
                        while (new_size < _size)
                            pop_back();
                        while (new_size > _size) 
                            push_back(val);                 
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
                    
                    void reallocate_Vector(size_type new_capacity)
                    {
                        pointer tmp = _alloc.allocate(new_capacity);
                        for (size_t i = 0; i < _size; i++)
                            _alloc.construct(&_tmp[i], _arr[i]);

                        this->~Vector();
                        _capacity = new_capacity;
                        _arr = tmp;
                    }
    };


}


#endif