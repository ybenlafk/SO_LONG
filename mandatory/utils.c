/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:52:50 by ybenlafk          #+#    #+#             */
/*   Updated: 2023/01/08 16:47:11 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ln(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	if (str[i - 1] == '\n')
		i--;
	return (i);
}

int	check_line(char *s)
{
	int	j;

	j = 0;
	while (s[j] != '\n' && s[j])
		if (s[j++] != '1')
			return (0);
	return (1);
}

int	check_wall(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ln(map[i]);
	if (!check_line(map[i]))
		return (0);
	while (map[++i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (0);
	}
	if (!check_line(map[--i]))
		return (0);
	return (1);
}

int	count_lines(char *f)
{
	char	c;
	int		count;
	int		fd;

	fd = open(f, O_RDONLY);
	count = 0;
	if (fd == -1)
		return (perror("Error opening file"), exit(0), -1);
	while (read(fd, &c, 1) == 1)
		if (c == '\n' || !c)
			count++;
	close(fd);
	return (count);
}

int	count_first_line_length(char *file)
{
	char	buffer[1024];
	char	c;
	int		len;
	int		fd;
	int		bytes_read;

	len = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror("Error opening file"), exit(0), -1);
	while (1)
	{
		bytes_read = read(fd, &c, 1);
		if (bytes_read == 0)
			break ;
		else if (bytes_read < 0)
			exit (-1);
		buffer[len] = c;
		len++;
		if (c == '\n')
			break ;
	}
	close(fd);
	return (len);
}
