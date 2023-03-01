/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:13:57 by ybenlafk          #+#    #+#             */
/*   Updated: 2023/02/10 16:54:20 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>

typedef struct var
{
	void	*mx;
	void	*win;
	void	*img;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	void	*img6;
	void	*img7;
	char	*map[10000];
	char	*dest[10000];
	void	*coins[10000];
	char	*filename;
	long	l;
	int		fd;
	int		len;
	int		len_line;
	int		i;
	int		j;
	int		x;
	int		y;
	int		h;
	int		w;
	int		hh;
	int		ww;
	int		exit;
	int		coll;
	int		moves;
}	t_var;

void	set_coins(t_var *p);
void	fill_assets(t_var *p);
void	fill_others(t_var *p);
void	fill_dor(t_var *p);
void	fill_coins(t_var *p);
void	freeallstr(char **str);
void	putnbr(int number);
void	putstrr(char *s);
void	dupp(t_var *p);
void	print_moves(t_var *p);
void	move(t_var *p, int (*mv)(t_var *));
char	*get_next_line(int fd);
char	*ft_itoa(int n);
char	*ft_strdup(char *src);
int		set_imgs(t_var *p);
int		animation(t_var *p);
int		get_player_pos(t_var *p, int *x, int *y, char c);
int		parsing(t_var *p);
int		check_wall(char **map);
int		count_first_line_length(char *file);
int		count_lines(char *file);
int		equal(char **map, int len_line, int len);
int		ln(char *str);
int		check_content(char **map, char c);
int		check_col(char **map);
int		check_enemy(char **map);
int		ft_strcmp(char *s1, char *s2);
int		event_key(int key, t_var *vars);
int		img_helper(t_var *p);
int		img_helper_(t_var *p);
int		move_up(t_var *p);
int		move_down(t_var *p);
int		move_right(t_var *p);
int		move_left(t_var *p);
int		check_path(t_var *p);
#endif