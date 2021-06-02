/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvaldes <mvaldes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:18:40 by mvaldes           #+#    #+#             */
/*   Updated: 2021/06/02 11:24:02 by mvaldes          ###   ########.fr       */
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

typedef struct s_memory
{
	int		size_spc;
	int		nb_prms;
	char	*prms;
	char	**prms_mod;
	int		*pile_a;
	int		*pile_b;
	int		pile_a_len;
	int		pile_b_len;
	float	avrg;
	int		mid;
	int		pivot;
	int		ope_count;
	int		degree;
}	t_memory;

void	exit_fail(t_memory *mem);
void	exit_success(t_memory *mem);
int		isnum(char *c);
float	ft_abs (float i);
int		word_count(t_memory *mem, const char *s, char c);
void	print_piles(int *pile_a, int *pile_b, int a_len, int b_len);

void	ft_swap(int *xp, int *yp);
int		find_idx(int *list, long num);
float	find_average(int *list, int longueur);

int		is_pile_ascend(int *pile, int len);
int		**stealth_sort(int *pile, long size);
int		*int_array_dup(int *src, int array_len);
int		find_smallest_nb(int *array, int len);

int		swap(int *pile, int len);
int		push(int *pile_from, int *pile_to, int len_from, int len_to);
int		rotate(int *pile, int pile_len);
int		reverse_rotate(int *pile, int pile_len);

void	exec_n_print(t_memory *mem, char *op, char pile);

void	check_n_parse(t_memory *mem, char **list_origin);

void	sort_buckets(t_memory *mem, int *pile_a_sort);
void	sort_lst_a(t_memory *mem, int *pile_a);
void	push_back_to_a(t_memory *mem, int *pile_b);

void	find_ope(t_memory *mem, int index, int pile_len, char lst_name);
void	sort_three_ascend(t_memory *mem, int *pile, char lst_name);
void	sort_three_descend(t_memory *mem, int *pile, char lst_name);
void	sort_prms(t_memory *mem);

#endif