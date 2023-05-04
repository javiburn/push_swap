/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_large_to_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:33:06 by jsarabia          #+#    #+#             */
/*   Updated: 2023/05/04 14:38:31 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

t_chunk	find_optimus_b(t_chunk chunk, int i)
{
	t_list	*aux;

	if (i < 0)
		i = 0;
	chunk.pos_opt_top = 0;
	aux = chunk.stack_b;
	chunk.optimus = ft_atoi(chunk.arr_ordered[i]);
	while (aux != NULL)
	{
		if (ft_atoi(aux->content) == ft_atoi(chunk.arr_ordered[i]))
			return (chunk);
		aux = aux->next;
		chunk.pos_opt_top++;
	}
	chunk.optimus = ft_atoi(chunk.arr_ordered[i]);
	return (chunk);
}

t_chunk	movements_undefined_b(t_chunk chunk, int i)
{
	while (ft_lstsize(chunk.stack_b) >= 0 && i >= 0)
	{
		chunk = find_optimus_b(chunk, i);
		if (chunk.pos_opt_top <= ft_lstsize(chunk.stack_b) / 2)
		{
			if (chunk.pos_opt_top == 0)
			{
				chunk = pa(chunk);
				i--;
			}
			if (chunk.pos_opt_top == 1)
			{
				chunk = sb(chunk);
				chunk = pa(chunk);
				i--;
			}
			else if (chunk.pos_opt_top > 1)
				chunk = rb(chunk);
		}
		else if (chunk.pos_opt_top > ft_lstsize(chunk.stack_b) / 2)
			chunk = rrb(chunk);
	}
	return (chunk);
}
