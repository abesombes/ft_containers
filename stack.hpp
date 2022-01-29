/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 09:59:16 by abesombes         #+#    #+#             */
/*   Updated: 2022/01/29 15:21:05 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP
#include <memory>
#include <iostream>
#include <cstddef>
#include <limits>
#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include "utils/enable_if.hpp"
#include "utils/is_integral.hpp"
#include "utils/const_or_not.hpp"
#include "vector.hpp"

namespace ft{
    


template <typename T, class Container = vector<T> >
class stack{

public:
        typedef T                   value_type;
        typedef Container  container_type;
        typedef size_t              size_type;

        /*
        ----------------------------------------------------------------------------------------------------
        Member functions
        ----------------------------------------------------------------------------------------------------
        (constructor) - Construct stack (public member function)
        empty - Test whether container is empty (public member function)
        size - Return size (public member function)
        top - Access next element (public member function)
        push - Insert element (public member function)
        pop - Remove top element (public member function)

        ----------------------------------------------------------------------------------------------------
        Non-member function overloads
        ----------------------------------------------------------------------------------------------------
        relational operators - Relational operators for stack (function)

        */
        




        /*
        ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        Stack: Constructor
        ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        */


        /*
        ----------------------------------------------------------------------------------------------------
        Stack - Default Constructor
        ----------------------------------------------------------------------------------------------------
        Constructs a stack container adaptor object.
        A container adaptor keeps internally a container object as data. This container object is a copy of
        the ctnr argument passed to the constructor, if any, otherwise it is an empty container.
        */
       
        explicit stack (const container_type& ctnr = container_type()): _ctnr(ctnr){}


        /*
        ----------------------------------------------------------------------------------------------------
        Stack - Copy Constructor
        ----------------------------------------------------------------------------------------------------
        Copy constructor, creates a stack with the same container object.
        */
       
        stack(stack const &src): _ctnr(src._ctnr) {}


        /*
        ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        Stack: Destructor
        ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        */

        ~stack() {}

        /*
        ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        Stack: Member Functions
        ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        */

        bool empty() const { return (!_ctnr.size()); }
        
        /*
        ----------------------------------------------------------------------------------------------------
        SIZE - Returns the number of elements in the stack.
        ----------------------------------------------------------------------------------------------------
        This member function effectively calls member size of the underlying container object.
        */

        size_type size() const
        {
            return (_ctnr.size());
        }

        /*
        ----------------------------------------------------------------------------------------------------
        TOP - Access next element
        ----------------------------------------------------------------------------------------------------
        Returns a reference to the top element in the stack. Since stacks are last-in first-out containers, 
        the top element is the last element inserted into the stack. This member function effectively calls
        member back of the underlying container object.
        */

        value_type& top() { return (size() > 0? _ctnr.back(): _ctnr[0]); };
        
        const value_type& top() const  { return (size() > 0? _ctnr.back(): _ctnr[0]); };

        /*
        ----------------------------------------------------------------------------------------------------
        PUSH - insert element
        ----------------------------------------------------------------------------------------------------
        Inserts a new element at the top of the stack, above its current top element. The content of this 
        new element is initialized to a copy of val. This member function effectively calls the member 
        function push_back of the underlying container object.
        */

        void push (const value_type& val) { _ctnr[0] = val; }
        container_type &get_ctnr() { return (_ctnr); };
        
        /*
        (1)	

        template <class T, class Container>
        bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

        (2)	

        template <class T, class Container>
        bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

        (3)	

        template <class T, class Container>
        bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

        (4)	

        template <class T, class Container>
        bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

        (5)	

        template <class T, class Container>
        bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

        (6)	

        template <class T, class Container>
        bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
        */

        private:
                container_type _ctnr;
    
};

}

#endif