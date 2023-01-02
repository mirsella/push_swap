/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_action_basic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:48:00 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/02 17:46:33 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(int *pa, size_t size)
{
	int	tmp;

	if (size < 2)
		return ;
	tmp = pa[0];
	pa[0] = pa[1];
	pa[1] = tmp;
	ft_putstr("sa\n");
}

void	swap_b(int *pb, size_t size)
{
	int	tmp;

	if (size < 2)
		return ;
	tmp = pb[0];
	pb[0] = pb[1];
	pb[1] = tmp;
	ft_putstr("sb\n");
}

void	swap(int *pa, int *pb, size_t sizea, size_t sizeb)
{
	int	tmp;

	if (pa && sizea > 1)
	{
		tmp = pa[0];
		pa[0] = pa[1];
		pa[1] = tmp;
	}
	if (pb && sizeb > 1)
	{
		tmp = pb[0];
		pb[0] = pb[1];
		pb[1] = tmp;
	}
}

void	push_a(int *pa, int *pb, size_t *sizea, size_t *sizeb)
{
	int		tmp;
	size_t	i;

	if (*sizeb < 1)
		return ;
	tmp = pb[0];
	i = 0;
	while (i < *sizeb - 1)
	{
		pb[i] = pb[i + 1];
		i++;
	}
	(*sizeb)--;
	i = *sizea;
	while (i > 0)
	{
		pa[i] = pa[i - 1];
		i--;
	}
	pa[0] = tmp;
	(*sizea)++;
	ft_putstr("pa\n");
}

void	push_b(int *pa, int *pb, size_t *sizea, size_t *sizeb)
{
	int		tmp;
	size_t	i;

	if (*sizea < 1)
		return ;
	tmp = pa[0];
	i = 0;
	while (i < *sizea - 1)
	{
		pa[i] = pa[i + 1];
		i++;
	}
	(*sizea)--;
	i = *sizeb;
	while (i > 0)
	{
		pb[i] = pb[i - 1];
		i--;
	}
	pb[0] = tmp;
	(*sizeb)++;
	ft_putstr("pb\n");
}
