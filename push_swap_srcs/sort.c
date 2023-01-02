/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:59:45 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/03 00:42:48 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int	get_limit(int *pa, int *pb, size_t sizea, int chunk)
// {
// 	static int		*sorted;
// 	static size_t	size;
// 	static int		lchunk;
// 
// 	if (!sorted)
// 	{
// 		size = sizea;
// 		lchunk = chunk;
// 		sorted = intdup(pa, size);
// 		if (sorted == NULL)
// 		{
// 			free(pb);
// 			error(pa);
// 		}
// 		ft_intsort(sorted, size);
// 	}
// 	return (sorted[(size / lchunk) * (lchunk + 1 - chunk)]);
// }

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


void	goto_closest_below(int *pa, size_t sizea, int max)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = 0;
	while (pa[start] > max && start < sizea)
		start++;
	while (pa[sizea - 1 - end] > max && end < sizea)
		end++;
	if (start < end)
		while (pa[0] > max)
			rotate_a(pa, sizea);
	else
		while (pa[0] > max)
		{
			ft_putstr("in loop");
			rrotate_a(pa, sizea);
		}
}

void	goto_num(int *pa, size_t sizea, int num)
{
	size_t	i;

	i = 0;
	while (i < sizea)
	{
		if (pa[i] == num)
			break ;
		i++;
	}
	if (i < sizea / 2)
		while (pa[0] != num)
			rotate_a(pa, sizea);
	else
		while (pa[0] != num)
			rrotate_a(pa, sizea);
}

void	goto_minimum(int *pa, size_t sizea)
{
	size_t	i;
	int		min;

	i = 0;
	min = pa[0];
	while (i < sizea)
	{
		if (pa[i] < min)
			min = pa[i];
		i++;
	}
	goto_num(pa, sizea, min);
}

void	sort(int *pa, int *pb, size_t sizea, size_t sizeb)
{
	if (sizea < 2)
		return ;
	else if (sizea == 2)
	{
		if (pa[0] > pa[1])
			swap_a(pa, sizea);
	}
	else if (sizea == 3)
		sort_3(pa, sizea);
	else if (ft_isascending(pa, sizea))
		return ;
	else if (sizea <= 10)
		sort_basic(pa, pb, sizea, sizeb);
	else if (sizea <= 100)
		sort_advanced(pa, pb, sizea, 4);
	else
		sort_advanced(pa, pb, sizea, 8);
}
