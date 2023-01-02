/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:30:57 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/03 00:31:19 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error(int *pa)
{
	free(pa);
	ft_putendl_fd("Error", 2);
	exit(0);
}

int	main(int ac, char **av)
{
	int		*pa;
	int		*pb;
	size_t	sizea;
	size_t	sizeb;

	if (ac == 1)
		return (0);
	sizea = count_numbers(ac, av);
	sizeb = 0;
	if (sizea < 1)
		error(NULL);
	pa = parse(ac, av, sizea);
	pb = malloc_pile(sizea);
	checkduplicate(pa, sizea);
	// printpiles(pa, pb, sizea, sizeb);
	sort(pa, pb, sizea, sizeb);
	// printpiles(pa, pb, sizea, sizeb);
}
