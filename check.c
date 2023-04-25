/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:35:13 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/25 12:27:14 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	*check_int(char **values, int argc)
{
	int	y;
	int	*nums;
	int	*temp;

	y = 0;
	temp = NULL;
	nums = ft_calloc(argc + 1, sizeof(int));
	while (y < argc)
	{
		if (ft_strlen(values[y]) > 11)
			return (NULL);
		if (ft_strncmp(values[y], "2147483647", 11) > 0
			&& ft_strlen(values[y]) >= 10)
			return (NULL);
		if (ft_strncmp(values[y], "-2147483648", 12) > 0
			&& ft_strlen(values[y]) >= 11)
			return (NULL);
		nums[y] = ft_atoi(values[y]);
		if (!nums[y] && (values[y][0] != '0' && ft_strlen(values[y]) != 1))
			return (NULL);
		y++;
	}
	temp = nums;
	free(nums);
	return (temp);
}

static int	check_repeat(int *num, int argc)
{
	int	n;
	int	i;

	n = 0;
	i = 1;
	while (n < argc)
	{
		while (i < argc)
		{
			if (num[n] == num[i])
				return (0);
			i++;
		}
		n++;
		i = n + 1;
	}
	return (1);
}

static int	check_nums(char **values, int argc)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	if ((!ft_atoi(values[n]) && !values[1]) || (!ft_atoi(values[n])
			&& !(values[n][0] == '0' && ft_strlen(values[n]) == 1)))
		return (0);
	while (n < argc)
	{
		while (i < argc)
		{
			if (!ft_atoi(values[i]))
			{
				if (!(values[i][0] == '0' && ft_strlen(values[i]) == 1))
					return (0);
			}
			i++;
		}
		n++;
		i = n + 1;
	}
	return (1);
}

int	check(char **values, int argc)
{
	int	*nums;

	if (!check_nums(values, argc))
		return (0);
	nums = check_int(values, argc);
	if (!nums)
		return (0);
	if (!check_repeat(nums, argc))
		return (0);
	return (1);
}
