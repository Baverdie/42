PROJECT = push_swap
NAME = push_swap
PROJET_EMOJY = 🌀
CC = $(SILENT)cc $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = src
OBJS_DIR = obj
LIBFT_DIR = $(SRCS_DIR)/utils/ft_libft
INCLUDE_LIBFT = $(LIBFT_DIR)/libft.a

LIBS = $(INCLUDE_LIBFT)

SRCS_FILES = main.c \
		parsing/parse_arg.c \
		parsing/index.c \
		move/rotate.c \
		move/reverse_rotate.c \
		utils/utils.c \
		utils/utils_stack.c \
		move/push.c \
		move/swap.c \
		sort/radix.c \
		sort/simple_sort.c

SRCS = 	$(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS = $(subst $(SRCS_DIR)/,$(OBJS_DIR)/, $(subst .c,.o, $(SRCS)))

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
MSG_COMPILING = "$(COLOUR_YELLOW)$(bold)[💧 Compiling 💧]$(notbold)$(COLOUR_YELLOW) $(^)$(NO_COLOR)";
MSG_READY = "$(PROJET_EMOJY) $(COLOUR_BLUE)$(bold)$(PROJECT) $(COLOUR_GREEN)$(bold)ready$(NO_COLOR)\n";

BANNER = $(PRINT) "$(COLOUR_PURPULE) ____  __  __  ___  _   _       ___  _    _    __    ____\n"
BANNER1 = printf "$(COLOUR_PURPULE)(  _ \(  )(  )/ __)( )_( )     / __)( \/\/ )  /__\  (  _ \ \n"
BANNER2 = printf "$(COLOUR_PURPULE) )___/ )(__)( \__ \ ) _ (  ___ \__ \ )    (  /(__)\  )___/\n"
BANNER3 = printf "$(COLOUR_PURPULE)(__)  (______)(___/(_) (_)(___)(___/(__/\__)(__)(__)(__)\n\n"

HEADER = $(BANNER);$(BANNER1);$(BANNER2);$(BANNER3); \

all: $(NAME)

$(NAME): $(OBJS) | $(OBJS_DIR)
	$(HEADER)
	@make -s -C $(LIBFT_DIR)
	$(CC) $^ -o $@ $(LIBS)
	$(DELET_LINE)
	$(PRINT) $(MSG_READY)

$(OBJS): $(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@mkdir -p $(@D)
	$(DELET_LINE)
	$(PRINT) $(MSG_COMPILING)
	$(CC) -c $< -o $@

$(OBJS_DIR):
	$(SILENT)mkdir -p $@

clean:
	@make clean -s -C $(LIBFT_DIR) 
	$(PRINT) $(MSG_CLEANING)
	$(RM) $(OBJS_DIR)
	$(DELET_LINE)
	$(PRINT) $(MSG_CLEANED)

fclean: clean
	@make fclean -s -C $(LIBFT_DIR)
	$(PRINT) $(MSG_CLEANING)
	$(RM) $(OBJS_DIR)
	$(RM) $(NAME)
	$(DELET_LINE)
	$(PRINT) $(MSG_CLEANED)

re: fclean all

.PHONY: all clean fclean re