NAME = libftprintf.a
SRCS =		ft_putstr.c \
			ft_printf.c \
			ft_print_c.c \
			ft_print_d_and_u.c \
			ft_print_p.c \
			ft_print_lx.c \
			ft_print_percent.c \
			ft_print_s.c \
			ft_print_x.c \
			ft_convert_dec_to_hexstr.c \

OBJS = ${SRCS:.c=.o}
CC		= gcc
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror

all:	${NAME}

$(NAME): ${OBJS}
		${MAKE} -C ./libft
		cp libft/libft.a ${NAME}
		ar rcs ${NAME} ${OBJS}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
		make clean -C libft
		${RM} ${OBJS}

fclean:	clean
		make fclean -C libft
		${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re .c.o 
