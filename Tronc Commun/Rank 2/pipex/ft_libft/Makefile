NAME = libft.a
CC = clang
CFLAGS = -Wall -Wextra -Werror

SRCS = char/ft_isalnum.c \
	char/ft_isalpha.c \
	char/ft_isascii.c \
	char/ft_isdigit.c \
	char/ft_isprint.c \
	char/ft_tolower.c \
	char/ft_toupper.c \
	list/ft_lstadd_back.c \
	list/ft_lstadd_front.c \
	list/ft_lstclear.c \
	list/ft_lstdelone.c \
	list/ft_lstiter.c \
	list/ft_lstlast.c \
	list/ft_lstmap.c \
	list/ft_lstnew.c \
	list/ft_lstsize.c \
	mem/ft_bzero.c \
	mem/ft_calloc.c \
	mem/ft_memchr.c \
	mem/ft_memcmp.c \
	mem/ft_memcpy.c \
	mem/ft_memmove.c \
	mem/ft_memset.c \
	print/ft_printf.c \
	print/ft_putchar.c \
	print/ft_putchar_fd.c \
	print/ft_putendl_fd.c \
	print/ft_puthexa.c \
	print/ft_putnbr.c \
	print/ft_putnbr_fd.c \
	print/ft_putptr.c \
	print/ft_putstr.c \
	print/ft_putstr_fd.c \
	string/ft_split.c \
	string/ft_striteri.c \
	string/ft_strchr.c \
	string/ft_strdup.c \
	string/ft_strjoin.c \
	string/ft_strlcat.c \
	string/ft_strlcpy.c \
	string/ft_strlen.c \
	string/ft_strmapi.c \
	string/ft_strncmp.c \
	string/ft_strnstr.c \
	string/ft_strrchr.c \
	string/ft_strtrim.c \
	string/ft_substr.c \
	type/ft_atoi.c \
	type/ft_atoll.c \
	type/ft_itoa.c \

OBJS = $(SRCS:.c=.o)
OBJSBONUS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	@echo "\033[38;5;48mft_libft is ready !\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	
bonus: $(OBJSBONUS) $(OBJS)
	@ar -rc $(NAME) $(OBJSBONUS) $(OBJS)
	@echo "\033[38;5;48mft_libft_bonus is ready !\033[0m"

clean:
	@rm -f $(OBJS) $(OBJSBONUS)

fclean: clean
	@rm -f $(NAME)
	@echo "\033[38;5;31mft_printf cleaned...\033[0m"

re: fclean all

.PHONY: all clean fclean re
