/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:33:44 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/26 10:59:20 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_n_print(t_memory *mem, char *operation)
{
	int	size;

	size = ft_strlen(operation);
	if (ft_strncmp(operation, "sa", size) == 0)
	{
		if (swap(mem->pile_a))
			printf("sa\n");
	}
	if (ft_strncmp(operation, "sb", size) == 0)
	{
		if (swap(mem->pile_b))
			printf("sb\n");
	}
	if (ft_strncmp(operation, "pa", size) == 0)
	{
		if (push(mem->pile_a, mem->pile_b))
			printf("pa\n");
	}
	if (ft_strncmp(operation, "pb", size) == 0)
	{
		if (push(mem->pile_b, mem->pile_a))
			printf("pb\n");
	}
	if (ft_strncmp(operation, "ss", size) == 0)
	{
		if (swap(mem->pile_a))
			mem->ope_a_worked = 1;
		if (swap(mem->pile_b))
			mem->ope_b_worked = 1;
		if (mem->ope_a_worked && mem->ope_b_worked)
			printf("ss\n");
		else if (mem->ope_a_worked)
			printf("sa\n");
		else if (mem->ope_b_worked)
			printf("sb\n");
		mem->ope_a_worked = 0;
		mem->ope_b_worked = 0;
	}
	else if (ft_strncmp(operation, "reverse_rr", size) == 0)
	{
		if (reverse_rotate(mem->pile_a))
			mem->ope_a_worked = 1;
		if (reverse_rotate(mem->pile_b))
			mem->ope_b_worked = 1;
		if (mem->ope_a_worked && mem->ope_b_worked)
			printf("rrr\n");
		else if (mem->ope_a_worked)
			printf("rra\n");
		else if (mem->ope_b_worked)
			printf("rrb\n");
		mem->ope_a_worked = 0;
		mem->ope_b_worked = 0;
	}
	else if (ft_strncmp(operation, "rr", size) == 0)
	{
		if (rotate(mem->pile_a))
			mem->ope_a_worked = 1;
		if (rotate(mem->pile_b))
			mem->ope_b_worked = 1;
		if (mem->ope_a_worked && mem->ope_b_worked)
			printf("rr\n");
		else if (mem->ope_a_worked)
			printf("ra\n");
		else if (mem->ope_b_worked)
			printf("rb\n");
		mem->ope_a_worked = 0;
		mem->ope_b_worked = 0;
	}
}
