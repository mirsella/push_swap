/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:46:47 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/04 12:04:22 by mirsella         ###   ########.fr       */
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
void	printpiles(int *pa, int *pb, size_t sizea, size_t sizeb);
void	swap_p(t_piles *pile);
void	swap_pp(t_piles *a, t_piles *b);
void	push_p(t_piles *dest, t_piles *src);
void	rotate_p(t_piles *pile);
void	rotate_pp(t_piles *a, t_piles *b);
void	rrotate_p(t_piles *pile);
void	rrotate_pp(t_piles *a, t_piles *b);
void	sort(t_piles *a, t_piles *b);
int		get_limit(t_piles *a, t_piles *b, size_t chunkn);
void	goto_minimum(t_piles *pile, char letter);
void	goto_maximum(t_piles *pile, char letter);
void	goto_num(t_piles *pile, int num, char letter);
void	sort_3(t_piles *pile);
void	sort_basic(t_piles *a, t_piles *b);
void	sort_advanced(t_piles *a, t_piles *b, int chunk);
int		*intdup(t_piles piles);
int		*parse(int ac, char **av, size_t size);
int		count_numbers(int ac, char **av);

#endif
