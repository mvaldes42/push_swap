/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:18:40 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/26 15:04:36 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_memory
{
	int		size_spc;
	int		nb_prms;
	char	*prms;
	char	**prms_mod;
	int		*pile_a;
	int		*pile_b;
	float	avrg;
	int		mid;
	int		pivot;
}	t_memory;

void	exit_fail(void);
int		isnum(char *c);
int		ft_abs (int i);
int		word_count(const char *s, char c);
void	print_piles(int *pile_a, int *pile_b);
int		size_of_array(int *pile);
float	find_average(int *list, int longueur);
int		find_cls_to_avrg(int *list, float average);

int		reverse_rotate(int *pile);
int		rotate(int *pile);
int		push(int *pile_from, int *pile_to);
int		swap(int *pile);

void	exec_n_print(t_memory *mem, char *op, char pile);

void	check_n_parse(t_memory *mem, char **list_origin, int argc);
void	sort_prms(t_memory *mem);

#endif