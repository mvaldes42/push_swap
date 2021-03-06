/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:14:17 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/31 15:34:41 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(int *pile, int pile_len)
{
	int	i;
	int	last;

	if (pile_len >= 2)
	{
		i = pile_len - 1;
		last = pile[i];
		while (i > 0)
		{
			pile[i] = pile[i - 1];
			i--;
		}
		pile[0] = last;
		return (1);
	}
	return (0);
}

int	rotate(int *pile, int pile_len)
{
	int	i;
	int	last;

	if (pile_len >= 2)
	{
		last = pile[0];
		i = 0;
		while (i <= pile_len - 2)
		{
			pile[i] = pile[i + 1];
			i++;
		}
		pile[pile_len - 1] = last;
		return (1);
	}
	return (0);
}

int	push(int *pile_from, int *pile_to, int len_from, int len_to)
{
	int	i;
	int	first_from;

	if (len_from >= 1)
	{
		i = -1;
		first_from = pile_from[0];
		pile_from[0] = pile_from[1];
		while (++i < len_from)
			pile_from[i] = pile_from[i + 1];
		pile_from[len_from] = '\0';
		i = len_to + 1;
		while (--i > 0)
			pile_to[i] = pile_to[i - 1];
		pile_to[0] = first_from;
		return (1);
	}
	return (0);
}

int	swap(int *pile, int len)
{
	int	first;
	int	second;

	if (len >= 2)
	{
		first = pile[0];
		second = pile[1];
		pile[0] = second;
		pile [1] = first;
		return (1);
	}
	return (0);
}
