/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_action_basic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:48:00 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/03 19:19:37 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_p(t_piles *pile)
{
	int	tmp;

	if (pile->size < 2)
		return ;
	tmp = pile->p[0];
	pile->p[0] = pile->p[1];
	pile->p[1] = tmp;
}

void	swap_pp(t_piles *a, t_piles *b)
{
	swap_p(a);
	swap_p(b);
}

void	push_p(t_piles *dest, t_piles *src)
{
	int		tmp;
	size_t	i;

	if (src->size < 1)
		return ;
	tmp = src->p[0];
	i = 0;
	while (i < src->size - 1)
	{
		src->p[i] = src->p[i + 1];
		i++;
	}
	(src->size)--;
	i = dest->size;
	while (i > 0)
	{
		dest->p[i] = dest->p[i - 1];
		i--;
	}
	dest->p[0] = tmp;
	(dest->size)++;
}
