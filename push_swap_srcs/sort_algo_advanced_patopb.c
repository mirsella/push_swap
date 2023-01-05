/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_advanced.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:16:28 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/05 02:05:48 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_there_number_below_limit(t_piles *a, int limit)
{
	size_t	i;

	i = 0;
	while (i < a->size)
	{
		if (a->p[i] < limit)
			return (1);
		i++;
	}
	return (0);
}

void	goto_first_below_limit(t_piles *a, t_piles *b, int limit, int limit2)
{
	while (a->p[0] > limit && is_there_number_below_limit(a, limit))
	{
		if (a->p[0] <= limit2 && a->p[0] > limit)
		{
			push_p(b, a);
			ft_putstr("pb\n");
			if (b->size > 1)
			{
				rotate_p(b);
				ft_putstr("rb\n");
			}
		}
		else
		{
			rotate_p(a);
			ft_putstr("ra\n");
		}
	}
}

int	goto_closest_below_limits(t_piles *a, t_piles *b, int chunk, int chunkn)
{
	int		limit;
	int		limit2;

	limit = get_limit(a, b, chunkn, 0);
	if (chunkn < chunk - 1)
		limit2 = get_limit(a, b, chunkn + 1, 0);
	else
		limit2 = limit;
	if (!is_there_number_below_limit(a, limit))
		return (0);
	goto_first_below_limit(a, b, limit, limit2);
	return (1);
}
