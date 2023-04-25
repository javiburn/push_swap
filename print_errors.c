/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:10:14 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/25 12:12:21 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	print_arg_error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(0);
	return (0);
}

int	print_int_error(char *str, char **values)
{
	ft_putstr_fd(str, 1);
	values = NULL;
	if (values)
		free_matrix(values);
	exit(0);
	return (0);
}
