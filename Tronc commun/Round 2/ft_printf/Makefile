NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRCS = ft_printf.c \
ft_tools/ft_putchar.c \
ft_tools/ft_putstr.c \
ft_tools/ft_putnbr.c \
ft_tools/ft_puthexa.c \
ft_tools/ft_puthexaptr.c \

OBJS = $(SRCS:.c=.o)

DEFAULT = \033[0m
PURPLE = \033[38;5;213m

BANNER = @printf "$(PURPLE) ____  ____      ____  ____  ____  _  _  ____  ____ \n"
BANNER1 = printf "$(PURPLE)( ___)(_  _)    (  _ \(  _ \(_  _)( \( )(_  _)( ___)\n"
BANNER2 = printf "$(PURPLE) )__)   )(  ___  )___/ )   / _)(_  )  (   )(   )__) \n"
BANNER3 = printf "$(PURPLE)(__)   (__)(___)(__)  (_)\_)(____)(_)\_) (__) (__)  \n\n"

HEADER = $(BANNER);$(BANNER1);$(BANNER2);$(BANNER3); \

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	$(HEADER)
	@echo "\033[38;5;48mft_printf is ready !\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@echo "\033[38;5;31mft_printf cleaned...\033[0m"

re: fclean all

.PHONY: all clean fclean re