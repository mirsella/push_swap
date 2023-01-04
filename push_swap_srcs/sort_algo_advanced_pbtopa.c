/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_advanced_pbtopa.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:27:01 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/04 22:45:20 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa_rra(t_piles *a, t_piles *b, size_t index, size_t *down)
{
	int	max;

	max = b->p[index];
	while (b->p[0] < max
		&& (*down == 0 || (*down > 0 && a->p[a->size - 1] < b->p[0])))
	{
		push_p(a, b);
		ft_putstr("pa\n");
		rotate_p(a);
		ft_putstr("ra\n");
		(*down)++;
	}
}

void	goto_max_pa(t_piles *a, t_piles *b, size_t index, size_t *down)
{
	int	max;

	max = b->p[index];
	if (index <= b->size / 2)
	{
		while (b->p[0] != max)
		{
			index = get_maximum(b);
			pa_rra(a, b, index, down);
			if (b->p[0] == max)
				break ;
			rotate_p(b);
			ft_putstr("rb\n");
		}
	}
	else
	{
		while (b->p[0] != max)
		{
			index = get_maximum(b);
			pa_rra(a, b, index, down);
			if (b->p[0] == max)
				break ;
			rrotate_p(b);
			ft_putstr("rrb\n");
		}
	}
	// while (b->p[0] != max)
	// {
	// 	index = get_maximum(b);
	// 	pa_rra(a, b, index, down);
	// 	if (b->p[0] == max)
	// 		break ;
	// 	if (index <= b->size / 2)
	// 	{
	// 		rotate_p(b);
	// 		ft_putstr("rb\n");
	// 	}
	// 	else
	// 	{
	// 		rrotate_p(b);
	// 		ft_putstr("rrb\n");
	// 	}
	// }
}


void	sort_pb_to_pa(t_piles *a, t_piles *b)
{
	size_t	down;

	down = 0;
	while (b->size > 0)
	{
		while (down > 0 && a->p[a->size - 1] > b->p[get_maximum(b)])
		{
			rrotate_p(a);
			ft_putstr("rra\n");
			down--;
		}
		goto_max_pa(a, b, get_maximum(b), &down);
		push_p(a, b);
		ft_putstr("pa\n");
	}
	if (down > 0)
	{
		while (down > 0)
		{
			rrotate_p(a);
			ft_putstr("rra\n");
			down--;
		}
	}
}
