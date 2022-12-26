/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:30:57 by mirsella          #+#    #+#             */
/*   Updated: 2022/12/26 18:56:21 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int *pa)
{
	free(pa);
	ft_putendl_fd("Error", 2);
	exit(0);
}

int	main(int ac, char **av)
{
	int		*pa;
	size_t	size;
	size_t		i;

	if (ac == 1)
		error(NULL);
	size = count_numbers(ac, av);
	ft_printf("size = %u\n", size);
	if (size < 1)
		error(NULL);
	pa = create_pile(ac, av, size);
	i = 0;
	while (i < size)
	{
		ft_printf("pa[%d] = %d\n", i, pa[i]);
		i++;
	}
}
