/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 00:36:30 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/03 00:40:13 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_round(double x)
{
	if (x < 0)
		return (x - 0.5);
	return (x + 0.5);
}

int	ft_floor(double x)
{
	if (x < 0)
		return (x - 1);
	return (x);
}

int	ft_ceil(double x)
{
	if (x < 0)
		return (x);
	return (x + 1);
}
