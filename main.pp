/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:34:41 by abesombe          #+#    #+#             */
/*   Updated: 2022/03/23 00:30:34 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// #include "vector.hpp"
// #include "stack.hpp"
#include "map.hpp"
#include "utils/pair.hpp"
#include "utils/red_black_tree.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <utility>
#include <map>
#include <fstream>
    
template <typename T>
void autohundreds(std::vector<T> &v)
{
    for (size_t i = 0; i < v.size(); i++)
        v[i] = 100 * (i + 1);
}

template <typename T>
void print_STLVec(std::vector<T> &v)
{
    std::cout << "\n-----------------------------------------" << std::endl; 
    std::cout << "---- STL VECTOR PRINTING (" << v.size() << "/" << v.capacity() << ") -----" << std::endl;
    std::cout << "-----------------------------------------" << std::endl; 
    for (size_t i = 0; i < v.size() ; i++)
    std::cout << "v[" << i << "]: " << v[i] << " - addr = "  << &v[i] << std::endl;
    std::cout << "-----------------------------------------" << std::endl; 
    std::cout << "-----------------------------------------\n" << std::endl; 
}

// // --- Class foo
// template <typename T>
// class foo {
// 	public:
// 		typedef T	value_type;

// 		foo(void) : value(), _verbose(false) { };
// 		foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
// 		foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
// 		~foo(void) { if (this->_verbose) std::cout << "~foo::foo()" << std::endl; };
// 		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
// 		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
// 		foo &operator=(value_type src) { this->value = src; return *this; };
// 		foo &operator=(foo const &src) {
// 			if (this->_verbose || src._verbose)
// 				std::cout << "foo::operator=(foo) CALLED" << std::endl;
// 			this->value = src.value;
// 			return *this;
// 		};
// 		value_type	getValue(void) const { return this->value; };
// 		void		switchVerbose(void) { this->_verbose = !(this->_verbose); };

// 		operator value_type(void) const {
// 			return value_type(this->value);
// 		}
// 	private:
// 		value_type	value;
// 		bool		_verbose;
// };

// template <typename T>
// std::ostream	&operator<<(std::ostream &o, foo<T> const &bar) {
// 	o << bar.getValue();
// 	return o;
// }
// // --- End of class foo

// template <typename Ite_1, typename Ite_2>
// void ft_eq_ope(const Ite_1 &first, const Ite_2 &second, const bool redo = 1)
// {
// 	std::cout << (first < second) << std::endl;
// 	std::cout << (first <= second) << std::endl;
// 	std::cout << (first > second) << std::endl;
// 	std::cout << (first >= second) << std::endl;
// 	if (redo)
// 		ft_eq_ope(second, first, 0);
// }

int main()
{

        
    /* DERNIER TEST VECTOR QUI NE PASSE PAS - IL FAUT TROUVER UNE SOLUTION */
    // const int size = 5;
	// ft::vector<int> const vct(size);
	// ft::vector<int>::const_iterator it = vct.begin(); // <-- error expected
    
    // TESTS POUR MAP
    
    // ft::RBTree<int, std::string> RedBlackT;
    // ft::bidirectional_iterator<int, std::string, > it;

    // std::map<char,int> map1;
  
    // // initializing
    // map1['a']=10;
    // map1['b']=20;
    // map1['c']=30;
    // map1['d']=40;
    
    std::map<int, std::string> smap1;
    for (std::map<int, std::string>::iterator it2 = smap1.begin(); it2 != smap1.end(); ++it2)
    {
        std::cout << it2->first << " => " << it2->second << '\n';
    }
    std::pair<int, std::string> sp1 = std::make_pair(445, "Hong Kong");
    std::pair<int, std::string> sp2 = std::make_pair(125, "Bangkok");
    std::pair<int, std::string> sp3 = std::make_pair(484, "London");
    std::pair<int, std::string> sp4 = std::make_pair(40, "Moscow");
    std::pair<int, std::string> sp5 = std::make_pair(60, "NYC");
    std::pair<int, std::string> sp6 = std::make_pair(20, "Madrid");
    std::pair<int, std::string> sp7 = std::make_pair(30, "Los Angeles");
    smap1.insert(sp1);
    std::cout << "\n=============================== STD - MAP CONTENT - 1 element - increasing order ==================================\n\n";
    for (std::map<int, std::string>::iterator it2 = smap1.begin(); it2 != smap1.end(); ++it2)
    {
        std::cout << it2->first << " => " << it2->second << '\n';
    }
    std::cout << "\n=============================== STD - Checking reverse iterator with 1 element starting from rbegin() ==================================\n\n";
    std::map<int, std::string>::reverse_iterator rit1 = smap1.rbegin();
    std::cout << "rbegin: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rbegin: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rbegin: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rbegin: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rbegin: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rbegin: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rbegin: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rbegin: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rbegin: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rbegin: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rbegin: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rbegin: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rbegin: " << (*rit1).first << std::endl;
    rit1 = smap1.rbegin();
    std::cout << "\n---------------------------\nrbegin: " << (*rit1).first << std::endl;
    ++rit1;
    std::cout << "++rbegin: " << (*rit1).first << std::endl;
    ++rit1;
    std::cout << "++rbegin: " << (*rit1).first << std::endl;    
    ++rit1;
    std::cout << "++rbegin: " << (*rit1).first << std::endl;    
    ++rit1;
    std::cout << "++rbegin: " << (*rit1).first << std::endl;
    ++rit1;
    std::cout << "++rbegin: " << (*rit1).first << std::endl;    
    ++rit1;
    std::cout << "++rbegin: " << (*rit1).first << std::endl;    
    ++rit1;
    std::cout << "++rbegin: " << (*rit1).first << std::endl;    
    ++rit1;
    std::cout << "++rbegin: " << (*rit1).first << std::endl;    
    ++rit1;
    std::cout << "++rbegin: " << (*rit1).first << std::endl;    
    ++rit1;
    std::cout << "++rbegin: " << (*rit1).first << std::endl;    
    ++rit1;
    std::cout << "++rbegin: " << (*rit1).first << std::endl;
    smap1.insert(sp2);
    std::cout << "\n=============================== STD - MAP CONTENT - 2 elements - increasing order ==================================\n\n";
    for (std::map<int, std::string>::iterator it2 = smap1.begin(); it2 != smap1.end(); ++it2)
    {
        std::cout << it2->first << " => " << it2->second << '\n';
    }
    std::cout << "\n=============================== STD - Checking reverse iterator with 2 elements starting from rbegin() ==================================\n\n";
    rit1 = smap1.rbegin();
    std::cout << "rbegin: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rbegin: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rbegin: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rbegin: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rbegin: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rbegin: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rbegin: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rbegin: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rbegin: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rbegin: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rbegin: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rbegin: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rbegin: " << (*rit1).first << std::endl;
    rit1 = smap1.rbegin();
    std::cout << "\n---------------------------\nrbegin: " << (*rit1).first << std::endl;
    ++rit1;
    std::cout << "++rbegin: " << (*rit1).first << std::endl;
    ++rit1;
    std::cout << "++rbegin: " << (*rit1).first << std::endl;    
    ++rit1;
    std::cout << "++rbegin: " << (*rit1).first << std::endl;    
    ++rit1;
    std::cout << "++rbegin: " << (*rit1).first << std::endl;
    ++rit1;
    std::cout << "++rbegin: " << (*rit1).first << std::endl;    
    ++rit1;
    std::cout << "++rbegin: " << (*rit1).first << std::endl;    
    ++rit1;
    std::cout << "++rbegin: " << (*rit1).first << std::endl;    
    ++rit1;
    std::cout << "++rbegin: " << (*rit1).first << std::endl;    
    ++rit1;
    std::cout << "++rbegin: " << (*rit1).first << std::endl;    
    ++rit1;
    std::cout << "++rbegin: " << (*rit1).first << std::endl;    
    ++rit1;
    std::cout << "++rbegin: " << (*rit1).first << std::endl;

    smap1.insert(sp3);
    smap1.insert(sp4);
    smap1.insert(sp5);
    smap1.insert(sp6);
    smap1.insert(sp7);


    std::cout << "\n=============================== STD - MAP CONTENT - 7 elements - decreasing order ==================================\n\n";
    for (std::map<int, std::string>::iterator it2 = --smap1.end(); it2 != smap1.begin(); --it2)
    {
        std::cout << it2->first << " => " << it2->second << '\n';
    }
    std::cout << "SMAP1 MAX_SIZE: " << smap1.max_size() << std::endl;

    std::map<int, std::string>::iterator it3 = smap1.end();
    std::map<int, std::string>::iterator it4 = smap1.begin();
    it4++;
    it4++;
    it4++;

    it3--;
    it3--;
    it3--;
    std::cout << "*it4: " << (*it4).first << std::endl;
    std::cout << "*it3: " << (*it3).first << std::endl;
    
    std::cout << "begin < end? " << smap1.value_comp()(*it4, *it3) << std::endl;
    std::cout << "\n=============================== STD - Checking reverse iterator with 7 elements starting from rend() ==================================\n\n";
    rit1 = smap1.rend();
    std::cout << "rend: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rend: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rend: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rend: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rend: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rend: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rend: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rend: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rend: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rend: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rend: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rend: " << (*rit1).first << std::endl;
    --rit1;
    std::cout << "--rend: " << (*rit1).first << std::endl;
    
    rit1 = smap1.rend();
    std::cout << "\n---------------------------\nrend: " << (*rit1).first << std::endl;
    ++rit1;
    std::cout << "++rend: " << (*rit1).first << std::endl;
    ++rit1;
    std::cout << "++rend: " << (*rit1).first << std::endl;
    ++rit1;
    std::cout << "++rend: " << (*rit1).first << std::endl;
    ++rit1;
    std::cout << "++rend: " << (*rit1).first << std::endl;
    ++rit1;
    std::cout << "++rend: " << (*rit1).first << std::endl;    
    ++rit1;
    std::cout << "++rend: " << (*rit1).first << std::endl;
    ++rit1;
    std::cout << "++rend: " << (*rit1).first << std::endl; 
    ++rit1;
    std::cout << "++rend: " << (*rit1).first << std::endl; 
    ++rit1;
    std::cout << "++rend: " << (*rit1).first << std::endl;  
    ++rit1;
    std::cout << "++rend: " << (*rit1).first << std::endl;   
    ++rit1;
    std::cout << "++rend: " << (*rit1).first << std::endl;
    

    std::cout << "\n=============================== STD - Checking normal iterator from begin() ==================================\n\n";
    std::map<int, std::string>::iterator it1 = smap1.begin();
    std::cout << "begin: " << (*it1).first << std::endl;
    --it1;
    std::cout << "--begin: " << (*it1).first << std::endl;
    --it1;
    std::cout << "--begin: " << (*it1).first << std::endl;
    --it1;
    std::cout << "--begin: " << (*it1).first << std::endl;
    --it1;
    std::cout << "--begin: " << (*it1).first << std::endl;
    --it1;
    std::cout << "--begin: " << (*it1).first << std::endl;
    --it1;
    std::cout << "--begin: " << (*it1).first << std::endl;
    --it1;
    std::cout << "--begin: " << (*it1).first << std::endl;
    --it1;
    std::cout << "--begin: " << (*it1).first << std::endl;
    --it1;
    std::cout << "--begin: " << (*it1).first << std::endl;
    --it1;
    std::cout << "--begin: " << (*it1).first << std::endl;
    --it1;
    std::cout << "--begin: " << (*it1).first << std::endl;
    it1 = smap1.begin();
    std::cout << "\n---------------------------\nbegin: " << (*it1).first << std::endl;
    ++it1;
    std::cout << "++begin: " << (*it1).first << std::endl;
    ++it1;
    std::cout << "++begin: " << (*it1).first << std::endl; 
    ++it1;
    std::cout << "++begin: " << (*it1).first << std::endl;  
    ++it1;
    std::cout << "++begin: " << (*it1).first << std::endl;
    ++it1;
    std::cout << "++begin: " << (*it1).first << std::endl;
    ++it1;
    std::cout << "++begin: " << (*it1).first << std::endl; 
    ++it1;
    std::cout << "++begin: " << (*it1).first << std::endl;  
    ++it1;
    std::cout << "++begin: " << (*it1).first << std::endl;
    ++it1;
    std::cout << "++begin: " << (*rit1).first << std::endl;    
    ++it1;
    std::cout << "++begin: " << (*it1).first << std::endl;
    ++it1;
    std::cout << "++begin: " << (*it1).first << std::endl;  

    std::cout << "\n=============================== STD - Checking normal iterator from end() ==================================\n\n";
    it1 = smap1.end();
    std::cout << "end: " << (*it1).first << std::endl;
    --it1;
    std::cout << "--end: " << (*it1).first << std::endl;
    --it1;
    std::cout << "--end: " << (*it1).first << std::endl;
    --it1;
    std::cout << "--end: " << (*it1).first << std::endl;
    --it1;
    std::cout << "--end: " << (*it1).first << std::endl;
    --it1;
    std::cout << "--end: " << (*it1).first << std::endl;
    --it1;
    std::cout << "--end: " << (*it1).first << std::endl;
    --it1;
    std::cout << "--end: " << (*it1).first << std::endl;
    --it1;
    std::cout << "--end: " << (*it1).first << std::endl;
    --it1;
    std::cout << "--end: " << (*it1).first << std::endl;
    --it1;
    std::cout << "--end: " << (*it1).first << std::endl;
    --it1;
    std::cout << "--end: " << (*it1).first << std::endl;
    --it1;
    std::cout << "--end: " << (*it1).first << std::endl;
    --it1;
    std::cout << "--end: " << (*it1).first << std::endl;

    it1 = smap1.end();
    std::cout << "\n---------------------------\nend: " << (*it1).first << std::endl;
    ++it1;
    std::cout << "++end: " << (*it1).first << std::endl;
    ++it1;
    std::cout << "++end: " << (*it1).first << std::endl;
    ++it1;
    std::cout << "++end: " << (*it1).first << std::endl;
    ++it1;
    std::cout << "++end: " << (*it1).first << std::endl;
    ++it1;
    std::cout << "++end: " << (*it1).first << std::endl;
    ++it1;
    std::cout << "++end: " << (*it1).first << std::endl;
    ++it1;
    std::cout << "++end: " << (*it1).first << std::endl;
    ++it1;
    std::cout << "++end: " << (*it1).first << std::endl;
    ++it1;
    std::cout << "++end: " << (*it1).first << std::endl;   
    ++it1;
    it1 = smap1.find(484);
    std::cout << "search for 484: " << (*it1).first << std::endl;
    std::cout << "Lower bound of 484: " << smap1.lower_bound(484)->first << std::endl;
    std::cout << "Lower bound of 480: " << smap1.lower_bound(480)->first << std::endl;
    std::cout << "Upper bound of 484: " << smap1.upper_bound(484)->first << std::endl;
    std::cout << "Upper bound of 480: " << smap1.upper_bound(480)->first << std::endl;
    std::cout << "Equal Range of 60: it1 =  " << smap1.equal_range(60).first->first << std::endl;
    std::cout << "Equal Range of 60: it2 = " << smap1.equal_range(60).second->first << std::endl;
    std::cout << "Equal Range of 55: it1 =  " << smap1.equal_range(55).first->first << std::endl;
    std::cout << "Equal Range of 55: it2 = " << smap1.equal_range(55).second->first << std::endl;
    for (std::map<int, std::string>::iterator it2 = --smap1.end(); it2 != smap1.begin(); --it2)
    {
        std::cout << it2->first << " => " << it2->second << '\n';
    }
    smap1.clear();
    std::map<int, std::string> smap3;
    std::map<int, std::string> smap4;
    smap3[10]="aaaaaa";
    smap3[20]="bbbbbb";
    smap3[30]="cccccc";
    smap3[40]="dddddd";
    smap4[2]="triangle";
    smap4[4]="square";
    smap4[8]="cube";
    smap4[16]="sphere";
    smap4[32]="octogon";
    smap4[64]="hexagon";
    smap4[128]="cylinder";
    smap4[256]="pipe";
    std::cout << "before swap\n";
    for (std::map<int, std::string>::iterator it2 = smap3.begin(); it2 != smap3.end(); ++it2)
    {
        std::cout << it2->first << " => " << it2->second << '\n';
    }
    smap3.swap(smap4);
    std::cout << "after swap\n";
    for (std::map<int, std::string>::iterator it2 = smap3.begin(); it2 != smap3.end(); ++it2)
    {
        std::cout << it2->first << " => " << it2->second << '\n';
    }

    std::cout << "\n============================================================= THE END ========================================================\n";
    std::cout << "\n==============================================================================================================================\n";
    std::cout << "\n==============================================================================================================================\n\n\n\n\n\n\n\n"; 
    // for (std::map<int, std::string>::iterator it2 = --smap1.end(); it2 != smap1.begin(); --it2)
    // {
    //     std::cout << it2->first << " => " << it2->second << '\n';
    // }
    // rit1 = smap1.end();
    // std::cout << "end: " << (*rit1).first << std::endl; 
    // rit1--;
    // std::cout << "end--: " << (*rit1).first << std::endl; 
    // std::pair<std::map<int, std::string>::iterator, bool> ret;
    // ret = map1.insert(p1);
    // std::cout << "wasInserted? " << ret.second << std::endl;
    // ret = map1.insert(p1);
    // std::cout << "wasInserted? " << ret.second << std::endl;
    
    // std::map<char, int>::iterator it;
    // std::map<char, int>::reverse_iterator rit;
    // map1.insert
    // rit = map1.rend();
    // // --rit;
    // std::cout << "*rit: " << (*rit).second << std::endl;
    // rrit++;
    // it = map1.begin();
    // std::cout << "(*it).first: " << (*it).first << std::endl;
    // std::cout << "(*it).second: " << (*it).second << std::endl;
    // std::cout << "it->first: " << it->first << std::endl;
    // std::cout << "it->second: " << it->second << std::endl;
    // for(it=map1.begin(); it!=map1.end(); ++it){
    //     std::cout << it->first << " => " << it->second << '\n';
    // }


    ft::map<int, std::string> map1;

    ft::pair<int, std::string> p1 = ft::make_pair(10, "Hong Kong");
    ft::pair<int, std::string> p2 = ft::make_pair(20, "Bangkok");
    ft::pair<int, std::string> p3 = ft::make_pair(484, "London");
    ft::pair<int, std::string> p4 = ft::make_pair(40, "Moscow");
    ft::pair<int, std::string> p5 = ft::make_pair(60, "NYC");
    ft::pair<int, std::string> p6 = ft::make_pair(50, "Madrid");
    ft::pair<int, std::string> p7 = ft::make_pair(30, "Los Angeles");
    map1.insert(p1);
    std::cout << "\n=============================== FT - MAP CONTENT - 1 element - increasing order ==================================\n\n";
    for (ft::map<int, std::string>::iterator it2 = map1.begin(); it2 != map1.end(); ++it2)
    {
        std::cout << it2->first << " => " << it2->second << '\n';
    }
    std::cout << "\n=============================== FT - Checking reverse iterator with 1 element starting from rbegin() ==================================\n\n";
    ft::map<int, std::string>::reverse_iterator rit = map1.rbegin();
    std::cout << "rbegin: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rbegin: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rbegin: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rbegin: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rbegin: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rbegin: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rbegin: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rbegin: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rbegin: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rbegin: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rbegin: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rbegin: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rbegin: " << (*rit).first << std::endl;
    rit = map1.rbegin();
    std::cout << "\n---------------------------\nrbegin: " << (*rit).first << std::endl;
    ++rit;
    std::cout << "++rbegin: " << (*rit).first << std::endl;
    ++rit;
    std::cout << "++rbegin: " << (*rit).first << std::endl;    
    ++rit;
    std::cout << "++rbegin: " << (*rit).first << std::endl;    
    ++rit;
    std::cout << "++rbegin: " << (*rit).first << std::endl;
    ++rit;
    std::cout << "++rbegin: " << (*rit).first << std::endl;    
    ++rit;
    std::cout << "++rbegin: " << (*rit).first << std::endl;    
    ++rit;
    std::cout << "++rbegin: " << (*rit).first << std::endl;    
    ++rit;
    std::cout << "++rbegin: " << (*rit).first << std::endl;    
    ++rit;
    std::cout << "++rbegin: " << (*rit).first << std::endl;    
    ++rit;
    std::cout << "++rbegin: " << (*rit).first << std::endl;    
    ++rit;
    std::cout << "++rbegin: " << (*rit).first << std::endl;

    map1.insert(p2);
    std::cout << "\n=============================== FT - MAP CONTENT - 2 elements - increasing order ==================================\n\n";
    for (ft::map<int, std::string>::iterator it2 = map1.begin(); it2 != map1.end(); ++it2)
    {
        std::cout << it2->first << " => " << it2->second << '\n';
    }
    std::cout << "\n=============================== FT - Checking reverse iterator with 2 elements starting from rbegin() ==================================\n\n";
    rit = map1.rbegin();
    std::cout << "rbegin: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rbegin: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rbegin: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rbegin: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rbegin: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rbegin: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rbegin: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rbegin: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rbegin: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rbegin: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rbegin: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rbegin: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rbegin: " << (*rit).first << std::endl;
    rit = map1.rbegin();
    std::cout << "\n---------------------------\nrbegin: " << (*rit).first << std::endl;
    ++rit;
    std::cout << "++rbegin: " << (*rit).first << std::endl;
    ++rit;
    std::cout << "++rbegin: " << (*rit).first << std::endl;    
    ++rit;
    std::cout << "++rbegin: " << (*rit).first << std::endl;    
    ++rit;
    std::cout << "++rbegin: " << (*rit).first << std::endl;
    ++rit;
    std::cout << "++rbegin: " << (*rit).first << std::endl;    
    ++rit;
    std::cout << "++rbegin: " << (*rit).first << std::endl;    
    ++rit;
    std::cout << "++rbegin: " << (*rit).first << std::endl;    
    ++rit;
    std::cout << "++rbegin: " << (*rit).first << std::endl;    
    ++rit;
    std::cout << "++rbegin: " << (*rit).first << std::endl;    
    ++rit;
    std::cout << "++rbegin: " << (*rit).first << std::endl;    
    ++rit;
    std::cout << "++rbegin: " << (*rit).first << std::endl;

    map1.insert(p3);
    map1.insert(p4);
    map1.insert(p5);
    map1.insert(p6);
    map1.insert(p7);

    ft::map<int, std::string> map2(map1);
    ft::map<int, std::string> map7;
    std::cout << "\n=============================== FT - MAP7 CONTENT - 2 elements - increasing order ==================================\n\n";
    ft::map<int, std::string>::iterator it7e = map1.begin();
    it7e++;
    it7e++;
    map7.insert(++map1.begin(), it7e);
    std::cout << "Size: " << map7.size() << std::endl;
    for (ft::map<int, std::string>::iterator it2 = map7.begin(); it2 != map7.end(); ++it2)
    {
        std::cout << it2->first << " => " << it2->second << '\n';
    }
    // map1.getRBTree().printRBT();
    std::cout << "\n=============================== FT - MAP1 CONTENT - 7 elements - decreasing order ==================================\n\n";
    for (ft::map<int, std::string>::iterator it2 = --map1.end(); it2 != --map1.begin(); --it2)
    {
        std::cout << it2->first << " => " << it2->second << '\n';
    }
    std::cout << "MAX_SIZE: " << map1.max_size() << std::endl;
    std::cout << "\n=============================== FT - MAP2 CONTENT (Copy of Map1) - 7 elements - decreasing order ==================================\n\n";
    for (ft::map<int, std::string>::iterator it2 = --map1.end(); it2 != --map1.begin(); --it2)
    {
        std::cout << it2->first << " => " << it2->second << '\n';
    }
    std::cout << "\n=============================== FT - Checking reverse iterator with 7 elements starting from rend() ==================================\n\n";
    rit = map1.rend();
    std::cout << "rend: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rend: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rend: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rend: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rend: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rend: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rend: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rend: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rend: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rend: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rend: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rend: " << (*rit).first << std::endl;
    --rit;
    std::cout << "--rend: " << (*rit).first << std::endl;
    
    rit = map1.rend();
    std::cout << "\n---------------------------\nrend: " << (*rit).first << std::endl;
    ++rit;
    std::cout << "++rend: " << (*rit).first << std::endl;
    ++rit;
    std::cout << "++rend: " << (*rit).first << std::endl;
    ++rit;
    std::cout << "++rend: " << (*rit).first << std::endl;
    ++rit;
    std::cout << "++rend: " << (*rit).first << std::endl;
    ++rit;
    std::cout << "++rend: " << (*rit).first << std::endl;    
    ++rit;
    std::cout << "++rend: " << (*rit).first << std::endl;
    ++rit;
    std::cout << "++rend: " << (*rit).first << std::endl; 
    ++rit;
    std::cout << "++rend: " << (*rit).first << std::endl; 
    ++rit;
    std::cout << "++rend: " << (*rit).first << std::endl;  
    ++rit;
    std::cout << "++rend: " << (*rit).first << std::endl;   
    ++rit;
    std::cout << "++rend: " << (*rit).first << std::endl;
    

    std::cout << "\n=============================== FT - Checking normal iterator from begin() ==================================\n\n";
    ft::map<int, std::string>::iterator it = map1.begin();
    std::cout << "begin: " << (*it).first << std::endl;
    --it;
    std::cout << "--begin: " << (*it).first << std::endl;
    --it;
    std::cout << "--begin: " << (*it).first << std::endl;
    --it;
    std::cout << "--begin: " << (*it).first << std::endl;
    --it;
    std::cout << "--begin: " << (*it).first << std::endl;
    --it;
    std::cout << "--begin: " << (*it).first << std::endl;
    --it;
    std::cout << "--begin: " << (*it).first << std::endl;
    --it;
    std::cout << "--begin: " << (*it).first << std::endl;
    --it;
    std::cout << "--begin: " << (*it).first << std::endl;
    --it;
    std::cout << "--begin: " << (*it).first << std::endl;
    --it;
    std::cout << "--begin: " << (*it).first << std::endl;
    --it;
    std::cout << "--begin: " << (*it).first << std::endl;
    it = map1.begin();
    std::cout << "\n---------------------------\nbegin: " << (*it).first << std::endl;
    ++it;
    std::cout << "++begin: " << (*it).first << std::endl;
    ++it;
    std::cout << "++begin: " << (*it).first << std::endl; 
    ++it;
    std::cout << "++begin: " << (*it).first << std::endl;  
    ++it;
    std::cout << "++begin: " << (*it).first << std::endl;
    ++it;
    std::cout << "++begin: " << (*it).first << std::endl;
    ++it;
    std::cout << "++begin: " << (*it).first << std::endl; 
    ++it;
    std::cout << "++begin: " << (*it).first << std::endl;  
    ++it;
    std::cout << "++begin: " << (*it).first << std::endl;
    ++it;
    std::cout << "++begin: " << (*rit).first << std::endl;    
    ++it;
    std::cout << "++begin: " << (*it).first << std::endl;
    ++it;
    std::cout << "++begin: " << (*it).first << std::endl;  

    it = map1.find(485);
    std::cout << "search for 485: " << (*it).first << std::endl;
    std::cout << "count(485): " << map1.count(485) << std::endl; 
    std::cout << "count(484): " << map1.count(484) << std::endl;
    for (ft::map<int, std::string>::iterator it2 = map1.begin(); it2 != map1.end(); ++it2)
    {
        std::cout << it2->first << " => " << it2->second << '\n';
    }  
    // it = map1.find(40);
    // map1.erase(it);
    // ft::map<int, std::string>::iterator i1b = map1.begin();
    // i1b++;
    // i1b++;
    // ft::map<int, std::string>::iterator i1e = map1.end();    
    // i1e--;
    // i1e--;
    // map1.erase(i1b, i1e);
    // map1.erase(60);
    map1.erase(30);
    // map1.erase(40);
    map1.erase(50);
    ((map1.begin()).getNode())->getRoot()->printNodeSubTree();
    // map1.erase(50);
    // map1.erase(60);
    for (ft::map<int, std::string>::iterator it2 = map1.begin(); it2 != map1.end(); ++it2)
    {
        std::cout << it2->first << " => " << it2->second << '\n';
    }  

    std::cout << "\n=============================== FT - Checking normal iterator from end() ==================================\n\n";
    it = map1.end();
    std::cout << "end: " << (*it).first << std::endl;
    --it;
    std::cout << "--end: " << (*it).first << std::endl;
    --it;
    std::cout << "--end: " << (*it).first << std::endl;
    --it;
    std::cout << "--end: " << (*it).first << std::endl;
    --it;
    std::cout << "--end: " << (*it).first << std::endl;
    --it;
    std::cout << "--end: " << (*it).first << std::endl;
    --it;
    std::cout << "--end: " << (*it).first << std::endl;
    --it;
    std::cout << "--end: " << (*it).first << std::endl;
    --it;
    std::cout << "--end: " << (*it).first << std::endl;
    --it;
    std::cout << "--end: " << (*it).first << std::endl;
    --it;
    std::cout << "--end: " << (*it).first << std::endl;
    --it;
    std::cout << "--end: " << (*it).first << std::endl;
    --it;
    std::cout << "--end: " << (*it).first << std::endl;
    --it;
    std::cout << "--end: " << (*it).first << std::endl;

    it = map1.end();
    std::cout << "\n---------------------------\nend: " << (*it).first << std::endl;
    ++it;
    std::cout << "++end: " << (*it).first << std::endl;
    ++it;
    std::cout << "++end: " << (*it).first << std::endl;
    ++it;
    std::cout << "++end: " << (*it).first << std::endl;
    ++it;
    std::cout << "++end: " << (*it).first << std::endl;
    ++it;
    std::cout << "++end: " << (*it).first << std::endl;
    ++it;
    std::cout << "++end: " << (*it).first << std::endl;
    ++it;
    std::cout << "++end: " << (*it).first << std::endl;
    ++it;
    std::cout << "++end: " << (*it).first << std::endl;
    ++it;
    std::cout << "++end: " << (*it).first << std::endl;   
    ++it;
    std::cout << "Lower bound of 1: " << map1.lower_bound(1)->first << std::endl;
    std::cout << "Lower bound of 19: " << map1.lower_bound(19)->first << std::endl;
    std::cout << "Lower bound of 40: " << map1.lower_bound(40)->first << std::endl;
    std::cout << "Lower bound of 42: " << map1.lower_bound(42)->first << std::endl;
    std::cout << "Upper bound of 484: " << map1.upper_bound(484)->first << std::endl;
    std::cout << "Upper bound of 480: " << map1.upper_bound(480)->first << std::endl;
    std::cout << "Equal Range of 60: it1 =  " << map1.equal_range(60).first->first << std::endl;
    std::cout << "Equal Range of 60: it2 = " << map1.equal_range(60).second->first << std::endl;
    std::cout << "Equal Range of 55: it1 =  " << map1.equal_range(55).first->first << std::endl;
    std::cout << "Equal Range of 55: it2 = " << map1.equal_range(55).second->first << std::endl;
    ft::map<int, std::string>::iterator it5 = map1.begin();
    it5++;
    it5++;
    ft::map<int, std::string>::iterator it6 = map1.begin();
    it6++;
    it6++;
    it6++;
    std::cout << "it5 < it6? " << map1.value_comp()(*it5, *it6) << std::endl;
    for (ft::map<int, std::string>::iterator it2 = map1.begin(); it2 != map1.end(); ++it2)
    {
        std::cout << it2->first << " => " << it2->second << '\n';
    }
    map1.clear();
    // for (ft::map<int, std::string>::iterator it2 = map1.begin(); it2 != map1.end(); ++it2)
    // {
    //     std::cout << it2->first << " => " << it2->second << '\n';
    // }
    std::cout << "\n===============================================================================================================\n";

    ft::map<int, std::string> map3;
    // ft::map<int, std::string> map4;
    // ft::pair<int, std::string> p01 = ft::make_pair(10, "aaaaaa");
    // ft::pair<int, std::string> p02 = ft::make_pair(20, "bbbbbb");
    // ft::pair<int, std::string> p03 = ft::make_pair(30, "cccccc");
    // ft::pair<int, std::string> p04 = ft::make_pair(40, "dddddd");
    // ft::pair<int, std::string> p01 = ft::make_pair(10, "Hong Kong");
    // ft::pair<int, std::string> p02 = ft::make_pair(20, "Bangkok");
    // ft::pair<int, std::string> p03 = ft::make_pair(30, "London");
    // ft::pair<int, std::string> p04 = ft::make_pair(40, "Moscow");
    // ft::pair<int, std::string> p05 = ft::make_pair(50, "NYC");
    // ft::pair<int, std::string> p06 = ft::make_pair(60, "Madrid");
    // ft::pair<int, std::string> p07 = ft::make_pair(70, "Los Angeles");
    map3[10]="aaaaaa";
    map3[20]="bbbbbb";
    map3[30]="cccccc";
    map3[40]="dddddd";
    // map3.insert(p01);
    // map3.insert(p02);
    // map3.insert(p03);
    // map3.insert(p04);
    // map3.insert(p05);
    // map3.insert(p06);
    // map3.insert(p07);
    // map4[2]="triangle";
    // map4[4]="square";
    // map4[8]="cube";
    // map4[16]="sphere";
    // map4[32]="octogon";
    // map4[64]="hexagon";
    // map4[128]="cylinder";
    // map4[256]="pipe";
    // std::cout << "before swap\n";
    for (ft::map<int, std::string>::iterator it2 = map3.begin(); it2 != map3.end(); ++it2)
    {
        std::cout << it2->first << " => " << it2->second << '\n';
    }
    // map3.swap(map4);
    // std::cout << "after swap\n";
    // for (ft::map<int, std::string>::iterator it2 = map3.begin(); it2 != map3.end(); ++it2)
    // {
    //     std::cout << it2->first << " => " << it2->second << '\n';
    // }












    
    // // it = map1.end();
    // ft::pair<int, std::string> p1 = ft::make_pair(445, "Hong Kong");
    // ft::pair<int, std::string> p2 = ft::make_pair(125, "Bangkok");
    // ft::pair<int, std::string> p3 = ft::make_pair(484, "London");
    // ft::pair<int, std::string> p4 = ft::make_pair(40, "Moscow");
    // ft::pair<int, std::string> p5 = ft::make_pair(60, "NYC");
    // ft::pair<int, std::string> p6 = ft::make_pair(20, "Madrid");
    // ft::pair<int, std::string> p7 = ft::make_pair(30, "Los Angeles");
    // // ft::pair<int, std::string> p4 = ft::make_pair(10, "Paris");
    // // // ft::pair<int, std::string> p4 = ft::make_pair(221, "Lahore");
    // // ft::pair<int, std::string> p5 = ft::make_pair(5, "Singapore");
    // // ft::pair<int, std::string> p6 = ft::make_pair(2, "Madrid");
    // ft::map<int, std::string> map1;
    // ft::pair<ft::map<int, std::string>::iterator, bool> ret;
    // // ret = map1.insert(p1);
    // // std::cout << "wasInserted? " << ret.second<< std::endl;
    // // ret = map1.insert(p1);
    // // std::cout << "wasInserted? " << ret.second << "Mapped Value: " << ret.first->second<< std::endl;
    // map1[445] = "Hong Kong";
    // map1[125] = "Bangkok";
    // // map1[484] = "London";
    // // map1[40] = "Moscow";
    // // map1[60] = "NYC";
    // // map1[20] = "Madrid";
    // // map1[30] = "Los Angeles";
    // // map1.insert(p1);
    // // map1.insert(p2);
    // // map1.insert(p3);
    // // map1.insert(p4);
    // // map1.insert(p5);
    // // map1.insert(p6);
    // // map1.insert(p7);
    // // map1[30] = "City of the World";
    // ft::map<int, std::string>::reverse_iterator rit = map1.rbegin();
    // // ft::pair<int, std::string> rpair = *rit;
    // // std::cout << rpair.first << std::endl;

    // std::cout << "\n\n\n****************************************\n\n\nbegin=> (*rit).first: " << (*rit).first << std::endl;
    // rit--;
    // std::cout << "begin-- => (*rit).first: " << (*rit).first << std::endl;
    // rit--;
    // std::cout << "begin-- => (*rit).first: " << (*rit).first << std::endl;
    // rit--;
    // std::cout << "begin-- => (*rit).first: " << (*rit).first << std::endl;
    // rit--;
    // std::cout << "begin-- => (*rit).first: " << (*rit).first << std::endl;
    // rit--;
    // std::cout << "begin-- => (*rit).first: " << (*rit).first << std::endl;
    // rit--;
    // std::cout << "begin-- => (*rit).first: " << (*rit).first << std::endl;
    // rit--;
    // std::cout << "begin-- => (*rit).first: " << (*rit).first << std::endl;
    // rit--;
    // std::cout << "begin-- => (*rit).first: " << (*rit).first << std::endl;
    // rit--;
    // std::cout << "begin-- => (*rit).first: " << (*rit).first << std::endl;
    // rit--;
    // std::cout << "begin-- => (*rit).first: " << (*rit).first << std::endl;
    // rit--;
    // std::cout << "begin-- => (*rit).first: " << (*rit).first << std::endl;
    // rit--;
    // std::cout << "begin-- => (*rit).first: " << (*rit).first << std::endl;
    // rit--;
    // std::cout << "begin-- => (*rit).first: " << (*rit).first << std::endl;
    // rit--;
    // std::cout << "begin-- => (*rit).first: " << (*rit).first << std::endl;
    // rit--;
    // std::cout << "begin-- => (*rit).first: " << (*rit).first << std::endl;
    // rit--;
    // std::cout << "begin-- => (*rit).first: " << (*rit).first << std::endl;
    
    // rit = map1.rbegin();
    // std::cout << "\n\n\n****************************************\n\n\nbegin=> (*rit).first: " << (*rit).first << std::endl;
    // rit++;
    // std::cout << "begin++ => (*rit).first: " << (*rit).first << std::endl;
    // rit++;
    // std::cout << "begin++ => (*rit).first: " << (*rit).first << std::endl;
    // rit++;
    // std::cout << "begin++ => (*rit).first: " << (*rit).first << std::endl;
    // rit++;
    // std::cout << "begin++ => (*rit).first: " << (*rit).first << std::endl;
    // rit++;
    // std::cout << "begin++ => (*rit).first: " << (*rit).first << std::endl;
    // rit++;
    // std::cout << "begin++ => (*rit).first: " << (*rit).first << std::endl;
    // rit++;
    // std::cout << "begin++ => (*rit).first: " << (*rit).first << std::endl;
    // rit++;
    // std::cout << "begin++ => (*rit).first: " << (*rit).first << std::endl;
    // rit++;
    // std::cout << "begin++ => (*rit).first: " << (*rit).first << std::endl;
    // rit++;
    // std::cout << "begin++ => (*rit).first: " << (*rit).first << std::endl;
    // rit++;
    // std::cout << "begin++ => (*rit).first: " << (*rit).first << std::endl;

    // // it = map1.begin();
    // // std::cout << "\n-----------------------------------------\nbegin => (*it).first: " << (*it).first << std::endl;
    // // rit++;
    // // std::cout << "++begin => (*it).first: " << (*it).first << std::endl;
    // // rit++;
    // // std::cout << "++begin => (*it).first: " << (*it).first << std::endl;
    // // rit++;
    // // std::cout << "++begin => (*it).first: " << (*it).first << std::endl;
    // // rit++;
    // // std::cout << "++begin => (*it).first: " << (*it).first << std::endl;
    // // rit++;
    // // std::cout << "++begin => (*it).first: " << (*it).first << std::endl;
    // // rit++;
    // // std::cout << "++begin => (*it).first: " << (*it).first << std::endl;
    // // it = map1.end();
    // // std::cout << "end => (*it).first: " << (*it).first << std::endl;
    // // --it;
    // // std::cout << "--end => (*it).first: " << (*it).first << std::endl;
    // // std::cout << "map1.end: " << map1.end()->first << map1.end()->second << std::endl;
    // for (ft::map<int, std::string>::iterator it = map1.begin(); it != map1.end(); ++it)
    // {
    //     std::cout << it->first << " => " << it->second << '\n';
    // }
    // ft::map<int, std::string>::iterator it = map1.begin();
    // std::cout << it->first << " => " << it->second << '\n';
    // it++;
    // std::cout << it->first << " => " << it->second << '\n';
    // it++;
    // std::cout << it->first << " => " << it->second << '\n';
    // it++;
    // std::cout << it->first << " => " << it->second << '\n';
    // it++;
    // std::cout << it->first << " => " << it->second << '\n';
    // it++;
    // std::cout << it->first << " => " << it->second << '\n';
    // it++;
    // std::cout << it->first << " => " << it->second << '\n';
    // it++;
    // std::cout << it->first << " => " << it->second << '\n';
    // it++;
    // std::cout << it->first << " => " << it->second << '\n';
    // it++;
    // std::cout << it->first << " => " << it->second << '\n';
    // it++;
    // std::cout << it->first << " => " << it->second << '\n';
    // map1.insert(p2);
    // map1.insert(p3);
    // map1.insert(p4);
    // // map1.insert(p4);
    // map1.insert(p5);
    // map1.insert(p5);
    // ft::bidirectional_iterator<int, std::string> it;
    // it = map1.begin();
    // std::cout << "*it: " << (*it).first << std::endl;
    // rit++;
    // std::cout << "*it: " << (*it).first << std::endl;
    // rit++;
    // std::cout << "*it: " << (*it).first << std::endl;
    // rit++;
    // std::cout << "*it: " << (*it).first << std::endl;
    // std::cout << "*it: " << (*it).second << std::endl;
    // std::map<char, int>::iterator base_rit;
    // base_rit = rit.base();
    // std::cout << "*base_rit: " << (*base_rit).second << std::endl;    
    // rit++;
    // std::cout << "*it: " << (*it).second << std::endl;
    // rit++;
    // std::cout << "*it: " << (*it).second << std::endl;
    // rit++;
    // std::cout << "*it: " << (*it).second << std::endl;
    // rit++;
    // std::cout << "*it: " << (*it).second << std::endl;
    // rit++;
    // std::cout << "*it: " << (*it).second << std::endl;
    // it--;
    // std::cout << "*it: " << (*it).second << std::endl;
    // it--;
    // std::cout << "*it: " << (*it).second << std::endl;
    // it--;
    // std::cout << "*it: " << (*it).second << std::endl;
    // it--;
    // std::cout << "*it: " << (*it).second << std::endl;
    // it--;
    // std::cout << "*it: " << (*it).second << std::endl;
    // it--;
    // std::cout << "*it: " << (*it).second << std::endl;
    // it--;
    // std::cout << "*it: " << (*it).second << std::endl;
    // it--;
    // std::cout << "*it: " << (*it).second << std::endl;
    // it--;
    // std::cout << "*it: " << (*it).second << std::endl;
    // it--;
    // std::cout << "*it: " << (*it).second << std::endl;
    

