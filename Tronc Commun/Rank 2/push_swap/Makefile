NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LIBS = ft_libft/ft_printf/libftprintf.a \
		ft_libft/libft.a \

SRCS = src/main.c \
		src/parsing/parse_arg.c \
		src/parsing/parse_stack.c \
		src/move/rotate.c \
		src/move/reverse_rotate.c \
		src/utils/utils.c \
		src/utils/utils_stack.c \
		src/move/push.c \
		src/move/swap.c \

OBJS = ${SRCS:.c=.o}

DEFAULT = \033[0m
COLOR = \033[38;5;197m

BANNER = @printf "$(COLOR) ____  __  __  ___  _   _       ___  _    _    __    ____\n"
BANNER1 = printf "$(COLOR)(  _ \(  )(  )/ __)( )_( )     / __)( \/\/ )  /__\  (  _ \ \n"
BANNER2 = printf "$(COLOR) )___/ )(__)( \__ \ ) _ (  ___ \__ \ )    (  /(__)\  )___/\n"
BANNER3 = printf "$(COLOR)(__)  (______)(___/(_) (_)(___)(___/(__/\__)(__)(__)(__)\n\n"

HEADER = $(BANNER);$(BANNER1);$(BANNER2);$(BANNER3); \

load:
	@sleep 0.4
	@printf "|\033[0;31m▰     34%%\033[0m|"
	@sleep 0.3
	@printf "\r|\033[0;31m▰▰    69%%\033[0m|"
	@sleep 0.3
	@printf "\r|\033[0;31m▰▰▰   82%%\033[0m|"
	@sleep 0.3
	@printf "\r|\033[0;31m▰▰▰▰ 100%%\033[0m|"
	@sleep 0.4
	@printf "\r"

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	$(HEADER)
	# @make --no-print-directory load
	@make -j -s -C ft_libft/
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)
	# @make --no-print-directory load
	@echo "\033[38;5;48mpush_swap is ready !\033[0m"

clean:
	@make clean -s -C ft_libft/
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -s -C ft_libft/
	@echo "\033[38;5;31mpush_swap cleaned...\033[0m"

re: fclean all

.PHONY: all clean fclean re
