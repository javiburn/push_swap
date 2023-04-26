/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:31:36 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/26 12:09:04 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void	free_matrix(char **str)
{
	int	y;

	y = 0;
	while (str[y])
		free(str[y++]);
	free(str);
}

void	free_chunk(t_chunk chunk)
{
	free_matrix(chunk.arr_ordered);
	free_matrix(chunk.num_arr);
}

void	free_nodes(t_chunk chunk)
{
	t_list	*aux;

	aux = chunk.stack_a;
	while (aux != NULL)
	{
		free(aux);
		aux = chunk.stack_a->next;
	}
}
