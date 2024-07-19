CC = c++
NAME = weapon
CFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = main.cpp \
		HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp
SRCS_OBJS = main.o \
		HumanA.o \
		HumanB.o \
		Weapon.o

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