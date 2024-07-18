CC = c++
NAME = zombie
CFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = main.cpp \
		newZombie.cpp \
		randomChump.cpp \
		Zombie.cpp
SRCS_OBJS = main.o \
		newZombie.o \
		randomChump.o \
		Zombie.o
SRCS_HPPS = Zombie.hpp

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