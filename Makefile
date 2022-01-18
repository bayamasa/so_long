# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 09:45:32 by mhirabay          #+#    #+#              #
#    Updated: 2022/01/18 13:55:42 by mhirabay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	main.c \
		map_reading.c \
		error_handling.c \
		map_validation.c \
		mapping_pixel.c \
		debug.c \
		map_algo.c \
		player_algo.c \

OPT_MLX = -Llib/mlx -lmlx -framework OpenGL -framework AppKit

all:	
	gcc  -Llib/gnl -lgnl -Llib/ft_printf -lftprintf ${OPT_MLX} ${SRCS} -o main
	./main

clean: 
	rm -rf *.out
