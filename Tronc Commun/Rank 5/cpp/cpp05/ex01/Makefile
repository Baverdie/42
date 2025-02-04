PROJECT = Bureaucrat
NAME = Bureaucrat
PROJET_EMOJY = 📚
CC = $(SILENT)c++ $(CFLAGS)
CFLAGS = -std=c++98 -Wall -Wextra -Werror -g

HSRCS = src
SRC_DIR = src
OBJ_DIR = obj

SRC = main.cpp \
	 Bureaucrat.cpp \

OBJS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC))

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

BANNER = $(PRINT) "$(COLOUR_PURPULE) ____  _____  __   _  _  __  __  _____  ____  ____  _   _  ____  ___  __  __ \n"
BANNER1 = printf "$(COLOUR_PURPULE)(  _ \(  _  )(  ) ( \/ )(  \/  )(  _  )(  _ \(  _ \( )_( )(_  _)/ __)(  \/  ) \n"
BANNER2 = printf "$(COLOUR_PURPULE) )___/ )(_)(  )(__ \  /  )    (  )(_)(  )   / )___/ ) _ (  _)(_ \__ \ )    (  \n"
BANNER3 = printf "$(COLOUR_PURPULE)(__)  (_____)(____)(__) (_/\/\_)(_____)(_)\_)(__)  (_) (_)(____)(___/(_/\/\_) \n\n"

HEADER = $(BANNER);$(BANNER1);$(BANNER2);$(BANNER3); \

all: $(NAME)

$(NAME): $(OBJS)
	$(HEADER)
	$(CC) $^ -o $@
	$(DELET_LINE)
	$(PRINT) $(MSG_READY)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(DELET_LINE)
	$(PRINT) $(MSG_COMPILING)
	@$(CC) $(CFLAGS) -I $(HSRCS) -o $@ -c $<

clean:
	$(PRINT) $(MSG_CLEANING)
	$(RM) $(OBJ_DIR)
	$(DELET_LINE)
	$(PRINT) $(MSG_CLEANED)

fclean: clean
	$(PRINT) $(MSG_CLEANING)
	$(RM) $(OBJ_DIR)
	$(RM) $(NAME)
	$(DELET_LINE)
	$(PRINT) $(MSG_TOTALY_CLEANED)

re: fclean all

.PHONY: all clean fclean re