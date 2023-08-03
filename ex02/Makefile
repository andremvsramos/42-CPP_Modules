NAME =	banking

SRC =	Account.cpp \
		tests.cpp \

HEADER =	Account.hpp \

OBJ = ${SRC:.cpp=.o}

CC = c++
FLAGS = -Wall -Werror -Wextra -g -std=c++98
RM = rm -rf

all: $(NAME)

%.o:%.cpp
	$(CC) $(FLAGS) -c -I. -o $@ $<

$(NAME): $(OBJ)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all
