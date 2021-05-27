/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_prms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:09:52 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/27 16:00:20 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_prms_cmds(t_memory *mem, int *pile_a, int *pile_b)
{
	int	i;
	int	pile_a_len;

	mem->pivot = mem->mid;
	i = 0;
	// 1) tout ce qui est moins que le pivot va en B
	pile_a_len = size_of_array(pile_a);
	while (pile_a_len > mem->nb_prms / 2)
	{
		pile_a_len = size_of_array(pile_a);
		if (pile_a[0] < mem->pivot)
		{
			F_PUSH_A
		}
		else if (pile_a[0] == mem->pivot && pile_a[1] < mem->pivot)
		{
			F_SWAP_A
		}
		if (pile_b[0] < pile_b[1])
		{
			F_ROTATE_B
		}
	}
	while (pile_b[0] != pile_b[1])
	{
		F_PUSH_B
	}
}

void	sort_prms(t_memory *mem)
{
	mem->pile_b = (int *)malloc(sizeof(int) * (mem->nb_prms + 1));
	ft_memset(mem->pile_b, 0, sizeof(int) * (mem->nb_prms + 1));
	mem->avrg = find_average(mem->pile_a, mem->nb_prms);
	mem->mid = find_cls_to_avrg(mem->pile_a, mem->avrg);
	// printf("mem->avrg : %f\n", mem->avrg);
	// printf("mem->mid : %d\n", mem->mid);
	// __F_PRINT_LST__
	sort_prms_cmds(mem, mem->pile_a, mem->pile_b);
}
