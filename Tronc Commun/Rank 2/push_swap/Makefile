NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = ft_libft/ft_printf/libftprintf.a \
		ft_libft/libft.a \

SRCS = src/main.c \
		src/parsing/parse_arg.c \
		src/parsing/index.c \
		src/move/rotate.c \
		src/move/reverse_rotate.c \
		src/utils/utils.c \
		src/utils/utils_stack.c \
		src/move/push.c \
		src/move/swap.c \
		src/move/radix.c \

OBJS = ${SRCS:.c=.o}

DEFAULT = \033[0m
COLOR = \033[38;5;197m

BANNER = @printf "$(COLOR) ____  __  __  ___  _   _       ___  _    _    __    ____\n"
BANNER1 = printf "$(COLOR)(  _ \(  )(  )/ __)( )_( )     / __)( \/\/ )  /__\  (  _ \ \n"
BANNER2 = printf "$(COLOR) )___/ )(__)( \__ \ ) _ (  ___ \__ \ )    (  /(__)\  )___/\n"
BANNER3 = printf "$(COLOR)(__)  (______)(___/(_) (_)(___)(___/(__/\__)(__)(__)(__)\n\n"

HEADER = $(BANNER);$(BANNER1);$(BANNER2);$(BANNER3); \

all: $(NAME)

$(NAME): $(OBJS)
	$(HEADER)
	@make -j -s -C ft_libft/
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)
	@echo "\033[38;5;48mpush_swap is ready !\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@make clean -s -C ft_libft/
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C ft_libft/
	@echo "\033[38;5;31mpush_swap cleaned...\033[0m"

re: fclean all

.PHONY: all clean fclean re
