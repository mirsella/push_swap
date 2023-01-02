/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:37:55 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/03 00:56:01 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(int *pa, size_t sizea)
{
	if (pa[0] > pa[1] && pa[0] > pa[2])
		rotate_a(pa, sizea);
	else if (pa[1] > pa[0] && pa[1] > pa[2])
		rrotate_a(pa, sizea);
	if (pa[0] > pa[1])
		swap_a(pa, sizea);
}

void	sort_basic(int *pa, int *pb, size_t sizea, size_t sizeb)
{
	if (ft_isascending(pa, sizea))
		return ;
	while (sizea > 3)
	{
		goto_minimum(pa, sizea);
		push_b(pa, pb, &sizea, &sizeb);
		if (ft_isascending(pa, sizea))
			break ;
	}
	if (sizea == 3)
		sort_3(pa, sizea);
	while (sizeb > 0)
		push_a(pa, pb, &sizea, &sizeb);
}

void	sort_pb_to_pa(int *pa, int *pb, size_t sizea, size_t sizeb);

void	sort_advanced(int *pa, int *pb, size_t sizea, int chunk)
{
	int		limit;
	int		chunkn;
	size_t	i;
	size_t	sizeb;

	chunkn = 1;
	sizeb = 0;
	get_limit(pa, pb, sizea, chunk);
	while (chunkn < chunk)
	{
		if (ft_isascending(pa, sizea))
			break ;
		limit = get_limit(pa, pb, sizea, chunkn);
		// ft_printf("limit: %d\n", limit);
		// (void)i;
		i = 0;
		while (i < sizea / chunk)
		{
			goto_closest_below(pa, sizea, limit);
			push_b(pa, pb, &sizea, &sizeb);
			if (ft_isascending(pa, sizea))
				break ;
		}
		chunkn++;
	}
	sort_basic(pa, pb, sizea, sizeb);
}
