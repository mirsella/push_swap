/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:59:45 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/02 17:47:52 by mirsella         ###   ########.fr       */
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

void	sort_10(int *pa, int *pb, size_t sizea, size_t sizeb)
{
	while (sizea > 3)
	{
		goto_minimum(pa, sizea);
		push_b(pa, pb, &sizea, &sizeb);
	}
	sort_3(pa, sizea);
	while (sizeb > 0)
		push_a(pa, pb, &sizea, &sizeb);
}

void	goto_minimum(int *pa, size_t sizea)
{
	size_t	i;
	int		min;
	size_t	min_index;

	i = 0;
	min = pa[0];
	min_index = 0;
	while (i < sizea)
	{
		if (pa[i] < min)
		{
			min = pa[i];
			min_index = i;
		}
		i++;
	}
	if (min_index < sizea / 2)
		while (pa[0] != min)
			rotate_a(pa, sizea);
	else
		while (pa[0] != min)
			rrotate_a(pa, sizea);
}

void	sort(int *pa, int *pb, size_t sizea, size_t sizeb)
{
	(void)sizeb;
	(void)pb;
	if (sizea < 2)
		return ;
	else if (sizea == 2)
	{
		if (pa[0] > pa[1])
			swap_a(pa, sizea);
	}
	else if (sizea == 3)
		sort_3(pa, sizea);
	else if (sizea <= 10)
		sort_10(pa, pb, sizea, sizeb);
}
