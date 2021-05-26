/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_prms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:09:52 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/26 16:27:00 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_prms_cmds(t_memory *mem, int *pile_a, int *pile_b)
{
	int i;

	mem->pivot = mem->mid;
	i = 0;
	// 1) tout ce qui est moins que le pivot va en B
	while (pile_a[i] <= mem->pivot)
	{
		F_PUSH_A
		i++;
		printf("pile_a[i]: %d, mem->pivot: %d\n", pile_a[i],mem->pivot);
		if (pile_a[i] == mem->pivot)
			F_REVERSE_ROTATE_A
	}
	// while (pile_b[0] != pile_b[1])
	// {

	// }
	// F_SWAP_A
	// F_PUSH_A
	// F_PUSH_A
	// F_PUSH_A
	// F_PUSH_B
	// F_SWAP_B
	// F_SWAP_ALL
	// F_REVERSE_ROTATE_ALL
}

void	sort_prms(t_memory *mem)
{
	mem->pile_b = (int *)malloc(sizeof(int) * mem->nb_prms);
	mem->avrg = find_average(mem->pile_a, mem->nb_prms);
	mem->mid = find_cls_to_avrg(mem->pile_a, mem->avrg);
	printf("mem->avrg : %f\n", mem->avrg);
	printf("mem->mid : %d\n", mem->mid);
	__F_PRINT_LST__
	sort_prms_cmds(mem, mem->pile_a, mem->pile_b);
}
