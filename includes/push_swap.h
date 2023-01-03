/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:46:47 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/03 16:02:33 by mirsella         ###   ########.fr       */
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
void	swap_p(int *pile, size_t size);
void	swap_pp(int *pa, size_t sizea, int *pb, size_t sizeb);
void	push_p(int *pdest, size_t *sizedest, int *psrc, size_t *sizesrc);
void	rotate_p(int *pile, size_t size);
void	rotate_pp(int *pa, size_t sizea, int *pb, size_t sizeb);
void	rrotate_p(int *pile, size_t size);
void	rrotate_pp(int *pa, size_t sizea, int *pb, size_t sizeb);
void	sort(int *pa, int *pb, size_t sizea, size_t sizeb);
void	goto_minimum(int *pa, size_t sizeas, char letter);
void	goto_maximum(int *pa, size_t sizeas, char letter);
int		goto_closest_below(int *pa, size_t sizea, int limit, char letter);
void	goto_num(int *pa, size_t sizea, int num, char letter);
void	sort_3(int *pa, size_t sizea);
void	sort_basic(int *pa, int *pb, size_t sizea, size_t sizeb);
void	sort_advanced(int *pa, int *pb, size_t sizea, int chunk);
int		*intdup(int *pile, size_t size);
int		*parse(int ac, char **av, size_t size);
int		count_numbers(int ac, char **av);

#endif
