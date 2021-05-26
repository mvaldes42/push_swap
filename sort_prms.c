/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_prms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:09:52 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/26 15:10:59 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_prms_cmds(t_memory *mem)
{
	mem->pivot = mem->mid;
	print_piles(mem->pile_a, mem->pile_b);
	exec_n_print(mem, "swap", 'a');
	print_piles(mem->pile_a, mem->pile_b);
	exec_n_print(mem, "push", 'a');
	print_piles(mem->pile_a, mem->pile_b);
	exec_n_print(mem, "push", 'a');
	print_piles(mem->pile_a, mem->pile_b);
	exec_n_print(mem, "push", 'a');
	print_piles(mem->pile_a, mem->pile_b);
	exec_n_print(mem, "push", 'b');
	print_piles(mem->pile_a, mem->pile_b);
	exec_n_print(mem, "swap", 'b');
	print_piles(mem->pile_a, mem->pile_b);
	exec_n_print(mem, "swap", '0');
	print_piles(mem->pile_a, mem->pile_b);
	exec_n_print(mem, "reverse_rr", '0');
	print_piles(mem->pile_a, mem->pile_b);
}

void	sort_prms(t_memory *mem)
{
	mem->pile_b = (int *)malloc(sizeof(int) * mem->nb_prms);
	mem->avrg = find_average(mem->pile_a, mem->nb_prms);
	mem->mid = find_cls_to_avrg(mem->pile_a, mem->avrg);
	printf("mem->avrg : %f\n", mem->avrg);
	printf("mem->mid : %d\n", mem->mid);
	sort_prms_cmds(mem);
}
