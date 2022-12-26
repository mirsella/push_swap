/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:24:19 by mirsella          #+#    #+#             */
/*   Updated: 2022/12/26 15:48:39 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*malloc_pile(int size)
{
	int	*pile;

	pile = ft_calloc(size, sizeof(int));
	if (!pile)
		error(NULL);
	return (pile);
}
