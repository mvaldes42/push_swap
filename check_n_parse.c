/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:35:08 by mvaldes           #+#    #+#             */
/*   Updated: 2021/06/01 10:05:41 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	isunique(int num, int *pile_a, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (pile_a[i] == num)
			return (0);
		i++;
	}
	return (1);
}

static void	count_size_prms(t_memory *mem, char **list_origin)
{
	int	i;
	int	j;

	i = 1;
	while (list_origin[i])
	{
		j = 0;
		while (list_origin[i][j])
		{
			j++;
			mem->size_spc++;
		}
		i++;
		mem->size_spc++;
	}
}

static char	*concatenate_args(t_memory *mem, char **list_origin)
{
	int		i;
	int		j;
	int		k;
	char	*concatenated;

	i = 1;
	count_size_prms(mem, list_origin);
	concatenated = (char *)malloc(sizeof(char *) * (mem->size_spc + 1));
	ft_bzero(concatenated, sizeof(char *) * (mem->size_spc + 1));
	i = 0;
	k = 0;
	while (list_origin[++i])
	{
		j = -1;
		while (list_origin[i][++j])
			concatenated[k++] = list_origin[i][j];
		concatenated[k++] = ' ';
	}
	return (concatenated);
}

void	check_n_parse(t_memory *mem, char **list_origin)
{
	long long	i;
	long long	num;

	mem->prms = concatenate_args(mem, list_origin);
	mem->nb_prms = word_count(mem->prms, ' ');
	if (mem->nb_prms < 2)
		exit_success(mem);
	mem->pile_a = (int *)malloc(sizeof(int) * (mem->nb_prms + 1));
	ft_memset(mem->pile_a, '\0', sizeof(int) * (mem->nb_prms + 1));
	mem->prms_mod = ft_split(mem->prms, ' ');
	i = 0;
	while (mem->prms_mod[i])
	{
		if (isnum(mem->prms_mod[i]))
			num = ft_atoi(mem->prms_mod[i]);
		else
			exit_fail(mem);
		if (!(num <= INT_MAX && num >= INT_MIN) || \
		(i > 0 && (!isunique(num, mem->pile_a, mem->pile_a_len))))
			exit_fail(mem);
		mem->pile_a[i] = num;
		mem->pile_a_len++;
		i++;
	}
}
