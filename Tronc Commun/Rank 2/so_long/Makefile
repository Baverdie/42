NAME = so_long
CC = clang
CFLAGS = -Wall -Wextra -Werror -g3
LIBS = ft_printf/libftprintf.a \
		ft_libft/libft.a \
		# MacroLibX/libmlx.so -lSDL2

SRCS = main.c \
	init.c \
	parsing/parsing_errors.c \
	parsing/parsing_map.c \
	parsing/parsing_data_map.c \
	utils/map.c \
	utils/utils.c \
	# graphique/so_long.c \

OBJS = ${SRCS:.c=.o}

DEFAULT = \033[0m
COLOR = \033[38;5;197m

BANNER = @printf "$(COLOR) ___  _____       __    _____  _  _  ___ \n"
BANNER1 = printf "$(COLOR)/ __)(  _  )     (  )  (  _  )( \( )/ __)\n"
BANNER2 = printf "$(COLOR)\__ \ )(_)(  ___  )(__  )(_)(  )  (( (_-.\n"
BANNER3 = printf "$(COLOR)(___/(_____)(___)(____)(_____)(_)\_)\___/\n\n"

HEADER = $(BANNER);$(BANNER1);$(BANNER2);$(BANNER3); \

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	@echo "\033[38;5;48mMLX42 is ready !\033[0m"
	@make -j -s -C ft_libft/
	@make -j -s -C ft_printf/
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)
	$(HEADER)
	@echo "\033[38;5;48mso_long is ready !\033[0m"

clean:
	@make clean -s -C ft_libft/
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C ft_libft/
	@make fclean -s -C ft_printf/
	@echo "\033[38;5;31mso_long cleaned...\033[0m"

re: fclean
	@make -j all --no-print-directory

.PHONY: all clean fclean re
