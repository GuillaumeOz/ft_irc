# #############################################################################
#
# Sources lists
#
# #############################################################################

# Project name
NAME		=	bot_client

CC			=	c++

# CPP files
SRC_DIR		=	$(shell find srcs -type d)
INC_DIR		=	$(shell find includes -type d)
TEM_DIR		=	$(shell find templates -type d)
OBJ_DIR		=	bin/obj

vpath %.cpp $(foreach dir, $(SRC_DIR), $(dir):)

SRC			=	$(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.cpp), $(notdir $(file))))

OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.opp))

# #############################################################################
#
# Compiler options
#
# #############################################################################

CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -g3 -lpthread -fsanitize=address #-Wshadow -Wno-shadow

IFLAGS		=	$(foreach dir, $(INC_DIR), -I $(dir))

TFLAGS		=	$(foreach dir, $(TEM_DIR), -I $(dir))

# #############################################################################
#
# Rules
#
# #############################################################################

.DEFAULT_GOAL = all

# Build target
$(NAME): $(OBJ)
	@echo "-----\nCreating Binary File $(_YELLOW)$@$(_WHITE) ... \c"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@mv bot_client bin
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

# Build obj binaries
$(OBJ_DIR)/%.opp: %.cpp
	@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
	@echo "$(_GREEN)DONE$(_WHITE)"

# Build all targets
all: $(NAME)

# Show macro details
show:
	@echo "$(_BLUE)SRC :\n$(_YELLOW)$(SRC)$(_WHITE)"
	@echo "$(_BLUE)OBJ :\n$(_YELLOW)$(OBJ)$(_WHITE)"
	@echo "$(_BLUE)CFLAGS :\n$(_YELLOW)$(CFLAGS)$(_WHITE)"
	@echo "$(_BLUE)IFLAGS :\n$(_YELLOW)$(IFLAGS)$(_WHITE)"
	@echo "$(_BLUE)TFLAGS :\n$(_YELLOW)  $(TFLAGS)$(NC)\n"
	@echo "\n-----\n"
	@echo "$(_BLUE)Compiling : \n$(_YELLOW)$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(_WHITE)"


# Remove objects
clean:
	@echo "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... \c"
	@$(foreach file, $(OBJ), rm -rf $(file))
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

# Remove every built binary
fclean: clean
	@echo "Deleting Binary File $(_YELLOW)$(NAME)$(_WHITE) ... \c"
	@rm -rf bin/
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

# Remove and rebuild everything
re: fclean all

.PHONY: all show clean fclean re

.ONESHELL:

# #############################################################################
#
# Makefile misc
#
# #############################################################################

# Colors
_GREY=	\033[1;30m
_RED=	\033[1;31m
_GREEN=	\033[1;32m
_YELLOW=\033[1;33m
_BLUE=	\033[1;34m
_PURPLE=\033[1;35m
_CYAN=	\033[1;36m
_WHITE=	\033[1;37m
_NC=	\033[0m

# Colored messages
SUCCESS=$(GREEN)SUCCESS$(NC)
COMPILING=$(_BLUE)COMPILING$(NC)

# #############################################################################
