# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaejo <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 16:11:45 by jaejo             #+#    #+#              #
#    Updated: 2024/10/29 14:44:00 by jaejo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

NAME = libftprintf.a

LIBFT = libft

SRCS = ft_printf.c ft_flag_setting.c ft_specifier_setting.c ft_print_chars.c \
       ft_print_c.c ft_str_dot.c ft_str_mdot.c ft_print_null.c ft_print_s.c \
       ft_print_id.c ft_id_width.c ft_m_id_width.c ft_id_dot_div.c ft_print_percent.c\
       ft_id_mdot_div.c ft_mid_dot_div.c ft_mid_mdot_div.c ft_print_u.c \
       ft_u_dot_div.c ft_u_mdot_div.c ft_print_x.c ft_x_dot_div.c ft_x_mdot_div.c \
       ft_print_ux.c ft_ux_dot_div.c ft_ux_mdot_div.c ft_print_p.c  ft_print_hash.c \


B_SRCS = 

OBJS = $(SRCS:.c=.o)

B_OBJS = $(B_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C ./libft
	cp ./libft/libft.a ./
	mv libft.a libftprintf.a
	ar rcs $(NAME) $(OBJS)

make_bonus : $(B_OBJS)
	ar rcs $(NAME) $(B_OBJS)
	touch $@

bonus : make_bonus

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS) $(B_OBJS)
	$(MAKE) clean -C ./libft

fclean : clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./libft

re : fclean all

.PHONY : all clean fclean re bonus
