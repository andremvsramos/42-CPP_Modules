NAME	=	abstract

#----------DIRS----------#

DIR		=	.
HEADER	=	./headers/.

SRC		=	src/main.cpp \
			src/Animal.cpp \
			src/Dog.cpp \
			src/Cat.cpp \
			src/WrongAnimal.cpp \
			src/WrongCat.cpp \
			src/Brain.cpp \

#----------COMMANDS----------#

C++		=	c++
CFLAGS	=	-Wall -Werror -Wextra -g -std=c++98

RM		=	rm -rf

OBJ		=	${SRC:.cpp=.o}

#----------COLORS----------#
GREEN	=	\033[0;32m
YELLOW	=	\033[0;33m
CYAN	=	\033[1;36m
RED		=	\033[0;31m

#--------ART & TEXT--------#
MS		=	" [ Compiled Abstract class ] "

#----------RULES----------#

%.o:%.cpp
		@$(C++) $(CFLAGS) -c -I$(HEADER) $< -o $*.o

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(C++) $(CFLAGS) $(OBJ)  -o $(NAME)
			@echo "$(GREEN)$(MS)"
			@echo "$(CYAN) [ Generated: $(NAME) ] "

clean:
			@$(RM) $(OBJ)

fclean:		clean
			@$(RM) $(NAME)

aclean:		all clean

re:			fclean all
