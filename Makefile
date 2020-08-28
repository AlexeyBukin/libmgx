# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/16 11:36:42 by kcharla           #+#    #+#              #
#    Updated: 2020/08/28 14:42:31 by u18600003        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libmgx.a

#--------------------------------   GENERAL   ---------------------------------#

CC			 = gcc

DEBUG		 = -g
OPTIM		 = -O2

CFLAGS		 = -Wall -Wextra -Wall $(DEBUG) $(OPTIM)
CLIBS		:= -L. -lmgx -framework OpenGL -framework AppKit
INCLUDE		:= -I ./inc

BUILD_DIR   := build/
SRC_DIR     := src/

#--------------------------------   HEADERS   ---------------------------------#

# find include -type f -name '*.h'

HEADER_FILES = \
inc/mgx.h \
inc/mgx_base_s.h \
inc/mgx_free.h \
inc/mgx_input.h \
inc/mgx_libs.h \
inc/mgx_mlx.h \
inc/mgx_mlx_s.h \
inc/mgx_struct.h \
inc/mlx_full.h \

LIB_FT		:= ./lib/ft/libft.a
LIB_MLX		:= ./lib/mlx/libmlx.a

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

EXTERNAL_HEADERS = \
./lib/ft/inc/libft.h ./lib/ft/inc/printf.h \
./lib/mlx/inc/mlx.h ./lib/mlx/inc/mlx_int.h \

LINKED_HEADERS_1 = $(EXTERNAL_HEADERS:./lib/ft/%=%)
LINKED_HEADERS = $(LINKED_HEADERS_1:./lib/mlx/%=%)

O_FILES = $(patsubst $(SRC_DIR)%.c, $(BUILD_DIR)%.o, $(SRC_FILES))

SRC_DIRS = $(shell find $(SRC_DIR) -type d)
BUILD_DIRS_REC = $(patsubst $(SRC_DIR)%, $(BUILD_DIR)%, $(SRC_DIRS))

.PHONY: all clean fclean re liner headers

#---------------------------------   RULES   ----------------------------------#

all: $(NAME)

$(NAME): headers $(LIB_FT) $(LIB_MLX) $(BUILD_DIRS_REC) $(O_FILES)
	libtool -static -o $(NAME) $(LIB_FT) $(LIB_MLX) $(O_FILES)
	ranlib $(NAME)

$(BUILD_DIR)%.o: $(SRC_DIR)%.c $(HEADER_FILES)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@make clean -C ./lib/ft
	@make clean -C ./lib/mlx
	@rm -rf $(BUILD_DIR)
	@echo "make: Done clean of \`$(NAME)'."

fclean: clean
	@make fclean -C ./lib/ft
	@make fclean -C ./lib/mlx
	@rm -f $(LINKED_HEADERS)
	@rm -f $(NAME)
	@echo "make: Done full clean of \`$(NAME)'."

re: fclean all
	@echo "make: Done recompile of \`$(NAME)'."

$(BUILD_DIRS_REC):
	@mkdir -vp $(BUILD_DIRS_REC)

headers:
	ln -f $(EXTERNAL_HEADERS) ./inc/

#----------------------------------  LIB_FT  ----------------------------------#

$(LIB_FT):
	make -C ./lib/ft/

#---------------------------------  LIB_MLX  ----------------------------------#

$(LIB_MLX):
	make -C ./lib/mlx/

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