// ft::pair<int, std::string> p1 = ft::make_pair(445, "Hong Kong");
// ft::pair<int, std::string> p2 = ft::make_pair(125, "Bangkok");
// ft::pair<int, std::string> p3 = ft::make_pair(484, "London");
// ft::pair<int, std::string> p4 = ft::make_pair(221, "Lahore");
// ft::pair<int, std::string> p5 = ft::make_pair(21, "Singapore");
// ft::pair<int, std::string> p6 = ft::make_pair(475, "Paris");
// ft::pair<int, std::string> p7 = ft::make_pair(38, "Dubai");
// ft::pair<int, std::string> p8 = ft::make_pair(358, "New York City");
// ft::pair<int, std::string> p9 = ft::make_pair(84, "Kuala Lumpur");
// ft::pair<int, std::string> p10 = ft::make_pair(248, "Istanbul");
// ft::pair<int, std::string> p11 = ft::make_pair(166, "Delhi");
// ft::pair<int, std::string> p12 = ft::make_pair(16, "Antalya");
// ft::pair<int, std::string> p13 = ft::make_pair(304, "Shenzhen");
// ft::pair<int, std::string> p14 = ft::make_pair(169, "Mumbai");
// ft::pair<int, std::string> p15 = ft::make_pair(290, "Phuket");
// ft::pair<int, std::string> p16 = ft::make_pair(130, "Rome");
// ft::pair<int, std::string> p17 = ft::make_pair(301, "Tokyo");
// ft::pair<int, std::string> p18 = ft::make_pair(215, "Pattaya");
// ft::pair<int, std::string> p19 = ft::make_pair(91, "Taipei");
// ft::pair<int, std::string> p20 = ft::make_pair(110, "Mecca");
// ft::pair<int, std::string> p21 = ft::make_pair(156, "Guangzhou");
// ft::pair<int, std::string> p22 = ft::make_pair(230, "Prague");
// ft::pair<int, std::string> p23 = ft::make_pair(340, "Medina");
// ft::pair<int, std::string> p24 = ft::make_pair(163, "Seoul");
// ft::pair<int, std::string> p25 = ft::make_pair(497, "Amsterdam");
// ft::pair<int, std::string> p26 = ft::make_pair(245, "Agra");
// ft::pair<int, std::string> p27 = ft::make_pair(400, "Miami");
// ft::pair<int, std::string> p28 = ft::make_pair(370, "Osaka");
// ft::pair<int, std::string> p29 = ft::make_pair(120, "Las Vegas");
// ft::pair<int, std::string> p30 = ft::make_pair(186, "Shanghai");
// ft::pair<int, std::string> p31 = ft::make_pair(448, "Ho Chi Minh City");
// ft::pair<int, std::string> p32 = ft::make_pair(239, "Denpasar");
// ft::pair<int, std::string> p33 = ft::make_pair(316, "Barcelona");
// ft::pair<int, std::string> p34 = ft::make_pair(206, "Los Angeles");
// ft::pair<int, std::string> p35 = ft::make_pair(464, "Milan");
// ft::pair<int, std::string> p36 = ft::make_pair(437, "Chennai");
// ft::pair<int, std::string> p37 = ft::make_pair(388, "Vienna");
// ft::pair<int, std::string> p38 = ft::make_pair(100, "Johor Bahru");
// ft::pair<int, std::string> p39 = ft::make_pair(1, "Jaipur");
// ft::pair<int, std::string> p40 = ft::make_pair(450, "Cancún");
// ft::pair<int, std::string> p41 = ft::make_pair(202, "Berlin");
// ft::pair<int, std::string> p42 = ft::make_pair(252, "Cairo");
// ft::pair<int, std::string> p43 = ft::make_pair(111, "Orlando");
// ft::pair<int, std::string> p44 = ft::make_pair(262, "Moscow");
// ft::pair<int, std::string> p45 = ft::make_pair(153, "Venice");
// ft::pair<int, std::string> p46 = ft::make_pair(177, "Madrid");
// ft::pair<int, std::string> p47 = ft::make_pair(66, "Ha Long");
// ft::pair<int, std::string> p48 = ft::make_pair(312, "Riyadh");
// ft::pair<int, std::string> p49 = ft::make_pair(286, "Dublin");
// ft::pair<int, std::string> p50 = ft::make_pair(311, "Florence");
// ft::pair<int, std::string> p51 = ft::make_pair(73, "Jerusalem");
// ft::pair<int, std::string> p52 = ft::make_pair(42, "Hanoi");
// ft::pair<int, std::string> p53 = ft::make_pair(74, "Toronto");
// ft::pair<int, std::string> p54 = ft::make_pair(387, "Johannesburg");
// ft::pair<int, std::string> p55 = ft::make_pair(423, "Sydney");
// ft::pair<int, std::string> p56 = ft::make_pair(276, "Munich");
// ft::pair<int, std::string> p57 = ft::make_pair(17, "Jakarta");
// ft::pair<int, std::string> p58 = ft::make_pair(96, "Beijing");
// ft::pair<int, std::string> p59 = ft::make_pair(257, "Saint Petersburg");
// ft::pair<int, std::string> p60 = ft::make_pair(142, "Brussels");
// ft::pair<int, std::string> p61 = ft::make_pair(317, "Budapest");
// ft::pair<int, std::string> p62 = ft::make_pair(150, "Lisbon");
// ft::pair<int, std::string> p63 = ft::make_pair(182, "Dammam");
// ft::pair<int, std::string> p64 = ft::make_pair(209, "Penang Island");
// ft::pair<int, std::string> p65 = ft::make_pair(315, "Heraklion");
// ft::pair<int, std::string> p66 = ft::make_pair(225, "Kyoto");
// ft::pair<int, std::string> p67 = ft::make_pair(269, "Zhuhai");
// ft::pair<int, std::string> p68 = ft::make_pair(434, "Vancouver");
// ft::pair<int, std::string> p69 = ft::make_pair(333, "Chiang Mai");
// ft::pair<int, std::string> p70 = ft::make_pair(217, "Copenhagen");
// ft::pair<int, std::string> p71 = ft::make_pair(93, "San Francisco");
// ft::pair<int, std::string> p72 = ft::make_pair(246, "Melbourne");
// ft::pair<int, std::string> p73 = ft::make_pair(119, "Warsaw");
// ft::pair<int, std::string> p74 = ft::make_pair(353, "Marrakesh");
// ft::pair<int, std::string> p75 = ft::make_pair(181, "Kolkata");
// ft::pair<int, std::string> p76 = ft::make_pair(451, "Cebu City");
// ft::pair<int, std::string> p77 = ft::make_pair(157, "Auckland");
// ft::pair<int, std::string> p78 = ft::make_pair(140, "Tel Aviv");
// ft::pair<int, std::string> p79 = ft::make_pair(5, "Guilin");
// ft::pair<int, std::string> p80 = ft::make_pair(356, "Honolulu");
// ft::pair<int, std::string> p81 = ft::make_pair(444, "Hurghada");
// ft::pair<int, std::string> p82 = ft::make_pair(135, "Kraków");
// ft::pair<int, std::string> p83 = ft::make_pair(235, "Muğla");
// ft::pair<int, std::string> p84 = ft::make_pair(213, "Buenos Aires");
// ft::pair<int, std::string> p85 = ft::make_pair(3, "Chiba");
// ft::pair<int, std::string> p86 = ft::make_pair(397, "Frankfurt am Main");
// ft::pair<int, std::string> p87 = ft::make_pair(292, "Stockholm");
// ft::pair<int, std::string> p88 = ft::make_pair(360, "Lima");
// ft::pair<int, std::string> p89 = ft::make_pair(274, "Da Nang");
// ft::pair<int, std::string> p90 = ft::make_pair(220, "Batam");
// ft::pair<int, std::string> p91 = ft::make_pair(118, "Nice");
// ft::pair<int, std::string> p92 = ft::make_pair(180, "Fukuoka");
// ft::pair<int, std::string> p93 = ft::make_pair(402, "Abu Dhabi");
// ft::pair<int, std::string> p94 = ft::make_pair(80, "Jeju");
// ft::pair<int, std::string> p95 = ft::make_pair(97, "Porto");
// ft::pair<int, std::string> p96 = ft::make_pair(227, "Rhodes");
// ft::pair<int, std::string> p97 = ft::make_pair(407, "Rio de Janeiro");
// ft::pair<int, std::string> p98 = ft::make_pair(425, "Krabi");
// ft::pair<int, std::string> p99 = ft::make_pair(30, "Bangalore");
// ft::pair<int, std::string> p100 = ft::make_pair(218, "Le Vesinet");
    // ft::pair<int, std::string> p1 = ft::make_pair(5, "London");
    // ft::pair<int, std::string> p2 = ft::make_pair(18, "Paris");
    // ft::pair<int, std::string> p3 = ft::make_pair(25, "Kiev");
    // ft::pair<int, std::string> p4 = ft::make_pair(9, "Madrid");
    // ft::pair<int, std::string> p5 = ft::make_pair(7, "Tungunska");
    // ft::pair<int, std::string> p6 = ft::make_pair(1, "Porto Vecchio");
    // ft::pair<int, std::string> p7 = ft::make_pair(6, "Salamanca");
    // ft::pair<int, std::string> p8 = ft::make_pair(50, "Dubrovnic");
    // ft::pair<int, std::string> p9 = ft::make_pair(90, "Santiago");
    // ft::pair<int, std::string> p10 = ft::make_pair(15, "NYC");
    // ft::pair<int, std::string> p11 = ft::make_pair(2, "Stockholm");
    // ft::pair<int, std::string> p12 = ft::make_pair(40, "Alger");
    // ft::pair<int, std::string> p13 = ft::make_pair(3, "Washington DC");
    // ft::pair<int, std::string> p14 = ft::make_pair(26, "Seattle");
    // ft::pair<int, std::string> p15 = ft::make_pair(55, "Atlanta");
    // ft::pair<int, std::string> p16 = ft::make_pair(10, "Dallas");
    // ft::pair<int, std::string> p17 = ft::make_pair(66, "St Louis");
    // ft::pair<int, std::string> p18 = ft::make_pair(75, "Chicago");
    // ft::pair<int, std::string> p19 = ft::make_pair(8, "Vancouver");
    // ft::pair<int, std::string> p20 = ft::make_pair(150, "Calgary");
    // ft::pair<int, std::string> p21 = ft::make_pair(80, "Rome");
    // ft::pair<int, std::string> p22 = ft::make_pair(17, "Geneva");
    // ft::pair<int, std::string> p23 = ft::make_pair(4, "Lausanne");
    // ft::pair<int, std::string> p24 = ft::make_pair(11, "Montreux");
    // ft::pair<int, std::string> p25 = ft::make_pair(22, "Gstaad");
    // ft::pair<int, std::string> p26 = ft::make_pair(72, "Zermatt");
    // ft::pair<int, std::string> p27 = ft::make_pair(97, "Courchevel");
    // ft::pair<int, std::string> p28 = ft::make_pair(48, "Megeve");
    // ft::pair<int, std::string> p29 = ft::make_pair(81, "Val Thorens");
    // ft::pair<int, std::string> p30 = ft::make_pair(12, "La Plagne");
    // ft::pair<int, std::string> p31 = ft::make_pair(51, "Flaine");
    // ft::pair<int, std::string> p32 = ft::make_pair(34, "Tignes");
    // ft::pair<int, std::string> p33 = ft::make_pair(46, "Meribel");
    // ft::pair<int, std::string> p34 = ft::make_pair(61, "Isola2000");
    // ft::pair<int, std::string> p35 = ft::make_pair(63, "St Moritz");
    // ft::pair<int, std::string> p36 = ft::make_pair(69, "Sant Anton");
    // ft::pair<int, std::string> p37 = ft::make_pair(19, "Davos");
    // ft::pair<int, std::string> p38 = ft::make_pair(62, "San Remo");
    // ft::pair<int, std::string> p39 = ft::make_pair(98, "San Francisco");
    // ft::pair<int, std::string> p40 = ft::make_pair(44, "San Jose");
    // RedBlackT.insertValue(p1);
    // RedBlackT.insertValue(p2);
    // RedBlackT.insertValue(p3);
    // RedBlackT.insertValue(p4);
    // RedBlackT.insertValue(p5);
    // RedBlackT.insertValue(p6);
    // RedBlackT.insertValue(p7);
    // RedBlackT.insertValue(p8);
    // RedBlackT.insertValue(p9);
    // RedBlackT.insertValue(p10);
    // std::cout << "sentinel->left: " << RedBlackT.getSentinel()->left->getKey() << " - sentinel->right: " << RedBlackT.getSentinel()->right->getKey() << std::endl;
    // RedBlackT.insertValue(p11);
    // RedBlackT.insertValue(p12);
    // RedBlackT.insertValue(p13);
    // RedBlackT.insertValue(p14);
    // RedBlackT.insertValue(p15);
    // std::cout << "sentinel->left: " << RedBlackT.getSentinel()->left->getKey() << " - sentinel->right: " << RedBlackT.getSentinel()->right->getKey() << std::endl;
    // RedBlackT.removeNode(RedBlackT.getRoot(), 16);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 84);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 34);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 484);
    // std::cout << "sentinel->left: " << RedBlackT.getSentinel()->left->getKey() << " - sentinel->right: " << RedBlackT.getSentinel()->right->getKey() << std::endl;
    // // RedBlackT.insertValue(p16);
    // RedBlackT.insertValue(p17);
    // RedBlackT.insertValue(p18);
    // RedBlackT.insertValue(p19);
    // RedBlackT.insertValue(p20);
    // RedBlackT.insertValue(p21);
    // RedBlackT.insertValue(p22);
    // RedBlackT.insertValue(p23);
    // RedBlackT.insertValue(p24);
    // RedBlackT.insertValue(p25);
    // RedBlackT.insertValue(p26);
    // RedBlackT.insertValue(p27);
    // RedBlackT.insertValue(p28);
    // RedBlackT.insertValue(p29);
    // RedBlackT.insertValue(p30);
    // RedBlackT.insertValue(p31);
    // RedBlackT.insertValue(p32);
    // RedBlackT.insertValue(p33);
    // RedBlackT.insertValue(p34);
    // RedBlackT.insertValue(p35);
    // RedBlackT.insertValue(p36);
    // RedBlackT.insertValue(p37);
    // RedBlackT.insertValue(p38);
    // RedBlackT.insertValue(p39);
    // RedBlackT.insertValue(p40);
    // RedBlackT.insertValue(p41);
    // RedBlackT.insertValue(p42);
    // RedBlackT.insertValue(p43);
    // RedBlackT.insertValue(p44);
    // RedBlackT.insertValue(p45);
    // RedBlackT.insertValue(p46);
    // RedBlackT.insertValue(p47);
    // RedBlackT.insertValue(p48);
    // RedBlackT.insertValue(p49);
    // RedBlackT.insertValue(p50);
    // RedBlackT.insertValue(p51);
    // RedBlackT.insertValue(p52);
    // RedBlackT.insertValue(p53);
    // RedBlackT.insertValue(p54);
    // RedBlackT.insertValue(p55);
    // RedBlackT.insertValue(p56);
    // RedBlackT.insertValue(p57);
    // RedBlackT.insertValue(p58);
    // RedBlackT.insertValue(p59);
    // RedBlackT.insertValue(p60);
    // RedBlackT.insertValue(p61);
    // RedBlackT.insertValue(p62);
    // RedBlackT.insertValue(p63);
    // RedBlackT.insertValue(p64);
    // RedBlackT.insertValue(p65);
    // RedBlackT.insertValue(p66);
    // RedBlackT.insertValue(p67);
    // RedBlackT.insertValue(p68);
    // RedBlackT.insertValue(p69);
    // RedBlackT.insertValue(p70);
    // RedBlackT.insertValue(p71);
    // RedBlackT.insertValue(p72);
    // RedBlackT.insertValue(p73);
    // RedBlackT.insertValue(p74);
    // RedBlackT.insertValue(p75);
    // RedBlackT.insertValue(p76);
    // RedBlackT.insertValue(p77);
    // RedBlackT.insertValue(p78);
    // RedBlackT.insertValue(p79);
    // RedBlackT.insertValue(p80);
    // RedBlackT.insertValue(p81);
    // RedBlackT.insertValue(p82);
    // RedBlackT.insertValue(p83);
    // RedBlackT.insertValue(p84);
    // RedBlackT.insertValue(p85);
    // RedBlackT.insertValue(p86);
    // RedBlackT.insertValue(p87);
    // RedBlackT.insertValue(p88);
    // RedBlackT.insertValue(p89);
    // RedBlackT.insertValue(p90);
    // RedBlackT.insertValue(p91);
    // RedBlackT.insertValue(p92);
    // RedBlackT.insertValue(p93);
    // RedBlackT.insertValue(p94);
    // RedBlackT.insertValue(p95);
    // RedBlackT.insertValue(p96);
    // RedBlackT.insertValue(p97);
    // RedBlackT.insertValue(p98);
    // RedBlackT.insertValue(p99);
    // RedBlackT.insertValue(p100);
    // RedBlackT.printRBT();

    // CODE POUR TESTS PACKS 1 A 8
    // ft::pair<int, std::string> p11 = ft::make_pair(2, "Stockholm");
    // ft::pair<int, std::string> p12 = ft::make_pair(40, "Alger");
    // ft::pair<int, std::string> p13 = ft::make_pair(3, "Washington DC");
    // ft::pair<int, std::string> p14 = ft::make_pair(26, "Seattle");
    // ft::pair<int, std::string> p15 = ft::make_pair(55, "Atlanta");
    // ft::pair<int, std::string> p16 = ft::make_pair(10, "Dallas");
    // ft::pair<int, std::string> p17 = ft::make_pair(66, "St Louis");
    // ft::pair<int, std::string> p18 = ft::make_pair(75, "Chicago");
    // ft::pair<int, std::string> p19 = ft::make_pair(8, "Vancouver");
    // ft::pair<int, std::string> p20 = ft::make_pair(150, "Calgary");
    // ft::pair<int, std::string> p21 = ft::make_pair(80, "Rome");
    // ft::pair<int, std::string> p22 = ft::make_pair(17, "Geneva");
    // ft::pair<int, std::string> p23 = ft::make_pair(4, "Lausanne");
    // ft::pair<int, std::string> p24 = ft::make_pair(11, "Montreux");
    // ft::pair<int, std::string> p25 = ft::make_pair(22, "Gstaad");
    // ft::pair<int, std::string> p26 = ft::make_pair(72, "Zermatt");
    // ft::pair<int, std::string> p27 = ft::make_pair(97, "Courchevel");
    // ft::pair<int, std::string> p28 = ft::make_pair(48, "Megeve");
    // ft::pair<int, std::string> p29 = ft::make_pair(81, "Val Thorens");
    // ft::pair<int, std::string> p30 = ft::make_pair(12, "La Plagne");
    // ft::pair<int, std::string> p31 = ft::make_pair(51, "Flaine");

    // PACK 1
    // RedBlackT.removeNode(RedBlackT.getRoot(), 22);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 80);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 10);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 3);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 48);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 4);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 75);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 97);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 12);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 2);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 51);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 17);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 40);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 150);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 72);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 55);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 66);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 11);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 8);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 26);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 81);

    // PACK 2
    // RedBlackT.removeNode(RedBlackT.getRoot(), 51);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 75);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 80);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 150);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 48);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 8);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 72);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 66);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 10);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 3);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 97);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 55);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 11);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 12);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 40);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 2);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 17);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 4);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 81);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 22);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 26);

    // PACK 3
    // RedBlackT.removeNode(RedBlackT.getRoot(), 72);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 8);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 40);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 12);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 48);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 26);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 55);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 10);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 66);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 2);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 75);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 11);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 97);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 51);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 17);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 81);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 4);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 3);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 150);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 80);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 22);

    // PACK 4
    // RedBlackT.removeNode(RedBlackT.getRoot(), 17);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 11);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 66);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 10);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 150);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 12);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 55);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 97);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 26);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 72);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 4);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 48);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 40);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 51);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 8);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 22);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 2);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 75);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 3);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 81);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 80);

    // PACK 5
    // RedBlackT.removeNode(RedBlackT.getRoot(), 11);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 51);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 97);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 48);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 8);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 10);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 12);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 4);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 66);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 150);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 40);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 3);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 22);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 26);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 81);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 55);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 2);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 75);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 17);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 72);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 80);

    // PACK 6 - good
    // RedBlackT.removeNode(RedBlackT.getRoot(), 17);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 12);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 40);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 2);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 51);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 66);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 55);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 72);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 150);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 97);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 26);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 11);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 4);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 3);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 10);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 22);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 75);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 8);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 48);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 80);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 81);

    // PACK 7 - good
    // RedBlackT.removeNode(RedBlackT.getRoot(), 3);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 72);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 55);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 4);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 22);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 150);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 97);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 75);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 81);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 26);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 10);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 48);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 51);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 2);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 8);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 11);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 40);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 66);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 80);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 17);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 12);

    // PACK 8 - good
    // RedBlackT.removeNode(RedBlackT.getRoot(), 26);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 8);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 40);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 3);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 72);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 17);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 150);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 12);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 22);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 81);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 48);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 66);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 10);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 51);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 75);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 4);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 97);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 80);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 11);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 2);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 55);

    // PACK 9 - extended to 40 values - good
    // RedBlackT.removeNode(RedBlackT.getRoot(), 8);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 6);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 5);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 9);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 81);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 90);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 3);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 62);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 17);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 75);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 18);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 12);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 69);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 11);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 55);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 19);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 2);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 46);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 22);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 26);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 1);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 48);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 7);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 25);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 98);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 34);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 4);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 61);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 97);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 40);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 51);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 15);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 63);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 50);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 10);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 72);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 66);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 44);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 150);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 80);


    // Extended Pack
    // ft::pair<int, std::string> p1 = ft::make_pair(5, "London");
    // ft::pair<int, std::string> p2 = ft::make_pair(18, "Paris");
    // ft::pair<int, std::string> p3 = ft::make_pair(25, "Kiev");
    // ft::pair<int, std::string> p4 = ft::make_pair(9, "Madrid");
    // ft::pair<int, std::string> p5 = ft::make_pair(7, "Tungunska");
    // ft::pair<int, std::string> p6 = ft::make_pair(1, "Porto Vecchio");
    // ft::pair<int, std::string> p7 = ft::make_pair(6, "Salamanca");
    // ft::pair<int, std::string> p8 = ft::make_pair(50, "Dubrovnic");
    // ft::pair<int, std::string> p9 = ft::make_pair(90, "Santiago");
    // ft::pair<int, std::string> p10 = ft::make_pair(15, "NYC");
    // ft::pair<int, std::string> p11 = ft::make_pair(2, "Stockholm");
    // ft::pair<int, std::string> p12 = ft::make_pair(40, "Alger");
    // ft::pair<int, std::string> p13 = ft::make_pair(3, "Washington DC");
    // ft::pair<int, std::string> p14 = ft::make_pair(26, "Seattle");
    // ft::pair<int, std::string> p15 = ft::make_pair(55, "Atlanta");
    // ft::pair<int, std::string> p16 = ft::make_pair(10, "Dallas");
    // ft::pair<int, std::string> p17 = ft::make_pair(66, "St Louis");
    // ft::pair<int, std::string> p18 = ft::make_pair(75, "Chicago");
    // ft::pair<int, std::string> p19 = ft::make_pair(8, "Vancouver");
    // ft::pair<int, std::string> p20 = ft::make_pair(150, "Calgary");
    // ft::pair<int, std::string> p21 = ft::make_pair(80, "Rome");
    // ft::pair<int, std::string> p22 = ft::make_pair(17, "Geneva");
    // ft::pair<int, std::string> p23 = ft::make_pair(4, "Lausanne");
    // ft::pair<int, std::string> p24 = ft::make_pair(11, "Montreux");
    // ft::pair<int, std::string> p25 = ft::make_pair(22, "Gstaad");
    // ft::pair<int, std::string> p26 = ft::make_pair(72, "Zermatt");
    // ft::pair<int, std::string> p27 = ft::make_pair(97, "Courchevel");
    // ft::pair<int, std::string> p28 = ft::make_pair(48, "Megeve");
    // ft::pair<int, std::string> p29 = ft::make_pair(81, "Val Thorens");
    // ft::pair<int, std::string> p30 = ft::make_pair(12, "La Plagne");
    // ft::pair<int, std::string> p31 = ft::make_pair(51, "Flaine");
    // ft::pair<int, std::string> p32 = ft::make_pair(34, "Tignes");
    // ft::pair<int, std::string> p33 = ft::make_pair(46, "Meribel");
    // ft::pair<int, std::string> p34 = ft::make_pair(61, "Isola2000");
    // ft::pair<int, std::string> p35 = ft::make_pair(63, "St Moritz");
    // ft::pair<int, std::string> p36 = ft::make_pair(69, "Sant Anton");
    // ft::pair<int, std::string> p37 = ft::make_pair(19, "Davos");
    // ft::pair<int, std::string> p38 = ft::make_pair(62, "San Remo");
    // ft::pair<int, std::string> p39 = ft::make_pair(98, "San Francisco");
    // ft::pair<int, std::string> p40 = ft::make_pair(44, "San Jose");

    // PACK 10 - good
    // RedBlackT.removeNode(RedBlackT.getRoot(), 97);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 40);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 25);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 12);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 9);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 11);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 18);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 7);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 17);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 4);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 98);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 150);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 26);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 10);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 55);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 8);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 44);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 90);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 2);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 22);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 62);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 19);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 51);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 3);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 48);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 50);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 80);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 75);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 72);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 6);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 61);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 5);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 81);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 15);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 46);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 63);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 66);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 1);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 34);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 69);

    // RedBlackT.removeNode(RedBlackT.getRoot(), 484);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 110);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 464);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 111);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 16);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 156);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 1);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 100);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 301);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 437);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 66);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 388);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 448);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 262);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 120);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 163);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 206);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 169);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 215);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 186);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 497);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 239);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 290);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 177);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 166);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 252);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 130);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 125);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 38);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 311);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 230);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 245);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 450);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 91);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 153);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 84);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 304);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 445);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 221);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 248);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 316);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 202);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 400);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 340);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 312);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 21);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 358);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 286);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 475);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 370);

    // RedBlackT.removeNode(RedBlackT.getRoot(), 153);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 110);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 484);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 286);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 311);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 400);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 445);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 84);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 91);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 464);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 120);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 156);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 304);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 437);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 358);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 215);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 130);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 21);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 230);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 475);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 370);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 186);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 125);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 312);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 177);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 239);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 202);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 221);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 497);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 38);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 301);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 100);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 252);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 1);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 166);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 163);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 262);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 169);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 206);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 111);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 450);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 316);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 340);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 388);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 248);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 290);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 245);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 66);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 448);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 16);

    // RedBlackT.removeNode(RedBlackT.getRoot(), 497);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 111);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 388);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 230);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 38);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 84);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 177);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 448);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 110);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 248);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 358);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 311);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 206);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 437);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 304);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 239);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 130);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 215);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 153);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 202);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 312);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 125);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 186);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 16);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 1);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 21);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 290);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 163);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 262);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 316);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 484);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 340);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 400);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 445);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 91);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 450);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 221);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 475);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 301);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 100);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 286);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 66);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 120);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 370);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 252);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 156);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 166);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 169);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 245);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 464);

    // RedBlackT.removeNode(RedBlackT.getRoot(), 388);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 16);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 125);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 230);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 84);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 290);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 316);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 156);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 130);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 464);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 91);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 21);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 450);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 239);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 202);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 497);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 252);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 358);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 215);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 312);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 484);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 38);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 100);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 304);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 169);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 163);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 370);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 340);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 262);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 111);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 475);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 245);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 400);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 177);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 1);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 206);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 448);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 166);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 153);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 437);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 221);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 120);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 445);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 186);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 248);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 286);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 66);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 311);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 110);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 301);

    // RedBlackT.removeNode(RedBlackT.getRoot(), 91);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 215);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 110);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 1);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 286);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 316);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 248);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 120);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 311);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 111);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 163);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 358);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 66);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 464);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 130);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 84);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 21);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 400);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 450);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 221);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 312);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 186);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 304);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 484);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 290);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 445);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 475);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 388);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 301);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 497);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 156);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 166);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 38);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 125);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 437);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 169);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 177);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 16);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 252);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 340);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 206);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 262);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 370);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 448);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 202);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 230);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 245);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 153);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 100);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 239);

    // RedBlackT.removeNode(RedBlackT.getRoot(), 91);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 400);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 38);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 230);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 177);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 304);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 153);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 16);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 111);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 239);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 316);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 437);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 215);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 497);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 206);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 450);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 163);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 370);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 156);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 245);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 120);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 252);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 110);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 484);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 290);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 21);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 166);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 186);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 202);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 445);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 84);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 312);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 221);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 125);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 1);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 66);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 358);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 248);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 100);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 311);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 262);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 169);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 464);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 340);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 388);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 475);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 448);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 130);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 286);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 301);

    // RedBlackT.removeNode(RedBlackT.getRoot(), 301);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 311);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 230);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 215);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 100);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 400);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 16);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 166);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 1);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 206);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 290);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 248);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 120);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 186);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 111);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 445);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 245);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 169);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 153);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 38);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 130);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 239);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 388);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 202);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 286);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 484);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 125);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 252);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 110);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 66);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 358);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 370);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 91);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 316);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 21);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 84);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 497);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 262);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 475);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 437);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 156);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 221);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 340);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 450);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 304);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 448);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 177);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 464);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 163);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 312);

    // RedBlackT.removeNode(RedBlackT.getRoot(), 100);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 166);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 475);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 120);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 125);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 497);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 262);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 304);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 370);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 245);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 400);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 340);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 311);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 464);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 111);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 91);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 177);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 239);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 230);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 156);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 484);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 286);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 301);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 206);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 252);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 1);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 130);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 358);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 163);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 437);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 388);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 221);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 38);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 16);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 215);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 290);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 312);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 450);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 84);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 186);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 66);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 21);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 202);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 169);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 110);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 248);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 316);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 153);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 448);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 445);

    // RedBlackT.removeNode(RedBlackT.getRoot(), 448);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 475);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 111);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 221);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 304);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 84);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 186);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 163);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 1);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 125);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 21);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 206);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 252);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 38);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 230);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 450);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 484);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 239);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 358);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 215);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 290);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 169);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 262);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 286);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 311);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 177);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 316);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 202);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 130);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 245);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 437);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 312);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 370);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 301);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 156);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 497);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 445);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 166);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 91);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 400);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 66);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 388);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 110);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 153);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 120);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 340);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 100);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 248);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 464);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 16);

    // RedBlackT.removeNode(RedBlackT.getRoot(), 130);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 312);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 311);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 125);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 215);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 450);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 370);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 245);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 484);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 111);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 475);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 166);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 304);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 445);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 169);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 388);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 239);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 21);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 84);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 91);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 163);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 206);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 262);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 153);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 110);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 38);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 1);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 358);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 202);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 100);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 464);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 290);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 186);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 248);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 316);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 437);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 400);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 66);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 156);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 448);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 221);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 120);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 16);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 301);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 497);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 286);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 340);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 252);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 230);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 177);

    
    // RedBlackT.removeNode(RedBlackT.getRoot(), 186);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 301);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 91);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 221);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 464);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 66);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 497);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 290);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 230);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 177);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 163);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 311);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 400);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 248);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 239);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 120);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 84);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 38);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 340);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 316);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 166);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 388);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 110);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 252);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 153);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 370);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 475);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 156);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 125);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 1);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 100);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 169);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 312);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 450);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 215);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 448);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 304);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 245);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 437);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 16);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 21);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 484);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 206);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 111);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 286);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 445);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 262);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 130);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 202);
    // RedBlackT.removeNode(RedBlackT.getRoot(), 358);
    // RedBlackT.printRBT();
    // RedBlackT.insertNode("Chocolat", "D");
    // RedBlackT.insertNode("Boat", "A");
    // RedBlackT.insertNode("Aristochat", "Disney");
    // RedBlackT.insertNode("Animal", "bB");
    // RedBlackT.insertNode("Attachant", "bbB");
    // RedBlackT.insertNode("Anemique", "FinCommeTout");
    // RedBlackT.insertNode("Alibaba", "BBb");
    // RedBlackT.insertNode("D", "C");
    // RedBlackT.insertNode("E", "D");   
    // RedBlackT.insertNode("F", "E");
    // std::cout << "------------------ before delete -----------------" << std::endl;
    // RedBlackT.insertNode("Wayne", "Clark");
    // RedBlackT.insertNode("Longoria", "Eva");
    // RedBlackT.insertNode("Melon", "Fruit");
    // RedBlackT.insertNode("Lane", "Lois");
    // RedBlackT.insertNode("Mountain", "View");
    // RedBlackT.insertNode("Alphabet", "Google");
    // // RedBlackT.insertNode("Amarillo", "Hello");
    // RedBlackT.insertNode("Abcdef", "Ghijklnop");
    // RedBlackT.insertNode("Aaaaaaa", "BBBBBBB");

    // ======================== TEST SACHIN ========================== //
    // #include <fstream>
    // std::ifstream source("test", std::ios::binary);
    // std::vector<char> data((std::istreambuf_iterator<char>(source)),
    //                    std::istreambuf_iterator<char>());
    // std::cout << data[0] << data[1] << data[2] << std::endl;
    // source.close();
    // std::ifstream sourceb("test", std::ios::binary);
    // ft::vector<char> data2((std::istreambuf_iterator<char>(sourceb)),
    //                    std::istreambuf_iterator<char>());
    // std::cout << data2[0] << data2[1] << data2[2] << std::endl;
    // return(0);
    // ======================== FIN TEST SACHIN ========================== //
    
    // ft::RBTree<int, std::string> RedBlackT;
    // RedBlackT.printRBT();

    // VANESSA EXAMPLE
    // RedBlackT.insertNode(8, "Paris");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(18, "Madrid");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(5, "London");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(15, "Copenhagen");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(17, "Amsterdam");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(25, "New-York");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(40, "Santiago");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(80, "Santiago");
    // RedBlackT.printRBT();
    //

    // WORKS 100% both insert and delete
    // RedBlackT.insertNode(57, "Santiago");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(26, "Paris");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(59, "London");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(16, "Madrid");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(71, "New-York");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(11, "Copenhagen");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(69, "Calixte");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(62, "Cordoba");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(78, "Sao Paolo");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(75, "Quito");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(1, "Medelin");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(15, "Cali");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(2, "Valdes");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(47, "Punta Arena");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(92, "Salta");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(51, "Mar Del Plata");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(77, "Chicago");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(39, "Dallas");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(20, "Philadelphia");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(13, "Boston");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(65, "Las Vegas");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(84, "Salt Lake City");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(6, "Colorado Spring");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(87, "Phoenix");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(4, "Santa Monica");
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 77);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 69);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 13);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 6);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 1);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 16);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 26);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 2);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 39);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 92);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 15);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 47);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 71);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 11);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 20);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 59);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 75);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 57);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 4);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 78);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 62);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 51);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 65);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 87);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 84);
    // RedBlackT.printRBT();


