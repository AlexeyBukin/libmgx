# libmgx Makefile
# @kcharla, 2020

NAME = libmgx.a

CC = gcc

DEBUG = -g
OPTIM = -O2

CFLAGS = -Wall -Wextra -Wall $(DEBUG) $(OPTIM)
CLIBS  = -L ./lib/libft -lft
INCLUDE = -I ./include -I ./lib/libmlx -I ./lib/libft/include

BUILD_DIR = build
SRC_DIR = src

# find include -type f -name '*.h' | sed 'N;N;s/\n/ /g' | sed 's/$/ \\/'| sed '$s/\\//' | column -t

HEADER_FILES = \
include/mgx.h

# find src -type f -name '*.c' | sed 'N;N;s/\n/ /g' | sed 's/$/ \\/'| sed '$s/\\//' | column -t
SRC_FILES = \
src/buf/mgx_buf.c \
src/mgx_free.c \
src/mgx_init.c \
src/mgx_lib_mlx.c \
src/mgx_loop.c \
src/win/mgx_win_buf.c \
src/win/mgx_win_draw.c \
src/win/mgx_win_init.c

O_FILES = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

O_FILES_LINER := ./src/liner/main.c

LINER_APP := liner.app

SRC_DIRS = $(shell find $(SRC_DIR) -type d)
BUILD_DIRS_REC = $(patsubst $(SRC_DIR)%, $(BUILD_DIR)%, $(SRC_DIRS))

all: $(NAME)

$(NAME): $(BUILD_DIRS_REC) $(O_FILES)
	ar rc $(NAME) $(O_FILES)
	ranlib $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER_FILES)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR)
	@echo "make: Done clean of \`$(NAME)'."

fclean: clean
	@rm -f $(NAME)
	@echo "make: Done full clean of \`$(NAME)'."

re: fclean all
	@echo "make: Done recompile of \`$(NAME)'."

$(BUILD_DIRS_REC):
	@mkdir -vp $(BUILD_DIRS_REC)

LIB_FT := ./lib/libft/libft.a

$(LIB_FT):
	make -C ./lib/libft/

$(LINER_APP): all $(LIB_FT) $(O_FILES_LINER)
	$(CC) $(CFLAGS) $(INCLUDE) $(CLIBS) -L . -lmgx -L ./lib/libmlx -lmlx -framework OpenGL -framework AppKit $(O_FILES_LINER) -o $@