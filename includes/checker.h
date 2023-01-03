/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:31:47 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/03 23:33:07 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "stdlib.h"

typedef struct s_piles
{
	int		*p;
	size_t	size;
}	t_piles;

void	error(int *pa, int *pb);
int		has_duplicates(t_piles pile);
int		*parse(int ac, char **av, size_t size);
int		count_numbers(int ac, char **av);
void	swap_p(t_piles *pile);
void	swap_pp(t_piles *a, t_piles *b);
void	push_p(t_piles *dest, t_piles *src);
void	rotate_p(t_piles *pile);
void	rotate_pp(t_piles *a, t_piles *b);
void	rrotate_p(t_piles *pile);
void	rrotate_pp(t_piles *a, t_piles *b);

#endif
