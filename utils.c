/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:55:20 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/27 14:09:02 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	*char_to_int(char **arr)
{
	int	y;
	int	aux;
	int	*arrnum;

	y = 0;
	aux = 0;
	while (arr[y])
		y++;
	y--;
	arrnum = ft_calloc(y, sizeof(int));
	while (aux < y)
	{
		arrnum[aux] = ft_atoi(arr[aux]);
		aux++;
	}
	return (arrnum);
}

char	**int_to_char(int *num)
{
	char	**newarr;
	int		y;
	int		aux;

	y = 0;
	aux = 0;
	while (num[y])
		y++;
	newarr = ft_calloc(y - 1, sizeof(char *));
	while (aux <= y - 1)
	{
		newarr[aux] = ft_itoa(num[aux]);
		aux++;
	}
	return (newarr);
}

t_list	*ptr_prev_last(t_list *ptr)
{
	t_list	*prev;

	prev = ptr;
	while (prev->next->next != NULL)
		prev = prev->next;
	return (prev);
}
