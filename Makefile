CC      = gcc
CFLAGS  = -Wall -Werror -Wextra -g
LDFLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm

NAME    = sas
SRCS    = main.c fractal.c math_complex.c ft_ft.c math.c mlx_stuff.c render.c
OBJS    = $(SRCS:.c=.o)
HEADER  = fractol.h

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

all: $(MLX_LIB) $(NAME)

bonus: all

$(MLX_LIB):
	@if [ ! -f "$(MLX_LIB)" ] || [ "$(MLX_DIR)/Makefile" -nt "$(MLX_LIB)" ]; then \
		echo "Building MinilibX..."; \
		$(MAKE) -C $(MLX_DIR); \
	else \
		echo "MinilibX is already up to date."; \
	fi

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re