/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:37:55 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/04 14:54:41 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stddef.h>

void	sort_3(t_piles *pile)
{
	if (pile->p[0] > pile->p[1] && pile->p[0] > pile->p[2])
	{
		rotate_p(pile);
		ft_putstr("ra\n");
	}
	else if (pile->p[1] > pile->p[0] && pile->p[1] > pile->p[2])
	{
		rrotate_p(pile);
		ft_putstr("rra\n");
	}
	if (pile->p[0] > pile->p[1])
	{
		swap_p(pile);
		ft_putstr("sa\n");
	}
}

void	sort_basic(t_piles *a, t_piles *b)
{
	size_t	i;

	i = 0;
	if (ft_isascending(a->p, a->size))
		return ;
	while (a->size > 3)
	{
		goto_index(a, get_minimum(a), 'a');
		if (ft_isascending(a->p, a->size))
			break ;
		push_p(b, a);
		ft_putstr("pb\n");
		i++;
	}
	sort(a, b);
	while (i-- > 0)
	{
		push_p(a, b);
		ft_putstr("pa\n");
	}
}
