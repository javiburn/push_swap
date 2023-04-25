/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:38:41 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/25 16:53:50 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	stack_b_sorted(t_chunk chunk)
{
	t_list	*help;

	if (!chunk.stack_b)
		return (1);
	help = ft_lstnew(chunk.stack_b->content);
	*help = *chunk.stack_b;
	while (help->next != NULL)
	{
		if (ft_atoi(help->content) < ft_atoi(help->next->content))
			return (0);
		help = help->next;
	}
	return (1);
}

int	stack_a_sorted(t_chunk chunk)
{
	t_list	*help;

	help = chunk.stack_a;
	while (help->next != NULL)
	{
		if (ft_atoi(help->content) > ft_atoi(help->next->content))
			return (0);
		help = help->next;
	}
	return (1);
}

int	is_sorted(t_chunk chunk)
{
	if (chunk.stack_b != NULL || !stack_a_sorted(chunk))
		return (0);
	if (chunk.stack_b == NULL && stack_a_sorted(chunk))
		return (1);
	return (1);
}
