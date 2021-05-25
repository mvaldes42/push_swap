/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_prms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:09:52 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/25 16:29:52 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_average(t_memory *mem, int *list, int longueur)
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
	mem->avrg = (float)somme / (float)longueur;
}

void	find_cls_to_avrg(t_memory *mem, int *list, float average)
{
	int	i;
	int	diff;
	int	diff_p;

	i = 0;
	diff = 0;
	diff_p = 0;
	while (list[i])
	{
		diff = ft_abs(list[i] / average);
		if (diff < diff_p)
			mem->mid = list[i];
		diff_p = diff;
		i++;
	}
}

void	reverse_rotate(int *pile, char pile_name, int lenght)
{
	int	i;
	int	last;

	i = lenght - 1;
	last = pile[i];
	while (i > 0)
	{
		pile[i] = pile[i - 1];
		i--;
	}
	pile[0] = last;
	printf("rr%c\n", pile_name);
}

void	rotate(int *pile, char pile_name, int lenght)
{
	int	i;
	int	last;

	last = pile[0];
	i = 0;
	while (i <= lenght - 2)
	{
		pile[i] = pile[i + 1];
		i++;
	}
	pile[lenght - 1] = last;
	printf("r%c\n", pile_name);
}

void	sort_prms_cmds(t_memory *mem)
{
	//1) choisir le pivot : mem->mid
	mem->pivot = mem->mid;
	//2) tout ce qui est moins que le pivot, va en (b)
	// Tout ce qui est plus, va en (a)
	// if (mem->pile_a[0] > mem->pivot)
	// 	//move to B
	// else
	// 	//stay in A
	// reverse_rotate(mem->pile_a, 'a', mem->nb_prms);
	rotate(mem->pile_a, 'a', mem->nb_prms);
}

void	sort_prms(t_memory *mem)
{
	print_array(mem->pile_a);
	find_average(mem, mem->pile_a, mem->nb_prms);
	find_cls_to_avrg(mem, mem->pile_a, mem->avrg);
	printf("mem->avrg : %f\n",mem->avrg);
	printf("mem->mid : %d\n", mem->mid);
	sort_prms_cmds(mem);
	print_array(mem->pile_a);
}
