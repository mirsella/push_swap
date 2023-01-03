/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_action_basic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:48:00 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/03 15:49:10 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_p(int *pile, size_t size)
{
	int	tmp;

	if (size < 2)
		return ;
	tmp = pile[0];
	pile[0] = pile[1];
	pile[1] = tmp;
}

void	swap_pp(int *pa, size_t sizea, int *pb, size_t sizeb)
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

void	push_p(int *pdest, size_t *sizedest, int *psrc, size_t *sizesrc)
{
	int		tmp;
	size_t	i;

	if (*sizesrc < 1)
		return ;
	tmp = psrc[0];
	i = 0;
	while (i < *sizesrc - 1)
	{
		psrc[i] = psrc[i + 1];
		i++;
	}
	(*sizesrc)--;
	i = *sizedest;
	while (i > 0)
	{
		pdest[i] = pdest[i - 1];
		i--;
	}
	pdest[0] = tmp;
	(*sizedest)++;
}
