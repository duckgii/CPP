CC = c++
NAME = megaphone
CFLAGS = -std=c++98
SRCS = megaphone.cpp

all : $(NAME)

clean :
#	rm -f $(SRCS_OBJS) $(VEC_OBJS) $(RAY_OBJS) $(SPHERE_OBJS) $(HIT_OBJS)
#	rm -f $(BUNUS_OBJS)

fclean : clean
	rm -f $(NAME)

re:
	make fclean
	make all

$(NAME) : $(SRCS)
		$(CC) $(CFLAGS) $^ -o $@

#%.o: %.c
#	$(CC) $(CFLAGS) -Imlx -c $< -o $@ 

.PHONY : all clean fclean re