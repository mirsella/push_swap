/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_action_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:48:06 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/03 15:51:47 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_p(int *pile, size_t size)
{
	int		tmp;
	size_t	i;

	tmp = pile[0];
	i = 0;
	while (i < size - 1)
	{
		pile[i] = pile[i + 1];
		i++;
	}
	pile[i] = tmp;
}

void	rotate_pp(int *pa, size_t sizea, int *pb, size_t sizeb)
{
	int		tmp;
	size_t	i;

	if (pa && sizea > 1)
	{
		tmp = pa[0];
		i = 0;
		while (i < sizea - 1)
		{
			pa[i] = pa[i + 1];
			i++;
		}
		pa[i] = tmp;
	}
	if (pb && sizeb > 1)
	{
		tmp = pb[0];
		i = 0;
		while (i < sizeb - 1)
		{
			pb[i] = pb[i + 1];
			i++;
		}
		pb[i] = tmp;
	}
}

void	rrotate_p(int *pile, size_t size)
{
	int		tmp;
	size_t	i;

	tmp = pile[size - 1];
	i = size - 1;
	while (i > 0)
	{
		pile[i] = pile[i - 1];
		i--;
	}
	pile[i] = tmp;
}

void	rrotate_pp(int *pa, size_t sizea, int *pb, size_t sizeb)
{
	int		tmp;
	size_t	i;

	if (pa && sizea > 1)
	{
		tmp = pa[sizea - 1];
		i = sizea - 1;
		while (i > 0)
		{
			pa[i] = pa[i - 1];
			i--;
		}
		pa[i] = tmp;
	}
	if (pb && sizeb > 1)
	{
		tmp = pb[sizeb - 1];
		i = sizeb - 1;
		while (i > 0)
		{
			pb[i] = pb[i - 1];
			i--;
		}
		pb[i] = tmp;
	}
}
