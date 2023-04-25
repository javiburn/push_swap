/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arrays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:24:56 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/25 13:38:39 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

char	**create_array(char **values, int argc)
{
	int		y;
	char	**nums;

	y = 0;
	nums = ft_calloc(argc, sizeof(char *));
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
		nums[y] = ft_itoa(ft_atoi(values[y]));
		if (!nums[y] && (values[y][0] != '0' && ft_strlen(values[y]) != 1))
			return (NULL);
		y++;
	}
	return (nums);
}
