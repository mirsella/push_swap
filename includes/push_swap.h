/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:46:47 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/03 00:03:59 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "stdlib.h"
# include "limits.h"

void	error(int *pa);
void	checkduplicate(int *pa, int size);
void	printpiles(int *pa, int *pb, size_t sizea, size_t sizeb);
void	swap_a(int *pa, size_t size);
void	swap_b(int *pb, size_t size);
void	swap(int *pa, int *pb, size_t sizea, size_t sizeb);
void	push_a(int *pa, int *pb, size_t *sizea, size_t *sizeb);
void	push_b(int *pa, int *pb, size_t *sizea, size_t *sizeb);
void	rotate_a(int *pa, size_t size);
void	rotate_b(int *pb, size_t size);
void	rotate(int *pa, int *pb, size_t sizea, size_t sizeb);
void	rrotate_a(int *pa, size_t size);
void	rrotate_b(int *pb, size_t size);
void	rrotate(int *pa, int *pb, size_t sizea, size_t sizeb);
void	sort(int *pa, int *pb, size_t sizea, size_t sizeb);
int		get_limit(int *pa, int *pb, size_t sizea, int chunk);
void	goto_minimum(int *pa, size_t sizea);
void	goto_closest_below(int *pa, size_t sizea, int limit);
void	goto_num(int *pa, size_t sizea, int num);
void	sort_3(int *pa, size_t sizea);
void	sort_basic(int *pa, int *pb, size_t sizea, size_t sizeb);
void	sort_advanced(int *pa, int *pb, size_t sizea, int chunk);
int		*intdup(int *pile, size_t size);
int		*malloc_pile(size_t size);
int		*parse(int ac, char **av, size_t size);
int		count_numbers(int ac, char **av);

#endif
