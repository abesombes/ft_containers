# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/27 18:48:21 by abesombe          #+#    #+#              #
#    Updated: 2022/03/27 18:48:25 by abesombe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NEW_DIR				= mkdir -p
DEL_DIR				= rm -rf
VERSION				= -std=c++98

CC					= c++
COMPILE_FLAG		= $(VERSION) -Wall -Werror -Wextra
DEPS_FLAG			= -MMD
INCLUDES_FLAG		= -I$(INCLUDES_DIR)

INCLUDES_DIR		= includes/
OBJS_DIR			= objs/
SRCS_DIR			= tests/

VPATH				= $(SRCS_DIR)

SRC_VECTOR			= vector_tests.cpp
SRC_STACK			= stack_tests.cpp
SRC_MAP				= map_tests.cpp
SRC_MAIN_42			= main.cpp

OBJS				= $(patsubst %.cpp, $(OBJS_DIR)%.o, $(SRC_VECTOR) $(SRC_STACK) $(SRC_MAP) $(SRC_MAIN_42))
DEPS				= $(OBJS:.o=.d)

FT_VECTOR			= ft_vector
FT_STACK			= ft_stack
FT_MAP				= ft_map
FT_MAIN_42			= ft_main_42

STD_VECTOR			= std_vector
STD_STACK			= std_stack
STD_MAP				= std_map
STD_MAIN_42			= std_main_42

NAMESPACE			= -D NAMESPACE=std

all					: $(OBJS) $(FT_VECTOR) $(FT_MAP) $(FT_STACK) $(FT_MAIN_42)
					
$(FT_VECTOR)		: $(SRC_VECTOR)
					$(CC) $(COMPILE_FLAG) $^ -o $@
					$(CC) $(COMPILE_FLAG) $(NAMESPACE) $^ -o $(STD_VECTOR)

$(FT_MAP)			: $(SRC_MAP)
					$(CC) $(COMPILE_FLAG) $^ -o $@
					$(CC) $(COMPILE_FLAG) $(NAMESPACE) $^ -o $(STD_MAP)

$(FT_STACK)			: $(SRC_STACK)
					$(CC) $(COMPILE_FLAG) $^ -o $@
					$(CC) $(COMPILE_FLAG) $(NAMESPACE) $^ -o $(STD_STACK)

$(FT_MAIN_42)		: $(SRC_MAIN_42)
					$(CC) $(COMPILE_FLAG) $^ -o $@
					$(CC) $(COMPILE_FLAG) $(NAMESPACE) $^ -o $(STD_MAIN_42)
					

$(OBJS_DIR)%.o		: %.cpp
					$(NEW_DIR) $(OBJS_DIR)
					$(CC) $(COMPILE_FLAG) $(DEPS_FLAG) -c $< $(INCLUDES_FLAG) -o $@

clean				:
					$(DEL_DIR) $(OBJS_DIR)

fclean				: clean
					$(DEL_DIR) $(FT_VECTOR) $(FT_MAP) $(FT_STACK) $(FT_MAIN_42) $(STD_VECTOR) $(STD_MAP) $(STD_STACK) $(STD_MAIN_42)

re					: fclean all

-include			$(DEPS)

.PHONY				: all clean fclean re

