CC = c++
NAME = a.out
CFLAGS = -std=c++98 -Wall -Wextra -Werror

SRCS = main.cpp \
		Bureaucrat.cpp \
		PresidentialPardonForm.cpp\
		RobotomyRequestForm.cpp\
		ShrubberyCreationForm.cpp\
		AForm.cpp

SRCS_OBJS = main.o \
			PresidentialPardonForm.o\
			RobotomyRequestForm.o\
			ShrubberyCreationForm.o\
			Bureaucrat.o \
			AForm.o

all : $(NAME)

clean :
	rm -f $(SRCS_OBJS)
	rm -f centos_shrubbery

fclean : clean
	rm -f $(NAME)

re:
	make fclean
	make all

$(NAME) : $(SRCS_OBJS)
		$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : all clean fclean re