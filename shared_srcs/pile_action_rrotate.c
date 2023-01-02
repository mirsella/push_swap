/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_action_rrotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:42:24 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/02 17:46:33 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrotate_a(int *pa, size_t sizea)
{
	int		tmp;
	size_t	i;

	tmp = pa[sizea - 1];
	i = sizea - 1;
	while (i > 0)
	{
		pa[i] = pa[i - 1];
		i--;
	}
	pa[i] = tmp;
	ft_putstr("rra\n");
}

void	rrotate_b(int *pb, size_t sizeb)
{
	int		tmp;
	size_t	i;

	tmp = pb[sizeb - 1];
	i = sizeb - 1;
	while (i > 0)
	{
		pb[i] = pb[i - 1];
		i--;
	}
	pb[i] = tmp;
	ft_putstr("rrb\n");
}

void	rrotate(int *pa, int *pb, size_t sizea, size_t sizeb)
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
