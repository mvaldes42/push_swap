/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:13:10 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/20 17:36:05 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_fail(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_memory	mem;

	ft_bzero(&mem, sizeof(mem));
	check_n_parse(&mem, argv, argc);
	exit(EXIT_SUCCESS);
}
