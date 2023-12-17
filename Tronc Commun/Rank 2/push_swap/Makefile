NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRCS = test.c

OBJS = $(SRCS:.c=.o)

DEFAULT = \033[0m
COLOR = \033[38;5;201m

BANNER = @printf "$(COLOR) ____  __  __  ___  _   _       ___  _    _    __    ____\n"
BANNER1 = printf "$(COLOR)(  _ \(  )(  )/ __)( )_( )     / __)( \/\/ )  /__\  (  _ \ \n"
BANNER2 = printf "$(COLOR) )___/ )(__)( \__ \ ) _ (  ___ \__ \ )    (  /(__)\  )___/\n"
BANNER3 = printf "$(COLOR)(__)  (______)(___/(_) (_)(___)(___/(__/\__)(__)(__)(__)\n\n"

HEADER = $(BANNER);$(BANNER1);$(BANNER2);$(BANNER3); \

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	$(HEADER)
	@echo "\033[38;5;48mpush_swap is ready !\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@echo "\033[38;5;31mpush_swap cleaned...\033[0m"

re: fclean all
	@echo "\033[38;5;48mpush_swap reloaded !\033[0m"

.PHONY: all clean fclean re
