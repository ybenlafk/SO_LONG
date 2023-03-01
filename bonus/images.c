/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 23:48:13 by ybenlafk          #+#    #+#             */
/*   Updated: 2023/01/08 15:34:53 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	set_imgs(t_var *p)
{
	p->h = 64;
	p->w = 64;
	p->img = mlx_xpm_file_to_image(p->mx, "./assets/wall.xpm", &p->w, &p->h);
	if (!p->img)
		return (putstrr("image error\n"), exit(0), 0);
	p->img1 = mlx_xpm_file_to_image(p->mx, "./assets/floor.xpm", &p->w, &p->h);
	if (!p->img1)
		return (putstrr("image error\n"), exit(0), 0);
	p->img2 = mlx_xpm_file_to_image(p->mx, "./assets/p.xpm", &p->w, &p->h);
	if (!p->img2)
		return (putstrr("image error\n"), exit(0), 0);
	p->img3 = mlx_xpm_file_to_image(p->mx, "./assets/close.xpm", &p->w, &p->h);
	if (!p->img3)
		return (putstrr("image error\n"), exit(0), 0);
	p->img4 = mlx_xpm_file_to_image(p->mx, "./assets/coin.xpm", &p->w, &p->h);
	if (!p->img4)
		return (putstrr("image error\n"), exit(0), 0);
	p->img5 = mlx_xpm_file_to_image(p->mx, "./assets/open.xpm", &p->w, &p->h);
	if (!p->img5)
		return (putstrr("image error\n"), exit(0), 0);
	p->img6 = mlx_xpm_file_to_image(p->mx, "./assets/enemy.xpm", &p->w, &p->h);
	if (!p->img6)
		return (putstrr("image error\n"), exit(0), 0);
	return (0);
}

void	set_coins(t_var *p)
{
	p->h = 64;
	p->w = 64;
	img_helper(p);
	img_helper_(p);
}

void	fill_assets(t_var *p)
{
	p->i = 0;
	p->h = 0;
	while (p->map[p->i])
	{
		p->j = 0;
		p->w = 0;
		while (p->map[p->i][p->j])
		{
			if (p->map[p->i][p->j] == '1')
				mlx_put_image_to_window(p->mx, p->win, p->img, p->w, p->h);
			else
				mlx_put_image_to_window(p->mx, p->win, p->img1, p->w, p->h);
			p->w += 64;
			p->j++;
		}
		p->h += 64;
		p->i++;
	}
}

void	fill_others(t_var *p)
{
	p->i = 0;
	p->h = 0;
	while (p->map[p->i])
	{
		p->j = 0;
		p->w = 0;
		while (p->map[p->i][p->j])
		{
			if (p->map[p->i][p->j] == 'P')
				mlx_put_image_to_window(p->mx, p->win, p->img2, p->w, p->h);
			if (p->map[p->i][p->j] == 'E')
				mlx_put_image_to_window(p->mx, p->win, p->img3, p->w, p->h);
			if (p->map[p->i][p->j] == 'X')
				mlx_put_image_to_window(p->mx, p->win, p->img6, p->w, p->h);
			p->w += 64;
			p->j++;
		}
		p->h += 64;
		p->i++;
	}
}

void	fill_dor(t_var *p)
{
	p->i = 0;
	p->h = 0;
	while (p->map[p->i])
	{
		p->j = 0;
		p->w = 0;
		while (p->map[p->i][p->j])
		{
			if (p->map[p->i][p->j] == 'E')
				mlx_put_image_to_window(p->mx, p->win, p->img5, p->w, p->h);
			p->w += 64;
			p->j++;
		}
		p->h += 64;
		p->i++;
	}
}
