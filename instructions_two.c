/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:48:47 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/26 15:02:46 by jsarabia         ###   ########.fr       */
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

	new = ft_lstnew(chunk.stack_a->content);
	*chunk.stack_a = *chunk.stack_a->next;
	ft_lstadd_back(&chunk.stack_a, new);
	write(1, "ra\n", 3);
	return (chunk);
}

t_chunk	rra(t_chunk chunk)
{
	t_list	*new;
	t_list	*aux;

	aux = NULL;
	new = ft_lstnew(ft_lstlast(chunk.stack_a)->content);
	ft_lstadd_front(&chunk.stack_a, new);
	chunk.stack_a = new;
	aux = chunk.stack_a;
	while (aux->next->next != NULL)
		aux = aux->next;
	aux->next = NULL;
	write(1, "rra\n", 4);
	return (chunk);
}
