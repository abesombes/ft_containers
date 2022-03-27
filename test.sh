#!/bin/bash

function test()
{
	printf "\033[0;34mTEST : \033[0;38m""\033[0;35m$1\033[0;38m\n"
	R1=$($2)
	R2=$($3)
	if [ "$R1" == "$R2" ]
	then
		printf "\033[0;32mOK\033[0;38m\n\n"
		return 1
	else
		printf "\033[0;31mKO\033[0;38m\n\n"
		return 0
	fi
}

make
test "vector" "./ft_vector" "./std_vector"
test "map" "./ft_map" "./std_map"
test "stack" "./ft_stack" "./std_stack"
test "main_42" "./ft_main_42 0" "./std_main_42 0"
