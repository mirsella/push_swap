/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_advanced.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:16:28 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/04 14:24:58 by mirsella         ###   ########.fr       */
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

size_t	should_rr_or_r(t_piles *a, t_piles *b, int should_rr)
{
	if (b->size > 0 && should_rr)
	{
		rotate_pp(a, b);
		ft_putstr("rr\n");
		return (1);
	}
	rotate_p(a);
	ft_putstr("ra\n");
	return (0);
}

void	goto_num_rr(t_piles *a, t_piles *b, size_t i, size_t counter)
{
	static size_t	rr_count = 0;
	int				num;

	if (counter == 0)
		rr_count = 0;
	num = a->p[i];
	if (i <= a->size / 2)
	{
		while (a->p[0] != num)
		{
			rr_count += should_rr_or_r(a, b, counter / 2 > rr_count);
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
}

int	goto_closest_below_pa1(t_piles *a, t_piles *b, int max, size_t counter)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = 0;
	while (a->p[start] > max && start < a->size)
		start++;
	while (a->p[a->size - 1 - end] > max && end < a->size)
		end++;
	if (start == end && start == a->size)
		return (0);
	goto_num_rr(a, b, start, counter);
	return (1);
}

// int	goto_closest_below_pa2(t_piles *a, t_piles *b, int max, size_t counter)
// {
// 	size_t	start;
// 	size_t	end;
// 	int		index;
// 
// 	start = 0;
// 	end = a->size - 1;
// 	while (a->p[start] > max && start < a->size)
// 		start++;
// 	while (a->p[end] > max && end > 0)
// 		end--;
// 	if (start == a->size)
// 		return (0);
// 	if (start < a->size - 1 - end)
// 		index = start;
// 	else
// 		index = end;
// 	goto_num_rr(a, b, index, counter);
// 	return (1);
// }

void	sort_advanced(t_piles *a, t_piles *b, int chunk)
{
	int		limit;
	int		chunkn;
	size_t	counter;

	chunkn = 1;
	get_limit(a, b, chunk);
	while (chunkn < chunk)
	{
		limit = get_limit(a, b, chunkn);
		counter = 0;
		while (goto_closest_below_pa1(a, b, limit, counter++))
		{
			push_p(b, a);
			ft_putstr("pb\n");
			if (b->size > 1 && a->size > 1 && b->p[0] < b->p[1])
			{
				swap_pp(a, b);
				ft_putstr("ss\n");
			}
		}
		chunkn++;
	}
	if (a->size > 2)
		sort_basic(a, b);
	sort_pb_to_pa(a, b);
}
