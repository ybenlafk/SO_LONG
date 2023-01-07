/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 23:48:13 by ybenlafk          #+#    #+#             */
/*   Updated: 2023/01/07 15:45:47 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    set_imgs(t_var *p)
{
    p->h = 64;
	p->w = 64;
    p->img = mlx_xpm_file_to_image(p->mlx, "./assets/wall.xpm", &p->w, &p->h);
    p->img1 = mlx_xpm_file_to_image(p->mlx, "./assets/floor.xpm", &p->w, &p->h);
    p->img2 = mlx_xpm_file_to_image(p->mlx, "./assets/player.xpm", &p->w, &p->h);
    p->img3 = mlx_xpm_file_to_image(p->mlx, "./assets/close.xpm", &p->w, &p->h);
    p->img4 = mlx_xpm_file_to_image(p->mlx, "./assets/coin.xpm", &p->w, &p->h);
    p->img5 = mlx_xpm_file_to_image(p->mlx, "./assets/open.xpm", &p->w, &p->h);
}

void fill_assets(t_var *p)
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
                mlx_put_image_to_window(p->mlx, p->mlx_win, p->img, p->w, p->h);
            else
                mlx_put_image_to_window(p->mlx, p->mlx_win, p->img1, p->w, p->h);
            p->w += 64;
            p->j++;
        }
        p->h += 64;
        p->i++;
    }
}

void    fill_others(t_var *p)
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
                mlx_put_image_to_window(p->mlx, p->mlx_win, p->img2, p->w, p->h);
            if (p->map[p->i][p->j] == 'E')
                mlx_put_image_to_window(p->mlx, p->mlx_win, p->img3, p->w, p->h);
            if (p->map[p->i][p->j] == 'C')
                mlx_put_image_to_window(p->mlx, p->mlx_win, p->img4, p->w, p->h);
            p->w += 64;
            p->j++;
        }
        p->h += 64;
        p->i++;
    }
}

void    fill_dor(t_var *p)
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
                mlx_put_image_to_window(p->mlx, p->mlx_win, p->img5, p->w, p->h);
            p->w += 64;
            p->j++;
        }
        p->h += 64;
        p->i++;
    }
}