/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:42:59 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/27 19:12:02 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

t_chunk	pa(t_chunk chunk)
{
	t_list	*aux;

	write(1, "pa\n", 3);
	aux = chunk.stack_b;
	aux->next = NULL;
	ft_lstadd_front(&chunk.stack_a, aux);
	if (!chunk.stack_b->next)
		chunk.stack_b = NULL;
	if (chunk.stack_b->next)
		chunk.stack_b = chunk.stack_b->next;
	return (chunk);
}

t_chunk	pb(t_chunk chunk)
{
	t_list	*aux;

	write(1, "pb\n", 3);
	aux = chunk.stack_a;
	chunk.stack_a = chunk.stack_a->next;
	aux->next = NULL;
	ft_lstadd_front(&chunk.stack_b, aux);
	return (chunk);
}
/*
t_chunk	ss(t_list *stack_a, t_list *stack_b, t_chunk chunk)
{

}

t_chunk	rr(t_chunk chunk)
{

}

t_chunk	rrr(t_chunk chunk)
{

}
*/
