CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft
SRCS = main/main.c     \
		main/main_atoi.c\
		ft_atoi.c        \
		main/main_strlen.c\
		ft_strlen.c		   \

SHLIST = ./bash/putchar.sh && ./bash/putnbr.sh && ./bash/putstr.sh

OBJS = ${SRCS:.c=.o}

define HEADER
 __    ____  ____  ____  ____ 
(  )  (_  _)(  _ \( ___)(_  _)
 )(__  _)(_  ) _ < )__)   )(  
(____)(____)(____/(__)   (__) 

endef
export HEADER

all:		${NAME}
	@echo "\033[1m\033[35m$$HEADER\033[0m\n\033[1m\033[36m$(NAME) is ready 🤓\033[0m\n"
	@./${NAME} && ${SHLIST}

${NAME}:	${OBJS}
	@${CC} ${CFLAGS} -o ${NAME} ${SRCS}

%.o:		%.c
	@echo "\033[1m\033[36mcompiled ✔️\033[0m"
	@${CC} ${CFLAGS} -c $< -o $@
clean:	
	@echo "\033[1m\033[36mevery .o cleaned 🧹\033[0m"
	@rm -rf $(OBJS)

fclean:		clean
	@echo "\033[1m\033[36mlibft cleaned 🧹\033[0m\n"
	@rm -rf ${NAME}

re:			clean fclean sh all

.PHONY:		all clean fclean sh re