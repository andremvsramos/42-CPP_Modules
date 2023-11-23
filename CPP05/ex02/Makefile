NAME	=	bureaucrat

#----------DIRS----------#

DIR		=	.
HEADER	=	./headers/.

SRC		=	src/main.cpp \
			src/Bureaucrat.cpp \
			src/AForm.cpp \
			src/ShrubberyCreationForm.cpp \
			src/RobotomyRequestForm.cpp \
			src/PresidentialPardonForm.cpp \

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
MS		=	" [ Compiled No, you need form 28B, not 28C... ] "

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
