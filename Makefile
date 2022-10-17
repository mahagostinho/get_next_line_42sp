NAME = get_next_line

SIZE = 10000000

all: $(NAME)

$(NAME): 
	cc -Werror -Wextra -Wall -D BUFFER_SIZE=$(SIZE) get_next_line.c get_next_line_utils.c main.c -o $(NAME)

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME)

re: fclean all