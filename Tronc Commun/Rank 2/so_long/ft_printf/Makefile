NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
ft_tools/ft_putchar.c \
ft_tools/ft_putstr.c \
ft_tools/ft_putnbr.c \
ft_tools/ft_puthexa.c \
ft_tools/ft_puthexaptr.c \

OBJS = $(SRCS:.c=.o)

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
	@echo "\033[38;5;48mft_printf reloaded !\033[0m"

.PHONY: all clean fclean re
