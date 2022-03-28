/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:48:39 by abesombe          #+#    #+#             */
/*   Updated: 2022/03/28 10:35:14 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include "../map.hpp"
#include <map>
#include <ctime>
#include <sys/time.h>
#include <unistd.h>
#include <typeinfo>
#include <cstdlib>
#include <list>

#ifdef NAMESPACE
# define NAME "std "
#endif
#ifndef NAMESPACE
# define NAMESPACE ft
# define NAME "ft  "
#endif

bool	fncomp(char lhs, char rhs)
{
	return (lhs < rhs);
}
struct classcomp
{
	bool	operator()(const char& lhs, const char& rhs) const
	{
		return (lhs < rhs);
	}
};
template<typename Key, typename T>
void	constructing_maps( void )
{
	NAMESPACE::map<Key, T>	first;

	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d'] = 70;

	NAMESPACE::map<Key, T>	second(first.begin(), first.end());

	NAMESPACE::map<Key, T>	third(second);

	NAMESPACE::map<Key, T, classcomp>	fourth;					// class as Compare

	bool(*fn_pt)(char,char) = fncomp;
	NAMESPACE::map<Key, T, bool(*)(char,char)>	fifth(fn_pt);	// function pointer as Compare
}

template<typename Key, typename T>
void	map_assignment_operator( void )
{
	NAMESPACE::map<Key, T>	first;
	NAMESPACE::map<Key, T>	second;

	first['x'] = 8;
	first['y'] = 16;
	first['z'] = 32;

	second = first;						// second now contains 3 ints
	first = NAMESPACE::map<Key, T>();	// and first is now empty

	std::cout << "Size of first: " << first.size() << '\n';
	std::cout << "Size of second: " << second.size() << '\n';
}

template<typename Key, typename T>
void	map_begin_end( void )
{
	NAMESPACE::map<Key, T>	mymap;

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	// show content:
	for (typename NAMESPACE::map<Key, T>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

template<typename Key, typename T>
void	map_rbegin_rend( void )
{
	NAMESPACE::map<Key, T>	mymap;

	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;

	// show content:
	typename NAMESPACE::map<Key, T>::reverse_iterator	rit;
	for (rit = mymap.rbegin(); rit != mymap.rend(); ++rit)
		std::cout << rit->first << " => " << rit->second << '\n';
}

template<typename Key, typename T>
void	map_empty( void )
{
	NAMESPACE::map<Key, T>	mymap;

	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;

	while (!mymap.empty())
	{
		std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
		mymap.erase(mymap.begin());
	}
}

template<typename Key, typename T>
void	map_size( void )
{
	NAMESPACE::map<Key, T>	mymap;
	mymap['a'] = 101;
	mymap['b'] = 202;
	mymap['c'] = 302;

	std::cout << "mymap.size() is " << mymap.size() << '\n';
}

template<typename Key, typename T>
void	map_max_size( void )
{
	int	i;
	NAMESPACE::map<Key, T>	mymap;

	if (mymap.max_size() > 1000)
	{
		for (i = 0; i < 1000; i++)
			mymap[i] = 0;
		std::cout << "The map contains 1000 elements.\n";
	}
	else
		std::cout << "The map could not hold 1000 elements.\n";
}

template<typename Key, typename T>
void	map_operator_accessing_mapped_values( void )
{
	NAMESPACE::map<Key, T>	mymap;

	mymap['a'] = "an element";
	mymap['b'] = "another element";
	mymap['c'] = mymap['b'];

	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	std::cout << "mymap['d'] is " << mymap['d'] << '\n';

	std::cout << "mymap now contains " << mymap.size() << " elements.\n";
}

template<typename Key, typename T>
void	map_insert( void )
{
	NAMESPACE::map<Key, T>	mymap;

	// first insert function version (single parameter):
	mymap.insert( NAMESPACE::pair<Key, T>('a',100) );
	mymap.insert( NAMESPACE::pair<Key, T>('z',200) );

	typename NAMESPACE::pair<typename NAMESPACE::map<Key, T>::iterator, bool> ret;
	ret = mymap.insert( NAMESPACE::pair<Key, T>('z',500) );
	if (ret.second == false)
	{
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

	// second insert function version (with hint position):
	typename NAMESPACE::map<Key, T>::iterator it = mymap.begin();
	mymap.insert(it, NAMESPACE::pair<Key, T>('b', 300));	// max efficiency inserting
	mymap.insert(it, NAMESPACE::pair<Key, T>('c', 400));	// no max efficiency inserting

	// third insert function version (range insertion):
	NAMESPACE::map<Key, T> anothermap;
	anothermap.insert(mymap.begin(), mymap.find('c'));

	// showing contents:
	std::cout << "mymap contains:\n";
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "anothermap contains:\n";
	for (it = anothermap.begin(); it != anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	NAMESPACE::map<Key, T>	mymap2;
	typedef typename NAMESPACE::map<Key, T>::value_type	G;
	std::list<G> lst;
	lst.push_back(NAMESPACE::make_pair('a', 1200));
	lst.push_back(NAMESPACE::make_pair('b', 2200));
	lst.push_back(NAMESPACE::make_pair('c', 3200));
	lst.push_back(NAMESPACE::make_pair('d', 4200));
	lst.push_back(NAMESPACE::make_pair('e', 5200));
	lst.push_back(NAMESPACE::make_pair('f', 6200));
	lst.push_back(NAMESPACE::make_pair('g', 7200));
	lst.push_back(NAMESPACE::make_pair('h', 8200));
	mymap2.insert(lst.begin(), lst.end());
}


std::string	get_string_value( void )
{
	std::string ret = "";

	for (int i = 0; i < 5; ++i)
		ret += (std::rand() % 26) + 'a';
	return (ret);
}

template<typename Key, typename T>
void	map_speed( void )
{
	struct timeval	start_time;
	struct timeval	end_time;
	time_t	s_time;
	time_t	e_time;
	time_t	diff_time;
	
	NAMESPACE::map<Key, T>   mymap;

	std::string	key = "";

	gettimeofday(&start_time, NULL);
	for (int i = 0; i <= 1000000; i++)
	{
		key = get_string_value();
		mymap.insert( NAMESPACE::pair<Key, T>(key, "hola") );
	}
	gettimeofday(&end_time, NULL);
	s_time = (start_time.tv_sec * 1000000) + (start_time.tv_usec);
	e_time = (end_time.tv_sec * 1000000) + (end_time.tv_usec);
	diff_time = e_time - s_time;
	std::cerr << NAME << "insert time:[" << diff_time << " microseconds]" << std::endl;

	// std::cout << "----------------------------------------------" << std::endl;
	// mymap.getRBTree()->printTree2(mymap.getRBTree()->getRoot(), 0);
	// std::cout << "----------------------------------------------" << std::endl;

	typename NAMESPACE::map<Key, T>::iterator	it = mymap.begin();
	typename NAMESPACE::map<Key, T>::iterator	ite = mymap.end();
	
	while (it != ite)
	{
		std::cout << (*it).first << std::endl;
		it++;
	}

	gettimeofday(&start_time, NULL);
	
	mymap.find("Alexandre");
	
	gettimeofday(&end_time, NULL);
	s_time = (start_time.tv_sec * 1000000) + (start_time.tv_usec);
	e_time = (end_time.tv_sec * 1000000) + (end_time.tv_usec);
	diff_time = e_time - s_time;
	std::cerr << NAME << "find time  :[" << diff_time << " microseconds]" << std::endl;




	typename NAMESPACE::map<Key, T>::iterator	it2 = mymap.begin();
	typename NAMESPACE::map<Key, T>::iterator	ite2 = mymap.end();

	it2++;

	gettimeofday(&start_time, NULL);

	mymap.erase(it2, ite2);

	gettimeofday(&end_time, NULL);
	s_time = (start_time.tv_sec * 1000000) + (start_time.tv_usec);
	e_time = (end_time.tv_sec * 1000000) + (end_time.tv_usec);
	diff_time = e_time - s_time;
	std::cerr << NAME << "erase time :[" << diff_time << " microseconds]" << std::endl;

	std::cout << std::endl << "After Erase:" << std::endl;

	typename NAMESPACE::map<Key, T>::iterator	it3 = mymap.begin();
	typename NAMESPACE::map<Key, T>::iterator	ite3 = mymap.end();

	while (it3 != ite3)
	{
		std::cout << (*it3).first << std::endl;
		it3++;
	}
}

template<typename Key, typename T>
void	map_erase( void )
{
	NAMESPACE::map<Key, T>	mymap;
	typename NAMESPACE::map<Key, T>::iterator it;

	// insert some values:
	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;
	mymap['d'] = 40;
	mymap['e'] = 50;
	mymap['f'] = 60;

	it = mymap.find('b');
	mymap.erase(it);                   // erasing by iterator

	mymap.erase('c');                  // erasing by key		

	it = mymap.find('e');
	mymap.erase( it, mymap.end() );    // erasing by range

	// show content:
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

template<typename Key, typename T>
void	map_swap( void )
{
	NAMESPACE::map<Key, T>	foo,bar;

	foo['x'] = 100;
	foo['y'] = 200;

	bar['a'] = 11;
	bar['b'] = 22;
	bar['c'] = 33;

	foo.swap(bar);

	std::cout << "foo contains:\n";
	for (typename NAMESPACE::map<Key, T>::iterator it = foo.begin(); it != foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains:\n";
	for (typename NAMESPACE::map<Key, T>::iterator it = bar.begin(); it != bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

template<typename Key, typename T>
void	map_clear( void )
{
	NAMESPACE::map<Key, T>	mymap;

	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;

	std::cout << "mymap contains:\n";
	for (typename NAMESPACE::map<Key, T>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	mymap.clear();
	mymap['a'] = 1101;
	mymap['b'] = 2202;

	std::cout << "mymap contains:\n";
	for (typename NAMESPACE::map<Key, T>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

template<typename Key, typename T>
void	map_key_comp( void )
{
	NAMESPACE::map<Key, T>	mymap;

	typename NAMESPACE::map<Key, T>::key_compare mycomp = mymap.key_comp();

	mymap['a'] = 100;
	mymap['b'] = 200;
	mymap['c'] = 300;

	std::cout << "mymap contains:\n";

	char	highest = mymap.rbegin()->first;     // key value of last element

	typename NAMESPACE::map<Key, T>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );
	std::cout << '\n';
}

template<typename Key, typename T>
void	map_value_comp( void )
{
	NAMESPACE::map<Key, T>	mymap;

	mymap['x'] = 1001;
	mymap['y'] = 2002;
	mymap['z'] = 3003;

	std::cout << "mymap contains:\n";

	NAMESPACE::pair<Key, T>	highest = *mymap.rbegin();          // last element

	typename NAMESPACE::map<Key, T>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mymap.value_comp()(*it++, highest) );
}

template<typename Key, typename T>
void	map_find( void )
{
	NAMESPACE::map<Key, T>	mymap;
	typename NAMESPACE::map<Key, T>::iterator it;

	mymap['a'] = 50;
	mymap['b'] = 100;
	mymap['c'] = 150;
	mymap['d'] = 200;

	it = mymap.find('b');
	if (it != mymap.end())
		mymap.erase(it);

	// print content:
	std::cout << "elements in mymap:" << '\n';
	std::cout << "a => " << mymap.find('a')->second << '\n';
	std::cout << "c => " << mymap.find('c')->second << '\n';
	std::cout << "d => " << mymap.find('d')->second << '\n';
}


template<typename Key, typename T>	
void	map_count( void )
{
	NAMESPACE::map<Key, T>	mymap;
	char	c;

	mymap['a'] = 101;
	mymap['c'] = 202;
	mymap['f'] = 303;

	for (c = 'a'; c < 'h'; c++)
	{
		std::cout << c;
		if (mymap.count(c) > 0)
			std::cout << " is an element of mymap.\n";
		else 
			std::cout << " is not an element of mymap.\n";
	}
}

template<typename Key, typename T>
void	map_lower_bound_upper_bound( void )
{
	NAMESPACE::map<Key, T>	mymap;
	typename NAMESPACE::map<Key, T>::iterator	itlow,itup;

	mymap['a'] = 20;
	mymap['b'] = 40;
	mymap['c'] = 60;
	mymap['d'] = 80;
	mymap['e'] = 100;

	itlow = mymap.lower_bound ('b');  // itlow points to b
	itup = mymap.upper_bound ('d');   // itup points to e (not d!)

	mymap.erase(itlow, itup);        // erases [itlow,itup)

	// print content:
	for (typename NAMESPACE::map<Key, T>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

template<typename Key, typename T>
void	map_equal_range( void )
{
	NAMESPACE::map<Key, T>	mymap;

	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;

	NAMESPACE::pair<typename NAMESPACE::map<Key, T>::iterator, typename NAMESPACE::map<Key, T>::iterator>	ret;
	ret = mymap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
}

template<typename Key, typename T>
void	 map_get_allocator( void )
{
	int	psize;
	NAMESPACE::map<Key, T>	mymap;
	NAMESPACE::pair<const Key, T>* p;

	// allocate an array of 5 elements using mymap's allocator:
	p = mymap.get_allocator().allocate(5);

	// assign some values to array
	psize = sizeof(typename NAMESPACE::map<Key, T>::value_type)*5;

	std::cout << "The allocated array has a size of " << psize << " bytes.\n";

	mymap.get_allocator().deallocate(p, 5);
}

template<typename Key, typename T>
void	map_relational_operators( void )
{
	NAMESPACE::map<Key, T>	foo, bar;
	foo['a'] = 100;
	foo['b'] = 200;
	bar['a'] = 10;
	bar['z'] = 1000;

	if (foo == bar)
		std::cout << "foo and bar are equal\n";
	if (foo != bar)
		std::cout << "foo and bar are not equal\n";
	if (foo < bar)
		std::cout << "foo is less than bar\n";
	if (foo > bar)
		std::cout << "foo is greater than bar\n";
	if (foo <= bar)
		std::cout << "foo is less than or equal to bar\n";
	if (foo >= bar)
		std::cout << "foo is greater than or equal to bar\n";
}

template<typename Key, typename T>
void	map_iterator_traits( void )
{
	typedef NAMESPACE::iterator_traits<typename NAMESPACE::map<Key, T>::iterator >	traits;

	if (typeid(typename traits::iterator_category) == typeid(NAMESPACE::bidirectional_iterator_tag))
		std::cout << "map has a bidirectional_iterator" << std::endl;
}

int		main(void)
{
	struct timeval	start_time;
	struct timeval	end_time;
	time_t	s_time;
	time_t	e_time;
	time_t	diff_time;
	gettimeofday(&start_time, NULL);
	/*--------------------------------------------------------------------*/
	constructing_maps<char, int>();
	map_assignment_operator<char, int>();
	map_begin_end<char, int>();
	map_rbegin_rend<char, int>();
	map_empty<char, int>();
	map_size<char, int>();
	map_max_size<int, int>();
	map_operator_accessing_mapped_values<char, std::string>();
	map_insert<char, int>();
	map_speed<std::string, std::string>();
	map_erase<char, int>();
	map_swap<char, int>();
	map_clear<char, int>();
	map_key_comp<char, int>();
	map_value_comp<char, int>();
	map_find<char, int>();
	map_count<char, int>();
	map_lower_bound_upper_bound<char, int>();
	map_equal_range<char, int>();
	map_get_allocator<char, int>();
	map_relational_operators<char, int>();

	map_iterator_traits<char, int>();
	/*--------------------------------------------------------------------*/
	gettimeofday(&end_time, NULL);
	s_time = (start_time.tv_sec * 1000000) + (start_time.tv_usec);
	e_time = (end_time.tv_sec * 1000000) + (end_time.tv_usec);
	diff_time = e_time - s_time;
	std::cerr << NAME << "time:[" << diff_time << " microseconds]" << std::endl;
	return (0);
}
