/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:55:20 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/27 16:06:41 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	*char_to_int(char **arr, int num)
{
	int	y;
	int	*arrnum;

	y = 0;
	arrnum = ft_calloc(num + 1, sizeof(int));
	while (y < num)
	{
		arrnum[y] = ft_atoi(arr[y]);
		y++;
	}
	return (arrnum);
}

char	**int_to_char(int *num, int n)
{
	char	**newarr;
	int		y;

	y = 0;
	newarr = ft_calloc(y + 1, sizeof(char *));
	while (y < n)
	{
		newarr[y] = ft_itoa(num[y]);
		y++;
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
