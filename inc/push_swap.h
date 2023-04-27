/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:47:27 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/27 17:01:15 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct s_chunk
{
	struct s_list	*stack_a;
	struct s_list	*stack_b;
	int				average;
	int				optimus;
	int				opt_top;
	int				pos_opt_top;
	int				opt_bot;
	int				pos_opt_bot;
	int				argcs;
	char			**num_arr;
	char			**arr_ordered;
}					t_chunk;

char	**create_values(int argc, char **argv, char **values);
int		check(char **values, int argc);
int		*check_int(char **values, int argc);
int		*char_to_int(char **arr, int num);
char	**int_to_char(int *num, int n);
t_chunk	order_nums(t_chunk chunk);
t_chunk	stack_init(t_chunk chunk);
int		print_arg_error(char *str);
int		print_int_error(char *str, char **values);
int		print_list(t_chunk chunk);
t_chunk	algorithm(t_chunk chunk);
t_chunk	movements(t_chunk chunk, int argc);
t_chunk	movements_b(t_chunk chunk);
int		is_sorted(t_chunk chunk);
int		min_num(t_chunk chunk);
int		stack_a_sorted(t_chunk chunk);
int		stack_b_sorted(t_chunk chunk);
t_list	*ptr_prev_last(t_list *ptr);
int		array_num(t_chunk chunk);
t_chunk	sa(t_chunk chunk);
/*t_chunk	pa( t_chunk chunk);
t_chunk	pb(t_chunk chunk);
t_chunk	ss(t_list *stack_a, t_list *stack_b, t_chunk chunk);
t_chunk	rr(t_chunk chunk);
t_chunk	rrr(t_chunk chunk);
t_chunk	sa(t_chunk chunk);
t_chunk	ra(t_chunk chunk);
t_chunk	rra(t_chunk chunk);
t_chunk	sb(t_chunk chunk);
t_chunk	rb(t_chunk chunk);
t_chunk	rrb(t_chunk chunk);
t_chunk	sort_b(t_chunk chunk);*/
void	free_matrix(char **str);
void	free_chunk(t_chunk chunk);
void	free_nodes(t_chunk chunk);
char	**create_array(char **values, int argc);

//int		check_nums(char **values, int argc);
/*
int		check(int argc, char **argv, int rest);
t_list	*stack_init(int argc, char **argv);
int		is_sorted(t_list *stack_a, t_list *stack_b);
int		stack_b_sorted(t_list *stack_b);
int		stack_a_sorted(t_list *stack_a);
int		print_list(t_list *stack_a, t_list *stack_b);
t_chunk	movements(t_chunk chunk);
t_chunk	movements_more(t_chunk chunk);
t_chunk	movements_even_more(t_chunk chunk);
t_list	*sa(t_list *stack_a);
t_chunk	ss(t_list *stack_a, t_list *stack_b, t_chunk chunk);
t_list	*pb(t_list *stack_a, t_list *stack_b);
t_chunk	pa( t_chunk chunk);
t_list	*ra(t_list *stack_a);
t_list	*rb(t_list *stack_b);
t_chunk	rra(t_chunk chunk);
t_list	*sb(t_list *stack_b);
t_chunk	rr(t_chunk chunk);
t_chunk	rrb(t_chunk chunk);
int		max_value(t_chunk chunk);
*/

#endif
