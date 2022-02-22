# #############################################################################
#
# Sources lists
#
# #############################################################################

# Project name
NAME		=	ircserv

CC			=	c++

# CPP files

SRC_DIR		=	$(shell find srcs -type d)
INC_DIR		=	$(shell find includes -type d)
TEM_DIR		=	$(shell find templates -type d)
OBJ_DIR		=	bin/obj

vpath %.cpp $(foreach dir, $(SRC_DIR), $(dir):)

SRC			=	$(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.cpp), $(notdir $(file))))

OBJ			=	$(addprefix $(OBJ_DIR)/, $(FILENAME_LIST_SRCS:%.cpp=%.opp))

# #############################################################################
#
# Compiler options
#
# #############################################################################

CFLAGS		=	-Wall -Wextra -Werror -lpthread -std=c++98 #-g3 #-fsanitize=address #-Wshadow -Wno-shadow

IFLAGS		=	$(foreach dir, $(INC_DIR), -I $(dir))

TFLAGS		=	$(foreach dir, $(TEM_DIR), -I $(dir))

# FILENAME_LIST_SRCS=\
# 	main.cpp

COMPILER_LIBS= \
	-lpthread \

COMPILER_A = \

COMPILER_WARNING_FLAGS= \
	-Wall \
	-Wextra \
	-Werror \
	# -std=c++98 \

# #############################################################################
#
# Project configuration
#
# #############################################################################

# Directories names
# DIRNAME_BIN=bin
# DIRNAME_OBJ=obj
# DIRNAME_SRC=srcs
# DIRNAME_INC=includes
# DIRNAME_TEM=templates

# Directory paths
# DIRPATH_OBJ=$(DIRNAME_BIN)/$(DIRNAME_OBJ)

# File path lists
# FILEPATHLIST_SRCS=$(addprefix $(DIRNAME_SRC)/, $(FILENAME_LIST_SRCS))

# Merge all CPP lists in one
# FILEPATHLIST_CPP= \
# 	$(FILEPATHLIST_SRCS) \

# FILEPATHLIST_OPP= \
# 	$(subst  \
# 		$(DIRNAME_SRC), \
# 		$(DIRPATH_OBJ), \
# 		$(FILEPATHLIST_CPP:.cpp=.opp) \
# 	)

# #############################################################################
#
# Rules
#
# #############################################################################

.DEFAULT_GOAL = all

# Build all targets
all: $(NAME)

# Build target
$(NAME): $(OBJ)
	@mkdir -p $$(dirname $@)
	@printf "$(COMPILING) $(WHITE) Creating Binary File $(YELLOW) $@ $(YELLOW)"
	@$(COMPILER_EXECUTABLE) -o OBJ_DIR$@ \
		$(IFLAGS) \
		$(TFLAGS) \
		$(COMPILER_LIBS) \
		$(COMPILER_WARNING_FLAGS) \
		$(OBJ) \
		$(COMPILER_A) \
			&& printf "$(SUCCESS)\n"

# Build obj binaries
$(OBJ_DIR)/%.opp: $(DIRNAME_SRC)/%.cpp
	@mkdir -p $$(dirname $@)
	@printf "$(COMPILING) $(YELLOW) $< $(NC) "
	@$(COMPILER_EXECUTABLE) -c $< -o $@ \
		$(IFLAGS) \
		$(TFLAGS) \
		$(COMPILER_WARNING_FLAGS) \
			&& printf "$(SUCCESS)\n"

# Show macro details
show:
	@printf "$(BLUE)SRCS LIST :\n$(YELLOW)$(FILENAME_LIST_SRCS)\n"
	@printf "$(BLUE)OBJS LIST :\n$(YELLOW)$(OBJ)$(WHITE)\n"
	@printf "\n-----\n\n"
	@printf "$(BLUE)COMPILING :\n  $(YELLOW)$(COMPILER_EXECUTABLE) \
	-o $(OBJ) $(IFLAGS) $(TFLAGS) \
	$(COMPILER_LIBS) $(COMPILER_WARNING_FLAGS) \
	$(FILEPATHLIST_OPP) $(COMPILER_A)\n"
	@printf "$(BLUE)CFLAGS :\n  $(YELLOW)$(COMPILER_LIBS) \
	$(COMPILER_WARNING_FLAGS)\n"
	@printf "$(BLUE)IFLAGS :\n$(YELLOW)  $(IFLAGS)\n"
	@printf "$(BLUE)TFLAGS :\n$(YELLOW)  $(TFLAGS)$(NC)\n"

# Remove objects
clean:
	@rm -rf $(DIRPATH_OBJ)

# Remove every built binary
fclean:
	@rm -rf $(OBJ)

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
GREY=	\033[1;30m
RED=	\033[1;31m
GREEN=	\033[1;32m
YELLOW=	\033[1;33m
BLUE=	\033[1;34m
PURPLE=	\033[1;35m
CYAN=	\033[1;36m
WHITE=	\033[1;37m
NC=		\033[1;0m

# Colored messages
SUCCESS=$(GREEN)SUCCESS$(NC)
COMPILING=$(BLUE)COMPILING$(NC)

# #############################################################################
