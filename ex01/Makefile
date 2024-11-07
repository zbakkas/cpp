CPP = c++
CFLAGS =  -Wall -Wextra -Werror -std=c++98
FILES = phonebook.cpp main.cpp

OBJ=$(FILES:.cpp=.o)

NAME=PhoneBook

all: $(NAME)


$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp classs.hpp
	$(CPP) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJ)

fclean:clean
	rm -rf $(NAME)

re: fclean all