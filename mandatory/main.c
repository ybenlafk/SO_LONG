/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:13:07 by ybenlafk          #+#    #+#             */
/*   Updated: 2023/02/16 16:33:57 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	usys(t_var *p)
{
	mlx_clear_window(p->mx, p->win);
	fill_assets(p);
	fill_others(p);
	if (!p->coll)
		fill_dor(p);
	return (0);
}

int	ft_close(t_var *p, int key)
{
	(void)p;
	(void)key;
	exit(0);
}

int	main(int ac, char **av)
{
	t_var	p;

	if (ac != 2)
		return (0);
	p.filename = av[1];
	p.hh = count_lines(p.filename) + 1;
	p.ww = count_first_line_length(p.filename) - 1;
	parsing(&p);
	p.mx = mlx_init();
	if (!p.mx)
		return (putstrr("mlx error\n"), exit(0), 0);
	p.win = mlx_new_window(p.mx, p.ww * 64, p.hh * 64, "SO LONG!");
	if (!p.win)
		return (putstrr("mlx window error\n"), exit(0), 0);
	set_imgs(&p);
	fill_assets(&p);
	fill_others(&p);
	mlx_loop_hook(p.mx, usys, &p);
	mlx_hook(p.win, 2, 0, event_key, &p);
	mlx_hook(p.win, 17, 0, ft_close, &p);
	mlx_loop(p.mx);
	return (0);
}
