NAME = libft.a
CC = clang
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_atoll.c ft_bzero.c ft_calloc.c \
ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_itoa.c \
ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memmove.c ft_memset.c ft_putchar_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
ft_split.c ft_striteri.c ft_strchr.c \
ft_strdup.c ft_strjoin.c ft_strlcat.c \
ft_strlcpy.c ft_strlen.c ft_strmapi.c \
ft_strncmp.c ft_strnstr.c ft_strrchr.c \
ft_strtrim.c ft_substr.c ft_tolower.c \
ft_toupper.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@make -j -s -C ft_printf/
	@echo "\033[38;5;48mft_libft ready !\033[0m"

clean:
	@rm -f $(OBJS)
	@make clean -s -C ft_printf/

fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C ft_printf/
	@echo "\033[38;5;31mft_libft cleaned...\033[0m"

re: fclean all

.PHONY: all clean fclean re
