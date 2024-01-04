NAME	=	RPN

#----------DIRS----------#

DIR		=	.
HEADER	=	./headers/.

SRC		=	src/main.cpp \
			src/RPN.cpp \

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
MS		=	" [ Compiled Reverse Polish Notation ] "

#----------ARGUMENTS----------#

# Change the value here to check runtime #
	ARG = "8 9 * 9 - 9 / 9 / 4 - 1 +"

#----------RULES----------#

%.o:%.cpp
		@$(C++) $(CFLAGS) -c -I$(HEADER) $< -o $*.o

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(C++) $(CFLAGS) $(OBJ)  -o $(NAME)
			@echo "$(GREEN)$(MS)"
			@echo "$(CYAN) [ Generated: $(NAME) ] $(RESET)"

clean:
			@$(RM) $(OBJ)

fclean:		clean
			@$(RM) $(NAME)

aclean:		all clean

runtime: 	$(NAME)
ifdef ARG
	@/usr/bin/time -f "$(YELLOW)\nElapsed time: %es$(RESET)" ./$(NAME) $(ARG) || { echo "$(RED)Execution failed with exit code $$?$(RESET)"; exit 0; }
else
	@echo "$(RED) Please provide an argument for this exercise"
endif

re:			fclean all
