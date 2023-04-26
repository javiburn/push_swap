/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:56:05 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/26 12:22:12 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

t_chunk	conditions(t_chunk chunk, t_list *prev, t_list *last)
{
	while (!is_sorted(chunk))
	{
		if (ft_atoi(chunk.stack_a->content)
			> ft_atoi(last->content) && ft_atoi((chunk.stack_a->content))
			> ft_atoi(prev->content))
			return (ra(chunk));
		if (ft_atoi(chunk.stack_a->content)
			> ft_atoi(chunk.stack_a->next->content))
			return (sa(chunk));
		if (ft_atoi(prev->content)
			> ft_atoi(last->content)
			|| ft_atoi(chunk.stack_a->content)
			< ft_atoi(prev->content))
			return (rra(chunk));
		else
			return (chunk);
	}
	return (chunk);
}

t_chunk	movements_six(t_chunk chunk)
{
	int	i;
	int	n;

	i = chunk.argcs / 2;
	n = 0;
	//while ()
	return (chunk);
}

t_chunk	movements_three(t_chunk chunk)
{
	t_list	*prev;
	t_list	*last;

	prev = ptr_prev_last(chunk.stack_a);
	last = prev->next;
	while (!is_sorted(chunk))
		chunk = conditions(chunk, prev, last);
	exit(0);
	return (chunk);
}

t_chunk	algorithm(t_chunk chunk)
{
	if (chunk.argcs <= 3)
	{
		while (!is_sorted(chunk))
			chunk = movements_three(chunk);
		return (chunk);
	}
	if (chunk.argcs <= 6)
	{
		while (!is_sorted(chunk))
			chunk = movements_six(chunk);
		return (chunk);
	}
		 //vamos a pasar un número que va a ser i, que será el que determine el valor del size que vamos a pasar al stack_b
	if (chunk.argcs > 10)
		return (chunk);
	return (chunk);
}
