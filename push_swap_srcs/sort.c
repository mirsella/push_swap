/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:59:45 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/04 22:41:07 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_limit(t_piles *a, t_piles *b, size_t chunkn, int freee)
{
	static int		*sorted = 0;
	static int		step = 0;

	if (!sorted)
	{
		sorted = intdup(*a);
		if (sorted == NULL)
			error(a->p, b->p);
		ft_intsort(sorted, a->size);
		step = ft_round((float)a->size / chunkn);
		return (step);
	}
	else if (freee)
	{
		free(sorted);
		sorted = 0;
		return (0);
	}
	else
		return (step);
	if (step * chunkn >= a->size)
		return (sorted[a->size - 1]);
	return (sorted[step * chunkn]);
}

void	goto_index(t_piles *pile, size_t index, char letter)
{
	int	num;

	num = pile->p[index];
	if (index <= pile->size / 2)
	{
		while (pile->p[0] != num)
		{
			rotate_p(pile);
			ft_printf("r%c\n", letter);
		}
	}
	else
	{
		while (pile->p[0] != num)
		{
			rrotate_p(pile);
			ft_printf("rr%c\n", letter);
		}
	}
}

size_t	get_maximum(t_piles *pile)
{
	size_t	i;
	int		max;
	size_t	index;

	i = 0;
	max = pile->p[0];
	index = 0;
	while (i < pile->size)
	{
		if (pile->p[i] > max)
		{
			max = pile->p[i];
			index = i;
		}
		i++;
	}
	return (index);
}

size_t	get_minimum(t_piles *pile)
{
	size_t	i;
	int		min;
	size_t	index;

	i = 0;
	min = pile->p[0];
	index = 0;
	while (i < pile->size)
	{
		if (pile->p[i] < min)
		{
			min = pile->p[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	sort(t_piles *a, t_piles *b)
{
	if (a->size < 2)
		return ;
	else if (a->size == 2)
	{
		if (a->p[0] > a->p[1])
		{
			swap_p(a);
			ft_putstr("sa\n");
		}
	}
	else if (a->size == 3)
		sort_3(a);
	else if (ft_isascending(a->p, a->size))
		return ;
	else if (a->size <= 10)
		sort_basic(a, b);
	else if (a->size <= 100)
		sort_advanced(a, b, 5);
	else
		sort_advanced(a, b, 12);
}
