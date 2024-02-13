NAME = libft.a
CC = clang
CFLAGS = -Wall -Wextra -Werror -g 

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c \
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
ft_toupper.c get_next_line.c

BONUS = ft_lstadd_back.c \
ft_lstadd_front.c \
ft_lstclear.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstlast.c \
ft_lstmap.c \
ft_lstnew.c \
ft_lstsize.c \

OBJS = $(SRCS:.c=.o)
OBJSBONUS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJSBONUS) $(OBJS)
	@ar -rc $(NAME) $(OBJSBONUS) $(OBJS)
	@echo "\033[38;5;48mft_libft ready !\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJS) $(OBJSBONUS)

fclean: clean
	@rm -f $(NAME)
	@echo "\033[38;5;31mft_libft cleaned...\033[0m"

re: fclean all

.PHONY: all clean fclean re
