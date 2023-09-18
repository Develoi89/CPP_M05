NAME		=	test

SRC			=	AForm.cpp\
				Intern.cpp\
				Bureaucrat.cpp\
				ShrubberyCreationForm.cpp\
				PresidentialPardonForm.cpp\
				RobotomyRequestForm.cpp\
				main.cpp

HDS			=	AForm.hpp\
				Intern.hpp\
				Bureaucrat.hpp\
				RobotomyRequestForm.hpp\
				ShrubberyCreationForm.hpp\
				PresidentialPardonForm.hpp

OBJ			=	$(SRC:.cpp=.o)

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

%.o:	%.cpp
		$(CC) ${CFLAGS} -o $@ -c $<

$(NAME)		:	$(OBJ) $(HDS)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
					
all			:	$(NAME)

clean		:
		@rm -rf

fclean		:	clean
		@rm -rf $(NAME) $(OBJ) prueba

re			:	fclean	all

.PHONY		:	all clean fclean re