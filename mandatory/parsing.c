/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:08:37 by ybenlafk          #+#    #+#             */
/*   Updated: 2023/01/07 15:45:56 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int    back_tracking(t_var *p, int x, int y)
{
    static int coll;
    static int exit;

    if (p->dest[x][y] == 'E')
        exit = 1;
    if (p->dest[x][y] == '1' || p->dest[x][y] == 'E')
        return(0);
    else if (p->dest[x][y] == 'C')
        coll++;
    p->dest[x][y] = '1';
    if (p->dest[x][y + 1] != '1')
        back_tracking(p, x, y + 1);
    if (p->dest[x][y - 1] != '1')
        back_tracking(p, x, y - 1);
    if (p->dest[x + 1][y] != '1')
        back_tracking(p, x + 1, y);
    if (p->dest[x - 1][y] != '1')
        back_tracking(p, x - 1, y);
    if (exit == 1 && coll == p->coll)
        return(1);
    return (0);
}

int get_player_pos(t_var *p, int *x, int *y, char c)
{
    while (p->map[*x])
    {
        *y = 0;
        while (p->map[*x][*y])
        {
            if (p->map[*x][*y] == c)
                return (0);
            (*y)++;
        }
        (*x)++;
    }
    return (1);
}

int    parsing(t_var *p)
{
    int x;
    int y;

    p->i = 0;
    x = 0;
    y = 0;
    p->len = countLines(p->filename);
    if (!p->len || ft_strcmp(".ber", p->filename + (ftstrlen(p->filename) - 4)))
        return(perror(""), exit(0), 0);
    p->fd = open(p->filename, O_RDONLY);
    if (p->fd == -1)
        return(perror(""), exit(-1), 0);
    p->i = 0;
    while (p->i <= p->len)
        p->map[p->i++] = get_next_line(p->fd);
    get_player_pos(p, &x, &y, 'P');
    dupp(p);
    p->coll = check_Col(p->map);
    if (!check_wall(p->map) || !is_equal_lines(p->map, ftstrlen(p->map[0]), countLines(p->filename))
        || !check_content(p->map, 'E') || !check_content(p->map, 'P')
        || !check_Col(p->map) || !back_tracking(p, x, y))
            return(perror(""), exit(0), 0);
    return (1);
}