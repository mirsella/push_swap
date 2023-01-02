/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_action_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:48:06 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/02 17:46:33 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(int *pa, size_t sizea)
{
	int		tmp;
	size_t	i;

	tmp = pa[0];
	i = 0;
	while (i < sizea - 1)
	{
		pa[i] = pa[i + 1];
		i++;
	}
	pa[i] = tmp;
	ft_putstr("ra\n");
}

void	rotate_b(int *pb, size_t sizeb)
{
	int		tmp;
	size_t	i;

	tmp = pb[0];
	i = 0;
	while (i < sizeb - 1)
	{
		pb[i] = pb[i + 1];
		i++;
	}
	pb[i] = tmp;
	ft_putstr("rb\n");
}

void	rotate(int *pa, int *pb, size_t sizea, size_t sizeb)
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
