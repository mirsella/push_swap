/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_action_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:48:06 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/03 22:04:06 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_p(t_piles *pile)
{
	int		tmp;
	size_t	i;

	if (pile->size < 2)
		return ;
	tmp = pile->p[0];
	i = 0;
	while (i < pile->size - 1)
	{
		pile->p[i] = pile->p[i + 1];
		i++;
	}
	pile->p[i] = tmp;
}

void	rotate_pp(t_piles *a, t_piles *b)
{
	rotate_p(a);
	rotate_p(b);
}

void	rrotate_p(t_piles *pile)
{
	int		tmp;
	size_t	i;

	if (pile->size < 2)
		return ;
	tmp = pile->p[pile->size - 1];
	i = pile->size - 1;
	while (i > 0)
	{
		pile->p[i] = pile->p[i - 1];
		i--;
	}
	pile->p[i] = tmp;
}

void	rrotate_pp(t_piles *a, t_piles *b)
{
	rrotate_p(a);
	rrotate_p(b);
}
