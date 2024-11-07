CPP = c++
CFLAGS =  -Wall -Wextra -Werror -std=c++98
FILES = megaphone.cpp

OBJ=$(FILES:.cpp=.o)

NAME=megaphone

all: $(NAME)


$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)
	
%.o:%.cpp
	$(CPP) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJ)

fclean:clean
	rm -rf $(NAME)

re: fclean all
