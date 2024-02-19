NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = ft_libft/ft_printf/libftprintf.a \
		ft_libft/libft.a \

SRCS = src/main.c \
	src/parsing/parsing_args.c \
	src/utils/utils.c \

OBJS = ${SRCS:.c=.o}

DEFAULT = \033[0m
COLOR = \033[38;5;197m

BANNER = @printf "$(COLOR) ____  ____  ____  ____  _  _ \n"
BANNER1 = printf "$(COLOR)(  _ \(_  _)(  _ \( ___)( \/ )\n"
BANNER2 = printf "$(COLOR) )___/ _)(_  )___/ )__)  )  ( \n"
BANNER3 = printf "$(COLOR)(__)  (____)(__)  (____)(_/\_)\n\n"

HEADER = $(BANNER);$(BANNER1);$(BANNER2);$(BANNER3); \

all: $(NAME)

$(NAME): $(OBJS)
	$(HEADER)
	@make -j -s -C ft_libft/
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)
	@echo "\033[38;5;48mpipex is ready !\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@make clean -s -C ft_libft/
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C ft_libft/
	@echo "\033[38;5;31mpipex cleaned...\033[0m"

re: fclean all

.PHONY: all clean fclean re
