/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:13:10 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/27 15:48:57 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_memory	mem;

	ft_bzero(&mem, sizeof(mem));
	// printf("argc : %d \n", argc);
	if (argc == 1)
		exit_fail();
	check_n_parse(&mem, argv, argc);
	sort_prms(&mem);
	exit(EXIT_SUCCESS);
}
