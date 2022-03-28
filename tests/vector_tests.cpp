/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:49:23 by abesombe          #+#    #+#             */
/*   Updated: 2022/03/28 10:50:12 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include "../vector.hpp"
#include "../iterators/iterator_traits.hpp"
#include <vector>
#include <ctime>
#include <sys/time.h>
#include <unistd.h>
#include <typeinfo>

#ifdef NAMESPACE
# define NAME "std "
#endif
#ifndef NAMESPACE
# define NAMESPACE ft
# define NAME "ft  "
#endif

template<typename T>	
void	constructing_vectors( void )
{
	NAMESPACE::vector<T>	first;
	NAMESPACE::vector<T>	second(4, 5);
	NAMESPACE::vector<T>	third (second.begin(), second.end());
	NAMESPACE::vector<T>	fourth (third);

	T	mytab[] = {16,2,77,29};
	NAMESPACE::vector<T>	fifth(mytab, mytab + sizeof(mytab) / sizeof(T) );

	std::cout << "The contents of fifth are:";
	typename NAMESPACE::vector<T>::iterator it = fifth.begin();
	for (; it != fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

template<typename T>	
void	vector_assignment( void )
{
	NAMESPACE::vector<T>	foo(3, "hola");
	NAMESPACE::vector<T>	bar(5, "chao");

	bar = foo;
	foo = NAMESPACE::vector<T>();

	std::cout << "Size of foo: " << foo.size() << '\n';
	std::cout << "Size of bar: " << bar.size() << '\n';
}

template<typename T>
void	vector_begin_end( void )
{
	NAMESPACE::vector<T>	myvector;
	for (int i = 1; i <= 5; i++)
		myvector.push_back(i);

	std::cout << "myvector contains:";
	typename NAMESPACE::vector<T>::iterator it = myvector.begin();

	for (; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

template<typename T>
void	vector_rbegin_rend( void )
{
	NAMESPACE::vector<int>	myvector (5);

	int i = 0;

	NAMESPACE::vector<int>::reverse_iterator rit = myvector.rbegin();
	for (; rit!= myvector.rend(); ++rit)
		*rit = ++i;

	std::cout << "myvector contains:";
	for (NAMESPACE::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

template<typename T>
void	vector_size( void )
{
	NAMESPACE::vector<T>	mytab;
	std::cout << "0. size: " << mytab.size() << '\n';

	for (int i = 0; i < 10; i++)
		mytab.push_back("bonjour");
	std::cout << "1. size: " << mytab.size() << '\n';

	mytab.insert(mytab.end(), 10, "au revoir");
	std::cout << "2. size: " << mytab.size() << '\n';

	mytab.pop_back();
	std::cout << "3. size: " << mytab.size() << '\n';
}

template<typename T>
void	vector_capacity( void )
{
	NAMESPACE::vector<T> myvector;

	for (int i = 0; i < 100; i++)
		myvector.push_back(i);

	std::cout << "size: " << myvector.size() << "\n";
	std::cout << "capacity: " << myvector.capacity() << "\n";
	std::cout << "max_size: " << myvector.max_size() << "\n";
}

template<typename T>
void	vector_resize( void )
{
	NAMESPACE::vector<T>	myvector;

	for (long i = 1; i < 10; i++)
		myvector.push_back(i);

	myvector.resize(5);
	myvector.resize(8,100);
	myvector.resize(12);

	std::cout << "myvector contains:";
	for (unsigned int i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

template<typename T>
void	vector_empty( void )
{
	NAMESPACE::vector<T>	myvector;
	int	sum(0);
	for (int i = 1; i <= 10; i++)
		myvector.push_back(i);
	while (!myvector.empty())
	{
		sum += myvector.back();
		myvector.pop_back();
	}
	std::cout << "total: " << sum << '\n';
}

template<typename T>
void	vector_reserve( void )
{
	typename NAMESPACE::vector<T>::size_type	sz;
	NAMESPACE::vector<T>	foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i) {
		foo.push_back(i);
		if (sz!=foo.capacity())
		{
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
	NAMESPACE::vector<T>	bar;
	sz = bar.capacity();
	bar.reserve(100);
	std::cout << "making bar grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		bar.push_back(i);
		if (sz!=bar.capacity())
		{
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
}

template<typename T>
void	vector_operator_access_element( void )
{
	NAMESPACE::vector<T> myvector (10);;

	typename NAMESPACE::vector<T>::size_type	sz = myvector.size();
	for (unsigned i = 0; i < sz; i++)
		myvector[i] = i;

	for (unsigned i = 0; i < sz / 2; i++)
	{
		int temp;
		temp = myvector[sz-1-i];
		myvector[sz - 1 - i] = myvector[i];
		myvector[i] = temp;
	}

	std::cout << "myvector contains:";
	for (unsigned i = 0; i < sz; i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

template<typename T>
void	vector_at( void )
{
	NAMESPACE::vector<T>	myvector (10);

	for (unsigned i = 0; i < myvector.size(); i++)
		myvector.at(i) = i;

	std::cout << "myvector contains:";
	for (unsigned i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector.at(i);
	std::cout << '\n';
}

template<typename T>
void	vector_front( void )
{
	NAMESPACE::vector<T>	myvector;

	myvector.push_back(78);
	myvector.push_back(16);
	myvector.front() -= myvector.back();

	std::cout << "myvector.front() is now " << myvector.front() << '\n';
}

template<typename T>
void	vector_back( void )
{
	NAMESPACE::vector<T> myvector;

	myvector.push_back(10);

	while (myvector.back() != 0)
	{
		myvector.push_back(myvector.back() -1);
	}

	std::cout << "myvector contains:";
	for (unsigned i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

}

template<typename T>
void	vector_assign( void )
{
	NAMESPACE::vector<T>	first;
	NAMESPACE::vector<T>	second;
	NAMESPACE::vector<T>	third;

	first.assign(7,100);

	typename NAMESPACE::vector<T>::iterator	it;
	it = first.begin() + 1;

	second.assign(it, first.end() - 1);

	int	myints[] = {1776, 7, 4};
	third.assign (myints, myints + 3);

	std::cout << "Size of first: " << T(first.size()) << '\n';
	std::cout << "Size of second: " << T(second.size()) << '\n';
	std::cout << "Size of third: " << T(third.size()) << '\n';
}

template<typename T>
void	vector_push_back( void )
{
	NAMESPACE::vector<T>			myvector;
	typename NAMESPACE::vector<T>::size_type	sz;

	sz = myvector.capacity();
	for (int i = 0; i < 1000000; i++)
	{
		myvector.push_back(i);
		if (sz != myvector.capacity())
		{
			sz = myvector.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	std::cout << "myvector stores " << T(myvector.size()) << " numbers.\n";
}

template<typename T>
void	vector_pop_back( void )
{
	NAMESPACE::vector<T> myvector;
	int	sum(0);
	myvector.push_back(100);
	myvector.push_back(200);
	myvector.push_back(300);

	while (!myvector.empty())
	{
		sum += myvector.back();
		myvector.pop_back();
	}
	std::cout << "The elements of myvector add up to " << sum << '\n';
}

#include <iostream>
#include <vector>

template<typename T>
void	vector_insert( void )
{
	NAMESPACE::vector<T>	myvector(3,100);
	typename NAMESPACE::vector<T>::iterator			it;
	typename NAMESPACE::vector<T>::const_iterator	cit;

	it = myvector.begin();
	cit = myvector.begin();
	if (it == cit)
		std::cout << "it = cit " << std::endl;
	else
		std::cout << "it != cit " << std::endl;
	it = myvector.insert(it, 200);

	myvector.insert(it, 2, 300);


	it = myvector.begin();

	NAMESPACE::vector<T>	anothervector(100, 400);
	myvector.insert(it + 2, anothervector.begin(), anothervector.end());

	int	myarray[] = {501, 502, 503};
	myvector.insert(myvector.begin(), myarray, myarray + 3);

	std::cout << "myvector contains:";
	for (it = myvector.begin(); it < myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

template<typename T>
void	vector_erase( void )
{
	NAMESPACE::vector<T>	myvector;

	for (int i = 1; i <= 10; i++)
		myvector.push_back(i);

	myvector.erase(myvector.begin() + 5);

	myvector.erase(myvector.begin(), myvector.begin() + 3);

	std::cout << "myvector contains:";
	for (unsigned i = 0; i < myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

template<typename T>
void	vector_swap( void )
{
	NAMESPACE::vector<T>					foo;
	NAMESPACE::vector<T>					bar;

	for (unsigned i = 0; i < 10; i++)
		foo.push_back(100 + i);

	for (unsigned i = 0; i < 18; i++)
		bar.push_back(200 + i);
	
	typename NAMESPACE::vector<T>::iterator	it_foo = foo.begin();
	typename NAMESPACE::vector<T>::iterator	it_bar = bar.begin();

	it_foo++;
	it_bar++;
	std::cout << "BEFORE SWAP" << std::endl;
	std::cout << "foo contains:";
	for (unsigned i = 0; i < foo.size(); i++)
		std::cout << ' ' << foo[i];
	std::cout << '\n';

	std::cout << "bar contains:";
	for (unsigned i = 0; i < bar.size(); i++)
		std::cout << ' ' << bar[i];
	std::cout << '\n';

	std::cout << "foo iterator: " << *it_foo << std::endl;
	std::cout << "bar iterator: " << *it_bar << std::endl;
	
	foo.swap(bar);

	std::cout << "AFTER SWAP" << std::endl;
	std::cout << "foo contains:";
	for (unsigned i = 0; i < foo.size(); i++)
		std::cout << ' ' << foo[i];
	std::cout << '\n';

	std::cout << "bar contains:";
	for (unsigned i = 0; i < bar.size(); i++)
		std::cout << ' ' << bar[i];
	std::cout << '\n';

	std::cout << "foo iterator: " << (*it_foo) << std::endl;
	std::cout << "bar iterator: " << (*it_bar)<< std::endl;
}

template<typename T>
void	vector_clear( void )
{
	NAMESPACE::vector<T>	myvector;
	myvector.push_back("hola");
	myvector.push_back("como");
	myvector.push_back("estas");

	std::cout << "myvector contains:";
	for (unsigned i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	myvector.clear();
	myvector.push_back("Salut");
	myvector.push_back("Hello");

	std::cout << "myvector contains:";
	for (unsigned i = 0; i < myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

template<typename T>
void	vector_get_allocator( void )
{
	NAMESPACE::vector<T>	myvector;
	int	*p;
	unsigned int	i;

	p = myvector.get_allocator().allocate(5);

	for (i = 0; i < 5; i++)
		myvector.get_allocator().construct(&p[i],i);

	std::cout << "The allocated array contains:";
	for (i = 0; i < 5; i++)
		std::cout << ' ' << p[i];
	std::cout << '\n';

	for (i = 0; i < 5; i++)
		myvector.get_allocator().destroy(&p[i]);
	myvector.get_allocator().deallocate(p,5);
}

template<typename T>
void	non_member_swap( void )
{
	NAMESPACE::vector<T>	foo(3,100);
	NAMESPACE::vector<T>	bar(5,200);

	foo.swap(bar);

	std::cout << "foo contains:";
	for (typename NAMESPACE::vector<T>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "bar contains:";
	for (typename NAMESPACE::vector<T>::iterator it = bar.begin(); it!=bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

template<typename T>
void	relational_operators( void )
{
	NAMESPACE::vector<T> foo(3, "Hola");
	NAMESPACE::vector<T> bar(2, "Bonjour");

	if (foo==bar)
		std::cout << "foo and bar are equal\n";
	if (foo!=bar)
		std::cout << "foo and bar are not equal\n";
	if (foo< bar)
		std::cout << "foo is less than bar\n";
	if (foo> bar)
		std::cout << "foo is greater than bar\n";
	if (foo<=bar)
		std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar)
		std::cout << "foo is greater than or equal to bar\n";
}

template<typename T>
void	vector_iterator_traits( void )
{
	typedef NAMESPACE::iterator_traits<typename NAMESPACE::vector<T>::iterator >	traits;

	if (typeid(typename traits::iterator_category) == typeid(NAMESPACE::random_access_iterator_tag))
		std::cout << "vector has a random-access iterator" << std::endl;
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
	constructing_vectors<double>();
	constructing_vectors<int>();
	vector_assignment<std::string>();
	vector_begin_end<int>();
	vector_rbegin_rend<int>();
	vector_size<std::string>();
	vector_capacity<int>();
	vector_resize<int>();
	vector_empty<int>();
	vector_reserve<int>();
	vector_operator_access_element<int>();
	vector_at<int>();
	vector_front<int>();
	vector_back<int>();
	vector_assign<int>();
	vector_push_back<int>();
	vector_pop_back<int>();
	vector_insert<int>();
	vector_erase<int>();
	vector_swap<int>();
	vector_clear<std::string>();
	vector_get_allocator<int>();
	non_member_swap<int>();
	relational_operators<std::string>();

	vector_iterator_traits<std::string>();
	/*--------------------------------------------------------------------*/
	gettimeofday(&end_time, NULL);
	s_time = (start_time.tv_sec * 1000000) + (start_time.tv_usec);
	e_time = (end_time.tv_sec * 1000000) + (end_time.tv_usec);
	diff_time = e_time - s_time;
	std::cerr << NAME << "time:[" << diff_time << " microseconds]" << std::endl;
	return (0);
}
