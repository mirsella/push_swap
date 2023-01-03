/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirsella <mirsella@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:31:16 by mirsella          #+#    #+#             */
/*   Updated: 2023/01/04 00:06:14 by mirsella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	is_valid_action(char *str)
{
	if (ft_strncmp(str, "sa\n", 3) == 0
		|| ft_strncmp(str, "sb\n", 3) == 0
		|| ft_strncmp(str, "ss\n", 3) == 0
		|| ft_strncmp(str, "pa\n", 3) == 0
		|| ft_strncmp(str, "pb\n", 3) == 0
		|| ft_strncmp(str, "ra\n", 3) == 0
		|| ft_strncmp(str, "rb\n", 3) == 0
		|| ft_strncmp(str, "rr\n", 3) == 0
		|| ft_strncmp(str, "rra\n", 4) == 0
		|| ft_strncmp(str, "rrb\n", 4) == 0
		|| ft_strncmp(str, "rrr\n", 4) == 0)
		return (1);
	return (0);
}

void	call_action(t_piles *a, t_piles *b, char *str)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		swap_p(a);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		swap_p(b);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		swap_pp(a, b);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		push_p(a, b);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		push_p(b, a);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		rotate_p(a);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rotate_p(b);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		rotate_pp(a, b);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		rrotate_p(a);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		rrotate_p(b);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		rrotate_pp(a, b);
}

int	is_sorting(t_piles *a, t_piles *b)
{
	char	*line;

	line = "";
	while (line)
	{
		line = ft_get_next_line(0, 0);
		if (!line)
			break ;
		if (!is_valid_action(line))
		{
			ft_get_next_line(0, 1);
			error(a->p, b->p);
		}
		call_action(a, b, line);
	}
	if (ft_isascending(a->p, a->size) && b->size == 0)
	{
		ft_get_next_line(0, 1);
		return (1);
	}
	return (0);
}

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
	if (is_sorting(&a, &b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free(a.p);
	free(b.p);
	return (0);
}
