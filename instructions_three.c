/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:43:40 by jsarabia          #+#    #+#             */
/*   Updated: 2023/05/03 13:33:04 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

t_chunk	rrb(t_chunk chunk)
{
	t_list	*aux;
	t_list	*prev;
	t_list	*last;

	aux = chunk.stack_b;
	prev = ptr_prev_last(aux);
	last = ft_lstlast(chunk.stack_b);
	prev->next = NULL;
	chunk.stack_b = last;
	chunk.stack_b->next = aux;
	write(1, "rrb\n", 4);
	return (chunk);
}
