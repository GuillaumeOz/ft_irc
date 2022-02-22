# #############################################################################
#
# Sources lists
#
# #############################################################################

# CPP files
FILENAME_LIST_SRCS= \
	main.cpp \
	class/class.config.cpp \
	class/class.error.cpp \

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
	# -std=c++17 \

# #############################################################################
#
# Project configuration
#
# #############################################################################

# Targets
FILENAMELIST_TARGET= \
	my_irc_server \

# Directories names
DIRNAME_BIN=bin
DIRNAME_OBJ=obj
DIRNAME_SRC=srcs
DIRNAME_INC=includes \
	-I includes/class/ \

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

# Build target
my_irc_server: $(FILEPATHLIST_OPP)
	@mkdir -p $$(dirname $@)
	@printf "$(COMPILING) TARGET --> $@ "
	@$(COMPILER_EXECUTABLE) -o $(DIRNAME_BIN)/$@ \
		-I $(DIRNAME_INC) \
		$(COMPILER_LIBS) \
		$(COMPILER_WARNING_FLAGS) \
		$(FILEPATHLIST_OPP) \
		$(COMPILER_A) \
			&& printf "$(SUCCESS)\n"

# Build obj binaries
$(DIRPATH_OBJ)/%.opp: $(DIRNAME_SRC)/%.cpp
	@mkdir -p $$(dirname $@)
	@printf "$(COMPILING) $< "
	@$(COMPILER_EXECUTABLE) -c $< -o $@ \
		-I $(DIRNAME_INC) \
		$(COMPILER_WARNING_FLAGS) \
			&& printf "$(SUCCESS)\n"

# Build all targets
all: $(FILENAMELIST_TARGET)

# Remove objects
clean:
	@rm -rf $(DIRPATH_OBJ)

# Remove every built binary
fclean:
	@rm -rf $(DIRNAME_BIN)

# Remove and rebuild everything
re: fclean all

.PHONY: all clean fclean re

.ONESHELL:

# #############################################################################
#
# Makefile misc
#
# #############################################################################

# Colors
RED=\033[1;31m
GREEN=\033[1;32m
BLUE=\033[1;34m
NC=\033[0m

# Colored messages
SUCCESS=$(GREEN)SUCCESS$(NC)
COMPILING=$(BLUE)COMPILING$(NC)

# #############################################################################
