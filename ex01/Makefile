CPP = c++
FLAGS =  -Wall -Wextra -Werror -std=c++98
FILES = test.cpp

OBJ=$(FILES:.cpp=.o)

NAME=PhoneBook

all: $(NAME)


$(NAME): $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:clean
	rm -rf $(NAME)

re: fclean all