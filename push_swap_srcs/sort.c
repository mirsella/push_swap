/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:59:45 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/03 16:19:21 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	goto_closest_below(int *pile, size_t size, int max, char letter)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = 0;
	while (pile[start] > max && start < size)
		start++;
	while (pile[size - 1 - end] > max && end < size)
		end++;
	if (start == end && start == size)
		return (0);
	goto_num(pile, size, pile[ft_llmin(start, size - 1 - end)], letter);
	return (1);
}

void	goto_num(int *pile, size_t size, int num, char letter)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (pile[i] == num)
			break ;
		i++;
	}
	if (i < size / 2)
		while (pile[0] != num)
		{
			rotate_p(pile, size);
			ft_printf("r%c\n", letter);
		}

	else
		while (pile[0] != num)
		{
			rrotate_p(pile, size);
			ft_printf("rr%c\n", letter);
		}
}

void	goto_maximum(int *pile, size_t size, char letter)
{
	size_t	i;
	size_t	max;

	i = 0;
	max = 0;
	while (i < size)
	{
		if (pile[i] > pile[max])
			max = i;
		i++;
	}
	goto_num(pile, size, pile[max], letter);
}

void	goto_minimum(int *pile, size_t size, char letter)
{
	size_t	i;
	int		min;

	i = 0;
	min = pile[0];
	while (i < size)
	{
		if (pile[i] < min)
			min = pile[i];
		i++;
	}
	goto_num(pile, size, min, letter);
}

void	sort(int *pa, int *pb, size_t sizea, size_t sizeb)
{
	if (sizea < 2)
		return ;
	else if (sizea == 2)
	{
		if (pa[0] > pa[1])
		{
			swap_p(pa, sizea);
			ft_putstr("sa\n");
		}
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
