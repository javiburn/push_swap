/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:56:05 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/26 17:52:19 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

t_chunk	conditions_b(t_chunk chunk)
{
	if (ft_atoi(chunk.stack_b->content)
		< ft_atoi(ft_lstlast(chunk.stack_b)->content)
		&& ft_atoi((chunk.stack_b->content))
		<ft_atoi(ptr_prev_last(chunk.stack_b)->content))
		return (rb(chunk));
	if (ft_atoi(chunk.stack_b->content)
		< ft_atoi(chunk.stack_b->next->content))
		return (sb(chunk));
	if (ft_atoi(ptr_prev_last(chunk.stack_b)->content)
		< ft_atoi(ft_lstlast(chunk.stack_b)->content)
		|| ft_atoi(chunk.stack_b->content)
		> ft_atoi(ptr_prev_last(chunk.stack_b)->content))
		return (rrb(chunk));
	else
		return (chunk);
	return (chunk);
}

t_chunk	movements_three(t_chunk chunk)
{
	if (ft_atoi(chunk.stack_a->content) > ft_atoi(chunk.stack_a->next->content)
		&& ft_atoi(chunk.stack_a->content)
		< ft_atoi(ft_lstlast(chunk.stack_a)->content))
		return (sa(chunk));
	if (ft_atoi(chunk.stack_a->content) > ft_atoi(chunk.stack_a->next->content)
		&& ft_atoi(chunk.stack_a->next->content)
		> ft_atoi(ft_lstlast(chunk.stack_a)->content))
	{
		chunk = sa(chunk);
		return (rra(chunk));
	}
	if (ft_atoi(chunk.stack_a->content) > ft_atoi(chunk.stack_a->next->content)
		&& ft_atoi(chunk.stack_a->content)
		> ft_atoi(ft_lstlast(chunk.stack_a)->content))
		return (ra(chunk));
	if (ft_atoi(chunk.stack_a->content) < ft_atoi(chunk.stack_a->next->content)
		&& ft_atoi(chunk.stack_a->content)
		< ft_atoi(ft_lstlast(chunk.stack_a)->content))
	{
		chunk = sa(chunk);
		return (ra(chunk));
	}
	else
		return (rra(chunk));
	return (chunk);
}
/*
t_chunk	movements_six(t_chunk chunk)
{
	int	n;

	n = 0;
	while (!is_sorted(chunk) || chunk.stack_b)
	{
		//print_list(chunk);
		if (stack_a_sorted(chunk) && chunk.stack_b && stack_b_sorted(chunk))
			return (pa(chunk));
		chunk = conditions(chunk);
		if (ft_atoi(chunk.stack_a->content) <= chunk.average
			&& ft_lstsize(chunk.stack_a) > chunk.argcs/2
			&& ft_lstsize(chunk.stack_a) > 3)
			return (pb(chunk));
		if (chunk.stack_b && !stack_b_sorted(chunk))
			chunk = conditions_b(chunk);
		if (stack_a_sorted(chunk) && chunk.stack_b)
			return (pa(chunk));
	}
	exit(0);
	return (chunk);
}*/

t_chunk	algorithm(t_chunk chunk)
{
	if (chunk.argcs <= 3)
		return(movements_three(chunk));
/*
	if (chunk.argcs <= 6)
	{
		while (!is_sorted(chunk))
			chunk = movements_six(chunk);
		return (chunk);
	}
		 //vamos a pasar un número que va a ser i, que será el que determine el valor del size que vamos a pasar al stack_b
	if (chunk.argcs > 10)
		return (chunk);*/
	return (chunk);
}
