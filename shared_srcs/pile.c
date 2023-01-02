/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:24:19 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/02 16:21:08 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*malloc_pile(int size)
{
	int	*pile;

	pile = ft_calloc(size, sizeof(int));
	if (!pile)
		error(NULL);
	return (pile);
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
