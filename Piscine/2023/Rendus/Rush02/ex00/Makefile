CC = cc
EXEC = prog
CFLAGS = -Wall -Wextra -Werror -g
SRC = 	main.c          \
		display.c        \
		pars_args.c       \
		parsing.c          \
		utils/ft_atoi.c     \
		utils/ft_openfile.c  \
		utils/ft_putstr.c     \
		utils/ft_str_char_cat.c\
		utils/ft_strdup.c       \
		utils/ft_strlen.c        \
		utils/ft_strcmp.c         \

OBJ = $(SRC:.c=.o)

NAME = ./rush-02

define banner

██████╗ ██╗   ██╗███████╗██╗  ██╗     ██████╗ ██████╗
██╔══██╗██║   ██║██╔════╝██║  ██║    ██╔═████╗╚════██╗
██████╔╝██║   ██║███████╗███████║    ██║██╔██║ █████╔╝
██╔══██╗██║   ██║╚════██║██╔══██║    ████╔╝██║██╔═══╝
██║  ██║╚██████╔╝███████║██║  ██║    ╚██████╔╝███████╗
╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝     ╚═════╝ ╚══════╝

endef
export banner

all : $(NAME)

BANNER:
	@printf "\033[1;32m$$banner\033[1;00m"

$(NAME): BANNER $(OBJ)
	@echo "\033[1;30m[ Building Files... ]\033[1;00m"
	@$(CC) -o $(NAME) $(OBJ)
	@echo "\033[1;30m[ Build Finished! ]\033[1;00m"

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@echo "\033[1;30m[ Cleaning Object Files... ]\033[1;00m"
	@rm -f $(OBJ)
	@echo "\033[1;30m[ Object Files Cleaned! ]\033[1;00m"

fclean: clean
	@echo "\033[1;30m[ Cleaning Binaries Files... ]\033[1;00m"
	@rm -f $(NAME)
	@echo "\033[1;30m[ Binaries Files Cleaned! ]\033[1;00m"

re: fclean all
