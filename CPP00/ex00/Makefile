NAME = megaphone

#----------DIRS----------#

DIR = .
HEADER = .

SRC	=	megaphone.cpp

#----------COMMANDS----------#

C++ = c++
CFLAGS = -Wall -Werror -Wextra -g -std=c++98

RM = rm -rf

OBJ = ${SRC:.cpp=.o}

#----------COLORS----------#
GREEN = \033[0;32m
YELLOW = \033[0;33m
CYAN = \033[1;36m
RED = \033[0;31m

#--------ART & TEXT--------#
MS = " [ Compiled Megaphone ] "

#----------RULES----------#

%.o:%.cpp
		@mkdir -p bin/$(dir $<)
		@$(C++) $(CFLAGS) -c -I$(HEADER) $< -o bin/$*.o


all:		$(NAME)
			@echo "$(GREEN)$(MS)"
			@echo "$(CYAN) [ Generated: $(NAME) ] "

$(NAME):	$(OBJ)
			@$(C++) $(CFLAGS) $(OBJ:%=bin/%)  -o $(NAME)


clean:
			@if [ -d "./bin" ]; then \
				$(RM) $(OBJ:%=bin/%) \
				rmdir ./bin ;\
			fi

fclean:		clean
			@$(RM) $(NAME)

aclean:		all clean

re:			fclean all
