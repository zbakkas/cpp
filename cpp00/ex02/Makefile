CC = c++
FLAGS =  -Wall -Wextra -Werror -std=c++98
FILES = Account.cpp tests.cpp

OBJ=$(FILES:.cpp=.o)

NAME=Account

all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)


clean:
	rm -f $(OBJ)

fclean:clean
	rm -rf $(NAME)

re: fclean all

