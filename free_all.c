/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:31:36 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/25 14:27:22 by jsarabia         ###   ########.fr       */
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
