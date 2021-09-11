# Project config
NAME_CLIENT := client
NAME_SERVER := server

SRC_DIR := src
OBJ_DIR := build/obj
LIB_DIR := lib
BIN_DIR := .

# Make config
SHELL := /bin/bash
.ONESHELL:
.SHELLFLAGS += -e
.DEFAULT_GOAL := all

# Make libraries
include maketools/source_list.mk
include maketools/add_library.mk

# Sources
INCLUDE := include

$(call source_list,sources.mk,SRC_CLIENT,src/client)
$(call source_list,sources.mk,SRC_SERVER,src/server)

OBJ_CLIENT := $(SRC_CLIENT:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJ_SERVER := $(SRC_SERVER:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

OBJ := $(OBJ_CLIENT) $(OBJ_SERVER)

DEP := $(OBJ:.o=.d)

OBJ_DIRS := $(sort $(dir $(OBJ)))

# Libraries
$(call add_library,lib/libft/libft.a,lib/libft/include)

# Compilation
CC := clang

# Compiler flags
CFLAGS := -MMD
ifdef DEBUG_MODE
	CFLAGS += -g
else
	CFLAGS += -O2
endif

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
cleanlibs: # This could've been implemented better
	$(foreach LIB,$(dir $(LIBS)),$(MAKE) fclean -C $(LIB);)

.PHONY: re
re: fclean
	$(MAKE)
