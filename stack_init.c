/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:13:55 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/27 14:27:31 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	*reverse(int *ptr)
{
	int	in;
	int	end;
	int	len;
	int	aux;

	in = 0;
	end = 0;
	while (ptr[end] != '\0')
		end++;
	end = end - 1;
	len = end;
	while (in <= len / 2)
	{
		aux = ptr[in];
		ptr[in] = ptr[end];
		ptr[end] = aux;
		in++;
		end--;
	}
	return (ptr);
}

int	*ordering(int *order, int pos, int n, int argc)
{
	int	aux;
	int	place;

	place = 0;
	aux = -2147483648;
	while (place < argc)
	{
		while (n < argc)
		{
			if (order[n] > aux)
			{
				aux = order[n];
				pos = n;
			}
			n++;
		}
		order[pos] = order[place];
		order[place] = aux;
		place++;
		n = place;
		aux = -2147483648;
	}
	order = reverse(order);
	return (order);
}

t_chunk	order_nums(t_chunk chunk)
{
	int	n;
	int	pos;
	int	*nums;

	n = 0;
	nums = NULL;
	nums = char_to_int(chunk.num_arr);
	pos = 0;
	nums = ordering(nums, pos, n, chunk.argcs);
	chunk.average = nums[chunk.argcs/2 - 1];
	chunk.arr_ordered = int_to_char(nums);
	free(nums);
	return (chunk);
}

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
	free_matrix(val);
	return (values);
}

t_chunk	stack_init(t_chunk chunk)
{
	int		n;
	t_list	*nodo;

	n = 0;
	chunk.stack_a = ft_lstnew(chunk.num_arr[n]);
	n++;
	while (n < chunk.argcs)
	{
		nodo = ft_lstnew(chunk.num_arr[n]);
		ft_lstadd_back(&chunk.stack_a, nodo);
		n++;
	}
	free(nodo);
	chunk.stack_b = NULL;
	return (chunk);
}

