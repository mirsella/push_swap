/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:46:37 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/03 23:38:23 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "limits.h"

int	pass_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		error(NULL, NULL);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	return (i);
}

int	count_numbers(int ac, char **av)
{
	int	acindex;
	int	i;
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
				error(NULL, NULL);
			i += pass_number(av[acindex] + i);
		}
		acindex++;
	}
	return (count);
}

int	has_duplicates(t_piles pile)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < pile.size)
	{
		j = i + 1;
		while (j < pile.size)
		{
			if (pile.p[i] == pile.p[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*parse(int ac, char **av, size_t size)
{
	int			*pa;
	long long	nb;
	int			acindex;
	int			i;
	int			pindex;

	acindex = 0;
	pindex = 0;
	i = 0;
	pa = ft_calloc(size, sizeof(int));
	while (pa && ++acindex < ac)
	{
		i = 0;
		if (av[acindex][0] == '\0')
			error(pa, NULL);
		while (av[acindex][i])
		{
			nb = ft_atoll(av[acindex] + i);
			if (nb > INT_MAX || nb < INT_MIN)
				error(pa, NULL);
			pa[pindex++] = nb;
			i += pass_number(av[acindex] + i);
		}
	}
	return (pa);
}
