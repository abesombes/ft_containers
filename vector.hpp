/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:25:50 by abesombe          #+#    #+#             */
/*   Updated: 2022/01/24 18:35:45 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <iostream>
#include <cstddef>
#include <limits>
#include <algorithm>
#include "iterators/random_access_iterator.hpp"


// typedef typename ft::vector_iterator<T, false> iterator;
// typedef typename ft::vector_iterator<T, true> const_iterator;
// typedef typename ft::vector_iterator<T, false> reverse_iterator;
// typedef typename ft::vector_iterator<T, true> const_reverse_iterator;

namespace ft{
    
#include <cstddef>
#include "utils/enable_if.hpp"
#include "utils/is_integral.hpp"

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
                    typedef random_access_iterator<value_type>           iterator;
                    typedef const random_access_iterator<value_type>           const_iterator;
                    iterator begin() { return iterator(_arr); };
                    iterator end() { return iterator(_arr + _size); };
                    const_iterator begin() const { return const_iterator(_arr); };
                    const_iterator end() const { return const_iterator(_arr + _size); };
                    iterator rbegin() { return iterator(_arr); };
                    iterator rend() { return iterator(_arr + _size); };
                    const_iterator rbegin() const { return const_iterator(_arr); };
                    const_iterator rend() const { return const_iterator(_arr + _size); };

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

                   void setName(std::string name) { _name = name; }; // to be removed later
                   std::string getName() { return (_name); }; // to be removed later

                    /*
                    ----------------------------------------------------------------------------------------------------
                    Vector - Default Constructor
                    ----------------------------------------------------------------------------------------------------
                    Constructs an empty container, with no elements.
                    */

                    explicit Vector(const allocator_type& alloc = allocator_type()): _alloc(alloc), _arr(NULL), _size(0), _capacity(0) { /*_arr = _alloc.allocate(0);*/ };

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
                    Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), 
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type = 0): _alloc(alloc)
                    {
                        _capacity = last - first;
                        if (max_size() - size() < _capacity)
	                        throw std::length_error("Vector");
                        _size = _capacity;
                        _arr = _alloc.allocate(_capacity);
                        for (size_t i = 0; i < _size; i++)
                        {
                            _alloc.construct(&_arr[i], *first);
                            first++;
                        }
                    }

                    Vector(Vector const &src): _alloc(src._alloc), _size(src._size), _capacity(src._capacity)
                    {
                        if (max_size() - size() < _capacity)
	                        throw std::length_error("Vector");
                        _arr = _alloc.allocate(_capacity);
                        for (size_t i = 0; i < _size; i++)
                            _alloc.construct(&_arr[i], src._arr[i]);
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
                            std::cout << "object destroyed " << i << std::endl;
                            _alloc.destroy(&_arr[i]);
                        }
                        _alloc.deallocate(_arr, this->_capacity);
                        std::cout << "destruction completed for " << getName() << std::endl;
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

                    reference operator[] (size_type n)
                    {
                        return (_arr[n]);
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
                            if (n > _size - 1)
                                throw std::out_of_range("Vector");
                        }
                        catch (const std::out_of_range& e) {
                            std::cerr << "\nVector: " << e.what() << '\n';
                        }
                        return (_arr[n]);
                    }
                    
                    reference at (size_type n)
                    {
                        try
                        {
                            if (n > _size - 1)
                                throw std::out_of_range("Vector");
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

                    reference front()
                    {
                        return (_arr[0]);
                    }

                    const_reference back() const
                    {
                        return (_arr[_size - 1]);
                    }

                    reference back()
                    {
                        return (_arr[_size - 1]);
                    }

                    /*
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    Vector: Capacity Functions
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    */
                    
                    size_type size() const { return (_size); };

                    size_type max_size() const{
                        // alternative solution: size_t max_size = -1;
                        // return (max_size / sizeof(T));
                        // other solution: return (std::numeric_limits<size_t>::max() / sizeof(T));   
                        return allocator_type().max_size();
                        // other solution: return std::numeric_limits<size_type>::max() / sizeof(value_type);
                    }
                    
                    /*
                    ----------------------------------------------------------------------------------------------------
                    RESIZE - Change size
                    ----------------------------------------------------------------------------------------------------
                    Resizes the container so that it contains n elements. If n is smaller than the current container 
                    size, the content is reduced to its first n elements, removing those beyond (and destroying them). 
                    If n is greater than the current container size, the content is expanded by inserting at the end as 
                    many elements as needed to reach a size of n. If val is specified, the new elements are initialized
                    as copies of val, otherwise, they are value-initialized. If n is also greater than the current 
                    container capacity, an automatic reallocation of the allocated storage space takes place. 
                    Notice that this function changes the actual content of the container by inserting or erasing 
                    elements from it.
                    */
                    
                    void resize (size_type new_size, value_type val = value_type()){
	                    if (new_size > max_size())
	                        throw std::length_error("Vector");
                        if (new_size > _capacity)
                            reallocate_Vector(new_size);
                        while (new_size < _size)
                            pop_back();
                        while (new_size > _size) 
                            push_back(val);                 
                    }

                    size_type capacity() const { return (_capacity); }

                    bool empty() const { return (_size == 0 ? true : false); }


                    /*
                    ----------------------------------------------------------------------------------------------------
                    RESERVE - Request a change in capacity
                    ----------------------------------------------------------------------------------------------------
                    Requests that the vector capacity be at least enough to contain n elements.
                    If n is greater than the current vector capacity, the function causes the container to reallocate 
                    its storage increasing its capacity to n (or greater). 
                    In all other cases, the function call does not cause a reallocation and the vector capacity is not 
                    affected. This function has no effect on the vector size and cannot alter its elements.
                    */

                    void reserve (size_type n)
                    {
                        if (n > max_size())
                            throw std::length_error("vector");
                        if (n > _capacity)
                            reallocate_Vector(n);
                    }
                    
                    /*
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    Vector: Modifier Functions
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    */
                    





                    
                    /*
                    ----------------------------------------------------------------------------------------------------
                    ASSIGN - Assign vector content
                    ----------------------------------------------------------------------------------------------------
                    Assigns new contents to the vector replacing its current contents & modifying its size accordingly.
                    In the range version (1), the new contents are elements constructed from each of the elements in the
                    range between first and last, in the same order. 
                    In the fill version (2), the new contents are n elements, each initialized to a copy of val.
                    If a reallocation happens,the storage needed is allocated using the internal allocator.
                    */
                   
                    template <class InputIterator>
                    void assign (InputIterator first, InputIterator last)
                    {
                        clear();
                        size_t n = last - first;
                        if (max_size() - size() < n)
	                        throw std::length_error("Vector");
                        if (n > _capacity)
                        {
                            _alloc.deallocate(_arr, this->_capacity);
                            _arr = _alloc.allocate(n);
                            _capacity = _size;
                        }
                        for (size_t i = 0; i < n; i++)
                        {
                            _alloc.construct(&_arr[i], *first);
                            first++;
                        }
                        _size = n;
                    }

                    void assign (size_type n, const value_type& val)
                    {
                        clear();
                        if (n > _capacity)
                        {
                            _alloc.deallocate(_arr, this->_capacity);
                            _arr = _alloc.allocate(n);
                            _capacity = _size;
                        }
                        for (size_t i = 0; i < n; i++)
                            _alloc.construct(&_arr[i], *val);
                        _size = n;
                    }
             
                    /*
                    ----------------------------------------------------------------------------------------------------
                    PUSH_BACK - Add element at the end
                    ----------------------------------------------------------------------------------------------------
                    Adds a new element at the end of the vector, after its current last element. The content of val is 
                    copied (or moved) to the new element. This effectively increases the container size by one, which 
                    causes an automatic reallocation of the allocated storage space if -and only if- the new vector size
                    surpasses the current vector capacity.
                    */

                    void push_back(T data)
                    {
                        if (_size + 1 > _capacity)
                            reallocate_Vector(_capacity ? _capacity * 2 : 1);
                        _alloc.construct(&_arr[_size++], data);
                    }

                    /*
                    ----------------------------------------------------------------------------------------------------
                    POP_BACK - Delete last element
                    ----------------------------------------------------------------------------------------------------
                    Removes the last element in the vector, effectively reducing the container size by one.
                    This destroys the removed element.
                    */

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
                        difference_type index = position - begin();
                        insert(position, 1, val);
                        return (iterator(&_arr[index]));
                    }
                 
                    void insert (iterator position, size_type n, const value_type& val)
                    {
                        difference_type offset = position - begin();
                        
                        if (_size + n > _capacity)
                            reallocate_Vector(_size > 0 ? _capacity * 2: 1);
                        iterator tmp;
                        position = iterator(_arr + offset);
                        for ( tmp = end() - 1 + n ; tmp > position + n - 1; tmp--)
                            *tmp = *(tmp - n);
                        for ( tmp = position + n - 1; tmp >= position; tmp-- )
                            *tmp = val;
                        _size = _size + n;
                    }

                    template <class InputIterator>
                    void insert (iterator position, InputIterator first, InputIterator last, 
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type = 0)
                    {
                        size_t n = last - first;
                        difference_type offset = position - begin();
                        
                        if (_size + n > _capacity)
                        {
                            reallocate_Vector(_size > 0 ? _capacity * 2: 1);
                            position = iterator(&_arr[offset]);
                        }
                        iterator tmp;
                        _size = _size + n;
                        for ( tmp = end() + n - 1; tmp > position + n - 1; tmp--)
                            *tmp = *(tmp - n);
                        for ( tmp = position + n - 1; tmp >= position; tmp-- )
                        {
                            *tmp = *(first + n - 1);
                            first--;
                        }
                    }
                   

                    /*
                    ----------------------------------------------------------------------------------------------------
                    ERASE - Erase elements
                    ----------------------------------------------------------------------------------------------------
                    Removes from the vector either a single element (position) or a range of elements ([first,last)).
                    This effectively reduces the container size by the number of elements removed, which are destroyed.
                    Because vectors use an array as their underlying storage, erasing elements in positions other than 
                    the vector end causes the container to relocate (NOT REALLOCATE) all the elements after the segment 
                    erased to their new positions. This is generally an inefficient operation compared to the one 
                    performed for the same operation by other kinds of sequence containers (list/forward_list). Returns 
                    an iterator pointing to the new location of the element that followed the last element erased by the
                    function call. This is the container end if the operation erased the last element in the sequence. 
                    Member type iterator is a random access iterator type that points to elements.
                    */
                   
                    iterator erase (iterator position)
                    {
                        erase(position, position + 1);
                    }
                    
                    iterator erase (iterator first, iterator last)
                    {
                        if (last < first)
                            throw std::logic_error("Error: first iterator > last iterator");
                        if (last == first || first == end())
                            return (end());
                        if (last > first)
                        {
                            size_t removed = (last > end()? end() - first : last - first);
                            size_t pos = first - begin();
                            while (first != end() && last != end())
                            {
                                _alloc.destroy(&(*first));
                                _alloc.construct(&(*first), *last);
                                first++;
                                last++;
                            }
                            _size -= removed;
                            first = begin() + pos;
                        }       
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


                    /*
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    Vector: Allocator Functions
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                    */
                    

                    allocator_type get_allocator() const { return (_alloc); };
                    
                    void fill(int start) // to be removed later
                    {
                        for (size_t i = 0; i < _size; i++, start++)
                            _arr[i] = (start + 1) * 100;
                    }

                    void printVec() // to be removed later
                    {
                        std::cout << "\n-----------------------------------------" << std::endl; 
                        std::cout << "---- VECTOR PRINTING: "<< getName() << " (" << size() << "/" << capacity() << ") -----" << std::endl;
                        std::cout << "-----------------------------------------" << std::endl; 
                        int j = 0;
                        for (iterator i = begin(); i < end(); i++)
                        {
                            std::cout << "vector[" << j << "]: " << *i << " - addr = " << &*i << std::endl;
                            j++;
                        }
                        std::cout << "-----------------------------------------" << std::endl; 
                        std::cout << "-----------------------------------------\n" << std::endl; 
                    }
            
        private:
                    allocator_type  _alloc;
                    pointer         _arr;
                    size_t          _size;
                    size_t          _capacity;
                    std::string     _name;
                    
                    void reallocate_Vector(size_type new_capacity)
                    {
                        pointer tmp = _alloc.allocate(new_capacity);
                        for (size_t i = 0; i < _size; i++)
                            _alloc.construct(&tmp[i], _arr[i]);

                        clean_former_arr();
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

                    void clean_former_arr()
                    {
                        for (size_t i = 0; i < _size; i++)
                            _alloc.destroy(&_arr[i]);
                        _alloc.deallocate(_arr, this->_capacity);
                    }

                    size_type check_len(size_type n) const
                    {
	                    if (max_size() - size() < n)
	                        throw std::length_error("Vector");

	                    const size_type len = size() + (std::max)(size(), n);
	                    return ((len < size() || len > max_size()) ? max_size() : len);
                    }
                    


    };
}


#endif