/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:43:40 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/26 12:44:01 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

t_chunk	rrb(t_chunk chunk)
{
	t_list	*new;
	t_list	*aux;

	aux = ft_lstnew(ft_lstlast(chunk.stack_b)->content);
	new = ft_lstnew(ft_lstlast(chunk.stack_b)->content);
	ft_lstadd_front(&chunk.stack_b, new);
	*chunk.stack_b = *new;
	*aux = *chunk.stack_b;
	while (aux->next->next != NULL)
		aux = aux->next;
	aux->next = NULL;
	write(1, "rrb\n", 4);
	return (chunk);
}

t_chunk	sort_b(t_chunk chunk)
{
	if (chunk.stack_b && chunk.stack_b->content
		< ft_lstlast(chunk.stack_b)->content && chunk.stack_b->content
			> chunk.stack_b->next->content)
		return (rb(chunk));
	if (chunk.stack_b && chunk.stack_b->next != NULL
		&& (chunk.stack_b->content < chunk.stack_b->next->content))
		return (sb(chunk));
	else
		return (rrb(chunk));
	return (chunk);
}
