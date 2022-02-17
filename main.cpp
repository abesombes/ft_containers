/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:34:41 by abesombe          #+#    #+#             */
/*   Updated: 2022/02/17 09:17:25 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vector.hpp"
#include "stack.hpp"
#include "utils/pair.hpp"
#include "utils/binary_search_tree.hpp"
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
    
    // ft::RBTree<std::string, std::string> RedBlackT;
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
    
    ft::RBTree<int, std::string> RedBlackT;
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

    RedBlackT.insertNode(39, "Dallas");
    RedBlackT.printRBT();
    RedBlackT.insertNode(11, "Copenhagen");
    RedBlackT.printRBT();
    RedBlackT.insertNode(26, "Paris");
    RedBlackT.printRBT();
    RedBlackT.insertNode(16, "Madrid");
    RedBlackT.printRBT();
    RedBlackT.insertNode(71, "New-York");
    RedBlackT.printRBT();
    RedBlackT.insertNode(69, "Calixte");
    RedBlackT.printRBT();
    RedBlackT.insertNode(13, "Boston");
    RedBlackT.printRBT();
    RedBlackT.insertNode(78, "Sao Paolo");
    RedBlackT.printRBT();
    RedBlackT.insertNode(75, "Quito");
    RedBlackT.printRBT();
    RedBlackT.insertNode(1, "Medelin");
    RedBlackT.printRBT();
    RedBlackT.insertNode(15, "Cali");
    RedBlackT.printRBT();
    RedBlackT.insertNode(2, "Valdes");
    RedBlackT.printRBT();
    RedBlackT.insertNode(47, "Punta Arena");
    RedBlackT.printRBT();
    RedBlackT.insertNode(57, "Santiago");
    RedBlackT.printRBT();
    RedBlackT.insertNode(62, "Cordoba");
    RedBlackT.printRBT();
    RedBlackT.insertNode(92, "Salta");
    RedBlackT.printRBT();
    RedBlackT.insertNode(4, "Santa Monica");
    RedBlackT.printRBT();
    RedBlackT.insertNode(51, "Mar Del Plata");
    RedBlackT.printRBT();
    RedBlackT.insertNode(59, "London");
    RedBlackT.printRBT();
    RedBlackT.insertNode(77, "Chicago");
    RedBlackT.printRBT();
    RedBlackT.insertNode(20, "Philadelphia");
    RedBlackT.printRBT();
    RedBlackT.insertNode(65, "Las Vegas");
    RedBlackT.printRBT();
    RedBlackT.insertNode(84, "Salt Lake City");
    RedBlackT.printRBT();
    RedBlackT.insertNode(6, "Colorado Spring");
    RedBlackT.printRBT();
    RedBlackT.insertNode(87, "Phoenix");
    RedBlackT.printRBT();

    RedBlackT.deleteNode(RedBlackT.getRoot(), 51);
    RedBlackT.printRBT();
    RedBlackT.deleteNode(RedBlackT.getRoot(), 77);
    RedBlackT.printRBT();
    RedBlackT.deleteNode(RedBlackT.getRoot(), 6);
    RedBlackT.printRBT();
    RedBlackT.deleteNode(RedBlackT.getRoot(), 16);
    RedBlackT.printRBT();
    RedBlackT.deleteNode(RedBlackT.getRoot(), 26);
    RedBlackT.printRBT();
    RedBlackT.deleteNode(RedBlackT.getRoot(), 2);
    RedBlackT.printRBT();
    RedBlackT.deleteNode(RedBlackT.getRoot(), 92);
    RedBlackT.printRBT();
    RedBlackT.deleteNode(RedBlackT.getRoot(), 15);
    RedBlackT.printRBT();
    RedBlackT.deleteNode(RedBlackT.getRoot(), 47);
    RedBlackT.printRBT();
    RedBlackT.deleteNode(RedBlackT.getRoot(), 84);
    RedBlackT.printRBT();
    RedBlackT.deleteNode(RedBlackT.getRoot(), 71);
    RedBlackT.printRBT();
    RedBlackT.deleteNode(RedBlackT.getRoot(), 11);
    RedBlackT.printRBT();
    RedBlackT.deleteNode(RedBlackT.getRoot(), 87);
    RedBlackT.printRBT();
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
    // ft::vector<int>::iterator it1 = v1.begin() + 2;
    // std::cout << *it1 << " " << &(*it1) << std::endl;    
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
    // it++;
    // vct.printVec();
    
    // *it = 14;
    // std::cout << &*it << std::endl;
    // it++;
    // vct.printVec();

    // *it = 21;
    // it++;
    // vct.printVec();
    
    // *it = 28;
    // it++;
    // vct.printVec();
    
    // *it = 35;
    // it++;
    // vct.printVec();
	// for (int i = 1; it != ite; ++i)
    // {
	// 	*it = (i * 7);
    //     it++;
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
	// std::cout << *(it++) << std::endl;
	// std::cout << *it++ << std::endl;
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