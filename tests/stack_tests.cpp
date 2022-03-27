/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:49:13 by abesombe          #+#    #+#             */
/*   Updated: 2022/03/27 18:50:31 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include "../stack.hpp"
#include <stack>
#include <vector>
#include <deque>
#include <list>
#include <ctime>
#include <sys/time.h>
#include <unistd.h>

#ifdef NAMESPACE
# define NAME "std "
#endif
#ifndef NAMESPACE
# define NAMESPACE ft
# define NAME "ft  "
#endif

template<typename T>
void	constructing_stacks( void )
{
	std::deque<T>			mydeque(3, 100);
	std::list<T>			mylist(4, 400);
	std::vector<T>			stdVector(5, 500);
	NAMESPACE::vector<T>	myvector(6, 600);

	NAMESPACE::stack<T>							first;
	NAMESPACE::stack<T, std::deque<T> >			second(mydeque);
	NAMESPACE::stack<T, std::list<T> >			third(mylist);
	NAMESPACE::stack<T, std::vector<T> >		fourth(stdVector);
	NAMESPACE::stack<T, NAMESPACE::vector<T> >	fifth(myvector);

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size() << '\n';
	std::cout << "size of fifth: " << fifth.size() << '\n';
}

template<typename T>
void	stack_empty( void )
{
	NAMESPACE::stack<T>	mystack;
	int sum(0);

	for (int i = 1; i <= 1000000;i++)
		mystack.push(i);

	while (!mystack.empty())
	{
		sum += mystack.top();
		mystack.pop();
	}
	std::cout << "total: " << sum << '\n';
}

template<typename T>
void	stack_size( void )
{
	NAMESPACE::stack<T>	myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i = 0; i < 5; i++)
		myints.push(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.pop();
	std::cout << "2. size: " << myints.size() << '\n';
}

template<typename T>
void	stack_top( void )
{
	NAMESPACE::stack<T>	mystack;

	mystack.push(10);
	mystack.push(20);

	mystack.top() -= 5;

	std::cout << "mystack.top() is now " << mystack.top() << '\n';
}

template<typename T>
void	stack_push_pop( void )
{
	NAMESPACE::stack<T>	mystack;

	for (int i = 0; i < 5; ++i)
		mystack.push(i);

	std::cout << "Popping out elements...";
	while (!mystack.empty())
	{
		std::cout << ' ' << mystack.top();
		mystack.pop();
	}
	std::cout << '\n';
}

template<typename T>
void	relational_operators( void )
{
	NAMESPACE::stack<T> a, b, c;
	a.push("hola");
	a.push("como");
	a.push("estas");

	b.push("hola");
	b.push("como");
	b.push("estas");

	c.push("estas");
	c.push("como");
	c.push("hola");

	if (a == b)
		std::cout << "a and b are equal\n";
	if (b != c)
		std::cout << "b and c are not equal\n";
	if (b < c)
		std::cout << "b is less than c\n";
	if (c > b)
		std::cout << "c is greater than b\n";
	if (a <= b)
		std::cout << "a is less than or equal to b\n";
	if (a >= b)
		std::cout << "a is greater than or equal to b\n";
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
	constructing_stacks<int>();
	stack_empty<int>();
	stack_size<int>();
	stack_top<int>();
	stack_push_pop<int>();
	relational_operators<std::string>();
	/*--------------------------------------------------------------------*/

	gettimeofday(&end_time, NULL);
	s_time = (start_time.tv_sec * 1000000) + (start_time.tv_usec);
	e_time = (end_time.tv_sec * 1000000) + (end_time.tv_usec);
	diff_time = e_time - s_time;
	std::cerr << NAME << "time:[" << diff_time << " microseconds]" << std::endl;
	return 0;
}
