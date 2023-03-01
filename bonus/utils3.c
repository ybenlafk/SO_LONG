/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:52:50 by ybenlafk          #+#    #+#             */
/*   Updated: 2023/02/08 22:30:12 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_moves(t_var *p)
{
	putstrr("move => ");
	putnbr(p->moves);
	putstrr("\n");
}

int	img_helper(t_var *p)
{
	p->coins[0] = mlx_xpm_file_to_image(p->mx, "./assets/c0.xpm", &p->w, &p->h);
	if (!p->coins[0])
		return (putstrr("image error\n"), exit(0), 0);
	p->coins[1] = mlx_xpm_file_to_image(p->mx, "./assets/c1.xpm", &p->w, &p->h);
	if (!p->coins[1])
		return (putstrr("image error\n"), exit(0), 0);
	p->coins[2] = mlx_xpm_file_to_image(p->mx, "./assets/c2.xpm", &p->w, &p->h);
	if (!p->coins[2])
		return (putstrr("image error\n"), exit(0), 0);
	p->coins[3] = mlx_xpm_file_to_image(p->mx, "./assets/c3.xpm", &p->w, &p->h);
	if (!p->coins[3])
		return (putstrr("image error\n"), exit(0), 0);
	p->coins[4] = mlx_xpm_file_to_image(p->mx, "./assets/c4.xpm", &p->w, &p->h);
	if (!p->coins[4])
		return (putstrr("image error\n"), exit(0), 0);
	return (0);
}

int	img_helper_(t_var *p)
{
	p->coins[5] = mlx_xpm_file_to_image(p->mx, "./assets/c5.xpm", &p->w, &p->h);
	if (!p->coins[5])
		return (putstrr("image error\n"), exit(0), 0);
	p->coins[6] = mlx_xpm_file_to_image(p->mx, "./assets/c6.xpm", &p->w, &p->h);
	if (!p->coins[6])
		return (putstrr("image error\n"), exit(0), 0);
	p->coins[7] = mlx_xpm_file_to_image(p->mx, "./assets/c7.xpm", &p->w, &p->h);
	if (!p->coins[7])
		return (putstrr("image error\n"), exit(0), 0);
	p->coins[8] = mlx_xpm_file_to_image(p->mx, "./assets/c8.xpm", &p->w, &p->h);
	if (!p->coins[8])
		return (putstrr("image error\n"), exit(0), 0);
	p->coins[9] = mlx_xpm_file_to_image(p->mx, "./assets/c9.xpm", &p->w, &p->h);
	if (!p->coins[9])
		return (putstrr("image error\n"), exit(0), 0);
	return (0);
}

void	fuf(t_var *p, int s)
{
	if (p->map[p->i][p->j] == 'C')
		mlx_put_image_to_window(p->mx, p->win, p->coins[s], p->w, p->h);
}

void	fill_coins(t_var *p)
{
	static int	l;
	static int	s;

	p->i = 0;
	p->h = 0;
	while (p->map[p->i])
	{
		p->j = 0;
		p->w = 0;
		while (p->map[p->i][p->j])
		{
			fuf(p, s);
			p->w += 64;
			p->j++;
		}
		p->h += 64;
		p->i++;
	}
	if (l++ == 4)
	{
		s++;
		l = 0;
	}
	if (s >= 10)
		s = 0;
}
