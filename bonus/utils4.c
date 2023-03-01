/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:50:51 by ybenlafk          #+#    #+#             */
/*   Updated: 2023/01/08 22:14:43 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_up(t_var *p)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	get_player_pos(p, &x, &y, 'P');
	if (p->map[x - 1][y] == '0')
	{
		p->map[x][y] = '0';
		p->map[x - 1][y] = 'P';
		return (1);
	}
	else if (p->map[x - 1][y] == 'C')
	{
		p->map[x][y] = '0';
		p->map[x - 1][y] = 'P';
		p->coll--;
		return (1);
	}
	else if ((p->map[x - 1][y] == 'E' && !check_col(p->map)))
		return (putstrr("you win the game 🥳.\n"), exit(0), 0);
	if (p->map[x - 1][y] == 'X')
		return (putstrr("you lose the game XD.\n"), exit(0), 0);
	return (0);
}

int	move_down(t_var *p)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	get_player_pos(p, &x, &y, 'P');
	if (p->map[x + 1][y] == '0')
	{
		p->map[x][y] = '0';
		p->map[x + 1][y] = 'P';
		return (1);
	}
	else if (p->map[x + 1][y] == 'C')
	{
		p->map[x][y] = '0';
		p->map[x + 1][y] = 'P';
		p->coll--;
		return (1);
	}
	else if ((p->map[x + 1][y] == 'E' && !check_col(p->map)))
		return (putstrr("you win the game 🥳.\n"), exit(0), 0);
	if (p->map[x + 1][y] == 'X')
		return (putstrr("you lose the game XD.\n"), exit(0), 0);
	return (0);
}

int	move_right(t_var *p)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	get_player_pos(p, &x, &y, 'P');
	if (p->map[x][y + 1] == '0')
	{
		p->map[x][y] = '0';
		p->map[x][y + 1] = 'P';
		return (1);
	}
	else if (p->map[x][y + 1] == 'C')
	{
		p->map[x][y] = '0';
		p->map[x][y + 1] = 'P';
		p->coll--;
		return (1);
	}
	else if ((p->map[x][y + 1] == 'E' && !check_col(p->map)))
		return (putstrr("you win the game 🥳.\n"), exit(0), 0);
	if (p->map[x][y + 1] == 'X')
		return (putstrr("you lose the game XD.\n"), exit(0), 0);
	return (0);
}

int	move_left(t_var *p)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	get_player_pos(p, &x, &y, 'P');
	if (p->map[x][y - 1] == '0')
	{
		p->map[x][y] = '0';
		p->map[x][y - 1] = 'P';
		return (1);
	}
	else if (p->map[x][y - 1] == 'C')
	{
		p->map[x][y] = '0';
		p->map[x][y - 1] = 'P';
		p->coll--;
		return (1);
	}
	else if ((p->map[x][y - 1] == 'E' && !check_col(p->map)))
		return (putstrr("you win the game 🥳.\n"), exit(0), 0);
	if (p->map[x][y - 1] == 'X')
		return (putstrr("you lose the game XD.\n"), exit(0), 0);
	return (0);
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
				&& p->map[i][j] != 'X' && p->map[i][j] != 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
