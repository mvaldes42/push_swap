/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:13:10 by mvaldes           #+#    #+#             */
/*   Updated: 2021/06/01 12:04:50 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_memory	mem;

	ft_bzero(&mem, sizeof(mem));
	if (argc == 1)
		exit_fail(&mem);
	check_n_parse(&mem, argv);
	sort_prms(&mem);
	exit_success(&mem);
}
