/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:03:27 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/26 10:53:40 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_fail(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	isnum(char *c)
{
	while (*c)
	{
		if (*c >= '0' && *c <= '9')
			c++;
		else
			exit_fail();
	}
	return (1);
}

int	ft_abs (int i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

int	word_count(const char *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	if (count == 0)
		exit_fail();
	return (count);
}

void	print_piles(int *pile_a, int *pile_b)
{
	int	i;

	i = 0;
	while (pile_a[i] || pile_b[i])
	{
		printf("[%3d]", i);
		if (pile_a[i])
			printf("[%3d]", pile_a[i]);
		else
			printf("[...]");
		if (pile_b[i])
			printf("[%3d]\n", pile_b[i]);
		else
			printf("[...]\n");
		i++;
	}
	printf("\n");
}
