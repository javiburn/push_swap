/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:42:59 by jsarabia          #+#    #+#             */
/*   Updated: 2023/05/04 14:06:17 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

t_chunk	pa(t_chunk chunk)
{
	t_list	*aux;
	t_list	*aux_two;

	write(1, "pa\n", 3);
	aux = chunk.stack_b;
	aux_two = chunk.stack_a;
	if (!aux->next)
		aux = NULL;
	if (aux && aux->next)
		aux = aux->next;
	chunk.stack_b->next = NULL;
	ft_lstadd_front(&aux_two, chunk.stack_b);
	chunk.stack_a = chunk.stack_b;
	chunk.stack_b = aux;
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
