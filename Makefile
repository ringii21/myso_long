# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abonard <abonard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 17:19:39 by abonard           #+#    #+#              #
#    Updated: 2022/05/24 19:53:01 by abonard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NC = \033[0m
RED = \033[0;91m
ORANGE = \033[93m
GREEN = \033[0;92m
PURPLE = \033[0;95m
BLUE = \033[0;34m
BOLD = \033[1m

SRCS		=	./srcs/ft_parcing.c \
				./srcs/so_long.c \
				./srcs/ft_solong_utils.c\
				./srcs/ft_moves.c

SRCS_BONUS	= 	./bonus/srcs/ft_parcing.c \
				./bonus/srcs/so_long.c \
				./bonus/srcs/ft_solong_utils.c\
				./bonus/srcs/digit.c\
				./bonus/srcs/ft_moves.c
				
INCLUDES	=	./includes/libft.h \
				./includes/ft_printf.h \

INCLUDES_BONUS	=	./bonus/includes/libft/libft.h \
					./bonus/includes/so_long.h\
					./bonus/includes/libft/ft_printf.h \

HEAD		= ./includes/

HEAD_BONUS	= ./bonus/includes/

MLX 		= minilibx-linux/libmlx_Linux.a

LIBFT		= ./libft/libft.a

LIB_DIR		= ./libft/

NAME		= So_long

CC			= clang

OBJS		= ${SRCS:.c=.o}

OBJS_B		= ${SRCS_BONUS:.c=.o}

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -g

LFLAGS		= -lm -lX11 -lXext -lbsd

.c.o:
		@${CC} ${CFLAGS} -I${HEAD_BONUS} -c $< -o ${<:.c=.o}
		@echo "${GREEN}[ OK ]	${ORANGE}${<:.s=.o}${NC}"

all:		${NAME}

${NAME}:	${OBJS}
			@make -C ${LIB_DIR}
			@echo "${GREEN}\nlibft.a		has been created"
			@${CC} ${CFLAGS} ${LFLAGS} -I${HEAD} -o ${NAME} $(OBJS) ${LIBFT} ${MLX}
			@echo "so_long		has been created\n${NC}"


bonus:		${OBJS_B}
			@make -C ${LIB_DIR}
			@${CC} ${CFLAGS} ${LFLAGS} -I${HEAD_BONUS} -o ${NAME} $(OBJS_B) ${LIBFT} ${MLX}
			@echo "${GREEN}so_long	with bonus has been created${NC}"

clean:
			@make -C $(LIB_DIR) clean
			@${RM} ${OBJS}
			@${RM} ${OBJS2}
			@${RM} ${OBJS3}
			@${RM} ${OBJS4}
			@echo "${GREEN}[ OK ]${RED}	*.o files	deleted${NC}"

fclean:		clean
			@make -C $(LIB_DIR) fclean
			@echo "${GREEN}[ OK ]${RED}	libft.a		deleted${NC}"
			@${RM} ${NAME} ${NAME2} ${NAME3} ${NAME4}
			@echo "${GREEN}[ OK ]${RED}everything	deleted${NC}"

re :		fclean all

.PHONY:		all	clean	fclean re
