/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_n_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:33:44 by mvaldes           #+#    #+#             */
/*   Updated: 2021/06/01 08:33:50 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exec_n_print_swap(t_memory *mem, int *pile_a, int *pile_b, char c)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if ((c == LIST_A || c == BOTH_LST) && swap(pile_a, mem->pile_a_len))
		a = 1;
	if ((c == LIST_B || c == BOTH_LST) && swap(pile_b, mem->pile_b_len))
		b = 1;
	if (a && b)
		printf(SWAP_ALL);
	else if (a)
		printf(SWAP_A);
	else if (b)
		printf(SWAP_B);
	return (1);
}

static int	exec_n_print_push(t_memory *mem, int *pile_a, int *pile_b, char c)
{
	if (c == LIST_A && push(pile_a, pile_b, mem->pile_a_len, mem->pile_b_len))
	{
		mem->pile_a_len -= 1;
		mem->pile_b_len += 1;
		printf(PUSH_B);
	}
	else if (push(pile_b, pile_a, mem->pile_b_len, mem->pile_a_len))
	{
		mem->pile_b_len -= 1;
		mem->pile_a_len += 1;
		printf(PUSH_A);
	}
	return (1);
}

static int	exec_n_print_reverse_rotate(t_memory *mem, int *pile_a, int *pile_b, char c)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if ((c == LIST_A || c == BOTH_LST) && reverse_rotate(pile_a, mem->pile_a_len))
		a = 1;
	if ((c == LIST_B || c == BOTH_LST) && reverse_rotate(pile_b, mem->pile_b_len))
		b = 1;
	if (a && b)
		printf(REVERSE_ROTATE_ALL);
	else if (a)
		printf(REVERSE_ROTATE_A);
	else if (b)
		printf(REVERSE_ROTATE_B);
	return (1);
}

static int	exec_n_print_rotate(t_memory *mem, int *pile_a, int *pile_b, char c)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if ((c == LIST_A || c == BOTH_LST) && rotate(pile_a, mem->pile_a_len))
		a = 1;
	if ((c == LIST_B || c == BOTH_LST) && rotate(pile_b, mem->pile_b_len))
		b = 1;
	if (a && b)
		printf("rr\n");
	else if (a)
		printf("ra\n");
	else if (b)
		printf("rb\n");
	return (1);
}

void	exec_n_print(t_memory *mem, char *operation, char pile_n)
{
	int	length;

	length = ft_strlen(operation);
	if (ft_strncmp(operation, SWAP, length) == 0)
		exec_n_print_swap(mem, mem->pile_a, mem->pile_b, pile_n);
	else if (ft_strncmp(operation, PUSH, length) == 0)
		exec_n_print_push(mem, mem->pile_a, mem->pile_b, pile_n);
	else if (ft_strncmp(operation, REVERSE_ROTATE, length) == 0)
		exec_n_print_reverse_rotate(mem, mem->pile_a, mem->pile_b, pile_n);
	else if (ft_strncmp(operation, ROTATE, length) == 0)
		exec_n_print_rotate(mem, mem->pile_a, mem->pile_b, pile_n);
	mem->ope_count++;
	__F_PRINT_LST__
}
