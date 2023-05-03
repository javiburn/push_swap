/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:51:45 by jsarabia          #+#    #+#             */
/*   Updated: 2023/05/03 13:11:41 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	print_list(t_chunk chunk)
{
	t_list	*aux_a;
	t_list	*aux_b;

	aux_a = chunk.stack_a;
	aux_b = chunk.stack_b;
	while (aux_a != NULL)
	{
		ft_printf("a: %s\n", aux_a->content);
		aux_a = aux_a->next;
	}
	while (aux_b != NULL)
	{
		ft_printf("b: %s\n", aux_b->content);
		aux_b = aux_b->next;
	}
	//ft_printf("Optimus: %d\n", chunk.optimus);
	return (0);
}
