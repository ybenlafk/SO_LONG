/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:13:07 by ybenlafk          #+#    #+#             */
/*   Updated: 2023/01/07 15:45:50 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"



int	ft_trace_map(t_var *p)
{
	mlx_clear_window(p->mlx, p->mlx_win);
	fill_assets(p);
    fill_others(p);
    if (!p->coll)
		fill_dor(p);
	return (0);
}


int main(int ac, char **av)
{
    t_var   p;

	if (ac != 2)
        return (0);
    p.filename = av[1];
    p.hh = countLines(p.filename) + 1;
    p.ww = count_first_line_length(p.filename) - 1;

    parsing(&p);
	p.mlx = mlx_init();
	p.mlx_win = mlx_new_window(p.mlx, p.ww * 64, p.hh * 64, "SO LONG!");
    set_imgs(&p);
    fill_assets(&p);
    fill_others(&p);
    mlx_loop_hook(p.mlx, ft_trace_map, &p);
    mlx_hook(p.mlx_win, 2, 0, event_key, &p);
	mlx_loop(p.mlx);
    return (0);
}
