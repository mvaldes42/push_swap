/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_prms_rules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 21:54:43 by mvaldes           #+#    #+#             */
/*   Updated: 2021/06/01 10:07:53 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	buckets_loop(t_memory *mem, int *pile_a_sort, int i, int j)
{
	int	nb_current;
	int	count;
	int	min_nbr;

	count = 0;
	while (i < mem->pile_a_len && count <= mem->nb_prms / mem->degree)
	{
		nb_current = mem->pile_a[i];
		min_nbr = pile_a_sort[mem->nb_prms / mem->degree * j - 1];
		if (mem->pile_a_len == 3)
			count += 3;
		else if (nb_current <= min_nbr)
		{
			while (mem->pile_a[0] != nb_current && j < mem->degree)
			{
				find_ope(mem, find_idx(mem->pile_a, nb_current),
					mem->pile_a_len, LIST_A);
			}
			exec_n_print(mem, PUSH, LIST_A);
			count++;
			i = 0;
		}
		else
			i++;
	}
}

void	sort_buckets(t_memory *mem, int *pile_a_sort)
{
	int	j;
	int	i;

	j = 1;
	while (j < mem->degree && ((mem->nb_prms / mem->degree) * j) - 1 >= 0)
	{
		i = 0;
		buckets_loop(mem, pile_a_sort, i, j);
		j++;
	}
}

void	sort_lst_a(t_memory *mem, int *pile_a)
{
	int	i;
	int	pile_a_ascending;
	int	smallest;

	i = 0;
	pile_a_ascending = is_pile_ascend(pile_a, mem->pile_a_len);
	while (!pile_a_ascending)
	{
		if (mem->pile_a_len == 3)
			sort_three_ascend(mem, pile_a, LIST_A);
		else
		{
			smallest = find_smallest_nb(pile_a, mem->pile_a_len);
			find_ope(mem, find_idx(pile_a, smallest), mem->pile_a_len, LIST_A);
			if (pile_a[0] == smallest && mem->pile_a_len > 2)
				exec_n_print(mem, PUSH, LIST_A);
		}
		pile_a_ascending = is_pile_ascend(pile_a, mem->pile_a_len);
		i++;
	}
}

void	push_back_to_a(t_memory *mem, int *pile_b)
{
	int	*pile_nested_sorted;
	int	i;
	int	current;

	pile_nested_sorted = stealth_sort(pile_b, mem->pile_b_len);
	i = mem->pile_b_len - 1;
	while (mem->pile_b_len > 0)
	{
		current = pile_nested_sorted[i];
		if (mem->pile_b_len == 3)
			sort_three_descend(mem, pile_b, LIST_B);
		while (pile_b[0] != current)
			find_ope(mem, find_idx(pile_b, current), mem->pile_b_len, LIST_B);
		exec_n_print(mem, PUSH, LIST_B);
		i--;
	}
}
