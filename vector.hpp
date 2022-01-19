/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:25:50 by abesombe          #+#    #+#             */
/*   Updated: 2022/01/19 16:44:02 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <iostream>
#include <cstddef>
#include <limits>
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
                    // typedef random_access_iterator<value_type> iterator;
                    typedef value_type*                 iterator;
                    typedef const value_type*                 const_iterator;
                    // typedef random_access_iterator<const value_type> const_iterator;
                    iterator begin() { return iterator(_arr); };
                    iterator end() { return iterator(_arr + _size); };
                    const_iterator begin() const { return const_iterator(_arr); };
                    const_iterator end() const { return const_iterator(_arr + _size); };

                    /*
                    ----------------------------------------------------------------------------------------------------
                    Member functions
                    ----------------------------------------------------------------------------------------------------
                    (constructor) - Construct vector (public member function )
                    (destructor) - Vector destructor (public member function )
                    operator= - Assign content (public member function )

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
                    size - Return size (public member function )
                    max_size - Return maximum size (public member function )
                    resize - Change size (public member function )
                    capacity - Return size of allocated storage capacity (public member function )
                    empty - Test whether vector is empty (public member function )
                    reserve - Request a change in capacity (public member function )

                    ----------------------------------------------------------------------------------------------------
                    Element access:
                    ----------------------------------------------------------------------------------------------------
                    operator[] - Access element (public member function )
                    at - Access element (public member function )
                    front - Access first element (public member function )
                    back - Access last element (public member function )

                    ----------------------------------------------------------------------------------------------------
                    Modifiers:
                    ----------------------------------------------------------------------------------------------------
                    assign - Assign vector content (public member function )
                    push_back - Add element at the end (public member function )
                    pop_back - Delete last element (public member function )
                    insert - Insert elements (public member function )
                    erase - Erase elements (public member function )
                    swap - Swap content (public member function )
                    clear - Clear content (public member function ) */

                    /*
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    Vector: Constructors
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    */

                    /*
                    ----------------------------------------------------------------------------------------------------
                    Vector - Default Constructor
                    ----------------------------------------------------------------------------------------------------
                    Constructs an empty container, with no elements.
                    */

                    explicit Vector(const allocator_type& alloc = allocator_type()): _alloc(alloc), _arr(NULL), _size(0), _capacity(0) {};

                    /*
                    ----------------------------------------------------------------------------------------------------
                    Vector - Fill Constructor
                    ----------------------------------------------------------------------------------------------------
                    Constructs a container with as many elements as the range [first,last), with each element constructed
                    from its corresponding element in that range, in the same order.
                    */

                    explicit Vector(size_type n, const value_type& value, const allocator_type& alloc = allocator_type()): _alloc(alloc), _size(n), _capacity(n)
                    {
                        _arr = _alloc.allocate(_capacity);
                        for (size_t i = 0; i < _size; i++)
                            _alloc.construct(&_arr[i], value);
                    }
                    
                    /*
                    ----------------------------------------------------------------------------------------------------
                    Vector - Range Constructor
                    ----------------------------------------------------------------------------------------------------
                    Constructs a container with as many elements as the range [first,last), with each element constructed
                    from its corresponding element in that range, in the same order.
                    */
                   
                    template <class InputIterator>
                    Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()): _alloc(alloc)
                    {
                        _capacity = last - first - 1;
                        _arr = _alloc.allocate(_capacity);
                        for (size_t i = 0; i < _size; i++)
                        {
                            _alloc.construct(&_arr[i], *first);
                            first++;
                        }
                    }

                    Vector(Vector const &src): _alloc(src._alloc), _size(src._size), _capacity(src._capacity)
                    {
                        _arr = _alloc.allocate(_capacity);
                        for (size_t i = 0; i < _size; i++)
                            _alloc.construct(&_arr[i], src._arc[i]);
                    }

                    /*
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    Vector: Destructors
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    */

                    ~Vector(){
                        for (size_t i = 0; i < _size; i++)
                        {
                            std::cout << "test " << i << std::endl;
                            _alloc.destroy(&_arr[i]);
                        }
                        _alloc.deallocate(_arr, this->_capacity);
                    };


                    /*
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    Vector: Operator Overloads = and []
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    */

                    Vector& operator= (const Vector& rhs)
                    {
                        Vector tmp(rhs);
                        this->swap(tmp);
                        return (*this);
                    }
    
                    const_reference operator[] (size_type n) const
                    {
                        return (_arr[n]);
                    }

                    /*
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    Vector: Element Access Functions
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    */

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

                    /*
                    ----------------------------------------------------------------------------------------------------
                    Vector: Capacity Functions
                    ----------------------------------------------------------------------------------------------------
                    */
                    
                    size_type size() const { return (_size); };

                    size_type max_size() const{
                        // size_t max_size = -1;
                        // return (max_size / sizeof(T));
                        // return (std::numeric_limits<size_t>::max() / sizeof(T));   
                        return allocator_type().max_size();
                        // return std::numeric_limits<size_type>::max() / sizeof(value_type);
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
                            reallocate_Vector(_size > 0 ? _capacity * 2: 1);
                        while (new_size < _size)
                            pop_back();
                        while (new_size > _size) 
                            push_back(val);                 
                    }

                    size_type capacity() const { return (_capacity); }

                    bool empty() const { return (_size == 0 ? true : false); }

                    void reserve (size_type n)
                    {
                        if (n > max_size())
                            throw std::length_error("vector");
                        if (n > _capacity)
                            reallocate_Vector(n);
                    }
                    
                    /*
                    ----------------------------------------------------------------------------------------------------
                    Vector: Modifiers Functions
                    ----------------------------------------------------------------------------------------------------
                    */
                    
                    template <class InputIterator>
                    void assign (InputIterator first, InputIterator last);

                    void assign (size_type n, const value_type& val);
             
                    void push_back(T data)
                    {
                        if (_size + 1 > _capacity)
                            reallocate_Vector(_capacity ? _capacity * 2 : 1);
                        _alloc.construct(&_arr[_size++], data);
                    }

                    void pop_back()
                    {
                        _size--;
                        _alloc.destroy(&_arr[_size]);
                    }
                    
                    /*
                    ----------------------------------------------------------------------------------------------------
                    INSERT - Insert elements
                    ----------------------------------------------------------------------------------------------------
                    The vector is extended by inserting new elements before the element at the specified position, 
                    effectively increasing the container size by the number of elements inserted.
                    This causes an automatic reallocation of the allocated storage space if -and only if- the new vector
                    size surpasses the current vector capacity. Because vectors use an array as their underlying storage,
                    inserting elements in positions other than the vector end causes the container to relocate all the
                    elements that were after position to their new positions. This is generally an inefficient operation
                    compared to the one performed for the same operation by other kinds of sequence containers (such as
                    list or forward_list). The parameters determine how many elements are inserted and to which values 
                    they are initialized.
                    */

                    iterator insert (iterator position, const value_type& val)
                    {
                        size_type n = 1;
                        insert(position, n, val);
                        return (position);
                        // difference_type index = position - begin();
                        
                        // insert(position, 1, val);
                        // return iterator(&_arr[index]);
                    }
                 
                    void insert (iterator position, size_type n, const value_type& val)
                    {
                        difference_type offset = position - begin();
                        
                        if (_size + n > _capacity)
                            reallocate_Vector(_size > 0 ? _capacity * 2: 1);
                        iterator tmp;
                        std::cout << "end() - 1 value: " << *(end() - 1)<< std::endl;
                        position = iterator(_arr + offset);
                        for ( tmp = end() - 1 + n ; tmp > position + n - 1; tmp--)
                            *tmp = *(tmp - n);
                        for ( tmp = position + n - 1; tmp >= position; tmp-- )
                            *tmp = val;
                        _size = _size + n;
                    }

                    template <class InputIterator>
                    void insert (iterator position, InputIterator first, InputIterator last)
                    {
                        size_t n = last - first;
                        difference_type offset = position - begin();
                        
                        if (_size + n > _capacity)
                            reallocate_Vector(_size > 0 ? _capacity * 2: 1);
                        position = iterator(_arr + offset);
                        iterator tmp;
                        for ( tmp = end() - 1 + n ; tmp > position + n - 1; tmp--)
                            *tmp = *(tmp - n);
                        for ( tmp = position + n - 1; tmp >= position; tmp-- )
                        {
                            *tmp = *last;
                            last--;
                        }
                        _size = _size + n;
                    }
                   

                    /*
                    ----------------------------------------------------------------------------------------------------
                    ERASE - Erase elements
                    ----------------------------------------------------------------------------------------------------
                    Removes from the vector either a single element (position) or a range of elements ([first,last)).
                    This effectively reduces the container size by the number of elements removed, which are destroyed.
                    Because vectors use an array as their underlying storage, erasing elements in positions other than 
                    the vector end causes the container to relocate (NOT REALLOCATE) all the elements after the segment erased to their 
                    new positions. This is generally an inefficient operation compared to the one performed for the same
                    operation by other kinds of sequence containers (such as list or forward_list). Returns an iterator 
                    pointing to the new location of the element that followed the last element erased by the function 
                    call. This is the container end if the operation erased the last element in the sequence. 
                    Member type iterator is a random access iterator type that points to elements.
                    */
                   
                    iterator erase (iterator position)
                    {
                        erase(position, position + 1);
                    }
                    
                    iterator erase (iterator first, iterator last)
                    {
                        if (first == end())
                            return (end());
                        size_t nb_pop_back = end() - first;
                        size_t removed = last - first;
                        if (last > end())
                        {
                            std::cout << "nb_pop_back: " << nb_pop_back << std::endl;
                            while (nb_pop_back--)
                                pop_back();
                        }
                        else
                        {
                            while (first != end() && last != end())
                            {
                                _alloc.destroy(&(*first));
                                _alloc.construct(&(*first), *last);
                                first++;
                                last++;
                            }
                        }
                        _size -= removed;
                        return (first);
                    }
                
                    /*
                    ----------------------------------------------------------------------------------------------------
                    SWAP - Swap content
                    ----------------------------------------------------------------------------------------------------
                    Exchanges the content of the container by the content of x, which is another vector object of the 
                    same type. Sizes may differ. After the call to this member function, the elements in this container 
                    are those which were in x before the call, and the elements of x are those which were in this. All 
                    iterators, references and pointers remain valid for the swapped objects. Notice that a non-member 
                    function exists with the same name, swap, overloading that algorithm with an optimization that 
                    behaves like this member function.
                    */

                    void swap (Vector& other)
                    {
                        swap(this->_arr, other._arr);
                        swap(this->_size, other._size);
                        swap(this->_capacity,other._capacity);
                    }

                    /*
                    ----------------------------------------------------------------------------------------------------
                    CLEAR - Clear content
                    ----------------------------------------------------------------------------------------------------
                    Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
                    A reallocation is not guaranteed to happen, and the vector capacity is not guaranteed to change due 
                    to calling this function. A typical alternative that forces a reallocation is to use swap:
                    vector<T>().swap(x);   // clear x reallocating 
                    */

                    void clear()
                    {
                        while (_size)
                            pop_back();
                    }
                    

                    void printVec()
                    {
                        std::cout << "\n---------------------------------" << std::endl; 
                        std::cout << "---- VECTOR PRINTING (" << size() << "/" << capacity() << ") -----" << std::endl;
                        std::cout << "---------------------------------" << std::endl; 
                        int j = 0;
                        for (iterator i = begin(); i < end(); i++)
                        {
                            std::cout << "vector[" << j << "]: " << *i << " - addr = " << &*i << std::endl;
                            j++;
                        }
                        std::cout << "---------------------------------" << std::endl; 
                        std::cout << "---------------------------------\n" << std::endl; 
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
                            _alloc.construct(&tmp[i], _arr[i]);

                        this->~Vector();
                        _capacity = new_capacity;
                        _arr = tmp;
                    }
                    void moveElementsToTheLeft(iterator first, iterator last)
                    {
                        for (; first != end(); ++first, ++last)
                        {
                            // Destructing the previous element to replace it by a new one.
                            // First will destroy all the element until the end.
                            _alloc.destroy(&(*first));
                            
                            // Moving a new element to the left at first position, only if there is
                            // still element to move
                            if (last < end())
                                _alloc.construct(&(*(first)), *last);
                        }
                    }


    };


}


#endif