/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:03:27 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/25 15:40:24 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_fail(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

char	isnum(char *c)
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

void	print_array(int *array)
{
	int	i;

	i = -1;
	while (array[++i])
		printf("[%d][%d]\n", i, array[i]);
}

// char	**rm_first(char **list_origin, int argc)
// {
// 	char			**list_mod;
// 	long long		i;

// 	i = 0;
// 	list_mod = (char **)malloc(sizeof(char *) * argc);
// 	while (list_origin[i + 1])
// 	{
// 		list_mod[i] = ft_strdup(list_origin[i + 1]);
// 		i++;
// 	}
// 	return (list_mod);
// }