/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_prms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:09:52 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/28 19:39:18 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_pile_ascend(int *pile)
{
	int	i;

	i = 0;
	while (pile[i] && pile[i + 1])
	{
		if (pile[i] > pile[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_swap(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// USE A STEALTH SORT TO BE ABLE TO PICK PIVOT CORRECTLY
int	*stealth_sort(int *pile, long size)
{
	int	*pile_sorted;
	int	min_idx;
	int	i;
	int	j;

	i = -1;
	pile_sorted = (int *)malloc(sizeof(int) * (size + 1));
	while (++i < size)
		pile_sorted[i] = pile[i];
	i = 0;
	while (i < size - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < size)
		{
			if (pile_sorted[j] < pile_sorted[min_idx])
				min_idx = j;
			j++;
		}
		ft_swap(&pile_sorted[min_idx], &pile_sorted[i]);
		i++;
	}
	return (pile_sorted);
}

void	faster_move_array_a(t_memory *mem, int *pile_a, int index, int pile_len)
{
	printf("<=== pile_a[0] = %d, pile_len / 2= %d && index: %d\n", pile_a[0], pile_len / 2, index);
	if (index < 2)
		F_SWAP_A
	else if (index > pile_len / 2)
		F_REVERSE_ROTATE_A
	else if (index <= pile_len / 2)
		F_ROTATE_A
}

int	find_my_index(int *list, long num)
{
	int	i;

	i = 0;
	while (list[i] != num)
		i++;
	return (i);
}
//  THE ALGO TO CHOOSE WHAT IS FASTER TO MOVE ITEM INDEX TO POS [0]
void	sort_prms_cmds(t_memory *mem, int *pile_a, int *pile_b)
{
	int	pile_a_len;
	int	pile_a_len_origin;
	int	pile_a_ascending;
	int	*pile_a_sorted;

	(void)mem;
	(void)pile_b;
	// USE A STEALTH SORT TO BE ABLE TO PICK PIVOT CORRECTLY
	// CREATE THE ALGO TO CHOOSE WHAT IS FASTER TO MOVE ITEM INDEX TO POS [0]
	pile_a_len = size_of_array(pile_a);
	pile_a_sorted = stealth_sort(pile_a, pile_a_len);
	while (pile_a[0] != 9)
	{
		int pivot = find_my_index(pile_a, 9);
		pile_a_len = size_of_array(pile_a);
		faster_move_array_a(mem, pile_a, pivot, pile_a_len);
	}
	// print_piles(pile_a, pile_a_sorted);
	// pile_a_len_origin = pile_a_len;
	// pile_a_ascending = is_pile_ascend(pile_a);
	// while (!pile_a_ascending && pile_a_len == pile_a_len_origin)//TANT QUE NOUS N'AVONS PAS TRIE A ET QUE A NE FAIT PAS SA TAILLE DE BASE !!
	// {
	// 	pile_a_ascending = is_pile_ascend(pile_a);
	// 	pile_a_len = size_of_array(pile_a);
	// 	// 1) PRENDRE LE 1ER PIVOT
	// 	// 2) TOUS LES ELEMENTS <= PIVOT VONT EN B EN UTILISANT ALGO DE SELECTION
	// 	// THEORIQUEMENT ? LE PIVOT DOIT ETRE EN B[0]
	// 	// 3) REPETER POUR TOUS LES PIVOTS JUSQU'A L'AVANT DERNIER
	// 	// => if (pivot == 4ème pivot)
	// 	// 4) ON TRIE ALORS A EN UTILISANT ALGO
	// 	// 5) ON RECUPERE LES ELEMENTS UNS A UNS DE B SUR A EN ORDRE AVEC L'ALGO
	// 	exit(EXIT_SUCCESS);
	// }
}

void	sort_prms(t_memory *mem)
{
	mem->pile_b = (int *)malloc(sizeof(int) * (mem->nb_prms + 1));
	ft_memset(mem->pile_b, 0, sizeof(int) * (mem->nb_prms + 1));
	mem->avrg = find_average(mem->pile_a, mem->nb_prms);
	mem->mid = find_cls_to_avrg(mem->pile_a, mem->avrg);
	printf("mem->avrg : %f\n", mem->avrg);
	printf("mem->mid : %d\n", mem->mid);
	__F_PRINT_LST__
	sort_prms_cmds(mem, mem->pile_a, mem->pile_b);
}

// int	pile_is_descending(int *pile)
// {
// 	int	descending;
// 	int	i;

// 	descending = 0;
// 	i = size_of_array(pile);
// 	while (i > 0)
// 	{
// 		if (pile[i] < pile[i - 1])
// 			descending = 1;
// 		else
// 			descending = 0;
// 		i--;
// 	}
// 	return (descending);
// }
