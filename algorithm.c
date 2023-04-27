/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:56:05 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/27 18:14:56 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"
/*
t_chunk	pass_to_b(t_chunk chunk)
{
	int		in;
	t_list	*aux;

	aux = chunk.stack_a;
	in = 0;
	while (aux != NULL)
	{
		if (ft_atoi(aux->content) <= chunk.average)
			break ;
		aux = aux->next;
		in++;
	}
	aux = chunk.stack_a;
	if (in < chunk.argcs / 2)
	{
		while (ft_atoi(chunk.stack_a->content) > chunk.average)
			chunk = ra(chunk);
		return (pb(chunk));
	}
	while (ft_atoi(chunk.stack_a->content) > chunk.average)
		chunk = rra(chunk);
	return (pb(chunk));
}

t_chunk	conditions_b(t_chunk chunk)
{
	if (ft_atoi(chunk.stack_b->content) < ft_atoi(chunk.stack_b->next->content)
		&& ft_atoi(chunk.stack_b->content)
		> ft_atoi(ft_lstlast(chunk.stack_b)->content))
		return (sb(chunk));
	if (ft_atoi(chunk.stack_b->content) < ft_atoi(chunk.stack_b->next->content)
		&& ft_atoi(chunk.stack_b->next->content)
		< ft_atoi(ft_lstlast(chunk.stack_b)->content))
	{
		chunk = sb(chunk);
		return (rrb(chunk));
	}
	if (ft_atoi(chunk.stack_b->content) < ft_atoi(chunk.stack_b->next->content)
		&& ft_atoi(chunk.stack_b->content)
		< ft_atoi(ft_lstlast(chunk.stack_b)->content))
		return (rb(chunk));
	if (ft_atoi(chunk.stack_b->content) > ft_atoi(chunk.stack_b->next->content)
		&& ft_atoi(chunk.stack_b->content)
		> ft_atoi(ft_lstlast(chunk.stack_b)->content))
	{
		chunk = sb(chunk);
		return (rb(chunk));
	}
	else
		return (rrb(chunk));
	return (chunk);
}*/

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
	}/*
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
		return (rra(chunk));*/
	return (chunk);
}
/*
t_chunk	movements_six(t_chunk chunk)
{
	while (ft_lstsize(chunk.stack_a) > 3)
		chunk = pass_to_b(chunk);
	if (!stack_a_sorted(chunk))
		chunk = movements_three(chunk);
	if (!stack_b_sorted(chunk))
		chunk = conditions_b(chunk);
	while (ft_lstsize(chunk.stack_b) > 0)
		chunk = pa(chunk);
	return (chunk);
}
*/
t_chunk	algorithm(t_chunk chunk)
{
	if (is_sorted(chunk))
		return (chunk);
	if (chunk.argcs <= 3)
		return (movements_three(chunk));
	/*if (chunk.argcs <= 6)
		return (movements_six(chunk));*/
/*
	if (chunk.argcs > 10)
		return (chunk);*/
	return (chunk);
}
