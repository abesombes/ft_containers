/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:34:25 by abesombe          #+#    #+#             */
/*   Updated: 2022/01/13 18:34:30 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#define NDEBUG     
#include <cassert>  
using namespace std;
void display_number(int* myInt) {
  assert (myInt!=NULL);
  cout<<"myInt contains value" << " = "<<*myInt<<endl;
}
// int main ()
// {
//   int myptr=5;
//   int * second_ptr = NULL;
//   int * third_ptr = NULL;
//   second_ptr=&myptr;
//   display_number (second_ptr);
//   display_number (third_ptr);
//   return 0;
// }