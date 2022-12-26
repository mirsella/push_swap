/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:46:47 by mirsella          #+#    #+#             */
/*   Updated: 2022/12/26 15:55:44 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "stdlib.h"
# include "limits.h"

void	error(int *pa);
int		*malloc_pile(int size);
int		*create_pile(int ac, char **av, size_t size);
int		count_numbers(int ac, char **av);

#endif
