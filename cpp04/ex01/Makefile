CC = c++
NAME = a.out
CFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = main.cpp \
		Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \
		Brain.cpp
SRCS_OBJS = main.o \
			Animal.o \
			Cat.o \
			Dog.o \
			WrongAnimal.o \
			WrongCat.o \
			Brain.o

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