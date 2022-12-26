/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:46:37 by mirsella          #+#    #+#             */
/*   Updated: 2022/12/26 16:07:50 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*pass_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (str + i);
}

int		count_numbers(int ac, char **av)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (i < ac)
	{
		while (*av[i])
		{
			count++;
			av[i] = pass_number(av[i]);
		}
		i++;
	}
	return (count);
}

int		*create_pile(int ac, char **av, size_t size)
{
	int	*pa;
	long long	nb;
	int	i;
	int	j;
	
	i = 1;
	j = 0;
	pa = malloc_pile(size);
	while (i < ac)
	{
		while (*av[i])
		{
			nb = ft_atoll(av[i]);
			if (nb > INT_MAX || nb < INT_MIN)
				error(pa);
			pa[j] = nb;
			j++;
			av[i] = pass_number(av[i]);
		}
	}
	return (pa);
}
