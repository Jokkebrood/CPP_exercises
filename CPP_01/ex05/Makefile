NAME = Harl

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
OBJ_DIR = obj
SRC =	main.cpp
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)
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
