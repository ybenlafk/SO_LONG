/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:52:50 by ybenlafk          #+#    #+#             */
/*   Updated: 2023/01/08 16:49:00 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	equal(char **map, int len_line, int len)
{
	int	i;

	i = 0;
	while (i <= len)
		if (len_line != ln(map[i++]))
			return (0);
	return (1);
}

int	check_content(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			if (map[i][j++] == c)
				count++;
		i++;
	}
	if (count == 1)
		return (1);
	return (0);
}

int	check_col(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			if (map[i][j++] == 'C')
				count++;
		i++;
	}
	if (count == 0)
		return (0);
	return (count);
}

void	freeallstr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	putstrr(char *s)
{
	while (*s)
		write(1, &*s++, 1);
}
