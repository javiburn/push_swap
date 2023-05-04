/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_large_arg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:43:34 by jsarabia          #+#    #+#             */
/*   Updated: 2023/05/04 14:27:18 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

t_chunk	find_bot(t_chunk chunk, t_list *aux_back, t_data data_back, int i)
{
	while (data_back.n > ft_lstsize(chunk.stack_a) / 2)
	{
		while (data_back.laps++ < data_back.n)
			aux_back = aux_back->next;
		if (data_back.num + i > chunk.argcs)
			data_back.num = chunk.argcs - i - 1;
		while (aux_back != NULL)
		{
			while (chunk.opt_bot < data_back.num + i)
			{
				if (aux_back->content == chunk.arr_ordered[chunk.opt_bot])
					return (chunk);
				chunk.opt_bot++;
			}
			aux_back = aux_back->next;
			chunk.opt_bot = 0;
			chunk.pos_opt_bot--;
		}
		data_back.laps = 0;
		data_back.n--;
		aux_back = chunk.stack_a;
		chunk.pos_opt_bot = data_back.n + 1;
	}
	chunk.opt_bot = data_back.num + i;
	return (chunk);
}

t_chunk	pos_optimus_ending(t_chunk chunk, t_list *aux_back,
t_data data_back, int i)
{
	data_back.laps = 0;
	data_back.n = ft_lstsize(chunk.stack_a);
	chunk.opt_bot = 0;
	chunk.pos_opt_bot = ft_lstsize(chunk.stack_a);
	chunk = find_bot(chunk, aux_back, data_back, i);
	return (chunk);
}

t_chunk	pos_optimus_initial(t_chunk chunk, t_list *aux, t_data data_back, int i)
{
	chunk.pos_opt_top = 0;
	if (data_back.num + i > chunk.argcs)
		data_back.num = chunk.argcs - i - 1;
	while (aux != NULL)
	{
		while (chunk.opt_top <= data_back.num + i)
		{
			if (ft_atoi(aux->content)
				== ft_atoi(chunk.arr_ordered[chunk.opt_top]))
				return (chunk);
			chunk.opt_top++;
		}
		aux = aux->next;
		chunk.opt_top = 0;
		chunk.pos_opt_top++;
	}
	chunk.opt_top = data_back.num + i;
	return (chunk);
}

t_chunk	find_optimus(t_chunk chunk, int arg)
{
	static int	i = 0;
	t_list		*aux;
	t_list		*aux_back;
	t_data		data_back;

	data_back.num = arg;
	aux = chunk.stack_a;
	aux_back = chunk.stack_a;
	chunk.opt_top = 0;
	chunk = pos_optimus_initial(chunk, aux, data_back, i);
	chunk.opt_bot = 0;
	chunk = pos_optimus_ending(chunk, aux_back, data_back, i);
	chunk.pos_opt_bot = ft_lstsize(chunk.stack_a) - chunk.pos_opt_bot;
	if ((ft_lstsize(chunk.stack_b) >= data_back.num + i
			&& data_back.num + i <= chunk.argcs)
		|| chunk.pos_opt_bot > ft_lstsize(chunk.stack_a) / 2)
	{
		i += data_back.num;
		return (chunk);
	}
	if (chunk.pos_opt_top > chunk.pos_opt_bot)
		chunk.optimus = ft_atoi(chunk.arr_ordered[chunk.opt_bot]);
	else
		chunk.optimus = ft_atoi(chunk.arr_ordered[chunk.opt_top]);
	return (chunk);
}

t_chunk	movements_undefined(t_chunk chunk, int num)
{
	while (ft_lstsize(chunk.stack_a) > 0)
	{
		if (ft_lstsize(chunk.stack_a) == 1)
			return (pb(chunk));
		chunk = find_optimus(chunk, num);
		if (chunk.stack_b && chunk.optimus == ft_atoi(chunk.stack_b->content))
			chunk = find_optimus(chunk, num);
		if (chunk.arr_ordered[chunk.opt_top]
			&& chunk.optimus == ft_atoi(chunk.arr_ordered[chunk.opt_top])
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
		else if (chunk.arr_ordered[chunk.opt_bot]
			&& chunk.optimus == ft_atoi(chunk.arr_ordered[chunk.opt_bot]))
			chunk = rra(chunk);
	}
	return (chunk);
}
