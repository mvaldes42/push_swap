/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_prms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:09:52 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/30 11:03:24 by mvaldes          ###   ########.fr       */
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

void	three_nbrs_case_ascen(t_memory *mem, int *pile, char lst_name)
{
	int one;
	int two;
	int three;

	one = pile[0];
	two = pile[1];
	three = pile[2];
	if (one > two && two < three && three > one)
		exec_n_print(mem, SWAP, lst_name);
	if (one > two && two < three && three < one)
		exec_n_print(mem, ROTATE, lst_name);
	if (one < two && two > three && three < one)
		exec_n_print(mem, REVERSE_ROTATE, lst_name);
	if (one > two && two > three && three < one)
	{
		exec_n_print(mem, SWAP, lst_name);
		exec_n_print(mem, REVERSE_ROTATE, lst_name);
	}
	if (one < two && two > three && three > one)
	{
		exec_n_print(mem, SWAP, lst_name);
		exec_n_print(mem, ROTATE, lst_name);
	}
}

void	three_nbrs_case_desc(t_memory *mem, int *pile, char lst_name)
{
	int one;
	int two;
	int three;

	one = pile[0];
	two = pile[1];
	three = pile[2];
	if (one > two && two < three && three > one)//1)
		exec_n_print(mem, REVERSE_ROTATE, lst_name);
	if (one > two && two < three && three < one)//3)
	{
		exec_n_print(mem, REVERSE_ROTATE, lst_name);
		exec_n_print(mem, SWAP, lst_name);
	}
	if (one < two && two > three && three < one)//5)
		exec_n_print(mem, SWAP, lst_name);
	if (one < two && two > three && three > one)//4)
		exec_n_print(mem, ROTATE, lst_name);
	if (one < two && two < three && three > one)
	{
		exec_n_print(mem, SWAP, lst_name);
		exec_n_print(mem, REVERSE_ROTATE, lst_name);
	}
}

void	sort_large_nbr_first(t_memory *mem, int *pile_a, int *pile_b, int *pile_a_sorted)
{
	int	j;
	int	i;
	int	count;
	int current_value;

	j = 1;
	while (j < 4)
	{
		i = 0;
		count = 0;
		printf("pivot_index= ((mem->nb_prms(%d) / 4) * j) - 1: %d, pivot_value= %d\n", mem->nb_prms,((mem->nb_prms / 4) * j) - 1, pile_a_sorted[((mem->nb_prms / 4) * j) - 1]);
		printf("mem->nb_prms: %d\n", mem->nb_prms);
		printf("(mem->nb_prms / 4)) = %d\n", (mem->nb_prms / 4));
		while (count <= mem->nb_prms / 4  && pile_a[i])
		{
			printf("pile_a[%d]= %d && count: %d && max: %d && mem->nb_prms%d\n", i, pile_a[i], count, mem->nb_prms / 4, mem->nb_prms);
			current_value = pile_a[i];
			if ( pile_a[i] <= pile_a_sorted[((mem->nb_prms / 4) * j) - 1]) //<= pivot_value)
			{
				printf("nb inf à pivot\n");
				while (pile_a[0] != current_value)//pile_a[i])
					faster_move_array_a(mem, find_my_index(pile_a, current_value), size_of_array(pile_a), LIST_A);
				F_PUSH_B
				count++;
				i = 0;
				printf("count : %d\n", count);
			}
			else
				i++;
		}
		j++;
	}
}

void	sort_large_nbr_second(t_memory *mem, int *pile_a, int *pile_b)
{
	int	i;
	int	pile_a_ascending;
	int	pile_a_len;
	int	smallest_nb;

	i = 0;
	pile_a_ascending = is_pile_ascend(pile_a);
	pile_a_len = size_of_array(pile_a);
	printf("pile_a_ascending= %d\n", pile_a_ascending);
	__F_PRINT_LST__
	while (!pile_a_ascending)
	{
		pile_a_len = size_of_array(pile_a);
		if (pile_a_len == 3)
			three_nbrs_case_ascen(mem, pile_a, LIST_A);
		else
		{
			smallest_nb = find_smallest_nb(pile_a);
			printf("smallest: %d\n", smallest_nb);
			faster_move_array_a(mem, find_my_index(pile_a, smallest_nb), pile_a_len, LIST_A);
			if (pile_a[0] == smallest_nb && pile_a_len != 1)
				F_PUSH_B
		}
		pile_a_ascending = is_pile_ascend(pile_a);
		i++;
	}
}

void	sort_large_nbr_third(t_memory *mem, int *pile_a, int *pile_b)
{
	int	*pile_nested_sorted;
	int	i;
	int	current_value;
	int	pile_b_len;

	pile_nested_sorted = stealth_sort(pile_b, size_of_array(pile_b));
	printf("pile b sorted = \n");
	print_piles(pile_b, pile_nested_sorted);
	i = size_of_array(pile_b) - 1;
	while(pile_b[i])
	{
		current_value = pile_nested_sorted[i];
		pile_b_len = size_of_array(pile_b);
		if (pile_b_len == 3)
			three_nbrs_case_desc(mem, pile_b, LIST_B);
		while (pile_b[0] != current_value)
			faster_move_array_a(mem, find_my_index(pile_b, current_value), size_of_array(pile_b), LIST_B);
		F_PUSH_A
		i--;
	}
}

void	sort_prms_cmds(t_memory *mem, int *pile_a, int *pile_b)
{
	int	pile_a_len;
	int	*pile_a_sorted;
	int	i;

	pile_a_len = size_of_array(pile_a);
	pile_a_sorted = stealth_sort(pile_a, pile_a_len);
	print_piles(pile_a, pile_a_sorted);
	sort_large_nbr_first(mem, pile_a, pile_b, pile_a_sorted);
	printf("\n //// NOW SORTING A ////\n");
	sort_large_nbr_second(mem, pile_a, pile_b);
	printf("\n //// NOW PUSHING B TO A ////\n");
	sort_large_nbr_third(mem, pile_a, pile_b);
	printf("\n\n//COUNT : %d//\n\n", mem->ope_count);
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
