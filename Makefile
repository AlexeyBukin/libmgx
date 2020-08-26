# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/16 11:36:42 by kcharla           #+#    #+#              #
#    Updated: 2020/08/26 06:02:33 by u18600003        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmgx.a

#--------------------------------   GENERAL   ---------------------------------#

CC = gcc

DEBUG = -g
OPTIM = -O2

CFLAGS = -Wall -Wextra -Wall $(DEBUG) $(OPTIM)
CLIBS  = -L ./lib/ft -lft -L. -lmgx -L ./lib/mlx -lmlx -framework OpenGL -framework AppKit
INCLUDE = -I ./include -I ./lib/mlx -I ./lib/ft/include

BUILD_DIR := build
SRC_DIR := src

#--------------------------------   HEADERS   ---------------------------------#

# find include -type f -name '*.h'

HEADER_FILES = \
include/mgx.h \
include/mgx_base_s.h \
include/mgx_free.h \
include/mgx_input.h \
include/mgx_libs.h \
include/mgx_mlx.h \
include/mgx_mlx_s.h \
include/mgx_struct.h \
include/mlx_full.h \


#--------------------------------   SOURCES   ---------------------------------#

# find src -type f -name '*.c'

SRC_FILES = \
src/buf/mgx_buf.c \
src/mgx_free.c \
src/mgx_init.c \
src/mgx_lib_mlx.c \
src/mgx_loop.c \
src/win/mgx_win_buf.c \
src/win/mgx_win_draw.c \
src/win/mgx_win_init.c \
src/buf/mgx_buf_draw_line.c

O_FILES = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

SRC_DIRS = $(shell find $(SRC_DIR) -type d)
BUILD_DIRS_REC = $(patsubst $(SRC_DIR)%, $(BUILD_DIR)%, $(SRC_DIRS))

.PHONY: all clean fclean re liner

#---------------------------------   RULES   ----------------------------------#

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
	@rm -f $(NAME)
	@echo "make: Done full clean of \`$(NAME)'."

re: fclean all
	@echo "make: Done recompile of \`$(NAME)'."

$(BUILD_DIRS_REC):
	@mkdir -vp $(BUILD_DIRS_REC)

#----------------------------------  LIB_FT  ----------------------------------#

LIB_FT := ./lib/ft/libft.a

$(LIB_FT):
	make -C ./lib/ft/

#---------------------------------  LIB_MLX  ----------------------------------#

LIB_MLX := ./lib/mlx/libmlx.a

$(LIB_MLX):
	make -C ./lib/mlx

#------------------------------------------------------------------------------#
#--------------------------------- DEMO PART ----------------------------------#
#------------------------------------------------------------------------------#

DEMO_DIR := ./demo/

$(DEMO_DIR):
	@mkdir -vp $(DEMO_DIR)

#----------------------------------  LINER   ----------------------------------#

LINER_APP := ./demo/liner.app

LINER_SRCS := ./src/demo/liner.c
LINER_OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(LINER_SRCS))

liner: $(LINER_APP)

$(LINER_APP): $(NAME) $(LIB_FT) $(LIB_MLX) $(LINER_OBJS) $(DEMO_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) $(CLIBS) $(LINER_OBJS) -o $@

#---------------------------------    END    ----------------------------------#
