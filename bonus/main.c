/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:13:07 by ybenlafk          #+#    #+#             */
/*   Updated: 2023/01/08 12:54:40 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"



int	ft_trace_map(t_var *p)
{
    char *s;

	mlx_clear_window(p->mlx, p->mlx_win);
	fill_assets(p);
    fill_others(p);
    fill_coins(p);
    animation(p);
    if (!p->coll)
		fill_dor(p);
    s = ft_itoa(p->moves);
	mlx_string_put(p->mlx, p->mlx_win, 20, 20, 10, s);
	return (free(s), 0);
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
    set_coins(&p);
    fill_assets(&p);
    fill_others(&p);
    fill_coins(&p);
    mlx_loop_hook(p.mlx, ft_trace_map, &p);
    mlx_hook(p.mlx_win, 2, 0, event_key, &p);
	mlx_loop(p.mlx);
    return (0);
}
