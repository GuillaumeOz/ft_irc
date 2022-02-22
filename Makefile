# #############################################################################
#
# Sources lists
#
# #############################################################################

# CPP files

SRC_DIR		=	$(shell find srcs -type d)

vpath %.cpp $(foreach dir, $(SRC_DIR), $(dir):)

FILENAME_LIST_SRCS=\
	$(foreach dir, \
	$(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.cpp), $(notdir $(file))))

# FILENAME_LIST_SRCS=\
# 	main.cpp

# #############################################################################
#
# Compiler options
#
# #############################################################################

COMPILER_EXECUTABLE=c++

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

# Project name
NAME		=	ircserv

# Directories names
DIRNAME_BIN=bin
DIRNAME_OBJ=obj
DIRNAME_SRC=srcs
DIRNAME_INC=includes
DIRNAME_TEM=templates

# Directory paths
DIRPATH_OBJ=$(DIRNAME_BIN)/$(DIRNAME_OBJ)

# File path lists
FILEPATHLIST_SRCS=$(addprefix $(DIRNAME_SRC)/, $(FILENAME_LIST_SRCS))

# Merge all CPP lists in one
FILEPATHLIST_CPP= \
	$(FILEPATHLIST_SRCS) \

FILEPATHLIST_OPP= \
	$(subst  \
		$(DIRNAME_SRC), \
		$(DIRPATH_OBJ), \
		$(FILEPATHLIST_CPP:.cpp=.opp) \
	)

# #############################################################################
#
# Rules
#
# #############################################################################

.DEFAULT_GOAL = all

# Build all targets
all: $(NAME)

# Build target
$(NAME): $(FILEPATHLIST_OPP)
	@mkdir -p $$(dirname $@)
	@printf "$(COMPILING) $(WHITE) Creating Binary File $(YELLOW) $@ $(YELLOW)"
	@$(COMPILER_EXECUTABLE) -o $(DIRNAME_BIN)/$@ \
		-I $(DIRNAME_INC) \
		-I $(DIRNAME_TEM) \
		$(COMPILER_LIBS) \
		$(COMPILER_WARNING_FLAGS) \
		$(FILEPATHLIST_OPP) \
		$(COMPILER_A) \
			&& printf "$(SUCCESS)\n"

# Build obj binaries
$(DIRPATH_OBJ)/%.opp: $(DIRNAME_SRC)/%.cpp
	@mkdir -p $$(dirname $@)
	@printf "$(COMPILING) $(YELLOW) $< $(NC) "
	@$(COMPILER_EXECUTABLE) -c $< -o $@ \
		-I $(DIRNAME_INC) \
		-I $(DIRNAME_TEM) \
		$(COMPILER_WARNING_FLAGS) \
			&& printf "$(SUCCESS)\n"

# Show macro details
show:
	@printf "$(BLUE)SRCS LIST :\n$(YELLOW)$(FILENAME_LIST_SRCS)\n"
	@printf "$(BLUE)OBJS LIST :\n$(YELLOW)$(FILEPATHLIST_OPP)$(WHITE)\n"
	@printf "\n-----\n\n"
	@printf "$(BLUE)COMPILING :\n  $(YELLOW)$(COMPILER_EXECUTABLE) \
	-o $(DIRNAME_BIN)/$(FILEPATHLIST_OPP) -I $(DIRNAME_INC) -I $(DIRNAME_TEM) \
	$(COMPILER_LIBS) $(COMPILER_WARNING_FLAGS) \
	$(FILEPATHLIST_OPP) $(COMPILER_A)\n"
	@printf "$(BLUE)CFLAGS :\n  $(YELLOW)$(COMPILER_LIBS) \
	$(COMPILER_WARNING_FLAGS)\n"
	@printf "$(BLUE)IFLAGS :\n$(YELLOW)  -I $(DIRNAME_INC)\n"
	@printf "$(BLUE)TFLAGS :\n$(YELLOW)  -I $(DIRNAME_TEM)$(NC)\n"

# Remove objects
clean:
	@rm -rf $(DIRPATH_OBJ)

# Remove every built binary
fclean:
	@rm -rf $(DIRNAME_BIN)

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
