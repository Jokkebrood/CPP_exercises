# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jade-vla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/05 10:49:16 by jade-vla          #+#    #+#              #
#    Updated: 2025/09/11 10:56:40 by jade-vla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
SRC =	main.cpp \
		add_contact.cpp \
		search_contact.cpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all
