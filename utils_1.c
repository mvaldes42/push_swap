/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:16:56 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/26 16:19:50 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_of_array(int *pile)
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
	diff_small = ft_abs((list[0] / average));
	while (list[i])
	{
		diff = ft_abs((list[i] / average));
		if (ft_abs(diff - 1) < ft_abs(diff_small - 1))
			mid = list[i];
		i++;
	}
	return (mid);
}
