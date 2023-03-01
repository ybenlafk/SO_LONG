/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:40:38 by ybenlafk          #+#    #+#             */
/*   Updated: 2023/01/08 22:17:39 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move(t_var *p, int (*mv)(t_var *))
{
	p->l = mv(p);
	p->moves += p->l;
	if (p->l)
		print_moves(p);
}

int	check_path(t_var *p)
{
	int	i;
	int	j;

	i = 0;
	while (p->map[i])
	{
		j = 0;
		while (p->map[i][j] && p->map[i][j] != '\n')
		{
			if (p->map[i][j] != '0' && p->map[i][j] != '1'
				&& p->map[i][j] != 'P' && p->map[i][j] != 'C'
				&& p->map[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
