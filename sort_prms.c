/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_prms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:09:52 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/28 16:26:15 by mvaldes          ###   ########.fr       */
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
	int	pile_b_len;
	int	pile_a_ascending;
	int	pile_b_ascending;

	mem->pivot = mem->mid;
	pile_a_len = size_of_array(pile_a);
	pile_a_ascending = pile_is_ascending(pile_a);
	pile_b_len = size_of_array(pile_b);
	while (!pile_a_ascending)
	{
		pile_a_len = size_of_array(pile_a) - 1;
		pile_b_len = size_of_array(pile_b);
		pile_a_ascending = pile_is_ascending(pile_a);
		// printf("ascending: %d\n", pile_a_ascending);
		if (pile_a[0] < mem->pivot)//SI LE HAUT DE LA PILE A EST INF AU PIVOT
		{
			printf("pile_a[0] < mem->pivot\n");
			if (pile_a[0] > pile_b[0])// SI LE HAUT DE LA PILE A > HAUT DE LA PILE B
				F_PUSH_B// ALORS IL PASSE SUR LE PILE B
			else
			{
				// printf("hello\n");
				F_PUSH_A
				F_SWAP_A
				F_PUSH_B
			}
		}
		//
		else if (pile_a[0] == mem->pivot && pile_a[1] < mem->pivot)// SI LE HAUT DE LA PILE A = PIVOT ET QUE LE 2EME DE A < PIVOT
		{
			printf("pile_a[0] == mem->pivot && pile_a[1] < mem->pivot\n");
			F_SWAP_A
		}
		//
		// else if (pile_a[0] > mem->pivot && pile_a[1] == mem->pivot && pile_a[pile_a_len] < mem->pivot// SI LE HAUT DE LA PILE A > PIVOT ET QUE LE DEUXIEME DE A
		// && pile_a[pile_a_len] != mem->pivot)////////////////////////////////////////////////////////// EST LE PIVOT ????????
		// {
		// 	F_REVERSE_ROTATE_A
		// 	if (pile_a[0] > pile_b[0] && pile_a[0] > mem->pivot)
		// 		F_PUSH_B
		// 	else
		// 	{
		// 		// printf("hello\n");
		// 		F_PUSH_A
		// 		F_SWAP_A
		// 		if (pile_a[0] > pile_b[0] && pile_a[0] > mem->pivot)
		// 			F_PUSH_B
		// 	}
		// }
		else if (pile_a[0] > mem->pivot && pile_a_len < 2)// SI LE HAUT DE LA PILE A > AU PIVOT ET QUE A N'A QUE 2 ELEM
			F_SWAP_A
		else if (pile_a_len == mem->nb_prms / 2)// WHEN IT'S TIME TO ORDER A
		{
			//MAKE REST OF THE PILE IN ASCENDING ORDER BUT THIS TIME WITH VALUES > PIVOT
			printf("pile separated\n");
			// mem->pivot = find_largest_nbr(pile_a);
			mem->pivot = 73;
			// exit(EXIT_SUCCESS);
		}
		else if (pile_a[0] > mem->pivot)// SI LE HAUT DE LA PILE A > PIVOT ET QUE LE DEUX < PREMIER (&& pile_a[1] < pile_a[0])
		{
			printf("pile_a[0] > mem->pivot\n");
			F_SWAP_A
			if (pile_a[0] < mem->pivot)
			{
				F_PUSH_B
			}
			else
			{
				printf("!! pile_a[0] > mem->pivot\n");
				F_ROTATE_A
			}
		}
		// if (pile_b[0] < pile_b[1])
		// {
		// 	F_ROTATE_B
		// }
	}
	printf("A triée\n");
	// //////////
	// pile_b_ascending = pile_is_ascending(pile_b);
	// while (!pile_b_ascending)
	// {
	// 	pile_b_len = size_of_array(pile_b) - 1;
	// 	pile_b_ascending = pile_is_ascending(pile_b);
	// 	printf("ascending: %d\n", pile_a_ascending);
	// 	if (pile_b[0] < mem->pivot)
	// 	{
	// 		if (pile_a[0] > pile_b[0])
	// 			F_PUSH_B
	// 		else
	// 		{
	// 			printf("hello\n");
	// 			F_PUSH_A
	// 			F_SWAP_A
	// 			F_PUSH_B
	// 		}
	// 	}
	// 	else if (pile_a[0] == mem->pivot && pile_a[1] < mem->pivot)
	// 	{
	// 		F_SWAP_A
	// 	}
	// 	else if (pile_a[0] > mem->pivot && pile_a[1] == mem->pivot && pile_a[pile_a_len] < mem->pivot
	// 	&& pile_a[pile_a_len] != mem->pivot)
	// 	{
	// 		F_REVERSE_ROTATE_A
	// 		if (pile_a[0] > pile_b[0])
	// 			F_PUSH_B
	// 		else
	// 		{
	// 			printf("hello\n");
	// 			F_PUSH_A
	// 			F_SWAP_A
	// 			F_PUSH_B
	// 		}
	// 	}
	// 	else if (pile_a[0] > mem->pivot && pile_a_len < 2)
	// 		F_SWAP_A
	// 	if (pile_b[0] < pile_b[1])
	// 	{
	// 		F_ROTATE_B
	// 	}
	// }
	// ///////
	while (pile_b[0] != pile_b[1])
	{
		F_PUSH_A
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
