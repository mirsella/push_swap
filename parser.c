/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:46:37 by mirsella          #+#    #+#             */
/*   Updated: 2022/12/26 19:06:00 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pass_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		error(NULL);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

int		count_numbers(int ac, char **av)
{
	int	acindex;
	int i;
	int	count;

	acindex = 1;
	count = 0;
	while (acindex < ac)
	{
		i = 0;
		while (av[acindex][i])
		{
			count++;
			if (pass_number(av[acindex] + i) == 0)
				error(NULL);
			i += pass_number(av[acindex] + i);
		}
		acindex++;
	}
	return (count);
}

int		*create_pile(int ac, char **av, size_t size)
{
	int	*pa;
	long long	nb;
	int	acindex;
	int	i;
	int	pindex;
	
	acindex = 1;
	pindex = 0;
	i = 0;
	pa = malloc(sizeof(int) * size);
	if (!pa)
		error(NULL);
	while (acindex < ac)
	{
		i = 0;
		while (av[acindex][i])
		{
			nb = ft_atoll(av[acindex] + i);
			if (nb > INT_MAX || nb < INT_MIN)
				error(pa);
			pa[pindex++] = nb;
			i += pass_number(av[acindex] + i);
		}
		acindex++;
	}
	return (pa);
}
