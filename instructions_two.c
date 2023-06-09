/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:48:47 by jsarabia          #+#    #+#             */
/*   Updated: 2023/05/04 14:39:49 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

t_chunk	rb(t_chunk chunk)
{
	t_list	*aux;

	aux = chunk.stack_b;
	chunk.stack_b = chunk.stack_b->next;
	aux->next = NULL;
	ft_lstlast(chunk.stack_b)->next = aux;
	write(1, "rb\n", 3);
	return (chunk);
}

t_chunk	sb(t_chunk chunk)
{
	t_list	*aux;

	aux = chunk.stack_b;
	chunk.stack_b = chunk.stack_b->next;
	aux->next = aux->next->next;
	chunk.stack_b->next = aux;
	write(1, "sb\n", 3);
	return (chunk);
}

t_chunk	sa(t_chunk chunk)
{
	t_list	*aux;

	aux = chunk.stack_a;
	chunk.stack_a = chunk.stack_a->next;
	aux->next = aux->next->next;
	chunk.stack_a->next = aux;
	write(1, "sa\n", 3);
	return (chunk);
}

t_chunk	ra(t_chunk chunk)
{
	t_list	*aux;

	aux = chunk.stack_a;
	chunk.stack_a = chunk.stack_a->next;
	aux->next = NULL;
	ft_lstlast(chunk.stack_a)->next = aux;
	write(1, "ra\n", 3);
	return (chunk);
}

t_chunk	rra(t_chunk chunk)
{
	t_list	*aux;
	t_list	*prev;
	t_list	*last;

	aux = chunk.stack_a;
	prev = ptr_prev_last(aux);
	last = ft_lstlast(chunk.stack_a);
	prev->next = NULL;
	chunk.stack_a = last;
	chunk.stack_a->next = aux;
	write(1, "rra\n", 4);
	return (chunk);
}
