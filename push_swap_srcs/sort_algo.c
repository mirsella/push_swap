/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:37:55 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/03 15:55:34 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3(int *pa, size_t sizea)
{
	if (pa[0] > pa[1] && pa[0] > pa[2])
	{
		rotate_p(pa, sizea);
		ft_putstr("ra\n");
	}
	else if (pa[1] > pa[0] && pa[1] > pa[2])
	{
		rrotate_p(pa, sizea);
		ft_putstr("rra\n");
	}
	if (pa[0] > pa[1])
	{
		swap_p(pa, sizea);
		ft_putstr("sa\n");
	}
}

void	sort_basic(int *pa, int *pb, size_t sizea, size_t sizeb)
{
	size_t	i;

	i = 0;
	if (ft_isascending(pa, sizea))
		return ;
	while (sizea > 3)
	{
		goto_minimum(pa, sizea, 'a');
		push_p(pb, &sizeb, pa, &sizea);
		ft_putstr("pb\n");
		i++;
		if (ft_isascending(pa, sizea))
			break ;
	}
	sort(pa, pb, sizea, sizeb);
	while (i-- > 0)
	{
		push_p(pa, &sizea, pb, &sizeb);
		ft_putstr("pa\n");
	}
}

int	get_limit(int *pa, int *pb, size_t sizea, int chunkn)
{
	static int		*sorted = 0;
	static int		step = 0;

	if (!sorted)
	{
		sorted = intdup(pa, sizea);
		if (sorted == NULL)
		{
			free(pb);
			error(pa);
		}
		ft_intsort(sorted, sizea);
		step = ft_round((float)sizea / chunkn);
		return (step);
	}
	return (sorted[step * chunkn]);
}

void	sort_pb_to_pa(int *pa, int *pb, size_t *sizea, size_t *sizeb)
{
	while (*sizeb > 0)
	{
		// printpiles(pa, pb, *sizea, *sizeb);
		goto_maximum(pb, *sizeb, 'b');
		// printpiles(pa, pb, *sizea, *sizeb);
		push_p(pa, sizea, pb, sizeb);
		ft_putstr("pa\n");
	}
}

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
		limit = get_limit(pa, pb, sizea, chunkn);
		// ft_printf("limit: %d\n", limit);
		i = 0;
		while (goto_closest_below(pa, sizea, limit, 'a'))
		{
			push_p(pb, &sizeb, pa, &sizea);
			ft_putstr("pb\n");
			i++;
		}
		chunkn++;
	}
	sort_basic(pa, pb, sizea, sizeb);
	sort_pb_to_pa(pa, pb, &sizea, &sizeb);
}
