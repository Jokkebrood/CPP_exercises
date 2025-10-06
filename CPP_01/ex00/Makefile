NAME = BraiiiiiiinnnzzzZ
SRC =	main.cpp \
		randomChump.cpp \
		newZombie.cpp \
		Zombie.cpp
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g
all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
