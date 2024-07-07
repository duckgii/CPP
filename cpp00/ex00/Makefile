CC = c++
NAME = megaphone
CFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = megaphone.cpp, \
		main.cpp
SRCS_OBJS = megaphone.o \
			main.o
SRCS_HPP = megaphone.hpp

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

%.o: %.cpp, $(SRCS_HPP)
	$(CC) $(CFLAGS) -c -I $< -o $@

.PHONY : all clean fclean re