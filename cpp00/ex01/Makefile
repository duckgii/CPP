CC = c++
NAME = phonebook
CFLAGS = -std=c++98 -Wall -Wextra -Werror
SRCS = Contact.cpp PhoneBook.cpp main.cpp
SRCS_OBJS = Contact.o PhoneBook.o main.o
SRCS_HPPS =  Contact.hpp PhoneBook.hpp

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