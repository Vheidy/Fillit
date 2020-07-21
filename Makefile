CC = gcc

FLAGS = -g -Wall -Wextra -Werror

NAME = fillit

SRC = ft_body.c ft_bust.c ft_coordinate.c ft_istetriminos.c ft_new_list.c ft_read.c

OBJ = $(SRC:.c=.o)

LIBFT = -L libft -lft

HEADER = -c -I fillit.h

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $<

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	@rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all