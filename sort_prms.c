/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_prms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:09:52 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/29 22:01:20 by mvaldes          ###   ########.fr       */
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

//  THE ALGO TO CHOOSE WHAT IS FASTER TO MOVE ITEM INDEX TO POS [0]
void	faster_move_array_a(t_memory *mem, int index, int pile_len, char lst_name)
{
	printf("index : %d, value: %d, (pile_len) = %d\n", index, mem->pile_a[index], (pile_len));
	if (index < 2)
		exec_n_print(mem, SWAP, lst_name);
	else if (index > (pile_len / 2))
		exec_n_print(mem, REVERSE_ROTATE, lst_name);
	else if (index <= (pile_len / 2))
		exec_n_print(mem, ROTATE, lst_name);
}

int	find_my_index(int *list, long num)
{
	int	i;

	i = 0;
	while (list[i] != num)
		i++;
	return (i);
}

int	*intdup(int *src)
{
	int 	*p;
	long	len;

	len = size_of_array(src) + 1;
	p = (int*)malloc(len * sizeof(int));
	memcpy(p, src, len * sizeof(int));
	return p;
}
int	find_smallest_nb(int *array)
{
	int	smallest;
	int	i;

	smallest = array[0];
	i = 0;
	while (array[i])
	{
		if (array[i] < smallest)
			smallest = array[i];
		i++;
	}
	return (smallest);
}

void	sort_prms_cmds(t_memory *mem, int *pile_a, int *pile_b)
{
	int	pile_a_len;
	int	pile_a_len_origin;
	int	pile_a_ascending;
	int	*pile_a_sorted;
	int	i;

	// USE A STEALTH SORT TO BE ABLE TO PICK PIVOT CORRECTLY
	// CREATE THE ALGO TO CHOOSE WHAT IS FASTER TO MOVE ITEM INDEX TO POS [0]
	pile_a_len = size_of_array(pile_a);
	pile_a_sorted = stealth_sort(pile_a, pile_a_len);
	print_piles(pile_a, pile_a_sorted);
	int j = 1;
	pile_a_ascending = is_pile_ascend(pile_a);
	// WHILE PIVOT 1 = PILE lEN / 4 OU 8), MOVE ALL < PIVOT TO B
	while (!pile_a_ascending)
	{
		printf("hello\n");
		while (j < 5)
		{
			i = 0;
			pile_a_len = size_of_array(pile_a);
			int pivot_index =  ((mem->nb_prms / 5)) * j;
			int pivot_value = pile_a_sorted[pivot_index];
			int count = 0;
			printf("pivot_index= %d, pivot_value= %d\n", pivot_index, pivot_value);
			printf("mem->nb_prms: %d\n", mem->nb_prms);
			printf("(mem->nb_prms / 4)) = %d\n", (mem->nb_prms / 4));
			while (count <= (mem->nb_prms / 5) && pile_a[i])
			{
				printf("pile_a[%d]= %d\n", i, pile_a[i]);
				pile_a_len = size_of_array(pile_a);
				int current_value = pile_a[i];
				if ( pile_a[i] <= pivot_value) //<= pivot_value)
				{
					printf("nb inf à pivot\n");
					while (pile_a[0] != current_value)//pile_a[i])
					{
						faster_move_array_a(mem, find_my_index(pile_a, current_value), pile_a_len, LIST_A);
						// exit(EXIT_SUCCESS);
					}
					F_PUSH_B
					count++;
					printf("count = %d\n", count);
					i = 0;
					// exit(EXIT_SUCCESS);
				}
				else
					i++;
			}
			j++;
		}
		// WE'VE PUSHED 3/4 OF ALL THE LIST INTO B, ALMOST SORTED INTO BUCKETS
		// NOW, WE'RE SORTING A PROPERLY
		printf("\n NOW SORTING A\n");
		i = 0;
		pile_a_ascending = is_pile_ascend(pile_a);
		int *pile_a_as_now = intdup(pile_a);
		int nb_pushed = 0;
		pile_a_len = size_of_array(pile_a);
		while (!pile_a_ascending && pile_a_len != 1)
		{
			int smallest_nb = find_smallest_nb(pile_a);
			pile_a_len = size_of_array(pile_a);
			printf("smallest: %d\n", smallest_nb);
			faster_move_array_a(mem, find_my_index(pile_a, smallest_nb), pile_a_len, LIST_A);
			if (pile_a[0] == smallest_nb && pile_a_len != 1)
			{
				F_PUSH_B
				nb_pushed++;
			}
			i++;
		}
		printf("nb_pushed: %d\n", nb_pushed);
		while (nb_pushed > 0)
		{
			F_PUSH_A
			printf("nb_pushed: %d\n", nb_pushed);
			nb_pushed--;
		}
		// pile_a_ascending = is_pile_ascend(pile_a);
		exit(EXIT_SUCCESS);
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
