/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:34:41 by abesombe          #+#    #+#             */
/*   Updated: 2022/01/13 22:05:34 by abesombe         ###   ########.fr       */
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
    std::cout << "end - 1: " << *(--(vector.end())) << std::endl;
    std::cout << "end: " << *(vector.end()) << std::endl;
    vector.pop_back();
    vector.pop_back();
    vector.pop_back();
    std::cout << "begin: " << *(vector.begin()) << std::endl;
    std::cout << "end: " << *(vector.end()) << std::endl;

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

    
}