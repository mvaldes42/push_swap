/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_prms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:09:52 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/28 18:26:43 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pile_is_ascending(int *pile)
{
	int	i;

	i = 0;
	while (pile[i] && pile[i + 1])
	{
		if (pile[i] < pile[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int	pile_is_descending(int *pile)
{
	int	descending;
	int	i;

	descending = 0;
	i = size_of_array(pile);
	while (i > 0)
	{
		if (pile[i] < pile[i - 1])
			descending = 1;
		else
			descending = 0;
		i--;
	}
	return (descending);
}

void	sort_prms_cmds(t_memory *mem, int *pile_a, int *pile_b)
{
	int	pile_a_len;
	int	pile_a_len_origin;
	int	pile_a_ascending;

	pile_a_len = size_of_array(pile_a);
	pile_a_len_origin = pile_a_len;
	pile_a_ascending = pile_is_ascending(pile_a);
	while (!pile_a_ascending && pile_a_len == pile_a_len_origin)//TANT QUE NOUS N'AVONS PAS TRIE A ET QUE A NE FAIT PAS SA TAILLE DE BASE !!
	{
		pile_a_ascending = pile_is_ascending(pile_a);
		pile_a_len = size_of_array(pile_a);
		// 1) PRENDRE LE 1ER PIVOT
		// 2) TOUS LES ELEMENTS <= PIVOT VONT EN B EN UTILISANT ALGO DE SELECTION
		// THEORIQUEMENT ? LE PIVOT DOIT ETRE EN B[0]
		// 3) REPETER POUR TOUS LES PIVOTS JUSQU'A L'AVANT DERNIER
		// => if (pivot == 4ème pivot)
		// 4) ON TRIE ALORS A EN UTILISANT ALGO
		// 5) ON RECUPERE LES ELEMENTS UNS A UNS DE B SUR A EN ORDRE AVEC L'ALGO
		exit(EXIT_SUCCESS);
	}
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
