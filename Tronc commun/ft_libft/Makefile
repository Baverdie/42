NAME = libft.a
CC = clang
CFLAGS = -Wall -Wextra  -Werror

SRCS = ft_atoi.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_memset.c \
ft_strlcpy.c \
ft_strlen.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

# $(NAME): $(OBJS)
# 	ar -rc $(NAME) $(OBJS)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re