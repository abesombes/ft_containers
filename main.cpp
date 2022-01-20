/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:34:41 by abesombe          #+#    #+#             */
/*   Updated: 2022/01/20 18:08:31 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vector.hpp"
#include <iostream>
#include <vector>

int main()
{

        // ft::Vector<std::string> v;

        // fill capacity a little
        // v.push_back("hello");
        // v.push_back("world");
        // std::cout << "v[0]: " << v[0] << std::endl;
        // std::cout << "v[1]: " << v[1] << std::endl;
        // v.printVec();
        // ft::Vector<int> v2;
        // v2.push_back(10);
        // v2.push_back(20);
        // v2.printVec();
        // ft::Vector<std::string> v;
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
    
    std::cout << "------------------------ MY VECTOR ----------------------------" << std::endl;
    ft::Vector<int> vector;
    
    {
        ft::Vector<int> v1;
        ft::Vector<int> v2;
        ft::Vector<int> v3;
        ft::Vector<int> v4;
    }
    
    vector.push_back(100);
    vector.push_back(200);
    vector.push_back(300);
    std::cout << "begin: " << *(vector.begin()) << std::endl;
    std::cout << "vector[1]: " << vector[1] << std::endl;
    std::cout << "vector.at(2): " << vector.at(2) << std::endl;
    std::cout << "vector.at(-1): " << vector.at(-1) << std::endl;
    std::cout << "vector.at(1432): " << vector.at(1432) << std::endl;
    // std::cout << "end - 1: " << *(--(vector.end())) << std::endl;
    std::cout << "end: " << *(vector.end()) << std::endl;
    vector.pop_back();
    vector.pop_back();
    vector.pop_back();
    std::cout << "begin: " << *(vector.begin()) << std::endl;
    std::cout << "end: " << *(vector.end()) << std::endl;
    ft::Vector<int> vector2;
    std::cout << "vector2.capacity(): " << vector2.capacity() << std::endl;
    vector2.push_back(6);
    std::cout << "vector2.capacity(): " << vector2.capacity() << std::endl;
    vector2.push_back(3);
    std::cout << "vector2.capacity(): " << vector2.capacity() << std::endl;
    vector2.push_back(12);
    std::cout << "vector2.capacity(): " << vector2.capacity() << std::endl;
    vector2.push_back(10);
    std::cout << "vector2.capacity(): " << vector2.capacity() << std::endl;
    vector2.push_back(1);
    std::cout << "vector2.capacity(): " << vector2.capacity() << std::endl;
    vector2.push_back(27);
    std::cout << "&_arr: " << &vector2.at(0) << std::endl;
    std::cout << "vector2.capacity(): " << vector2.capacity() << std::endl;
    std::cout << "vector2.size(): " << vector2.size() << std::endl;
    ft::Vector<int>::iterator itb = vector2.begin() + 1;
    std::cout << "itb: " << *itb << std::endl;
    std::cout << "vector2.begin(): " << *vector2.begin() << std::endl;
    ft::Vector<int>::iterator ite = vector2.begin() + 3;
    std::cout << "ite: " << *ite << std::endl;
    vector2.printVec();
    vector2.insert(ite, 34);
    std::cout << "&_arr: " << &vector2.at(0) << std::endl;
    vector2.printVec();
    ite = vector2.begin() + 4;
    vector2.insert(ite, 38);
    std::cout << "&_arr: " << &vector2.at(0) << std::endl;
    vector2.printVec();
    ite = vector2.begin() + 5;
    vector2.insert(ite, 42);
    std::cout << "&_arr: " << &vector2.at(0) << std::endl;
    std::cout << "_arr[8]: " << *(vector2.begin()+8) << std::endl;
    vector2.printVec();
    ite = vector2.begin() + 3;
    size_t n = 4;
    vector2.insert(ite, n, 50);
    vector2.printVec();
    std::cout << "ite: " << *ite << "\n" << "&*ite: " << &*ite << std::endl;
    std::cout << "_capacity: " << vector2.capacity() << std::endl;
    // vector2.insert(vector2.begin()+2, *vector2.begin());
    // vector2.insert(vector2.begin()+2, 2, *vector2.begin());
    ft::Vector<int> vector3;
    vector3.push_back(7);
    vector3.push_back(2);
    vector3.push_back(9);
    vector3.printVec();
    vector2.insert(ite, vector3.begin(), vector3.begin() + 2);
    vector2.printVec();
    // std::cout << "vector[5]: " << vector[5] << std::endl;
        
    // std::cout << "vector2.end: " << *(vector2.end()) << std::endl;    
    vector2.erase(itb, ite);
    std::cout << "vector2.size(): " << vector2.size() << std::endl;
    std::cout << "vector2[0]: " << vector2[0] << std::endl;
    std::cout << "vector2[1]: " << vector2[1] << std::endl;
    std::cout << "vector2[2]: " << vector2[2] << std::endl;
    std::cout << "vector2[3]: " << vector2[3] << std::endl;
    std::cout << "vector2[4]: " << vector2[4] << std::endl;
    std::cout << "vector2[5]: " << vector2[5] << std::endl;
    std::cout << "vector.size(): " << vector.size() << " - vector.capacity(): " << vector.capacity() << std::endl;
    std::cout << "vector2.size(): " << vector2.size() << std::endl;
    std::cout << "vector3.size(): " << vector3.size() << std::endl;
    ft::Vector<int *> ptr_vec;
    std::cout << "max_size(): " << ptr_vec.max_size() << std::endl;

    

    std::cout << "\n------------------------- STL VECTOR --------------------------\n" << std::endl;
    std::vector<int> stl_vector;
    stl_vector.push_back(100);
    stl_vector.push_back(200);
    stl_vector.push_back(300);
    // std::cout << "stl_vector.at(-1): " << stl_vector.at(-1) << std::endl;
    // std::cout << "stl_vector.at(1432): " << stl_vector.at(1432) << std::endl;
    std::cout << "begin: " << *(stl_vector.begin()) << std::endl;
    std::cout << "vector[1]: " << stl_vector[1] << std::endl;
    std::cout << "end - 1: " << *(--(stl_vector.end())) << std::endl;
    std::cout << "end: " << *(stl_vector.end()) << std::endl;
    stl_vector.pop_back();
    stl_vector.pop_back();
    stl_vector.pop_back();
    
    std::cout << "begin: " << *(stl_vector.begin()) << std::endl;
    std::cout << "end: " << *(stl_vector.end()) << std::endl;

    
    std::vector<int> stl_vector2;
    std::cout << "stl_vector2.capacity(): " << stl_vector2.capacity() << std::endl;
    stl_vector2.push_back(6);
    std::cout << "stl_vector2.capacity(): " << stl_vector2.capacity() << std::endl;
    stl_vector2.push_back(3);
    std::cout << "stl_vector2.capacity(): " << stl_vector2.capacity() << std::endl;
    stl_vector2.push_back(12);
    std::cout << "stl_vector2.capacity(): " << stl_vector2.capacity() << std::endl;
    stl_vector2.push_back(10);
    std::cout << "stl_vector2.capacity(): " << stl_vector2.capacity() << std::endl;
    stl_vector2.push_back(1);
    std::cout << "stl_vector2.capacity(): " << stl_vector2.capacity() << std::endl;
    stl_vector2.push_back(27);
    std::cout << "stl_vector2.capacity(): " << stl_vector2.capacity() << std::endl;
    std::cout << "stl_vector2.size(): " << stl_vector2.size() << std::endl;
    std::vector<int>::iterator stl_itb = stl_vector2.begin() + 1;
    std::vector<int>::iterator stl_ite = stl_vector2.begin() + 3;

    std::cout << "stl_itb: " << *stl_itb << std::endl;
    std::cout << "stl_ite: " << *stl_ite << std::endl;
    stl_vector2.insert(stl_ite, 34);
    std::cout << "stl_ite: " << *stl_ite << std::endl;
    std::cout << "\n----------------- BEFORE RANGE INSERTION ----------------\n" << std::endl;
    std::cout << "stl_vector2[0]: " << stl_vector2[0] << std::endl;
    std::cout << "stl_vector2[1]: " << stl_vector2[1] << std::endl;
    std::cout << "stl_vector2[2]: " << stl_vector2[2] << std::endl;
    std::cout << "stl_vector2[3]: " << stl_vector2[3] << std::endl;
    std::cout << "stl_vector2[4]: " << stl_vector2[4] << std::endl;
    std::cout << "stl_vector2[5]: " << stl_vector2[5] << std::endl;
    std::cout << "stl_vector2[6]: " << stl_vector2[6] << std::endl;
    // std::cout << "stl_vector2.end: " << *(stl_vector2.end()) << std::endl;    
    // stl_vector2.erase(stl_itb, ++stl_vector2.end());
    stl_vector2.insert(stl_ite, vector3.begin(), vector3.begin() + 2);
    std::cout << "\n----------------- AFTER RANGE INSERTION ----------------\n" << std::endl;
    std::cout << "stl_vector2[0]: " << stl_vector2[0] << std::endl;
    std::cout << "stl_vector2[1]: " << stl_vector2[1] << std::endl;
    std::cout << "stl_vector2[2]: " << stl_vector2[2] << std::endl;
    std::cout << "stl_vector2[3]: " << stl_vector2[3] << std::endl;
    std::cout << "stl_vector2[4]: " << stl_vector2[4] << std::endl;
    std::cout << "stl_vector2[5]: " << stl_vector2[5] << std::endl;
    std::cout << "stl_vector2[6]: " << stl_vector2[6] << std::endl;
    std::cout << "stl_vector2[7]: " << stl_vector2[7] << std::endl;
    std::cout << "stl_vector2[8]: " << stl_vector2[8] << std::endl;
    // stl_vector2.printVec();

    stl_itb = stl_vector2.begin() + 1;
    stl_ite = stl_vector2.begin() + 3;
    stl_vector2.erase(stl_itb, stl_ite);
    std::cout << "\n----------------- AFTER RANGE ERASE ----------------\n" << std::endl;
    std::cout << "stl_vector2[0]: " << stl_vector2[0] << std::endl;
    std::cout << "stl_vector2[1]: " << stl_vector2[1] << std::endl;
    std::cout << "stl_vector2[2]: " << stl_vector2[2] << std::endl;
    std::cout << "stl_vector2[3]: " << stl_vector2[3] << std::endl;
    std::cout << "stl_vector2[4]: " << stl_vector2[4] << std::endl;
    std::cout << "stl_vector2[5]: " << stl_vector2[5] << std::endl;
    std::cout << "stl_vector2[6]: " << stl_vector2[6] << std::endl;
    std::cout << "stl_vector2.size(): " << stl_vector2.size() << std::endl;
    std::vector<int *> stl_ptr_vector;
    std::cout << "max_size(): " << stl_ptr_vector.max_size() << std::endl; 
}