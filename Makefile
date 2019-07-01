# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmofoken <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/13 11:16:46 by gmofoken          #+#    #+#              #
#    Updated: 2017/12/13 11:17:03 by gmofoken         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = nibbler
SRC = main.cpp Game.cpp Snake.cpp
LIB1 = lib1/Graphics.cpp
LIB2 = lib2/Graphics.cpp
LIB2 = lib2/Graphics.cpp
LIB3 = lib3/Graphics.cpp
FLAGS 	= clang++ -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(FLAGS) -shared -o lib1/ncurses.so $(LIB1) -I . -lncurses
	$(FLAGS) -shared -o lib2/ncurses2.so $(LIB2) -I . -lncurses
	$(FLAGS) -shared -o lib3/ncurses3.so $(LIB3) -I . -lncurses
	$(FLAGS) -o nibbler $(SRC) -ldl

clean:

fclean:
	rm -f $(NAME)
	rm -f lib1/ncurses.so
	rm -f lib2/ncurses2.so
	rm -f lib3/ncurses3.so

re: fclean all clean
