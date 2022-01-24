/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:34:41 by abesombe          #+#    #+#             */
/*   Updated: 2022/01/24 16:25:23 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vector.hpp"
#include <iostream>
#include <vector>

int main()
{
        // std::cout << SIZE_MAX << std::endl;
        
        // ft::Vector<int> v9(8998000, 82387432);
        // ft::Vector<int> v10(100, 0);
        // v10.fill(0);
        // v10.printVec();
        // // ft::Vector<int> v12(v10);
        // v10.resize(1942730943297535664);

        // ft::Vector<int> v11(v10.begin() + 2, v10.begin() + 6);

        // std::vector<int> sv10(10, 0);
        // sv10.resize(1942730943297535664);
        // std::vector<int> sv11(sv10.begin() + 6, sv10.begin() + 2);

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
    
    // std::cout << "------------------------ MY VECTOR ----------------------------" << std::endl;
    // ft::Vector<int> v6;
    
    // ft::Vector<int> v1(3, 8);
    // v1.printVec();
    // v1.setName("v1");
    // ft::Vector<int> v2(v1);
    // v2.setName("v2");
    // v2.printVec();
    // v2[1] = 9;
    // v2[2] = 10;
    // v2.printVec();
    // ft::Vector<int>::iterator it1 = v2.begin() + 2;
    
    // ft::Vector<int> v3(it1, it1 + 1);
    // v3.setName("v3");
    // v3.printVec();    
    // ft::Vector<int> v4(5, 100);
    // v4[1] = 200;
    // v4[2] = 300;
    // v4[3] = 400;
    // v4[4] = 500;
    // v4.setName("v4");
    // v4.printVec();
    // v4.erase(v4.end() - 1, v4.end() - 2);
    // v4.printVec();
    // ft::Vector<int> v7(16, 100);
    // v7.setName("v7");
    // v7.resize(17);
    // v7.push_back(999);
    // v7.printVec();
    // std::cout << v7.capacity() << std::endl;

    // ft::Vector<int> v8(10, 0);
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
    // ft::Vector<int> vector2;
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
    // ft::Vector<int>::iterator itb = vector2.begin() + 1;
    // std::cout << "itb: " << *itb << std::endl;
    // std::cout << "vector2.begin(): " << *vector2.begin() << std::endl;
    // ft::Vector<int>::iterator ite = vector2.begin() + 3;
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
    ft::Vector<int> vector3;
    vector3.setName("vector3");
    vector3.push_back(7);
    vector3.push_back(2);
    vector3.push_back(9);
    vector3.printVec();
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
    // ft::Vector<int *> ptr_vec;
    // ptr_vec.setName("ptr_vec");
    // std::cout << "max_size(): " << ptr_vec.max_size() << std::endl;
    ft::Vector<int> vector4;
    vector4.setName("vector4");
    vector4.push_back(96);
    vector4.push_back(97);
    vector4.push_back(98);
    vector4.push_back(99);
    vector4.push_back(100);
    vector4.assign(vector3.end(), vector3.begin());
    vector4.printVec();
    // ft::Vector<int> vector5;
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
    // std::vector<int> stl_vector;
    // std::vector<int> stl_v1(16, 100);
    // stl_v1.resize(17);
    // stl_v1.push_back(999);
    // for (size_t i = 0; i < stl_v1.size() ; i++)
    //     std::cout << "stl_v1[" << i << "]: " << stl_v1[i] << std::endl;
    // stl_vector.push_back(100);
    // stl_vector.push_back(200);
    // stl_vector.push_back(300);
    // stl_vector.push_back(400);
    // stl_vector.push_back(500);
    // stl_vector.push_back(600);
    // stl_vector.push_back(700);
    // stl_vector.push_back(800);
    // for (size_t i = 0; i < stl_vector.size() ; i++)
    //     std::cout << "stl_vector[" << i << "]: " << stl_vector[i] << std::endl;
    
    // // stl_vector.erase(stl_vector.end() - 1, stl_vector.end() - 2);
    // std::cout << *stl_vector.insert(stl_vector.begin() + 2, 555) << std::endl;
    // // stl_vector.insert(stl_vector.begin() + 2, stl_vector.begin() + 1, stl_vector.begin() + 3);
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