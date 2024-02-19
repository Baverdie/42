NAME = libft.a
CC = clang
CFLAGS = -Wall -Wextra -Werror

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
ft_toupper.c

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

DEFAULT = \033[0m
PURPLE = \033[38;5;213m

BANNER = @printf "$(PURPLE) ____  ____      __    ____  ____  ____  ____ \n"
BANNER1 = printf "$(PURPLE)( ___)(_  _)    (  )  (_  _)(  _ \( ___)(_  _)\n"
BANNER2 = printf "$(PURPLE) )__)   )(  ___  )(__  _)(_  ) _ < )__)   )(  \n"
BANNER3 = printf "$(PURPLE)(__)   (__)(___)(____)(____)(____/(__)   (__) \n\n"

HEADER = $(BANNER);$(BANNER1);$(BANNER2);$(BANNER3); \

BANNERB = @printf "$(PURPLE) ____  ____      __    ____  ____  ____  ____      ____  _____  _  _  __  __  ___ \n"
BANNERB1 = printf "$(PURPLE)( ___)(_  _)    (  )  (_  _)(  _ \( ___)(_  _)    (  _ \(  _  )( \( )(  )(  )/ __)\n"
BANNERB2 = printf "$(PURPLE) )__)   )(  ___  )(__  _)(_  ) _ < )__)   )(  ___  ) _ < )(_)(  )  (  )(__)( \__ \ \n"
BANNERB3 = printf "$(PURPLE)(__)   (__)(___)(____)(____)(____/(__)   (__)(___)(____/(_____)(_)\_)(______)(___/\n\n"

HEADERB = $(BANNERB);$(BANNERB1);$(BANNERB2);$(BANNERB3); \

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	$(HEADER)
	@echo "\033[38;5;48mft_libft is ready !\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	
bonus: $(OBJSBONUS) $(OBJS)
	ar -rc $(NAME) $(OBJSBONUS) $(OBJS)
	$(HEADERB)
	@echo "\033[38;5;48mft_libft_bonus is ready !\033[0m"

clean:
	@rm -f $(OBJS) $(OBJSBONUS)

fclean: clean
	@rm -f $(NAME)
	@echo "\033[38;5;31mft_printf cleaned...\033[0m"

re: fclean all

.PHONY: all clean fclean re
