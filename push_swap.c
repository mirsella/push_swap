/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:30:57 by mirsella          #+#    #+#             */
/*   Updated: 2022/12/26 16:07:11 by mirsella         ###   ########.fr       */
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
	// int		*pa;
	size_t	size;

	if (ac == 1)
		error(NULL);
	size = count_numbers(ac, av);
	ft_putnbr(size);
	// pa = create_pile(ac, av, size);
	// while (size--)
	// 	ft_putnbr(pa[size]);
}
