/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:03:27 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/31 12:04:47 by mvaldes          ###   ########.fr       */
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

float	ft_abs (float i)
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

void	print_piles(int *pile_a, int *pile_b, int a_len, int b_len)
{
	int	i;

	i = 0;
	while (i < a_len || i < b_len)
	{
		printf("[%3d]", i);
		if (i < a_len)
			printf("[%3d]", pile_a[i]);
		else
			printf("[   ]");
		if (i < b_len)
			printf("[%3d]\n", pile_b[i]);
		else
			printf("[   ]\n");
		i++;
	}
	printf("\n");
}
