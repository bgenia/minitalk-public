# Project config
NAME_CLIENT := client
NAME_SERVER := server

SRC_DIR := src
OBJ_DIR := build/obj
LIB_DIR := lib
BIN_DIR := .

# Sources
INCLUDE := include

# Include auto-generated source file list
include sources.mk

SRC_CLIENT := $(SRC_LIST_CLIENT)
SRC_SERVER := $(SRC_LIST_SERVER)

OBJ_CLIENT := $(SRC_CLIENT:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_SERVER := $(SRC_SERVER:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

OBJ := $(OBJ_CLIENT) $(OBJ_SERVER)

DEP := $(OBJ:.o=.d)

OBJ_DIRS := $(sort $(dir $(OBJ)))

# Libraries
include maketools/add_library.mk

$(call add_library,lib/libft/libft.a,lib/libft/include)

# Compilation
CC := clang

# Compiler flags
CFLAGS := -MMD
CFLAGS += $(if $(DEBUG_MODE),-g,-O2)

# Preprocessor flags
CPPFLAGS := -Wall -Werror -Wextra
CPPFLAGS += $(addprefix -I,$(INCLUDE))
CPPFLAGS += $(addprefix -I,$(LIBINCLUDES))

bonus: CPPFLAGS += -D BONUS

# Linker flags
LDFLAGS :=

# Linker libs
LDLIBS := $(LIBFLAGS)

# Build targets
# Default target
.DEFAULT_GOAL := all

.PHONY: all bonus
all bonus: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
$(NAME_SERVER): $(OBJ_SERVER)
$(NAME_CLIENT) $(NAME_SERVER): | $(BIN_DIR)
	$(MAKE) $(LIBS)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIRS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIRS) $(BIN_DIR):
	mkdir -p $@

# Include dependecy files
-include $(DEP)

# Utility targets
.PHONY: clean
clean:
	$(RM) -rf $(OBJ_DIR)

.PHONY: fclean
fclean: clean
	$(RM) -rf $(NAME_CLIENT) $(NAME_SERVER)

.PHONY: cleanlibs
cleanlibs:
	$(foreach LIB,$(dir $(LIBS)),$(MAKE) fclean -C $(LIB);)

.PHONY: re
re: fclean
	$(MAKE)
