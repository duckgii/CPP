CC = c++
NAME = megaphone
CFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = Megaphone.cpp
SRCS_OBJS = Megaphone.o

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