/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:16:56 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/26 10:52:24 by mvaldes          ###   ########.fr       */
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
	int	i;
	int	diff;
	int	diff_p;
	int	mid;

	i = 0;
	diff = 0;
	diff_p = 0;
	mid = 0;
	while (list[i])
	{
		diff = ft_abs(list[i] / average);
		if (diff < diff_p)
			mid = list[i];
		diff_p = diff;
		i++;
	}
	return (mid);
}
