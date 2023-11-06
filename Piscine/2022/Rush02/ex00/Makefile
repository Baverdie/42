# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kroussar <contact@xtrm.me>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 18:27:52 by kroussar          #+#    #+#              #
#    Updated: 2022/07/31 23:40:58 by kroussar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= rush-02

SRCS	:= 	src/dict.c \
			src/error.c \
			src/input.c  \
			src/io.c      \
			src/main.c     \
			src/parser.c    \
			src/print.c		 \

OBJS	= ${SRCS:.c=.o}
INCLUDE = include

LIBFT	= libft.a
LIBFT_SRC = libft

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
COPTS	= -I./${INCLUDE}
RM		= rm -f

green			:= \033[38;5;82m
blue			:= \033[38;5;75m
red				:= \033[38;5;196m
orange			:= \033[38;5;214m

blinking		:= \033[5m
reset			:= \033[0m

define ascii_art
                                         
                    8      .oPYo. .oPYo. 
                    8      8  .o8     `8 
oPYo. o    o .oPYo. 8oPYo. 8 .P'8    oP' 
8  `' 8    8 Yb..   8    8 8.d' 8 .oP'   
8     8    8   'Yb. 8    8 8o'  8 8'     
8     `YooP' `YooP' 8    8 `YooP' 8ooooo 
..:::::.....::.....:..:::..:.....:.......
:::::::::::::::::::::::::::::::::::::::::
:::::::::::::::::::::::::::::::::::::::::

endef
export ascii_art


.c.o:
	${CC} ${CFLAGS} ${COPTS} -c $< -o ${<:.c=.o}

all:		call_logo ${LIBFT} norm ${NAME}

norm:		${SRCS} ${INCLUDE}
	norminette -R CheckDefine -R CheckForbiddenSourceHeader ${INCLUDE} ${SRCS}

call_logo:
	@printf "${red}$$ascii_art${reset}"

${LIBFT}:	
	make -C ${LIBFT_SRC} all

${NAME}:	${OBJS}
	${CC} ${CFLAGS} ${COPTS} -o ${NAME} ${OBJS} ${LIBFT_SRC}/${LIBFT} 

clean:
	${RM} ${OBJS}
	make -C ${LIBFT_SRC} clean

fclean:		clean
	${RM} ${NAME}
	make -C ${LIBFT_SRC} fclean

re:			fclean all

.PHONY:		all clean fclean re norm
