/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:14:17 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/30 22:19:47 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(int *pile)
{
	int	i;
	int	last;
	int	lenght;

	if (pile[0] && pile[1] && (pile[0] != pile[1]))
	{
		lenght = array_len(pile);
		i = lenght - 1;
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

int	rotate(int *pile)
{
	int	i;
	int	last;
	int	lenght;

	if (pile[0] && pile[1] && (pile[0] != pile[1]))
	{
		lenght = array_len(pile);
		last = pile[0];
		i = 0;
		while (i <= lenght - 2)
		{
			pile[i] = pile[i + 1];
			i++;
		}
		pile[lenght - 1] = last;
		return (1);
	}
	return (0);
}

int	push(int *pile_from, int *pile_to)
{
	int	i;
	int	first_from;
	int	lenght_from;

	if (pile_from[0])
	{
		i = -1;
		first_from = pile_from[0];
		lenght_from = array_len(pile_from);
		pile_from[0] = pile_from[1];
		while (++i < lenght_from)
			pile_from[i] = pile_from[i + 1];
		pile_from[lenght_from] = '\0';
		i = array_len(pile_to) + 1;
		while (--i > 0)
			pile_to[i] = pile_to[i - 1];
		pile_to[0] = first_from;
		return (1);
	}
	return (0);
}

int	swap(int *pile)
{
	int	first;
	int	second;

	if (pile[0] && pile[1] && (pile[0] != pile[1]))
	{
		first = pile[0];
		second = pile[1];
		pile[0] = second;
		pile [1] = first;
		return (1);
	}
	return (0);
}
