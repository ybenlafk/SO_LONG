/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 23:48:13 by ybenlafk          #+#    #+#             */
/*   Updated: 2023/01/08 13:04:52 by ybenlafk         ###   ########.fr       */
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
    p->img6 = mlx_xpm_file_to_image(p->mlx, "./assets/enemy.xpm", &p->w, &p->h);
}

void    set_coins(t_var *p)
{
    p->h = 64;
	p->w = 64;
    p->coins[0] = mlx_xpm_file_to_image(p->mlx, "./assets/coin0.xpm", &p->w, &p->h);
    p->coins[1] = mlx_xpm_file_to_image(p->mlx, "./assets/coin1.xpm", &p->w, &p->h);
    p->coins[2] = mlx_xpm_file_to_image(p->mlx, "./assets/coin2.xpm", &p->w, &p->h);
    p->coins[3] = mlx_xpm_file_to_image(p->mlx, "./assets/coin3.xpm", &p->w, &p->h);
    p->coins[4] = mlx_xpm_file_to_image(p->mlx, "./assets/coin4.xpm", &p->w, &p->h);
    p->coins[5] = mlx_xpm_file_to_image(p->mlx, "./assets/coin5.xpm", &p->w, &p->h);
    p->coins[6] = mlx_xpm_file_to_image(p->mlx, "./assets/coin6.xpm", &p->w, &p->h);
    p->coins[7] = mlx_xpm_file_to_image(p->mlx, "./assets/coin7.xpm", &p->w, &p->h);
    p->coins[8] = mlx_xpm_file_to_image(p->mlx, "./assets/coin8.xpm", &p->w, &p->h);
    p->coins[9] = mlx_xpm_file_to_image(p->mlx, "./assets/coin9.xpm", &p->w, &p->h);
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
            if (p->map[p->i][p->j] == 'X')
                mlx_put_image_to_window(p->mlx, p->mlx_win, p->img6, p->w, p->h);
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

void    fill_coins(t_var *p)
{
    static int l;
    static int s;
    p->i = 0;
    p->h = 0;
    while (p->map[p->i])
    {
        p->j = 0;
        p->w = 0;
        while (p->map[p->i][p->j])
        {
            if (p->map[p->i][p->j] == 'C')
                mlx_put_image_to_window(p->mlx, p->mlx_win, p->coins[s], p->w, p->h);
            p->w += 64;
            p->j++;
        }
        p->h += 64;
        p->i++;
    }
    if (l++ == 10)
    {
        s++;
        l = 0;
    }
    if (s >= 10)
        s = 0;
}
