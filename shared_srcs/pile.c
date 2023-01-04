/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:24:19 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/04 15:37:01 by mirsella         ###   ########.fr       */
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

void	printpiles(t_piles a, t_piles b)
{
	size_t	i;

	i = 0;
	ft_putstr("--------------------------------------\n");
	ft_printf("a.size: %2u\t|\tsizeb: %2u\n", a.size, b.size);
	while (i < a.size || i < b.size)
	{
		if (a.p && i < a.size)
			ft_printf("a.p[%2u] = %4d\t|\t", i, a.p[i]);
		else
			ft_putstr("             \t|\t");
		if (b.p && i < b.size)
			ft_printf("b.p[%2u] = %4d", i, b.p[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putstr("--------------------------------------\n");
}
