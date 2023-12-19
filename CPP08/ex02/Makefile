NAME	=	stack

#----------DIRS----------#

DIR		=	.
HEADER	=	./headers/.

SRC		=	src/main.cpp \

#----------COMMANDS----------#

C++		=	c++
CFLAGS	=	-Wall -Werror -Wextra -g -std=c++98

RM		=	rm -rf

OBJ		=	${SRC:.cpp=.o}

#----------COLORS----------#
GREEN	=	\033[0;32m
YELLOW	=	$(shell tput setaf 3)
CYAN	=	\033[1;36m
RED		=	\033[0;31m
RESET	=	$(shell tput sgr0)

#--------ART & TEXT--------#
MS		=	" [ Compiled Mutated abomination ] "

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

runtime: 	$(NAME)
			@/usr/bin/time -f "$(YELLOW)\nElapsed time: %es$(RESET)" ./$(NAME)

re:			fclean all
