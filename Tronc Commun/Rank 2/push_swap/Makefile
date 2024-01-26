NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = ft_printf/libftprintf.a \
		ft_libft/libft.a \

SRCS = src/main.c \
		src/parsing/parse_arg.c \
		src/parsing/parse_stack.c \
		src/move/rotate.c \
		src/move/reverse_rotate.c \
		src/utils/utils.c \
		src/utils/utils_stack.c \
		# src/moves/swap.c \
		# src/moves/push.c \

OBJS = ${SRCS:.c=.o}

DEFAULT = \033[0m
COLOR = \033[38;5;197m

BANNER = @printf "$(COLOR) ____  __  __  ___  _   _       ___  _    _    __    ____\n"
BANNER1 = printf "$(COLOR)(  _ \(  )(  )/ __)( )_( )     / __)( \/\/ )  /__\  (  _ \ \n"
BANNER2 = printf "$(COLOR) )___/ )(__)( \__ \ ) _ (  ___ \__ \ )    (  /(__)\  )___/\n"
BANNER3 = printf "$(COLOR)(__)  (______)(___/(_) (_)(___)(___/(__/\__)(__)(__)(__)\n\n"

HEADER = $(BANNER);$(BANNER1);$(BANNER2);$(BANNER3); \

all: $(NAME)

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

$(NAME): $(OBJS)
	$(HEADER)
	# @make --no-print-directory load
	@echo "\033[38;5;48mMLX42 is ready !\033[0m"
	# @make --no-print-directory load
	@make -j -s -C ft_libft/
	# @make --no-print-directory load
	@make -j -s -C ft_printf/
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)
	# @make --no-print-directory load
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
