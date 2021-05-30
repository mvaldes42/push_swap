/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:16:56 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/30 22:10:12 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int	find_idx(int *list, long num)
{
	int	i;

	i = 0;
	while (list[i] != num)
		i++;
	return (i);
}

int	array_len(int *pile)
{
	int	i;

	i = 0;
	while (pile[i])
		i++;
	return (i);
}

float	find_average(int *list, int longueur)
{
	int		i;
	int		somme;

	i = 0;
	somme = 0;
	while (i < longueur)
	{
		somme += list[i];
		i++;
	}
	return ((float)somme / (float)longueur);
}

int	find_cls_to_avrg(int *list, float average)
{
	int		i;
	float	diff;
	float	diff_small;
	int		mid;

	i = 1;
	diff = 0;
	diff_small = 0;
	mid = 0;
	diff_small = ft_abs((list[0] - average));
	while (list[i])
	{
		diff = ft_abs((list[i] - average));
		if (diff < diff_small)
		{
			diff_small = diff;
			mid = list[i];
			printf("change... mid: %d & list[i]: %d\n", mid, list[i]);
		}
		printf("list[%d]: %d, average: %f, diff: %f, diff_small: %f, diff < diff_small %d, mid : %d\n", i, list[i], average, diff, diff_small, diff < diff_small, mid);
		i++;
	}
	return (mid);
}
