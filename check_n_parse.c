/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_n_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:35:08 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/25 15:00:08 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	count_size_prms(t_memory *mem, char **list_origin)
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

char	*concatenate_args(t_memory *mem, char **list_origin)
{
	int		i;
	int		j;
	int		k;
	char	*concatenated;

	i = 1;
	count_size_prms(mem, list_origin);
	concatenated = (char *)malloc(sizeof(char *) * mem->size_spc);
	i = 0;
	k = 0;
	while (list_origin[++i])
	{
		j = -1;
		while (list_origin[i][++j])
			concatenated[k++] = list_origin[i][j];
		concatenated[k++] = ' ';
	}
	printf("params with spaces : %d\n", mem->size_spc);
	printf("conca : %s\n", concatenated);
	return (concatenated);
}

static int		word_count(const char *s, char c)
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

int	check_n_parse(t_memory *mem, char **list_origin, int argc)
{
	long long	i;
	long long	num;

	mem->prms = concatenate_args(mem, list_origin);
	mem->nb_prms = word_count(mem->prms, ' ');
	printf("wcont : %d\n", mem->nb_prms);
	mem->pile_a = (int *)malloc(sizeof(int) * mem->nb_prms);
	mem->prms_mod = ft_split(mem->prms, ' ');
	i = 0;
	while (mem->prms_mod[i])
	{
		if (isnum(mem->prms_mod[i]))
			num = ft_atoi(mem->prms_mod[i]);
		else
			exit_fail();
		if (!(num <= INT_MAX && num >= INT_MIN) || \
		(i > 0 && (!isunique(num, mem->pile_a))))
			exit_fail();
		mem->pile_a[i] = num;
		printf("%d\n", mem->pile_a[i]);
		i++;
	}
	return (1);
}
