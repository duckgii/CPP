CC = c++
NAME = account
CFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = Account.cpp tests.cpp
SRCS_OBJS = Account.o tests.o
SRCS_HPPS = Account.hpp

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

%.o: %.cpp $(SRCS_HPPS)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY : all clean fclean re