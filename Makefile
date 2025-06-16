# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seungsch <seungsch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 16:11:45 by jaejo             #+#    #+#              #
#    Updated: 2025/06/17 03:31:24 by seungsch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -g

NAME = miniRT

FREE_SRCS = ./free/free.c \

HOOK_SRCS = ./hook/hook_list.c ./hook/hook_utils.c ./hook/hook_rotate.c \

PRINT_SRCS = ./print/write_color.c ./print/print_image.c \

TRACE_SRCS = ./trace/trace.c ./trace/hit_sphere.c ./trace/phong_lighting.c \
			./trace/hit.c ./trace/hit_plane.c ./trace/hit_utils.c ./trace/hit_cylinder.c\
			./trace/hit_circle.c

SCENE_SRCS = ./scene/scene.c ./scene/object_utils.c ./scene/object_create.c \
			./scene/file_init.c ./scene/file_data_check.c ./scene/file_check_utils.c \
			./scene/data_init.c ./scene/data_utils.c \

VEC_UTILS_SRCS = ./vec/make_vec_utils.c ./vec/vec_minus_utils.c ./vec/vec_mult_div_utils.c \
				 ./vec/vec_operator_utils.c ./vec/vec_plus_utils.c \

SRCS = ./main.c $(PRINT_SRCS) $(VEC_UTILS_SRCS) $(TRACE_SRCS) $(SCENE_SRCS) $(FREE_SRCS) \
		$(HOOK_SRCS)

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./ft_printf 
	$(MAKE) -C ./minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) -L./ft_printf -lftprintf -L./minilibx-linux -lmlx -lXext -lX11 -lm -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)
	$(MAKE) clean -C ./ft_printf

fclean : clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./ft_printf

re : fclean all

.PHONY : all clean fclean re
