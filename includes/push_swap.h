/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:46:47 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/02 17:46:52 by mirsella         ###   ########.fr       */
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
void	goto_minimum(int *pa, size_t sizea);
int		*malloc_pile(int size);
int		*parse(int ac, char **av, size_t size);
int		count_numbers(int ac, char **av);

#endif
