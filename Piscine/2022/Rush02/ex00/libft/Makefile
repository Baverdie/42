# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kroussar <contact@xtrm.me>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/31 02:23:26 by kroussar          #+#    #+#              #
#    Updated: 2022/07/31 10:56:41 by kroussar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

# find . -type f -name "ft_*.c" | sed 's/\.\///g' | xargs -Iname echo "          " name "\\"
SRCS	:=	src/io/ft_putstr.c \
			src/io/ft_putnbr.c \
			src/string/ft_isdigit.c \
			src/string/ft_strchr.c \
			src/string/ft_isalnum.c \
			src/string/ft_strcpy.c \
			src/string/ft_strcmp.c \
			src/string/ft_islower.c \
			src/string/ft_isspace.c \
			src/string/ft_isprint.c \
			src/string/ft_strncpy.c \
			src/string/ft_strstr.c \
			src/string/ft_strdup.c \
			src/string/ft_strndup.c \
			src/string/ft_tolower.c \
			src/string/ft_strncat.c \
			src/string/ft_isalpha.c \
			src/string/ft_strlcpy.c \
			src/string/ft_strlen.c \
			src/string/ft_atoi.c \
			src/string/ft_isupper.c \
			src/string/ft_isascii.c \
			src/string/ft_strncmp.c \
			src/string/ft_strrchr.c \
			src/string/ft_strcat.c \
			src/string/ft_strlcat.c \
			src/string/ft_toupper.c 

OBJS	= ${SRCS:.c=.o}
INCLUDE = include

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
COPTS	= -I ../${INCLUDE} -fPIC

RM		= rm -f

.c.o:
	${CC} ${CFLAGS} ${COPTS} -c $< -o ${<:.c=.o}

all:		norm ${NAME}

norm:		${SRCS}
	norminette -R CheckDefine -R CheckForbiddenSourceHeader ${INCLUDE} ${SRCS}

${NAME}:	${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re norm
