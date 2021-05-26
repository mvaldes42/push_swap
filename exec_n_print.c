/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_n_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:33:44 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/26 15:09:58 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exec_swap(int *pile_a, int *pile_b, char c)
{
	int	ope_a_worked;
	int	ope_b_worked;

	ope_a_worked = 0;
	ope_b_worked = 0;
	if ((c == 'a' || c == '0') && swap(pile_a))
		ope_a_worked = 1;
	if ((c == 'b' || c == '0') && swap(pile_b))
		ope_b_worked = 1;
	if (ope_a_worked && ope_b_worked)
		printf("ss\n");
	else if (ope_a_worked)
		printf("sa\n");
	else if (ope_b_worked)
		printf("sb\n");
	return (1);
}

int	exec_push(int *pile_a, int *pile_b, char c)
{
	if (c == 'a' && push(pile_a, pile_b))
		printf("pa\n");
	else if (push(pile_b, pile_a))
		printf("pb\n");
	return (1);
}

int	exec_reverse_rotate(int *pile_a, int *pile_b, char c)
{
	int	ope_a_worked;
	int	ope_b_worked;

	ope_a_worked = 0;
	ope_b_worked = 0;
	if ((c == 'a' || c == '0') && reverse_rotate(pile_a))
		ope_a_worked = 1;
	if ((c == 'b' || c == '0') && reverse_rotate(pile_b))
		ope_b_worked = 1;
	if (ope_a_worked && ope_b_worked)
		printf("rrr\n");
	else if (ope_a_worked)
		printf("rra\n");
	else if (ope_b_worked)
		printf("rrb\n");
	return (1);
}

int	exec_rotate(int *pile_a, int *pile_b, char c)
{
	int	ope_a_worked;
	int	ope_b_worked;

	ope_a_worked = 0;
	ope_b_worked = 0;
	if ((c == 'a' || c == '0') && rotate(pile_a))
		ope_a_worked = 1;
	if ((c == 'b' || c == '0') && rotate(pile_b))
		ope_b_worked = 1;
	if (ope_a_worked && ope_b_worked)
		printf("rr\n");
	else if (ope_a_worked)
		printf("ra\n");
	else if (ope_b_worked)
		printf("rb\n");
	return (1);
}

void	exec_n_print(t_memory *mem, char *op, char pile_n)
{
	int	sz;

	sz = ft_strlen(op);
	if (ft_strncmp(op, "swap", sz) == 0)
		exec_swap(mem->pile_a, mem->pile_b, pile_n);
	else if (ft_strncmp(op, "push", sz) == 0)
		exec_push(mem->pile_a, mem->pile_b, pile_n);
	else if (ft_strncmp(op, "reverse_rr", sz) == 0)
		exec_reverse_rotate(mem->pile_a, mem->pile_b, pile_n);
	else if (ft_strncmp(op, "rotate", sz) == 0)
		exec_rotate(mem->pile_a, mem->pile_b, pile_n);
}
