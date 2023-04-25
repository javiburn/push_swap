/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:56:05 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/25 18:08:43 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

t_chunk	movements_five(t_chunk chunk)
{
	t_list	*prev;

	prev = ptr_prev_last(chunk.stack_a);
	while (!is_sorted(chunk))
	{
		if (ft_atoi(chunk.stack_a->content)
			> ft_atoi(chunk.stack_a->next->content))
			return (sa(chunk));
		if (ft_atoi(prev->content)
			> ft_atoi(ft_lstlast(chunk.stack_a)->content)
			|| ft_atoi(chunk.stack_a->content)
			< ft_atoi(ft_lstlast(chunk.stack_a)->content))
			return (rra(chunk));
		else if (ft_atoi(chunk.stack_a->content)
			> ft_atoi(ft_lstlast(chunk.stack_a)->content))
			return (ra(chunk));
	}
	return (chunk);
}

t_chunk	algorithm(t_chunk chunk)
{
	if (chunk.argcs <= 3)
	{
		while (!is_sorted(chunk))
			chunk = movements_five(chunk);
		return (chunk);
	}
		 //vamos a pasar un número que va a ser i, que será el que determine el valor del size que vamos a pasar al stack_b
	if (chunk.argcs > 10)
		return (chunk);
	return (chunk);
}
