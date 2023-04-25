/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:13:55 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/25 12:27:25 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

char	**create_values(int argc, char **argv, char **values)
{
	int		y;
	char	**val;

	y = 0;
	val = ft_split(argv[1], ' ');
	if (argc == 2 && val != NULL)
		return (val);
	if (val && argc > 2)
		free_matrix(val);
	val = ft_calloc(argc, sizeof(char *));
	if (!val)
		free_matrix(val);
	while (argv[y + 1] != '\0')
	{
		val[y] = ft_substr(argv[y + 1], 0, ft_strlen(argv[y + 1]));
		y++;
	}
	values = val;
	return (values);
}
