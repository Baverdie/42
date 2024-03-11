PROJECT = ft_libft
NAME = libft.a
PROJET_EMOJY = 📚
CC = $(SILENT)cc $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror

OBJS_DIR = obj

SRCS_FILES = char/ft_isalnum.c \
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

SRCS = 	$(addprefix ./, $(SRCS_FILES))
OBJS = $(subst ./,$(OBJS_DIR)/, $(subst .c,.o, $(SRCS)))

DELET_LINE = $(SILENT) echo -n "\033[2K";
RM = $(SILENT) rm -rf

SILENT = @
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_PURPULE = \033[38;5;197m
COLOUR_BLUE=\033[0;34m
COLOUR_YELLOW=\033[0;33m
NO_COLOR=\033[m

bold := $(shell tput bold)
notbold := $(shell tput sgr0)

PRINT = $(SILENT) printf "\r%b"

MSG_CLEANING = "$(COLOUR_RED)$(bold)🧹cleaning $(notbold)$(COLOUR_YELLOW)$(PROJECT)$(NO_COLOR)";
MSG_CLEANED = "$(COLOUR_RED)$(bold)[🗑️ ]$(PROJECT) $(notbold)$(COLOUR_YELLOW)cleaned $(NO_COLOR)\n";
MSG_TOTALY_CLEANED = "$(COLOUR_RED)$(bold)[🗑️ ]$(PROJECT) $(notbold)$(COLOUR_YELLOW)is totaly cleaned $(NO_COLOR)\n";
MSG_COMPILING = "$(COLOUR_YELLOW)$(bold)[💧 Compiling 💧]$(notbold)$(COLOUR_YELLOW) $(^)$(NO_COLOR)";
MSG_READY = "$(PROJET_EMOJY) $(COLOUR_BLUE)$(bold)$(PROJECT) $(COLOUR_GREEN)$(bold)ready$(NO_COLOR)\n";

BANNER = $(PRINT)"$(COLOUR_PURPULE) ____  ____      __    ____  ____  ____  ____ \n"
BANNER1 = printf "$(COLOUR_PURPULE)( ___)(_  _)    (  )  (_  _)(  _ \( ___)(_  _)\n"
BANNER2 = printf "$(COLOUR_PURPULE) )__)   )(  ___  )(__  _)(_  ) _ < )__)   )(  \n"
BANNER3 = printf "$(COLOUR_PURPULE)(__)   (__)(___)(____)(____)(____/(__)   (__) \n\n"

HEADER = $(BANNER);$(BANNER1);$(BANNER2);$(BANNER3); \

all: $(NAME)

$(NAME): $(OBJS) | $(OBJS_DIR)
	$(HEADER)
	@ar rcs $(NAME) $(OBJS)
	$(DELET_LINE)
	$(PRINT) $(MSG_READY)

$(OBJS): $(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	@mkdir -p $(@D)
	$(DELET_LINE)
	$(PRINT) $(MSG_COMPILING)
	$(CC) -c $< -o $@

$(OBJS_DIR):
	$(SILENT)mkdir -p $@

clean:
	$(PRINT) $(MSG_CLEANING)
	@sleep 0.5
	$(RM) $(OBJS_DIR)
	$(DELET_LINE)
	$(PRINT) $(MSG_CLEANED)

fclean: clean
	$(PRINT) $(MSG_CLEANING)
	@sleep 0.5
	$(RM) $(OBJS_DIR)
	$(RM) $(NAME)
	$(DELET_LINE)
	$(PRINT) $(MSG_TOTALY_CLEANED)

re: fclean all

.PHONY: all clean fclean re