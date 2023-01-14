NAME = so_long
CFLAGS = -Wall -Wextra -Werror
CC = CC
RM = rm -f
SRC = check_map.c fill_map.c ft_split.c ft_strjoin.c get_next_line.c get_next_line_utils.c handle_input.c init_asset.c is_valid.c print_exit.c \
	so_long.c valid_path.c
OBJ= $(SRC:.c=.o)

all: ${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf ${NAME}

re: fclean
	make all