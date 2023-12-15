NAME = so_long
CC = clang
CFLAGS = -Wall -Wextra -g3
LIBS = MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm -Llibft 

SRCS = test.c
OBJS = ${SRCS:.c=.o}

DEFAULT = \033[0m
COLOR = \033[38;5;197m

BANNER = @printf "$(COLOR) ___  _____       __    _____  _  _  ___ \n"
BANNER1 = printf "$(COLOR)/ __)(  _  )     (  )  (  _  )( \( )/ __)\n"
BANNER2 = printf "$(COLOR)\__ \ )(_)(  ___  )(__  )(_)(  )  (( (_-.\n"
BANNER3 = printf "$(COLOR)(___/(_____)(___)(____)(_____)(_)\_)\___/\n\n"

HEADER = $(BANNER);$(BANNER1);$(BANNER2);$(BANNER3); \

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	@make -s -C MLX42/build/
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)
	$(HEADER)
	@echo "\033[38;5;48mso_long is ready !\033[0m"

clean: 
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@echo "\033[38;5;31mso_long cleaned...\033[0m"

re: fclean all
	make -j all

.PHONY: all clean fclean re
