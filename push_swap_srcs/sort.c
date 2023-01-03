/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:59:45 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/04 00:06:53 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_limit(t_piles *a, t_piles *b, int chunkn)
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
	return (sorted[step * chunkn]);
}

void	goto_num(t_piles *pile, int num, char letter)
{
	size_t	i;

	i = 0;
	while (i < pile->size)
	{
		if (pile->p[i] == num)
			break ;
		i++;
	}
	if (i <= pile->size / 2)
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

void	goto_maximum(t_piles *pile, char letter)
{
	size_t	i;
	size_t	max;

	i = 0;
	max = 0;
	while (i < pile->size)
	{
		if (pile->p[i] > pile->p[max])
			max = i;
		i++;
	}
	goto_num(pile, pile->p[max], letter);
}

void	goto_minimum(t_piles *pile, char letter)
{
	size_t	i;
	int		min;

	i = 0;
	min = pile->p[0];
	while (i < pile->size)
	{
		if (pile->p[i] < min)
			min = pile->p[i];
		i++;
	}
	goto_num(pile, min, letter);
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
