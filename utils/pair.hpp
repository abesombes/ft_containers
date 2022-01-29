/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:14:29 by abesombes         #+#    #+#             */
/*   Updated: 2022/01/29 22:55:30 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft{

template <typename T1, typename T2>
struct pair{
    
    public:
    
                typedef T1 first_type;
                typedef T2 second_type;
                T1 first;
                T2 second;

                /* 
                ----------------------------------------------------------------------------------------------------
                PAIR - Pair of values
                ----------------------------------------------------------------------------------------------------
                This class couples together a pair of values, which may be of different types (T1 and T2). The 
                individual values can be accessed through its public members first and second.
                Pairs are a particular case of tuple.

                ----------------------------------------------------------------------------------------------------
                Member functions
                ----------------------------------------------------------------------------------------------------
                (constructor) - Construct map (public member function )
                pair::operator= - Copy container content (public member function )

                */

                /*
                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                Pair: Constructors
                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                */

                /*
                ----------------------------------------------------------------------------------------------------
                Pair - Default Constructor
                ----------------------------------------------------------------------------------------------------
                Constructs a pair object with its elements value-initialized.
                */

                pair(): first(), second(){};

                //pair(): first(0), second(0){}; // seems to have the same effect as first(0), second(0)

                /*
                ----------------------------------------------------------------------------------------------------
                Pair - Copy Constructor / Implicit Conversion
                ----------------------------------------------------------------------------------------------------
                The object is initialized with the contents of the pr pair object.
                The corresponding member of pr is passed to the constructor of each of its members.
                */
               
                template<class U, class V>
                pair (const pair<U,V>& pr): first(pr.first), second(pr.second){};

                /*
                ----------------------------------------------------------------------------------------------------
                Pair - Initialization Constructor
                ----------------------------------------------------------------------------------------------------
                Member first is constructed with a and member second with b.
                */

                pair (const first_type& a, const second_type& b): first(a), second(b){};


                /*
                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                Pair: Destructor
                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                */

                ~pair(){};

                /*
                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                Vector: Operator Overload =
                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                */
               
                /*
                Assign contents
                Assigns pr as the new content for the pair object.
                Member first is assigned pr.first, and member second is assigned pr.second.
                The copying forms (1) perform copy assignments, with the elements of its argument 
                preserving their values after the call. While the moving forms (2) perform move 
                assignments (as if calling forward for each element), which, for elements of types
                supporting move semantics implies that these elements of pr are left in an 
                unspecified but valid state.
                */

                pair& operator= (const pair& pr)
                { 
                    first = pr.first;
                    second = pr.second; 
                    return (*this);
                };


                /*
                Relational operators for pair
                Performs the appropriate comparison operation between the pair objects lhs and rhs.
                Two pair objects compare equal to each other if both their first members compare equal to each other
                and both their second members compare also equal to each other (in both cases using operator== for
                the comparison). Similarly, operators <, >, <= and >= perform a lexicographical comparison on the 
                sequence formed by members first and second (in all cases using operator< reflexively for the 
                comparisons).
                */

                friend bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first == rhs.first && lhs.second == rhs.second); };
                friend bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (!(lhs == rhs)); };
                friend bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first < rhs.first || (!(lhs.first < rhs.first) && lhs.second < rhs.second)); };
                friend bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (!(lhs > rhs)); };
                friend bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (lhs.first > rhs.first || (!(lhs.first > rhs.first) && lhs.second > rhs.second)); };
                friend bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return (!(lhs < rhs)); };

};



template <class T1, class T2>
pair<T1,T2> make_pair (T1 x, T2 y) 
{ 
    pair<T1, T2> tmp; 
    tmp.first = x; 
    tmp.second = y; 
    return (tmp);
};

};

#endif