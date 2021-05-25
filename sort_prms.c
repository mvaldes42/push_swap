/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_prms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:09:52 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/25 17:52:02 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_of_array(int *pile)
{
	int	i;

	i = 0;
	while (pile[i])
		i++;
	return (i);
}

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

void	reverse_rotate(int *pile, char pile_name)
{
	int	i;
	int	last;
	int	lenght;

	lenght = size_of_array(pile);
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

void	rotate(int *pile, char pile_name)
{
	int	i;
	int	last;
	int	lenght;

	lenght = size_of_array(pile);
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

void	push(int *pile_from, int *pile_to, char to)
{
	int	i;
	int	first_from;
	int	lenght_from;

	if (pile_from[0])
	{
		i = -1;
		first_from = pile_from[0];
		lenght_from = size_of_array(pile_from);
		pile_from[0] = pile_from[1];
		while (++i < lenght_from)
			pile_from[i] = pile_from[i + 1];
		pile_from[lenght_from] = '\0';
		i = size_of_array(pile_to) + 1;
		while (--i > 0)
			pile_to[i] = pile_to[i - 1];
		pile_to[0] = first_from;
		printf("p%c\n", to);
	}
}

void	swap(int *pile, char pile_name)
{
	int	first;
	int	second;

	if (pile[0] && pile[1])
	{
		first = pile[0];
		second = pile[1];
		pile[0] = second;
		pile [1] = first;
		printf("s%c\n", pile_name);
	}
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
	rotate(mem->pile_a, 'a');
	print_piles(mem);
	push(mem->pile_a, mem->pile_b, 'b');
	print_piles(mem);
	push(mem->pile_a, mem->pile_b, 'b');
	print_piles(mem);
	rotate(mem->pile_a, 'b');
	print_piles(mem);
	reverse_rotate(mem->pile_a, 'a');
	print_piles(mem);
	swap(mem->pile_a, 'a');
	print_piles(mem);
}

void	sort_prms(t_memory *mem)
{
	mem->pile_b = (int *)malloc(sizeof(int) * mem->nb_prms);
	ft_memset(mem->pile_b, 0, mem->nb_prms);
	find_average(mem, mem->pile_a, mem->nb_prms);
	find_cls_to_avrg(mem, mem->pile_a, mem->avrg);
	printf("mem->avrg : %f\n",mem->avrg);
	printf("mem->mid : %d\n", mem->mid);
	print_piles(mem);
	sort_prms_cmds(mem);
}
