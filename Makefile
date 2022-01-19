# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 09:45:32 by mhirabay          #+#    #+#              #
#    Updated: 2022/01/19 16:50:48 by mhirabay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	main.c \
		map_reading.c \
		error_handling.c \
		map_validation.c \
		map_valiidation_2.c \
		mapping_pixel.c \
		debug.c \
		map_algo.c \
		player_algo.c \

# OPT_MLX = -Llib/mlx -lmlx -framework OpenGL -framework AppKit
OPT_MLX = -I/usr/X11/include -Llib/mlx -lmlx_Darwin -L/usr/X11/include/../lib -lXext -lX11 -lm


CC = gcc 
CFLAGS = -Wall -Werror -Wextra
DEBUG_FLAGS = -g -fsanitize=address

all:	
	${CC} ${CFLAGS}  -Llib/gnl -lgnl -Llib/ft_printf -lftprintf ${OPT_MLX} ${SRCS} -o main

debug:
	${CC} ${CFLAGS} ${DEBUG_FLAGS} -Llib/gnl -lgnl -Llib/ft_printf -lftprintf ${OPT_MLX} ${SRCS} -o main

clean: 
	rm -rf *.out
