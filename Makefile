# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 15:00:46 by jsarabia          #+#    #+#              #
#    Updated: 2023/04/25 16:51:57 by jsarabia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

LIBFT = libft
PRINTF = ft_printf

LIBFTOUT = libft/libft.a
PRINTFOUT = ft_printf/libftprintf.a

OBJS = push_swap.o print_errors.o stack_init.o free_all.o check.o create_arrays.o utils.o algorithm.o check_if_sorted.o instructions_one.o instructions_two.o print_list.o
#stack_init.o check.o print_error.o print_list.o movements.o check_if_sorted.o instructions_one.o instructions_two.o instructions_three.o utils.o movements_b.o

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): compile_libft compile_printf $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTOUT) $(PRINTFOUT) -o $(NAME)

compile_libft:
	@make bonus -C libft/

compile_printf:
	@make all -C ft_printf/

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C libft/
	@make clean -C ft_printf/
	/bin/rm -f *.o

fclean: clean
	@make fclean -C libft/
	@make fclean -C ft_printf/
	rm -rf push_swap

re: fclean all

.PHONY: clean fclean re
