NAME = I_don’t_want_to_set_the_world_on_fire
SRC =	main.cpp \
		Animal.cpp \
		Dog.cpp \
		Cat.cpp \
		Brain.cpp
OBJ_DIR = obj
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g
all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)


$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
