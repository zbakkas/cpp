CC = c++
FLAGS =  -Wall -Wextra -Werror -std=c++98
FILES = megaphone.cpp

OBJ=$(FILES:.cpp=.o)

NAME=megaphone

all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	
%.o:%.cpp
	$(CPP) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJ)

fclean:clean
	rm -rf $(NAME)

re: fclean all
