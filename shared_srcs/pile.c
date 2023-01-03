/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:24:19 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/03 23:21:51 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error(int *pa, int *pb)
{
	free(pa);
	free(pb);
	ft_putendl_fd("Error", 2);
	exit(0);
}

int	*intdup(t_piles pile)
{
	int		*new_pile;
	size_t	i;

	new_pile = ft_calloc(pile.size, sizeof(int));
	if (!new_pile)
		return (NULL);
	i = 0;
	while (i < pile.size)
	{
		new_pile[i] = pile.p[i];
		i++;
	}
	return (new_pile);
}

void	printpiles(int *pa, int *pb, size_t sizea, size_t sizeb)
{
	size_t	i;

	i = 0;
	ft_putstr("--------------------------------------\n");
	ft_printf("sizea: %2u\t|\tsizeb: %2u\n", sizea, sizeb);
	while (i < sizea || i < sizeb)
	{
		if (pa && i < sizea)
			ft_printf("pa[%2u] = %4d\t|\t", i, pa[i]);
		else
			ft_putstr("             \t|\t");
		if (pb && i < sizeb)
			ft_printf("pb[%2u] = %4d", i, pb[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putstr("--------------------------------------\n");
}
