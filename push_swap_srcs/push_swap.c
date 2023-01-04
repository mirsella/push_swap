/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:30:57 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/04 15:29:56 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_piles	a;
	t_piles	b;

	if (ac == 1)
		return (0);
	a.size = count_numbers(ac, av);
	b.size = 0;
	if (a.size < 1)
		error(NULL, NULL);
	a.p = parse(ac, av, a.size);
	b.p = ft_calloc(a.size, sizeof(int));
	if (!a.p || !b.p)
		error(a.p, b.p);
	if (has_duplicates(a))
		error(a.p, b.p);
	sort(&a, &b);
	free(a.p);
	free(b.p);
	return (0);
}
