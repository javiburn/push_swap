/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:42:59 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/26 15:00:19 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

t_chunk	pa(t_chunk chunk)
{
	t_list	*new;

	new = ft_lstnew(chunk.stack_b->content);
	write(1, "pa\n", 3);
	if (!chunk.stack_a)
	{
		ft_lstadd_front(&chunk.stack_a, new);
		chunk.stack_a = new;
		chunk.stack_b = chunk.stack_b->next;
		return (chunk);
	}
	if (chunk.stack_b->next == NULL)
	{
		ft_lstadd_front(&chunk.stack_a, new);
		chunk.stack_a = new;
		chunk.stack_b = NULL;
		return (chunk);
	}
	*chunk.stack_b = *chunk.stack_b->next;
	ft_lstadd_front(&chunk.stack_a, new);
	*chunk.stack_a = *new;
	return (chunk);
}

t_chunk	pb(t_chunk chunk)
{
	t_list	*new;

	new = ft_lstnew(chunk.stack_a->content);
	if (!chunk.stack_a)
		return (chunk);
	if (!chunk.stack_a->next)
	{
		ft_lstadd_front(&chunk.stack_b, new);
		chunk.stack_b = new;
		chunk.stack_a = NULL;
		return (chunk);
	}
	*chunk.stack_a = *chunk.stack_a->next;
	ft_lstadd_front(&chunk.stack_b, new);
	*chunk.stack_b = *new;
	write(1, "pb\n", 3);
	return (chunk);
}

t_chunk	ss(t_list *stack_a, t_list *stack_b, t_chunk chunk)
{
	char	*aux;

	if (stack_a == NULL || stack_a->next == NULL)
		return (chunk);
	aux = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = aux;
	if (stack_b == NULL || stack_b->next == NULL)
		return (chunk);
	aux = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next->content = aux;
	write(1, "ss\n", 3);
	return (chunk);
}

t_chunk	rr(t_chunk chunk)
{
	t_list	*new_a;
	t_list	*new_b;

	new_b = ft_lstnew(chunk.stack_b->content);
	*chunk.stack_b = *chunk.stack_b->next;
	ft_lstadd_back(&chunk.stack_b, new_b);
	new_a = ft_lstnew(chunk.stack_a->content);
	*chunk.stack_a = *chunk.stack_a->next;
	ft_lstadd_back(&chunk.stack_a, new_a);
	write(1, "rr\n", 3);
	return (chunk);
}

t_chunk	rrr(t_chunk chunk)
{
	t_list	*new_a;
	t_list	*new_b;
	t_list	*aux;
	t_list	*aux_a;

	new_b = ft_lstnew(ft_lstlast(chunk.stack_b)->content);
	aux = ft_lstnew(ft_lstlast(chunk.stack_b)->content);
	ft_lstadd_front(&chunk.stack_b, new_b);
	*chunk.stack_b = *new_b;
	*aux = *chunk.stack_b;
	while (aux->next->next != NULL)
		aux = aux->next;
	aux->next = NULL;
	new_a = ft_lstnew(ft_lstlast(chunk.stack_a)->content);
	aux_a = ft_lstnew(ft_lstlast(chunk.stack_a)->content);
	ft_lstadd_front(&chunk.stack_a, new_a);
	*chunk.stack_a = *new_a;
	*aux_a = *chunk.stack_a;
	while (aux_a->next->next != NULL)
		aux_a = aux_a->next;
	aux_a->next = NULL;
	write(1, "rrr\n", 4);
	return (chunk);
}
