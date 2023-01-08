/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 23:39:17 by ybenlafk          #+#    #+#             */
/*   Updated: 2023/01/08 12:53:19 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_up(t_var *p)
{
	int x = 0;
	int y = 0;
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
	else if ((p->map[x - 1][y] == 'E' && !check_Col(p->map))
			|| p->map[x - 1][y] == 'X')
		{
			putstrr("you lose the game XD.\n");
			exit(0);
		}
	return (0);
}

int	move_down(t_var *p)
{
	int x = 0;
	int y = 0;
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
	else if ((p->map[x + 1][y] == 'E' && !check_Col(p->map))
			|| p->map[x + 1][y] == 'X')
		{
			putstrr("you lose the game XD.\n");
			exit(0);
		}
	return (0);
}

int	move_right(t_var *p)
{
	int x = 0;
	int y = 0;
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
	else if ((p->map[x][y + 1] == 'E' && !check_Col(p->map))
			|| p->map[x][y + 1] == 'X')
		{
			putstrr("you lose the game XD.\n");
			exit(0);
		}
	return (0);
}

int	move_left(t_var *p)
{
	int x = 0;
	int y = 0;
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
	else if ((p->map[x][y - 1] == 'E' && !check_Col(p->map))
			|| p->map[x][y - 1] == 'X')
		{
			putstrr("you lose the game XD.\n");
			exit(0);
		}
	return (0);
}

void	move(t_var *p, int (*mv)(t_var *))
{
	p->l = mv(p);
	p->moves += p->l;
}

void	around(int i, int j, t_var *p)
{
	int y = rand() % 3 - 1;
	int x = rand() % 3 - 1;
	if (p->map[i - x][j + y] == 'P')
	{
		putstrr("you lose the game XD.\n");
		exit(0);
	}
	if (p->map[i + x][j + y] == '0' && p->map[i][j + 1] != 'X')
	{
		p->map[i][j] = '0';
		p->map[i + x][j + y] = 'X';
	}
}

int	animation(t_var *p)
{
	static int s;
	int i;
    int j;

	if (s++ == 30)
	{
    	i = 0;
    	while (p->map[i])
    	{
    	    j = 0;
    	    while (p->map[i][j])
			{
    	        if (p->map[i][j] == 'X')
					around(i, j, p);
				j++;
			}
    	    i++;
    	}
		s = 0;
	}
	return (1);
}

int	event_key(int key, t_var *p)
{
	p->x = 0;
	p->x = 0;
	p->coll = check_Col(p->map);
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
