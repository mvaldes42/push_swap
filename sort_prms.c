/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_prms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:09:52 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/31 17:25:47 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_ope(t_memory *mem, int index, int pile_len, char lst_name)
{
	// printf("index : %d, value: %d, (pile_len) = %d\n", index, \
	// mem->pile_a[index], (pile_len));
	if (index < 2)
		exec_n_print(mem, SWAP, lst_name);
	else if (index > (pile_len / 2))
		exec_n_print(mem, REVERSE_ROTATE, lst_name);
	else if (index <= (pile_len / 2))
		exec_n_print(mem, ROTATE, lst_name);
}

void	sort_three_ascend(t_memory *mem, int *pile, char lst_name)
{
	int	one;
	int	two;
	int	three;

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

void	sort_three_descend(t_memory *mem, int *pile, char lst_name)
{
	int	one;
	int	two;
	int	three;

	one = pile[0];
	two = pile[1];
	three = pile[2];
	// printf("one: %d, two: %d, three: %d\n", one, two, three);
	if (one > two && two < three && three > one)
		exec_n_print(mem, REVERSE_ROTATE, lst_name);
	if (one > two && two < three && three < one)
	{
		exec_n_print(mem, REVERSE_ROTATE, lst_name);
		exec_n_print(mem, SWAP, lst_name);
	}
	if (one < two && two > three && three < one)
		exec_n_print(mem, SWAP, lst_name);
	if (one < two && two > three && three > one)
		exec_n_print(mem, ROTATE, lst_name);
	if (one < two && two < three && three > one)
	{
		exec_n_print(mem, SWAP, lst_name);
		exec_n_print(mem, REVERSE_ROTATE, lst_name);
	}
}

void	sort_prms_cmds(t_memory *mem, int *pile_a, int *pile_b)
{
	int	*pile_a_sorted;

	pile_a_sorted = stealth_sort(pile_a, mem->pile_a_len);
	if (!memcmp(pile_a, pile_a_sorted, sizeof(&pile_a_sorted)))
		exit(EXIT_SUCCESS);
	// print_piles(pile_a, pile_a_sorted, mem->pile_a_len, mem->pile_a_len);
	sort_buckets(mem, pile_a_sorted);
	// printf("\n //// NOW SORTING A ////\n");
	sort_lst_a(mem, pile_a);
	// printf("\n //// NOW PUSHING B TO A ////\n");
	push_back_to_a(mem, pile_b);
	// __F_PRINT_LST__;
	// printf("\n\n//COUNT : %d//\n\n", mem->ope_count);
}

void	sort_prms(t_memory *mem)
{
	mem->pile_b = (int *)malloc(sizeof(int) * (mem->nb_prms + 1));
	ft_memset(mem->pile_b, 0, sizeof(int) * (mem->nb_prms + 1));
	// if (mem->nb_prms >= 500)
	// 	mem->degree = 14;
	// else if (mem->nb_prms == 150)
	// 	mem->degree = 8;
	// else if (mem->nb_prms >= 200 && mem->nb_prms < 500)
	// 	mem->degree = 8;
	// else if (mem->nb_prms >= 100 && mem->nb_prms < 200)
	// 	mem->degree = 4;
	// else if (mem->nb_prms <= 50 && mem->nb_prms > 10)
	// 	mem->degree = 4;
	// else if (mem->nb_prms <= 10)
	// 	mem->degree = 2;
	mem->degree = (0.0239011 * mem->nb_prms) + 2.3299;
	// mem->degree = pow(-0.0000125529 * mem->nb_prms, 2) + (0.0305552 * mem->nb_prms) + 1.89533;
	sort_prms_cmds(mem, mem->pile_a, mem->pile_b);
	// printf("mem->nb_prms: %d, mem->degree : %d\n", mem->nb_prms, mem->degree);
	// printf("%d\n", ((int)(0.0239011 * mem->nb_prms) + 2.3299));
}