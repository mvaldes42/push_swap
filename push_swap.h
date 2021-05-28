/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:18:40 by mvaldes           #+#    #+#             */
/*   Updated: 2021/05/28 10:45:02 by mvaldes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <float.h>

# define PUSH "push"
# define SWAP "swap"
# define ROTATE "rotate"
# define REVERSE_ROTATE "reverse_rr"
# define LIST_A 'a'
# define LIST_B 'b'
# define BOTH_LST '0'

# define SWAP_A "sa\n"
# define SWAP_B "sb\n"
# define SWAP_ALL "ss\n"

# define PUSH_A "pa\n"
# define PUSH_B "pb\n"

# define ROTATE_A "ra\n"
# define ROTATE_B "rb\n"
# define ROTATE_ALL "rr\n"

# define REVERSE_ROTATE_A "rra\n"
# define REVERSE_ROTATE_B "rrb\n"
# define REVERSE_ROTATE_ALL "rrr\n"

/// TO DELETE BEFORE FINISHING : ONLY EASIER TO CODE
# define __F_PRINT_LST__ print_piles(mem->pile_a, mem->pile_b);

# define F_SWAP_A exec_n_print(mem, SWAP, LIST_A);
# define F_SWAP_B exec_n_print(mem, SWAP, LIST_B);
# define F_SWAP_ALL exec_n_print(mem, SWAP, BOTH_LST);

# define F_PUSH_A exec_n_print(mem, PUSH, LIST_B);
# define F_PUSH_B exec_n_print(mem, PUSH, LIST_A);

# define F_ROTATE_A exec_n_print(mem, ROTATE, LIST_A);
# define F_ROTATE_B exec_n_print(mem, ROTATE, LIST_B);
# define F_ROTATE_ALL exec_n_print(mem, ROTATE, BOTH_LST);

# define F_REVERSE_ROTATE_A exec_n_print(mem, REVERSE_ROTATE, LIST_A);
# define F_REVERSE_ROTATE_B exec_n_print(mem, REVERSE_ROTATE, LIST_B);
# define F_REVERSE_ROTATE_ALL exec_n_print(mem, REVERSE_ROTATE, BOTH_LST);
/////////

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
float	ft_abs (float i);
int		word_count(const char *s, char c);
void	print_piles(int *pile_a, int *pile_b);
int		size_of_array(int *pile);
float	find_average(int *list, int longueur);
int		find_cls_to_avrg(int *list, float average);

int		swap(int *pile);
int		push(int *pile_from, int *pile_to);
int		rotate(int *pile);
int		reverse_rotate(int *pile);

void	exec_n_print(t_memory *mem, char *op, char pile);

void	check_n_parse(t_memory *mem, char **list_origin, int argc);
void	sort_prms(t_memory *mem);

#endif