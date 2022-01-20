# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 09:45:32 by mhirabay          #+#    #+#              #
#    Updated: 2022/01/20 16:38:40 by mhirabay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = 	main.c \
		map_reading.c \
		error_handling.c \
		map_validation.c \
		map_valiidation_2.c \
		mapping_pixel.c \
		debug.c \
		map_algo.c \
		player_algo.c \

LIB_NAME = libftprintf

OBJS = ${SRCS:.c=.o}
UNAME := $(shell uname)

ifeq (${UNAME},Darwin)
	OPT_MLX = -I/usr/X11/include -Llib/mlx -lmlx_Darwin -L/usr/X11/include/../lib -lXext -lX11 -lm
else
	OPT_MLX = -Ilib/mlx -Llib/mlx -lmlx -lXext -lX11 -lm
endif

CC = gcc
CFLAGS = -Wall -Werror -Wextra
DEBUG_FLAGS = -g -fsanitize=address
LDFLAGS = -Llib/ft_printf -lftprintf -Llib/gnl -lgnl 

all: ${LIB_NAME} ${NAME}

${LIB_NAME} :
	make -C lib/ft_printf
	make -C lib/gnl
	make -C lib/mlx

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${LDFLAGS} ${OPT_MLX} -o ${NAME} 

debug: ${LIB_NAME} ${OBJS}
	${CC} ${CFLAGS} ${DEBUG_FLAGS} ${OBJS} ${LDFLAGS} ${OPT_MLX} -o ${NAME}

.c.o:
		${CC} ${CFLAGS} -Iincludes -c $< -o $@

clean: 
	make clean -C lib/ft_printf
	make clean -C lib/gnl
	make clean -C lib/mlx
	${RM} ${OBJS}

fclean: clean
	make fclean -C lib/ft_printf
	make fclean -C lib/gnl
	make clean -C lib/mlx
	${RM} ${NAME}
re:		fclean all

.PHONY: all clean fclean re .c.o 
