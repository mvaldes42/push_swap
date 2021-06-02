/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 21:49:48 by mvaldes           #+#    #+#             */
/*   Updated: 2021/06/02 12:26:07 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_pile_ascend(int *pile, int len)
{
	int	i;

	i = 0;
	while (i < len && i + 1 < len)
	{
		if (pile[i] > pile[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	**stealth_sort(int *pile, long size)
{
	static int	*pile_sorted;
	int			min_idx;
	int			i;
	int			j;

	i = -1;
	pile_sorted = (int *)malloc(sizeof(int) * (size + 1));
	ft_bzero(pile_sorted, sizeof(int) * (size + 1));
	while (++i < size)
		pile_sorted[i] = pile[i];
	i = 0;
	while (i < size - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < size)
		{
			if (pile_sorted[j] < pile_sorted[min_idx])
				min_idx = j;
			j++;
		}
		ft_swap(&pile_sorted[min_idx], &pile_sorted[i]);
		i++;
	}
	return (&pile_sorted);
}

int	*int_array_dup(int *src, int array_len)
{
	int	*p;
	int	len;

	len = array_len + 1;
	p = (int *)malloc(len * sizeof(int));
	ft_memcpy(p, src, len * sizeof(int));
	return (p);
}

int	find_smallest_nb(int *array, int len)
{
	int	smallest;
	int	i;

	smallest = array[0];
	i = 0;
	while (i < len)
	{
		if (array[i] < smallest)
			smallest = array[i];
		i++;
	}
	return (smallest);
}

void	exit_success(t_memory *mem)
{
	free(mem->pile_b);
	free(mem->pile_a);
	free(mem->prms_mod);
	exit(EXIT_SUCCESS);
}
