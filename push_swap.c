/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:13:10 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/20 16:31:57 by mvaldes          ###   ########.fr       */
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

char	**rm_first(char **list_origin, int argc)
{
	char			**list_mod;
	long long		i;

	i = 0;
	list_mod = (char **)malloc(sizeof(char *) * argc);
	while (list_origin[i + 1])
	{
		list_mod[i] = ft_strdup(list_origin[i + 1]);
		i++;
	}
	return (list_mod);
}

int		checker(char **list_origin, int argc)
{
	char		**list_mod;
	long long	i;
	long long	number;

	i = 0;
	list_mod = rm_first(list_origin, argc);
	while (list_mod[i])
	{
		if (isnum(list_mod[i]))
			number = ft_atoi(list_mod[i]);
		else
			exit_fail();
		i++;
		if (!(number <= INT_MAX && number >= INT_MIN))
			exit_fail();
	}
	return (1);
}

int		main(int argc, char *argv[])
{
	checker(argv, argc);
	exit(EXIT_SUCCESS);
}
