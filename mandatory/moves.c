/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:39:17 by ybenlafk          #+#    #+#             */
/*   Updated: 2023/01/08 16:58:51 by ybenlafk         ###   ########.fr       */
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
	return (0);
}

int	event_key(int key, t_var *p)
{
	p->x = 0;
	p->x = 0;
	p->coll = check_col(p->map);
	if (key == 53)
		exit(0);
	else if (key == 13 || key == 126)
		move(p, move_up);
	else if (key == 0 || key == 123)
		move(p, move_left);
	else if (key == 1 || key == 125)
		move(p, move_down);
	else if (key == 2 || key == 124)
		move(p, move_right);
	return (1);
}
