/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:46:47 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/04 22:30:02 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "stdlib.h"

typedef struct s_piles
{
	int		*p;
	size_t	size;
}	t_piles;

void	error(int *pa, int *pb);
int		has_duplicates(t_piles pile);
void	printpiles(t_piles a, t_piles b);
void	swap_p(t_piles *pile);
void	swap_pp(t_piles *a, t_piles *b);
void	push_p(t_piles *dest, t_piles *src);
void	rotate_p(t_piles *pile);
void	rotate_pp(t_piles *a, t_piles *b);
void	rrotate_p(t_piles *pile);
void	rrotate_pp(t_piles *a, t_piles *b);
void	sort(t_piles *a, t_piles *b);
int		get_limit(t_piles *a, t_piles *b, size_t chunkn, int freee);
size_t	get_minimum(t_piles *pile);
size_t	get_maximum(t_piles *pile);
void	goto_index(t_piles *pile, size_t index, char letter);
void	sort_3(t_piles *pile);
void	sort_basic(t_piles *a, t_piles *b);
void	sort_advanced(t_piles *a, t_piles *b, int chunk);
void	sort_pb_to_pa(t_piles *a, t_piles *b);
int		*intdup(t_piles piles);
int		*parse(int ac, char **av, size_t size);
int		count_numbers(int ac, char **av);

#endif
