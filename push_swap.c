/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:13:10 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/20 17:24:55 by mvaldes          ###   ########.fr       */
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

int	isunique(int num, int *pile_a)
{
	while (*pile_a)
	{
		if (*pile_a == num)
			exit_fail();
		pile_a++;
	}
	return (1);
}

int	check_n_parse(t_memory *mem, char **list_origin, int argc)
{
	char		**list_mod;
	long long	i;
	long long	num;

	i = 0;
	mem->pile_a = (int *)malloc(sizeof(int) * argc);
	list_mod = rm_first(list_origin, argc);
	while (list_mod[i])
	{
		if (isnum(list_mod[i]))
			num = ft_atoi(list_mod[i]);
		else
			exit_fail();
		if (i > 0 && (!isunique(num, mem->pile_a)))
			exit_fail();
		mem->pile_a[i] = num;
		printf("%d\n", mem->pile_a[i]);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_memory	mem;

	ft_bzero(&mem, sizeof(mem));
	check_n_parse(&mem, argv, argc);
	exit(EXIT_SUCCESS);
}