//TESTS TO COMPLETE:

    // RedBlackT.insertNode(39, "Dallas");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(11, "Copenhagen");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(26, "Paris");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(16, "Madrid");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(71, "New-York");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(69, "Calixte");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(13, "Boston");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(78, "Sao Paolo");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(75, "Quito");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(1, "Medelin");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(15, "Cali");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(2, "Valdes");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(47, "Punta Arena");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(57, "Santiago");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(62, "Cordoba");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(92, "Salta");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(4, "Santa Monica");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(51, "Mar Del Plata");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(59, "London");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(77, "Chicago");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(20, "Philadelphia");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(65, "Las Vegas");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(84, "Salt Lake City");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(6, "Colorado Spring");
    // RedBlackT.printRBT();
    // RedBlackT.insertNode(87, "Phoenix");
    // RedBlackT.printRBT();

    // RedBlackT.deleteNode(RedBlackT.getRoot(), 51);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 77);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 6);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 16);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 26);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 2);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 92);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 15);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 47);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 84);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 71);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 11);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 87);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 20);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 59);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 1);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 75);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 69);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 57);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 4);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 78);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 13);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 62);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 65);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 39);
    // RedBlackT.printRBT();

    
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 25);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 16);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 18);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 13);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 5);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 22);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 10);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 1);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 7);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 8);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 25);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 30);
    // RedBlackT.printRBT();

    // RedBlackT.deleteNode(RedBlackT.getRoot(), 17);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 9);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 12);
    // RedBlackT.printRBT();
    // RedBlackT.deleteNode(RedBlackT.getRoot(), 27);
    // RedBlackT.printRBT();

    
    // RedBlackT.insertNode(80, "Brasilia");
    // RedBlackT.printRBT();
    // int needle = 15;
    // ft::Node<int, std::string>* needle_node = searchNode(RedBlackT.getRoot(), needle);
    // needle_node->leftRotate(needle_node);
    // RedBlackT.printRBT();
    // needle = 17;
    // needle_node = searchNode(RedBlackT.getRoot(), needle);
    // needle_node->rightRotate(needle_node);
    // RedBlackT.printRBT(); 
    // RedBlackT.insertNode(50, "Paris");
    // RedBlackT.insertNode(30, "Madrid");
    // RedBlackT.insertNode(100, "London");
    // RedBlackT.insertNode(20, "Copenhagen");
    // RedBlackT.insertNode(40, "Berlin");
    // RedBlackT.insertNode(80, "Rome");
    // RedBlackT.insertNode(120, "Barcelona");
    // RedBlackT.insertNode(15, "Milan");
    // RedBlackT.insertNode(25, "Nice");
    // RedBlackT.insertNode(23, "Mougins");
    // RedBlackT.insertNode(24, "Sorbonne");
    // RedBlackT.insertNode(26, "Monaco");
    // RedBlackT.insertNode(27, "Cannes");
    // RedBlackT.insertNode(17, "Dublin");
    // RedBlackT.insertNode(18, "Tokyo");
    // RedBlackT.printRBT();
    // std::string needle = "Lane";
    // ft::Node<std::string, std::string>* needle_node = searchNode(RedBlackT.getRoot(), needle);
    // int needle = 50;
    // ft::Node<int, std::string>* needle_node = searchNode(RedBlackT.getRoot(), needle);
    // std::cout << "Uncle: " << (RedBlackT.getUncle(needle_node) != NULL ? RedBlackT.getUncle(needle_node)->data : "None") << std::endl;
    // std::cout << "------------------ after delete -----------------" << std::endl;
    // RedBlackT.NodeDelete(RedBlackT.getRoot(), "Alphabet");
    // std::cout << "------------------ IO SUCCESSOR -----------------" << std::endl;    
    // std::cout << (RedBlackT.getIOSuccessor(needle_node) ? (RedBlackT.getIOSuccessor(needle_node))->data : 0) << std::endl;
    // std::cout << "------------------ IO PREDECESSOR -----------------" << std::endl;    
    // std::cout << (RedBlackT.getIOPredecessor(needle_node) ? (RedBlackT.getIOPredecessor(needle_node))->data : 0) << std::endl;

    // std::cout << "------------------ after delete -----------------" << std::endl;
    // RedBlackT.NodeDelete(RedBlackT.getRoot(), needle);
    // RedBlackT.printRBT();
    // setRoot(RedBlackT, deleteNode(RedBlackT.getRoot(), "Longoria"));
    // RedBlackT.printRBT();

    // ft::vector<int> v1(5, 100);
    // ft::vector<int>::iterator rit = v1.begin() + 2;
    // std::cout << *it << " " << &(*it1) << std::endl;    
    // it1 = 1 - it1;
    // v1.printVec();
    // std::cout << *it1 << " " << &(*it1) << std::endl;
    
    // std::vector<int> v1(5, 100);
    // std::vector<int>::iterator it1(465, 4564) = v1.begin() + 2;
    // std::cout << *it1 << " " << &(*it1) << std::endl;    
    // it1 = it1 / 0;
    // print_STLVec(v1);
    // std::cout << *it1 << " " << &(*it1) << std::endl;

    // ft::BST b, *root = NULL;
    // root = b.Insert(root, 50);
    // b.Insert(root, 30);
    // b.Insert(root, 80);
    // b.Insert(root, 40);
    // b.Insert(root, 70);
    // b.Insert(root, 1000);
    // b.Insert(root, 10);

    // b.Inorder(root);

    
    // BINARY SEARCH TREE - BASIC NODE
    // ft::Node BST;
    // BST.data = 0;
    // BST.left = NULL;
    // BST.right = NULL;
    // std::cout << "BST size: " << ft::size(&BST) << std::endl;
    // BST.left = ft::newNode(-10);
    // // ft::insert(&BST, 10);
    // std::cout << "BST size: " << ft::size(&BST) << std::endl;
    // BST.right = ft::newNode(10);
    // std::cout << "BST size: " << ft::size(&BST) << std::endl;
    // // std::cout << "\t";
    // (BST.left)->left = ft::newNode(-15);
    // (BST.left)->right = ft::newNode(-5);
    // ft::print_BST(&BST);


    
    // std::map<int, int> smap1;
    // std::cout << "\n=================== SMAP1: ===================\n" << std::endl;
    // smap1.insert(std::pair<int, int> (6, 50));
    // smap1.insert(std::pair<int, int> (17, -3));
    // std::map<int,int>::iterator sit;
    // std::cout << '\t' << "KEY" << '\t' << "VALUE" << std::endl; 
    // for (sit = smap1.begin(); sit != smap1.end(); ++sit)
    // {
    //     std::cout << '\t' << sit->first << '\t' << sit->second << std::endl; 
    // }
    // std::cout << "\n==============================================\n" << std::endl;
    // ft::pair<int, int> p1(5, 10);
    // ft::pair<int, int> p2 (5, 11);
    // std::cout << "p1 values: " << p1.first << " " << p1.second << std::endl;
    // std::cout << "p2 values: " << p2.first << " " << p2.second << std::endl;
    // std::cout << "p1 == p2? " << (p1 == p2) << std::endl;
    // std::cout << "p1 != p2? " << (p1 != p2) << std::endl;    
    // std::cout << "p1 < p2? " << (p1 < p2) << std::endl;   
    // std::cout << "p1 > p2? " << (p1 > p2) << std::endl;   
    // std::cout << "p1 <= p2? " << (p1 <= p2) << std::endl;   
    // std::cout << "p1 >= p2? " << (p1 >= p2) << std::endl;   
    // ft::pair<int, int> p3 = ft::make_pair(3, 10);

    // std::pair<int, int> sp1(5, 10);
    // std::pair<int, int> sp2(5, 11);
    // std::cout << "sp1 values: " << sp1.first << " " << sp1.second << std::endl;
    // std::cout << "sp2 values: " << sp2.first << " " << sp2.second << std::endl;
    // std::cout << "sp1 == sp2? " << (sp1 == sp2) << std::endl;
    // std::cout << "sp1 != sp2? " << (sp1 != sp2) << std::endl;    
    // std::cout << "sp1 < sp2? " << (sp1 < sp2) << std::endl;   
    // std::cout << "sp1 > sp2? " << (sp1 > sp2) << std::endl;   
    // std::cout << "sp1 <= sp2? " << (sp1 <= sp2) << std::endl;   
    // std::cout << "sp1 >= sp2? " << (sp1 >= sp2) << std::endl; 
    // ft::stack<int, ft::vector<int> > s0;
    // std::cout << "s0 empty? " << s0.empty() << std::endl;
    // std::cout << "s0 size? " << s0.size() << std::endl;   
    // s0.push(1);
    // s0.push(2);
    // s0.push(3); 
    // s0.push(4);
    // (s0.get_ctnr()).printVec();
    // std::cout << "TOP before pop: " <<  s0.top() << std::endl;
    // s0.pop();
    // std::cout << "TOP after pop: " <<  s0.top() << std::endl;   
    // ft::stack<int, ft::vector<int> > s1;
    // s1.push(1);
    // s1.push(2);
    // s1.push(3); 
    // std::cout << "Comparaison s0 < s1? " << std::boolalpha << (s0 > s1) << std::endl;       

    // std::stack<int, ft::vector<int> > ss0;
    // std::cout << "================================================================================" << std::endl;
    // std::cout << "ss0 empty? " << ss0.empty() << std::endl;
    // std::cout << "ss0 size? " << ss0.size() << std::endl;
    // ss0.push(1);
    // ss0.push(2);
    // ss0.push(3);
    // // print_STLVec(ss0.get_ctnr());
    // std::cout << "TOP before pop: " <<  ss0.top() << std::endl;
    // ss0.pop();
    // std::cout << "TOP after pop: " <<  ss0.top() << std::endl;
    // std::stack<int, ft::vector<int> > ss1;
    // ss1.push(1);
    // ss1.push(2);
    // ss1.push(3); 
    // ss1.push(4);
    // std::cout << "Comparaison ss0 < ss1? " << std::boolalpha << (ss0 > ss1) << std::endl;  


	// std::vector<int> const svct(size);
	// std::vector<int>::iterator sit = svct.begin();  // <-- error expected
	// // std::vector<int>::const_iterator sit = svct.begin(); // <-- no error anymore
    // std::cout << *sit << std::endl;
        // std::cout << SIZE_MAX << std::endl;
        
        // std::list<int> lst1;
        // for (int i = 0; i < 10; i++)
        //     lst1.push_back(i);
        
        // std::list<int>::iterator itl1 = lst1.begin();
        // for (size_t i = 0; i < 7; i++)
        //     itl1++;
        // std::list<int>::iterator itl2 = lst1.begin();
        // for (size_t i = 0; i < 3; i++)
        //     itl2++;

    // const int size = 5;
	// ft::vector<foo<int> > vct(size);
	// ft::vector<foo<int> >::reverse_iterator it_0(vct.rbegin());
	// ft::vector<foo<int> >::reverse_iterator it_1(vct.rend());
	// ft::vector<foo<int> >::reverse_iterator it_mid;

	// ft::vector<foo<int> >::const_reverse_iterator cit_0 = vct.rbegin();
	// ft::vector<foo<int> >::const_reverse_iterator cit_1;
	// ft::vector<foo<int> >::const_reverse_iterator cit_mid;

	// for (int i = size; it_0 != it_1; --i)
	// 	*it_0++ = i;
    // vct.printVec();
	// it_0 = vct.rbegin();
	// cit_1 = vct.rend();
	// it_mid = it_0 + 3;
	// cit_mid = it_0 + 3; cit_mid = cit_0 + 3; cit_mid = it_mid;

	// std::cout << std::boolalpha;
	// std::cout << ((it_0 + 3 == cit_0 + 3) && (cit_0 + 3 == it_mid)) << std::endl;

	// std::cout << "\t\tft_eq_ope:" << std::endl;
    // 	// regular it
	// // ft_eq_ope(it_0 + 3, it_mid);
	// ft_eq_ope(it_0, it_1);
	// ft_eq_ope(it_1 - 3, it_mid);
	// // const it
	// ft_eq_ope(cit_0 + 3, cit_mid);
	// ft_eq_ope(cit_0, cit_1);
	// ft_eq_ope(cit_1 - 3, cit_mid);
	// // both it
	// ft_eq_ope(it_0 + 3, cit_mid);
	// ft_eq_ope(it_mid, cit_0 + 3);
	// ft_eq_ope(it_0, cit_1);
	// ft_eq_ope(it_1, cit_0);
	// ft_eq_ope(it_1 - 3, cit_mid);
	// ft_eq_ope(it_mid, cit_1 - 3);
    
	// const int size = 5;
	// ft::vector<foo<int> > vct(size);
    // vct.printVec();
	// ft::vector<foo<int> >::reverse_iterator it(vct.rbegin());
	// ft::vector<foo<int> >::const_reverse_iterator ite(vct.rend());

    // *it = 7;
    // rit++;
    // vct.printVec();
    
    // *it = 14;
    // std::cout << &*it << std::endl;
    // rit++;
    // vct.printVec();

    // *it = 21;
    // rit++;
    // vct.printVec();
    
    // *it = 28;
    // rit++;
    // vct.printVec();
    
    // *it = 35;
    // rit++;
    // vct.printVec();
	// for (int i = 1; it != ite; ++i)
    // {
	// 	*it = (i * 7);
    //     rit++;
    // }
	// vct.printVec();

	// it = vct.rbegin();
	// ite = vct.rbegin();

	// std::cout << *(++ite) << std::endl;
	// std::cout << *(ite++) << std::endl;
	// std::cout << *ite++ << std::endl;
	// std::cout << *++ite << std::endl;

	// it->m();
	// ite->m();

	// std::cout << *(++it) << std::endl;
	// std::cout << *(rit++) << std::endl;
	// std::cout << *rit++ << std::endl;
	// std::cout << *++it << std::endl;

	// std::cout << *(--ite) << std::endl;
	// std::cout << *(ite--) << std::endl;
	// std::cout << *--ite << std::endl;
	// std::cout << *ite-- << std::endl;

	// (*it).m();
	// (*ite).m();

	// std::cout << *(--it) << std::endl;
	// std::cout << *(it--) << std::endl;
	// std::cout << *it-- << std::endl;
	// std::cout << *--it << std::endl;


	    // const int size = 5;
        // ft::vector<int> vct(size);
        // ft::vector<int>::reverse_iterator it = vct.rbegin();
	    // ft::vector<int>::const_reverse_iterator ite = vct.rbegin();

        // for (int i = 0; i < size; ++i)
        // {
        //     // std::cout << "Just before " << i << std::endl;
		//     it[i] = (size - i) * 5;
        //     // std::cout << "it[i] = " << it[i] << " - address = " << &it[i] << std::endl;
        //     // std::cout << "Just after " << i << std::endl;
        //     // vct.printVec();
        // }
        // vct.printVec();
        // it = it + 5;
        // it = 1 + it;

        // for (unsigned long int i = 0; i < vct.size(); ++i)
        //     vct[i] = (vct.size() - i) * 3;
        // vct.printVec();
        
        // ft::vector<int>::reverse_iterator rit = vct.rbegin() + 3;
        // ft::vector<int>::iterator it = rit.base();
        // std::cout << *it << std::endl;
        // vct2.insert(vct2.end(), 42);
        // vct2.insert(vct2.begin(), 2, 21);
        // vct2.printVec();

        // std::vector<int> svct(10);
        // std::vector<int> svct2;

        // for (unsigned long int i = 0; i < svct.size(); ++i)
        //     svct[i] = (svct.size() - i) * 3;
        // print_STLVec(svct);

        // std::vector<int>::reverse_iterator srit = svct.rbegin() + 3;
        // std::vector<int>::iterator sit = srit.base();
        // std::cout << *sit << std::endl;

        // svct2.insert(svct2.end(), 42);
        // svct2.insert(svct2.begin(), 2, 21);
        // print_STLVec(svct2);

        // for (unsigned long int i = 0; i < vct.size(); ++i)
        //     vct[i] = (vct.size() - i) * 7;
        // // vct.printVec();

        // for (unsigned long int i = 0; i < vct3.size(); ++i)
        //     vct3[i] = (vct3.size() - i) * 5;
        // // vct3.printVec();

        // vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
        // // vct2.printVec();
        // vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
        // // vct2.printVec();
    	// vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut + 1);
        // // vct2.printVec();
    	// vct2.insert(vct2.begin() + 3, vct3.begin() + 1, vct3.begin() + 12);
        // vct2.printVec();
    	// vct2.insert(vct2.begin() + 3, vct2.begin() + 1, vct2.begin() + 5);
        // vct2.printVec();
        
        // std::vector<int> svct(5);
        // std::vector<int> svct2;
        // std::vector<int> svct3(15);

        // for (unsigned long int i = 0; i < svct.size(); ++i)
        //     svct[i] = (svct.size() - i) * 7;
        // // print_STLVec(svct);

        // for (unsigned long int i = 0; i < svct3.size(); ++i)
        //     svct3[i] = (svct3.size() - i) * 5;
        // // print_STLVec(svct3);

        // svct2.insert(svct2.begin(), svct.begin(), svct.begin() + cut);
        // // print_STLVec(svct2);
        // svct2.insert(svct2.begin(), svct.begin() + cut, svct.end());
        // // print_STLVec(svct2);
    	// svct2.insert(svct2.end(), svct.begin(), svct.begin() + cut + 1);
        // // print_STLVec(svct2);
    	// svct2.insert(svct2.begin() + 3, svct3.begin() + 1, svct3.begin() + 12);
        // print_STLVec(svct2);
    	// svct2.insert(svct2.begin() + 3, svct2.begin() + 1, svct2.begin() + 5);
        // print_STLVec(svct2);
        // std::vector<int> vct(5);
        // std::vector<int> vct2;
	    // const int cut = 3;

        // for (unsigned long int i = 0; i < vct.size(); ++i)
        //     vct[i] = (vct.size() - i) * 7;
        // print_STLVec(vct);

        // vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
        // print_STLVec(vct2);
        // vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
        // print_STLVec(vct2);
        // vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);
        // vct2.printVec();
        // vct2.insert(vct2.end(), 42);
        // std::cout << *vct2.insert(vct2.end(), 42) << std::endl;
        // std::cout << *vct2.insert(vct2.begin() + 5, 84) << std::endl;

        // for (unsigned long int i = 0; i < vct.size(); ++i)
        //     vct[i] = std::string((vct.size() - i), i + 65);
        // vct.printVec();
        // vct.erase(vct.begin() + 2);
        // vct.printVec();       
        // vct.erase(vct.begin());         
        // ft::vector<int> vct_c(itl1, itl2);
        // vct_c.setName("vct_c");
        // vct_c.printVec();
        // std::vector<int> std_v(itl1, itl2);
        // print_STLVec(std_v);
	    // for (unsigned long int i = 0; i < vct_c.size(); ++i)
		//     vct_c[i] = (vct_c.size() - i) * 3;
            
        // ft::vector<int> vct_three;
        // vct_three.setName("vct_three");
        // vct_three.assign(vct.begin(), vct.end());
        // vct_three.printVec();
        // try {
        //     std::cout << vct_c.at(10) << std::endl;
        // }
        // catch (std::out_of_range &e) {
        //     std::cout << "Catch out_of_range exception!" << std::endl;
        // }
        // catch (std::exception &e) {
        //     std::cout << "Catch exception: " << e.what() << std::endl;
        // }
        
        // ft::vector<int> v11(5, 0);
        // v11.fill(0);
        // v11.printVec();
        // ft::vector<int>::reverse_iterator rit = v11.rbegin();
        // ft::vector<int>::reverse_iterator rite = v11.rend();
        // std::cout << *rit << std::endl;
        // std::cout << *(rit + 2) << std::endl;
        // std::cout << *(rite - 2) << std::endl;
        
        // ft::vector<int> v9(8998000, 82387432);
        // ft::vector<int> v10(100, 0);
        // v10.fill(0);
        // v10.printVec();
        // // ft::vector<int> v12(v10);
        // v10.resize(1942730943297535664);

        // ft::vector<int> v11(v10.begin() + 2, v10.begin() + 6);

        // std::vector<int> sv10(10, 0);
        // sv10.resize(1942730943297535664);
        // std::vector<int> sv11(sv10.begin() + 6, sv10.begin() + 2);

        // ft::vector<std::string> v;

        // fill capacity a little
        // v.push_back("hello");
        // v.push_back("world");
        // std::cout << "v[0]: " << v[0] << std::endl;
        // std::cout << "v[1]: " << v[1] << std::endl;
        // v.printVec();
        // ft::vector<int> v2;
        // v2.push_back(10);
        // v2.push_back(20);
        // v2.printVec();
        // ft::vector<std::string> v;
        // v.push_back("hello");
        // v.push_back("world");
        // v.push_back("world");
        // v.printVec();
        // std::cout << "capacity: " << v.capacity() << std::endl;
        // // overwrite capacity
        // v.insert(v.begin(), *(v.end() - 1));
        // v.printVec();
        // std::cout << "capacity: " << v.capacity() << std::endl;
        // v.insert(v.begin(), *(v.end() - 1));
        // v.printVec();
        // v.insert(v.begin(), *(v.end() - 1));
        // v.printVec();
        // v.insert(v.begin(), *(v.end() - 1));
        // v.printVec(); 
        // std::cout << "capacity: " << v.capacity() << std::endl;
        // v.insert(v.begin(), *(v.end() - 1));
        // v.printVec();
        // v.insert(v.begin(), *(v.end() - 1));
        // v.insert(v.begin(), *(v.end() - 1));
        // v.insert(v.begin(), *(v.end() - 1));
        // v.insert(v.begin(), *(v.end() - 1));
        // // std::cout << "v[5]: " << v[5] << std::endl;
        // v.insert(v.begin(), *(v.end() - 1));
        // v.insert(v.begin(), *(v.end() - 1));
        // v.insert(v.begin(), *(v.end() - 1));
    
    // std::cout << "------------------------ MY vector ----------------------------" << std::endl;
    // ft::vector<int> v6;
    
    // ft::vector<int> v1(3, 8);
    // v1.printVec();
    // v1.setName("v1");
    // ft::vector<int> v2(v1);
    // v2.setName("v2");
    // v2.printVec();
    // v2[1] = 9;
    // v2[2] = 10;
    // v2.printVec();
    // ft::vector<int>::iterator it1 = v2.begin() + 2;
    
    // ft::vector<int> v3(it1, it1 + 1);
    // v3.setName("v3");
    // v3.printVec();    
    // ft::vector<int> v4(5, 100);
    // v4[1] = 200;
    // v4[2] = 300;
    // v4[3] = 400;
    // v4[4] = 500;
    // v4.setName("v4");
    // v4.printVec();
    // v4.erase(v4.end() - 1, v4.end() - 2);
    // v4.printVec();
    // ft::vector<int> v7(16, 100);
    // v7.setName("v7");
    // v7.resize(17);
    // v7.push_back(999);
    // v7.printVec();
    // std::cout << v7.capacity() << std::endl;

    // ft::vector<int> v8(10, 0);
    // v8.setName("v8");
    // for (size_t i = 0; i < 10; i++)
    //     v8[i] = i;
    // v8.printVec();
    // v8.erase(v8.begin() + 4, v8.begin() + 8);
    // v8.printVec();

    // std::vector<int> sv8(10, 0);
    // for (size_t i = 0; i < 10; i++)
    //     sv8[i] = i;
    // sv8.erase(sv8.begin() + 1, sv8.begin() + 11);
    // for (size_t i = 0; i < sv8.size() ; i++)
    //     std::cout << "sv8[" << i << "]: " << sv8[i] << std::endl;
    
    // vector.push_back(100);
    // vector.push_back(200);
    // vector.push_back(300);
    // std::cout << "begin: " << *(vector.begin()) << std::endl;
    // std::cout << "vector[1]: " << vector[1] << std::endl;
    // std::cout << "vector.at(2): " << vector.at(2) << std::endl;
    // std::cout << "vector.at(-1): " << vector.at(-1) << std::endl;
    // std::cout << "vector.at(1432): " << vector.at(1432) << std::endl;
    // // std::cout << "end - 1: " << *(--(vector.end())) << std::endl;
    // std::cout << "end: " << *(vector.end()) << std::endl;
    // vector.pop_back();
    // vector.pop_back();
    // vector.pop_back();
    // std::cout << "begin: " << *(vector.begin()) << std::endl;
    // std::cout << "end: " << *(vector.end()) << std::endl;
    // ft::vector<int> vector2;
    // vector2.setName("vector2");
    // std::cout << "vector2.capacity(): " << vector2.capacity() << std::endl;
    // vector2.push_back(6);
    // std::cout << "vector2.capacity(): " << vector2.capacity() << std::endl;
    // vector2.push_back(3);
    // std::cout << "vector2.capacity(): " << vector2.capacity() << std::endl;
    // vector2.push_back(12);
    // std::cout << "vector2.capacity(): " << vector2.capacity() << std::endl;
    // vector2.push_back(10);
    // std::cout << "vector2.capacity(): " << vector2.capacity() << std::endl;
    // vector2.push_back(1);
    // std::cout << "vector2.capacity(): " << vector2.capacity() << std::endl;
    // vector2.push_back(27);
    // std::cout << "&_arr: " << &vector2.at(0) << std::endl;
    // std::cout << "vector2.capacity(): " << vector2.capacity() << std::endl;
    // std::cout << "vector2.size(): " << vector2.size() << std::endl;
    // ft::vector<int>::iterator itb = vector2.begin() + 1;
    // std::cout << "itb: " << *itb << std::endl;
    // std::cout << "vector2.begin(): " << *vector2.begin() << std::endl;
    // ft::vector<int>::iterator ite = vector2.begin() + 3;
    // std::cout << "ite: " << *ite << std::endl;
    // vector2.printVec();
    // vector2.insert(ite, 34);
    // std::cout << "&_arr: " << &vector2.at(0) << std::endl;
    // vector2.printVec();
    // ite = vector2.begin() + 4;
    // vector2.insert(ite, 38);
    // std::cout << "&_arr: " << &vector2.at(0) << std::endl;
    // vector2.printVec();
    // ite = vector2.begin() + 5;
    // vector2.insert(ite, 42);
    // std::cout << "&_arr: " << &vector2.at(0) << std::endl;
    // std::cout << "_arr[8]: " << *(vector2.begin()+8) << std::endl;
    // vector2.printVec();
    // ite = vector2.begin() + 3;
    // size_t n = 4;
    // vector2.insert(ite, n, 50);
    // vector2.printVec();
    // std::cout << "ite: " << *ite << "\n" << "&*ite: " << &*ite << std::endl;
    // std::cout << "_capacity: " << vector2.capacity() << std::endl;
    // // vector2.insert(vector2.begin()+2, *vector2.begin());
    // // vector2.insert(vector2.begin()+2, 2, *vector2.begin());
    // ft::vector<int> vector3;
    // vector3.setName("vector3");
    // vector3.push_back(7);
    // vector3.push_back(2);
    // vector3.push_back(9);
    // vector3.printVec();
    // vector2.insert(ite, vector3.begin(), vector3.begin() + 2);
    // vector2.printVec();
    // // std::cout << "vector[5]: " << vector[5] << std::endl;
        
    // // std::cout << "vector2.end: " << *(vector2.end()) << std::endl;    
    // vector2.erase(vector2.begin(), vector2.end());
    // std::cout << "vector2.size(): " << vector2.size() << std::endl;
    // std::cout << "vector2[0]: " << vector2[0] << std::endl;
    // std::cout << "vector2[1]: " << vector2[1] << std::endl;
    // std::cout << "vector2[2]: " << vector2[2] << std::endl;
    // std::cout << "vector2[3]: " << vector2[3] << std::endl;
    // std::cout << "vector2[4]: " << vector2[4] << std::endl;
    // std::cout << "vector2[5]: " << vector2[5] << std::endl;
    // std::cout << "vector.size(): " << vector.size() << " - vector.capacity(): " << vector.capacity() << std::endl;
    // std::cout << "vector2.size(): " << vector2.size() << std::endl;
    // std::cout << "vector3.size(): " << vector3.size() << std::endl;
    // ft::vector<int *> ptr_vec;
    // ptr_vec.setName("ptr_vec");
    // std::cout << "max_size(): " << ptr_vec.max_size() << std::endl;
    // ft::vector<int> vector4(10, 0);
    // vector4.setName("vector4");
    // vector4.fill(0);
    // vector4.assign(vector3.end(), vector3.begin());
    // vector4.printVec();
    // vector4.erase(vector4.begin() + 2, vector4.begin() + 7);
    // vector4.erase(vector4.begin() + 7, vector4.begin() + 2);
    // vector4.insert(vector4.begin() + 3, vector4.begin() + 2, vector4.begin() + 7);
    // vector4.printVec();
    // std::vector<int> sv14(10, 0);
    // autohundreds(sv14);
    // print_STLVec(sv14);
    // // sv14.erase(sv14.begin() + 2, sv14.begin() + 7);
    // sv14.erase(sv14.begin() + 7, sv14.begin() + 2);
    // print_STLVec(sv14);
    
    // ft::vector<int> vector5;
    // vector5.setName("vector5");
    // vector5.push_back(93);
    // vector5.push_back(94);
    // vector5.push_back(95);
    // vector5.push_back(96);
    // vector5.push_back(97);
    // vector5.push_back(98);
    // vector5.push_back(99);
    // vector5.push_back(100);
    // vector5.printVec();
    // vector5.assign(vector3.begin(), vector3.end());
    // vector5.printVec();
    // ft::Vector<int> vector6;
    // vector6.setName("vector6");
    // vector6.push_back(30);
    // vector6.push_back(40);
    // vector6.printVec();
    // ft::Vector<int> vector7;
    // vector7.setName("vector7");
    // vector7.push_back(1000);
    // vector7.push_back(2000);
    // vector7.push_back(3000);
    // vector7.push_back(4000);
    // vector7.push_back(5000);
    // vector7.printVec();
    // vector7.assign(vector6.begin(), vector6.end());
    // vector7.printVec();
    

    // std::cout << "\n------------------------- STL VECTOR --------------------------\n" << std::endl;
    // std::vector<int> stl_vector(8, 0);
    // // std::vector<int> stl_v1(16, 100);
    // // stl_v1.resize(17);
    // // stl_v1.push_back(999);
    // // for (size_t i = 0; i < stl_v1.size() ; i++)
    // //     std::cout << "stl_v1[" << i << "]: " << stl_v1[i] << std::endl;
    // autohundreds(stl_vector);
    // // stl_vector.push_back(100);
    // // stl_vector.push_back(200);
    // // stl_vector.push_back(300);
    // // stl_vector.push_back(400);
    // // stl_vector.push_back(500);
    // // stl_vector.push_back(600);
    // // stl_vector.push_back(700);
    // // stl_vector.push_back(800);
    // // for (size_t i = 0; i < stl_vector.size() ; i++)
    // //     std::cout << "stl_vector[" << i << "]: " << stl_vector[i] << std::endl;
    // print_STLVec(stl_vector);
    
    // // // stl_vector.erase(stl_vector.end() - 1, stl_vector.end() - 2);
    // // std::cout << *stl_vector.insert(stl_vector.begin() + 2, 555) << std::endl;
    // stl_vector.insert(stl_vector.begin() + 2, stl_vector.begin(), stl_vector.begin() + 6);
    // print_STLVec(stl_vector);
    
    // // stl_vector.insert(stl_vector.begin() + 2, stl_vector.begin() + 3, stl_vector.begin() + 1); 
    // /* terminate called after throwing an instance of 'std::length_error'  what():  vector::_M_range_insert
    // [1]    133894 abort (core dumped)  ./a.out */
    // stl_vector.size();
    
    // std::cout << "\n------------------------- AFTER WRONG ERASE --------------------------\n" << std::endl;
    // for (size_t i = 0; i < stl_vector.size() ; i++)
    //     std::cout << "stl_vector[" << i << "]: " << stl_vector[i] << std::endl;
    // std::cout << "stl_vector[100]: " << stl_vector[100] << std::endl;
    // // std::cout << "stl_vector.at(-1): " << stl_vector.at(-1) << std::endl;
    // // std::cout << "stl_vector.at(1432): " << stl_vector.at(1432) << std::endl;
    // std::cout << "begin: " << *(stl_vector.begin()) << std::endl;
    // std::cout << "vector[1]: " << stl_vector[1] << std::endl;
    // std::cout << "end - 1: " << *(--(stl_vector.end())) << std::endl;
    // std::cout << "end: " << *(stl_vector.end()) << std::endl;
    // stl_vector.pop_back();
    // stl_vector.pop_back();
    // stl_vector.pop_back();
    
    // std::cout << "begin: " << *(stl_vector.begin()) << std::endl;
    // std::cout << "end: " << *(stl_vector.end()) << std::endl;

    
    // std::vector<int> stl_vector2;
    // std::cout << "stl_vector2.capacity(): " << stl_vector2.capacity() << std::endl;
    // stl_vector2.push_back(6);
    // std::cout << "stl_vector2.capacity(): " << stl_vector2.capacity() << std::endl;
    // stl_vector2.push_back(3);
    // std::cout << "stl_vector2.capacity(): " << stl_vector2.capacity() << std::endl;
    // stl_vector2.push_back(12);
    // std::cout << "stl_vector2.capacity(): " << stl_vector2.capacity() << std::endl;
    // stl_vector2.push_back(10);
    // std::cout << "stl_vector2.capacity(): " << stl_vector2.capacity() << std::endl;
    // stl_vector2.push_back(1);
    // std::cout << "stl_vector2.capacity(): " << stl_vector2.capacity() << std::endl;
    // stl_vector2.push_back(27);
    // std::cout << "stl_vector2.capacity(): " << stl_vector2.capacity() << std::endl;
    // std::cout << "stl_vector2.size(): " << stl_vector2.size() << std::endl;
    // std::vector<int>::iterator stl_itb = stl_vector2.begin() + 1;
    // std::vector<int>::iterator stl_ite = stl_vector2.begin() + 3;

    // std::cout << "stl_itb: " << *stl_itb << std::endl;
    // std::cout << "stl_ite: " << *stl_ite << std::endl;
    // stl_vector2.insert(stl_ite, 34);
    // std::cout << "stl_ite: " << *stl_ite << std::endl;
    // std::cout << "\n----------------- BEFORE RANGE INSERTION ----------------\n" << std::endl;
    // std::cout << "stl_vector2[0]: " << stl_vector2[0] << std::endl;
    // std::cout << "stl_vector2[1]: " << stl_vector2[1] << std::endl;
    // std::cout << "stl_vector2[2]: " << stl_vector2[2] << std::endl;
    // std::cout << "stl_vector2[3]: " << stl_vector2[3] << std::endl;
    // std::cout << "stl_vector2[4]: " << stl_vector2[4] << std::endl;
    // std::cout << "stl_vector2[5]: " << stl_vector2[5] << std::endl;
    // std::cout << "stl_vector2[6]: " << stl_vector2[6] << std::endl;
    // // std::cout << "stl_vector2.end: " << *(stl_vector2.end()) << std::endl;    
    // // stl_vector2.erase(stl_itb, ++stl_vector2.end());
    // std::vector<int>::iterator stl_start = stl_vector2.begin() + 1;    
    // std::cout << "stl_start: " << *stl_start << std::endl;

    // std::vector<int> stl_vector3;
    // stl_vector3.push_back(7);
    // stl_vector3.push_back(2);
    // stl_vector3.push_back(9);
    // stl_vector2.insert(stl_start, stl_vector3.begin(), stl_vector3.begin() + 2);
    // std::cout << "\n----------------- AFTER RANGE INSERTION ----------------\n" << std::endl;
    // std::cout << "stl_vector2[0]: " << stl_vector2[0] << std::endl;
    // std::cout << "stl_vector2[1]: " << stl_vector2[1] << std::endl;
    // std::cout << "stl_vector2[2]: " << stl_vector2[2] << std::endl;
    // std::cout << "stl_vector2[3]: " << stl_vector2[3] << std::endl;
    // std::cout << "stl_vector2[4]: " << stl_vector2[4] << std::endl;
    // std::cout << "stl_vector2[5]: " << stl_vector2[5] << std::endl;
    // std::cout << "stl_vector2[6]: " << stl_vector2[6] << std::endl;
    // std::cout << "stl_vector2[7]: " << stl_vector2[7] << std::endl;
    // std::cout << "stl_vector2[8]: " << stl_vector2[8] << std::endl;

    // stl_itb = stl_vector2.begin() + 1;
    // stl_ite = stl_vector2.begin() + 3;
    // stl_vector2.erase(stl_itb, stl_ite);
    // std::cout << "\n----------------- AFTER RANGE ERASE ----------------\n" << std::endl;
    // std::cout << "stl_vector2[0]: " << stl_vector2[0] << std::endl;
    // std::cout << "stl_vector2[1]: " << stl_vector2[1] << std::endl;
    // std::cout << "stl_vector2[2]: " << stl_vector2[2] << std::endl;
    // std::cout << "stl_vector2[3]: " << stl_vector2[3] << std::endl;
    // std::cout << "stl_vector2[4]: " << stl_vector2[4] << std::endl;
    // std::cout << "stl_vector2[5]: " << stl_vector2[5] << std::endl;
    // std::cout << "stl_vector2[6]: " << stl_vector2[6] << std::endl;
    // std::cout << "stl_vector2.size(): " << stl_vector2.size() << std::endl;
    // std::vector<int *> stl_ptr_vector;
    // std::cout << "max_size(): " << stl_ptr_vector.max_size() << std::endl; 

    // std::vector<int> stl_v3;
    // // ft::Vector<int> v8(-3, 250);
    
    // stl_v3.push_back(7);
    // stl_v3.push_back(2);
    // stl_v3.push_back(9);
    // std::vector<int> stl_v4;
    // stl_v4.push_back(96);
    // stl_v4.push_back(97);
    // stl_v4.push_back(98);
    // stl_v4.push_back(99);
    // stl_v4.assign(stl_v3.begin(), stl_v3.end());
    // for (size_t i = 0; i < stl_v4.size() ; i++)
    //     std::cout << "stl_v4[" << i << "]: " << stl_v4[i] << std::endl;
    // std::cout << "stl_v4: size = " << stl_v4.size() << " - capacity = " << stl_v4.capacity() << std::endl;
    // std::cout << "stl_v4[0]: " << stl_v4[0] << std::endl;
    // std::cout << "stl_v4[1]: " << stl_v4[1] << std::endl;
    // std::cout << "stl_v4[2]: " << stl_v4[2] << std::endl;
    // std::cout << "stl_v4[3]: " << stl_v4[3] << std::endl;
    // std::cout << "stl_v4[4]: " << stl_v4[4] << std::endl;
    // std::cout << "stl_v4: size = " << stl_v4.size() << " - capacity = " << stl_v4.capacity() << std::endl;
    // std::vector<int> stl_v5;
    // stl_v5.push_back(93);
    // stl_v5.push_back(94);
    // stl_v5.push_back(95);
    // stl_v5.push_back(96);
    // stl_v5.push_back(97);
    // stl_v5.push_back(98);
    // stl_v5.push_back(99);
    // stl_v5.push_back(100);
    // stl_v5.assign(stl_v3.begin(), stl_v3.end());
    // std::cout << "\n----------------- AFTER ASSIGN ----------------\n" << std::endl;    
    // std::cout << "stl_v5[0]: " << stl_v5[0] << std::endl;
    // std::cout << "stl_v5[1]: " << stl_v5[1] << std::endl;
    // std::cout << "stl_v5[2]: " << stl_v5[2] << std::endl;
    // std::cout << "stl_v5[3]: " << stl_v5[3] << std::endl;
    // std::cout << "stl_v5[4]: " << stl_v5[4] << std::endl;
    // std::cout << "stl_v5: size = " << stl_v5.size() << " - capacity = " << stl_v5.capacity() << std::endl;
}