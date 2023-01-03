/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_advanced.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:16:28 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/03 22:26:53 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_pb_to_pa(t_piles *a, t_piles *b)
{
	while (b->size > 0)
	{
		goto_maximum(b, 'b');
		push_p(a, b);
		ft_putstr("pa\n");
	}
}

void	should_rr_or_r(t_piles *a, t_piles *b, int *should_rr)
{
	if (*should_rr && b->size > 0)
	{
		(*should_rr) = 0;
		rotate_pp(a, b);
		ft_putstr("rr\n");
	}
	else
	{
		rotate_p(a);
		ft_putstr("ra\n");
	}
}

void	goto_num_rr(t_piles *a, t_piles *b, int num, size_t i)
{
	static int	should_rr = 0;

	if (i <= a->size / 2)
	{
		while (a->p[0] != num)
		{
			should_rr_or_r(a, b, &should_rr);
		}
	}
	else
	{
		while (a->p[0] != num)
		{
			rrotate_p(a);
			ft_putstr("rra\n");
		}
	}
	should_rr = !should_rr;
}

int	goto_closest_below_pa(t_piles *a, t_piles *b, int max)
{
	size_t	start;
	size_t	end;
	int		num;

	start = 0;
	end = 0;
	while (a->p[start] > max && start < a->size)
		start++;
	while (a->p[a->size - 1 - end] > max && end < a->size)
		end++;
	if (start == end && start == a->size)
		return (0);
	num = a->p[ft_llmin(start, a->size - 1 - end)];
	goto_num_rr(a, b, num, ft_llmin(start, a->size - 1 - end));
	return (1);
}

void	sort_advanced(t_piles *a, t_piles *b, int chunk)
{
	int		limit;
	int		chunkn;

	chunkn = 1;
	get_limit(a, b, chunk);
	while (chunkn < chunk)
	{
		limit = get_limit(a, b, chunkn);
		while (goto_closest_below_pa(a, b, limit))
		{
			push_p(b, a);
			ft_putstr("pb\n");
		}
		chunkn++;
	}
	sort_basic(a, b);
	sort_pb_to_pa(a, b);
}
