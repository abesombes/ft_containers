/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <abesombes@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:26:37 by abesombe          #+#    #+#             */
/*   Updated: 2022/01/09 17:17:45 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <iostream>

int main()
{
    ft::Vector<int> vector;
    
    vector.push_back(100);
    vector.push_back(200);
    vector.push_back(300);
    std::cout << "begin: " << *(vector.begin()) << std::endl;
    std::cout << "vector[1]: " << vector[1] << std::endl;
    std::cout << "end - 1: " << *(--(vector.end())) << std::endl;
    std::cout << "end: " << *(vector.end()) << std::endl;
}