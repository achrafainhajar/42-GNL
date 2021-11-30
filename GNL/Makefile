SRC = get_next_line.c\
get_next_line_utils.c

OBJ = get_next_line.o\
get_next_line_utils.o

NAME = get_next_line.a

CC = cc -Wall -Wextra -Werror -D BUFFER_SIZE

all : $(NAME)
	
$(NAME) : $(OBJ)

%.o: %.c
	$(CC) -c $<
	ar -rc $(NAME) $@
	
clean : 
	rm -rf $(OBJ) $(OBJB)

bonus : $(OBJB)

fclean : clean
	rm -rf $(NAME)

re : fclean all