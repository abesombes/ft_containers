# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 15:24:59 by abesombe          #+#    #+#              #
#    Updated: 2022/01/03 15:25:31 by abesombe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX =			c++

VERSION = 		-std=c++98

DEPF =			-MMD -MP

CXXFLAGS =		-Wall -Wextra -Werror $(VERSION) $(DEPF)

RM =			rm -rf

DIR_OBJS =		objs/

SRC =			main.cpp

SRCS =			$(addprefix $(DIR_SRCS), $(SRC))

COMPIL =		$(CXXFLAGS)	

OBJS =			$(addprefix $(DIR_OBJS), $(SRCS:.cpp=.o))

DEP =			$(OBJS:%.o=%.d)

NAME = 			ft_containers

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(COMPIL) $(OBJS) -o $(NAME)

$(DIR_OBJS)%.o: %.cpp
				mkdir -p $(@D)
				$(CXX) $(CXXFLAGS) -c $< -o $@
				echo "Compiled "$<" successfully!"

clean:
				$(RM) $(DIR_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all, clean, fclean, re, bonus

-include $(DEP)