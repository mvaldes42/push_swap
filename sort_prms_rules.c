/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_prms_rules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 21:54:43 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/30 22:26:35 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	buckets_loop(t_memory *mem, int *pile_a_sort, int i, int j)
{
	int	current;
	int	count;

	count = 0;
	while (count <= mem->nb_prms / mem->degree && mem->pile_a[i])
	{
		// printf("pile_a[%d]= %d && count: %d && max: %d && mem->nb_prms%d\n", i, mem->pile_a[i], count, mem->nb_prms / mem->degree, mem->nb_prms);
		current = mem->pile_a[i];
		if (array_len(mem->pile_a) == 3)
			count += 3;
		else if (mem->pile_a[i] <= pile_a_sort[mem->nb_prms / \
					mem->degree * j - 1])
		{
			// printf("nb inf à pivot\n");
			while (mem->pile_a[0] != current && j < mem->degree)
				find_ope(mem, find_idx(mem->pile_a, current),
					array_len(mem->pile_a), LIST_A);
			exec_n_print(mem, PUSH, LIST_A);
			count++;
			i = 0;
		}
		else
			i++;
	}
}
void	sort_buckets(t_memory *mem, int *pile_a, int *pile_b, int *pile_a_sort)
{
	int	j;
	int	i;
	int	count;

	mem->degree = 2;
	j = 1;
	while (j < mem->degree)
	{
		// printf("pivot_index= ((mem->nb_prms(%d) / degree) * j) - 1: %d, pivot_value= %d\n", mem->nb_prms,((mem->nb_prms / degree) * j) - 1, pile_a_sorted[((mem->nb_prms / degree) * j) - 1]);
		// printf("count : %d\n", count);
		// printf("(mem->nb_prms / degree)) = %d\n", (mem->nb_prms / degree));
		i = 0;
		buckets_loop(mem, pile_a_sort, i, j);
		j++;
	}
}

void	sort_lst_a(t_memory *mem, int *pile_a, int *pile_b)
{
	int	i;
	int	pile_a_ascending;
	int	pile_a_len;
	int	smallest_nb;

	i = 0;
	pile_a_ascending = is_pile_ascend(pile_a);
	pile_a_len = array_len(pile_a);
	// printf("pile_a_ascending= %d\n", pile_a_ascending);
	// __F_PRINT_LST__
	while (!pile_a_ascending)
	{
		pile_a_len = array_len(pile_a);
		if (pile_a_len == 3)
			sort_three_ascend(mem, pile_a, LIST_A);
		else
		{
			smallest_nb = find_smallest_nb(pile_a);
			// printf("smallest: %d\n", smallest_nb);
			find_ope(mem, find_idx(pile_a, smallest_nb), pile_a_len, LIST_A);
			if (pile_a[0] == smallest_nb && pile_a_len != 1)
				exec_n_print(mem, PUSH, LIST_A);
		}
		pile_a_ascending = is_pile_ascend(pile_a);
		i++;
	}
}

void	push_back_to_a(t_memory *mem, int *pile_a, int *pile_b)
{
	int	*pile_nested_sorted;
	int	i;
	int	current;
	int	pile_b_len;

	pile_nested_sorted = stealth_sort(pile_b, array_len(pile_b));
	i = array_len(pile_b) - 1;
	while (pile_b[i])
	{
		current = pile_nested_sorted[i];
		pile_b_len = array_len(pile_b);
		if (pile_b_len == 3)
			sort_three_descend(mem, pile_b, LIST_B);
		while (pile_b[0] != current)
			find_ope(mem, find_idx(pile_b, current), array_len(pile_b), LIST_B);
		exec_n_print(mem, PUSH, LIST_B);
		i--;
	}
}
