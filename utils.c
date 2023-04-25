/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:55:20 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/25 14:24:17 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	*char_to_int(char **arr)
{
	int	y;
	int	*arrnum;

	y = 0;
	while (arr[y])
		y++;
	arrnum = ft_calloc(y, sizeof(int));
	y = 0;
	while (arr[y])
	{
		arrnum[y] = ft_atoi(arr[y]);
		y++;
	}
	return (arrnum);
}

char	**int_to_char(int *num)
{
	char	**newarr;
	int		y;

	y = 0;
	while (num[y])
		y++;
	newarr = ft_calloc(y, sizeof(char *));
	y = 0;
	while (num[y])
	{
		newarr[y] = ft_itoa(num[y]);
		y++;
	}
	return (newarr);
}
