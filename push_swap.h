/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:18:40 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/25 14:56:38 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

// typedef struct s_stack
// {
// 	char			*element;
// 	struct s_stack	*next;
// }	t_stack;

// typedef struct s_piles
// {
// 	t_stack	list_a;
// 	t_stack	list_b;
// }	t_piles;

typedef struct s_memory
{
	int	size_spc;
	int	nb_prms;
	char *prms;
	char **prms_mod;
	int	*pile_a;
	int	*pile_b;
	int	mid;
}	t_memory;

int		main(int argc, char *argv[]);
void	exit_fail(void);
int		check_n_parse(t_memory *mem, char **list_origin, int argc);

#endif