NAME = so_long

SRCS = mapcontrol.c mapcontrol2.c mapcontrol3.c mapcontrol4.c \
		mapcontrol5.c mapcontrol6.c mapcontrol7.c utls.c utls2.c \
		main.c utls3.c ft_itoa.c minilibx/libmlx.a \
		getnextline/get_next_line.c getnextline/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

MLX = make -C ./minilibx

LFALGS = -framework AppKit -framework OpenGL -L./minilibx -lmlx

$(NAME):
		@$(MLX)
		@gcc $(FLAGS) $(LFALGS) $(SRCS) getnextline/get_next_line.a minilibx/libmlx.a -o so_long

all: $(NAME)

clean:
		@make clean -C ./minilibx

fclean: clean
		@rm -rf so_long

re: fclean all

.PHONY: all clean fclean re