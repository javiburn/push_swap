/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:34:45 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/25 15:41:45 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

t_chunk	find_bot(t_chunk chunk, t_list *aux_back, int i, int laps, int n)
{
	while (n > ft_lstsize(chunk.stack_a) / 2)
	{
		while (laps++ < n)
			aux_back = aux_back->next;
		while (aux_back != NULL)
		{
			while (chunk.opt_bot < 10 + i && chunk.arr_ordered[chunk.opt_bot])
			{
				if (aux_back->content == chunk.arr_ordered[chunk.opt_bot])
					return (chunk);
				chunk.opt_bot++;
			}
			aux_back = aux_back->next;
			chunk.opt_bot = 0;
			chunk.pos_opt_bot--;
		}
		laps = 0;
		n--;
		aux_back = chunk.stack_a;
		chunk.pos_opt_bot = n + 1;
	}
	chunk.opt_bot = 10;
	return (chunk);
}

t_chunk	pos_optimus_ending(t_chunk chunk, t_list *aux_back, int i)
{
	int		laps;
	int		n;

	laps = 0;
	n = ft_lstsize(chunk.stack_a);
	chunk.opt_bot = 0;
	chunk.pos_opt_bot = ft_lstsize(chunk.stack_a);
	chunk = find_bot(chunk, aux_back, i, laps, n);
	return (chunk);
}

t_chunk	pos_optimus_initial(t_chunk chunk, t_list *aux, int i)
{
	chunk.pos_opt_top = 0;
	while (aux != NULL)
	{
		while (chunk.opt_top < 10 + i && chunk.arr_ordered[chunk.opt_top])
		{
			ft_printf("%d, %d\n", aux->content, chunk.arr_ordered[chunk.opt_top]);
			if (aux->content == chunk.arr_ordered[chunk.opt_top])
				return (chunk);
			chunk.opt_top++;
		}
		aux = aux->next;
		chunk.opt_top = 0;
		chunk.pos_opt_top++;
	}
	chunk.opt_top = 10;
	return (chunk);
}

t_chunk	find_optimus(t_chunk chunk)
{
	static int	i = 0;
	t_list		*aux;
	t_list		*aux_back;

	aux = chunk.stack_a;
	aux_back = chunk.stack_a;
	chunk.opt_top = 0;
	chunk = pos_optimus_initial(chunk, aux, i);
	chunk.opt_bot = 0;
	chunk = pos_optimus_ending(chunk, aux_back, i);
	chunk.pos_opt_bot = ft_lstsize(chunk.stack_a) - chunk.pos_opt_bot;
	if (chunk.opt_top == 10 && chunk.opt_bot == 10)
	{
		i += 10;
		return (chunk);
	}
	if (chunk.pos_opt_top > chunk.pos_opt_bot)
		chunk.optimus = chunk.arr_ordered[chunk.opt_bot];
	else
		chunk.optimus = chunk.arr_ordered[chunk.opt_top];
	return (chunk);
}

t_chunk	movements(t_chunk chunk, int argc)
{
	while (ft_lstsize(chunk.stack_a) > 0)
	{
		if (ft_lstsize(chunk.stack_a) == 1)
			return (pb(chunk));
		if (argc > 10)
		{
			chunk = find_optimus(chunk);
			if (chunk.optimus == chunk.arr_ordered[chunk.opt_top]
				&& chunk.pos_opt_top <= chunk.pos_opt_bot)
			{
				if (chunk.pos_opt_top == 0)
					chunk = pb(chunk);
				else if (chunk.pos_opt_top == 1)
				{
					chunk = sa(chunk);
					chunk = pb(chunk);
				}
				else
					chunk = ra(chunk);
			}
			if (chunk.optimus == chunk.arr_ordered[chunk.opt_bot])
				chunk = rra(chunk);
		}
	}
	if (ft_lstsize(chunk.stack_a) == 1)
		return (pb(chunk));
	return (chunk);
}
