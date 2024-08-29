CC = c++
NAME = a.out
CFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = main.cpp \
		AMateria.cpp \
		Character.cpp \
		Cure.cpp \
		Ice.cpp \
		MateriaSource.cpp
SRCS_OBJS = main.o \
			AMateria.o \
			Character.o \
			Cure.o \
			Ice.o \
			MateriaSource.o

all : $(NAME)

clean :
	rm -f $(SRCS_OBJS)

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