/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:05:58 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/25 12:27:07 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

static int	check_argc(char **values)
{
	int	n;

	n = 0;
	if (!values)
		return (0);
	while (values[n] != '\0')
		n++;
	return (n);
}

void	leaks()
{
	system("leaks -q push_swap");
}

int	main(int argc, char **argv)
{
	t_chunk	chunk;
	char	**values;

	atexit(leaks);
	values = NULL;
	if (argc < 2)
		return (print_arg_error
			("Error!\nYou have to enter at least one number\n"));
	values = create_values(argc, argv, values);
	chunk.argcs = check_argc(values);
	if (!values || !check(values, chunk.argcs))
		return (print_int_error("Error!\nInvalid numbers\n", values));
	ft_printf("Todo OK Jose Luis\n");
	exit(0);
	return (0);
}
