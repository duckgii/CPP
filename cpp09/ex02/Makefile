CC = c++
NAME = PmergeMe
CFLAGS = -std=c++98 -fsanitize=address -Wall -Wextra -Werror

SRCS = main.cpp \
		PmergeMe.cpp
		
SRCS_OBJS = main.o \
			PmergeMe.o

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