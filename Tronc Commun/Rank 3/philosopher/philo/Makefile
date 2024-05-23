PROJECT = philosophers
NAME = philo
PROJET_EMOJY = 💭
CC = $(SILENT)cc $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror -g

SRCS_DIR = src
OBJS_DIR = obj

SRCS_FILES = main.c				\
		exec/execution.c		\
		parsing/parse_args.c	\
		utils/ft_overflow.c		\
		utils/ft_free.c			\
		utils/mem.c				\
		utils/string.c			\
		utils/type.c			\
		utils/delete.c			\

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
MSG_TOTALY_CLEANED = "$(COLOUR_RED)$(bold)[🗑️ ]$(PROJECT) $(notbold)$(COLOUR_YELLOW)is totaly cleaned $(NO_COLOR)\n";
MSG_COMPILING = "$(COLOUR_YELLOW)$(bold)[💧 Compiling 💧]$(notbold)$(COLOUR_YELLOW) $(^)$(NO_COLOR)";
MSG_READY = "$(PROJET_EMOJY) $(COLOUR_BLUE)$(bold)$(PROJECT) $(COLOUR_GREEN)$(bold)ready$(NO_COLOR)\n";

BANNER = $(PRINT) "$(COLOUR_PURPULE) ____  _   _  ____  __    _____  ___  _____  ____  _   _  ____  ____  ___ \n"
BANNER1 = printf "$(COLOUR_PURPULE)(  _ \( )_( )(_  _)(  )  (  _  )/ __)(  _  )(  _ \( )_( )( ___)(  _ \/ __) \n"
BANNER2 = printf "$(COLOUR_PURPULE) )___/ ) _ (  _)(_  )(__  )(_)( \__ \ )(_)(  )___/ ) _ (  )__)  )   /\__ \\n"
BANNER3 = printf "$(COLOUR_PURPULE)(__)  (_) (_)(____)(____)(_____)(___/(_____)(__)  (_) (_)(____)(_)\_)(___/\n\n"

HEADER = $(BANNER);$(BANNER1);$(BANNER2);$(BANNER3); \

all: $(NAME)

$(NAME): $(OBJS) | $(OBJS_DIR)
	$(HEADER)
	$(CC) $^ -o $@
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
	$(PRINT) $(MSG_CLEANING)
	$(RM) $(OBJS_DIR)
	$(DELET_LINE)
	$(PRINT) $(MSG_CLEANED)

fclean: clean
	$(PRINT) $(MSG_CLEANING)
	$(RM) $(OBJS_DIR)
	$(RM) $(NAME)
	$(DELET_LINE)
	$(PRINT) $(MSG_TOTALY_CLEANED)

re: fclean all

.PHONY: all clean fclean re
