/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:34:41 by abesombe          #+#    #+#             */
/*   Updated: 2022/01/13 23:23:06 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vector.hpp"
#include <iostream>
#include <vector>

int main()
{
    
    std::cout << "------------------------ MY VECTOR ----------------------------" << std::endl;
    ft::Vector<int> vector;
    
    vector.push_back(100);
    vector.push_back(200);
    vector.push_back(300);
    std::cout << "begin: " << *(vector.begin()) << std::endl;
    std::cout << "vector[1]: " << vector[1] << std::endl;
    std::cout << "vector.at(2): " << vector.at(2) << std::endl;
    std::cout << "vector.at(-1): " << vector.at(-1) << std::endl;
    std::cout << "vector.at(1432): " << vector.at(1432) << std::endl;
    std::cout << "end - 1: " << *(--(vector.end())) << std::endl;
    std::cout << "end: " << *(vector.end()) << std::endl;
    vector.pop_back();
    vector.pop_back();
    vector.pop_back();
    std::cout << "begin: " << *(vector.begin()) << std::endl;
    std::cout << "end: " << *(vector.end()) << std::endl;
    ft::Vector<int *> ptr_vec;
    std::cout << "max_size(): " << ptr_vec.max_size() << std::endl; 
    

    std::cout << "------------------------- STL VECTOR --------------------------" << std::endl;
    std::vector<int> stl_vector;
    stl_vector.push_back(100);
    stl_vector.push_back(200);
    stl_vector.push_back(300);
    std::cout << "begin: " << *(stl_vector.begin()) << std::endl;
    std::cout << "vector[1]: " << stl_vector[1] << std::endl;
    std::cout << "end - 1: " << *(--(stl_vector.end())) << std::endl;
    std::cout << "end: " << *(stl_vector.end()) << std::endl;
    stl_vector.pop_back();
    stl_vector.pop_back();
    stl_vector.pop_back();
    std::cout << "begin: " << *(stl_vector.begin()) << std::endl;
    std::cout << "end: " << *(stl_vector.end()) << std::endl;
    std::vector<int *> stl_ptr_vector;
    std::cout << "max_size(): " << stl_ptr_vector.max_size() << std::endl; 
    
}