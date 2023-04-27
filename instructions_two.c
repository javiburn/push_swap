/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:48:47 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/27 14:55:51 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

t_chunk	rb(t_chunk chunk)
{
	t_list	*new;

	new = ft_lstnew(chunk.stack_b->content);
	*chunk.stack_b = *chunk.stack_b->next;
	ft_lstadd_back(&chunk.stack_b, new);
	write(1, "rb\n", 3);
	return (chunk);
}

t_chunk	sb(t_chunk chunk)
{
	char	*aux;

	if (chunk.stack_b == NULL || chunk.stack_b->next == NULL)
		return (chunk);
	aux = chunk.stack_b->content;
	chunk.stack_b->content = chunk.stack_b->next->content;
	chunk.stack_b->next->content = aux;
	write(1, "sb\n", 3);
	return (chunk);
}

t_chunk	sa(t_chunk chunk)
{
	char	*aux;

	if (chunk.stack_a == NULL || chunk.stack_a->next == NULL)
		return (chunk);
	aux = chunk.stack_a->content;
	chunk.stack_a->content = chunk.stack_a->next->content;
	chunk.stack_a->next->content = aux;
	write(1, "sa\n", 3);
	return (chunk);
}

t_chunk	ra(t_chunk chunk)
{
	t_list	*new;
	t_list	*aux;
	t_list	*prev;

	prev = ft_lstnew(ft_lstlast(chunk.stack_a)->content);
	new = ft_lstnew(chunk.stack_a->content);
	aux = chunk.stack_a->next;
	chunk.stack_a = aux;
	ft_lstadd_back(&chunk.stack_a, new);
	new->next = NULL;
	write(1, "ra\n", 3);
	return (chunk);
}

t_chunk	rra(t_chunk chunk)
{
	t_list	*new;
	t_list	*aux;

	new = ft_lstlast(chunk.stack_a);
	aux = ptr_prev_last(chunk.stack_a);
	ft_lstadd_front(&chunk.stack_a, new);
	aux->next = NULL;
	chunk.stack_a = new;
	write(1, "rra\n", 4);
	return (chunk);
}