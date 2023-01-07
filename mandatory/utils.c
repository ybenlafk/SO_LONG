/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:52:50 by ybenlafk          #+#    #+#             */
/*   Updated: 2023/01/07 15:46:02 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ftstrlen(char *str)
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

int check_line(char *s)
{
    int j;

    j = 0;
    while (s[j] != '\n' && s[j])
        if (s[j++] != '1')
            return (0);
    return (1);
}

int check_wall(char **map)
{
    int i;
    int j;
    int len;

    i = 0;
    j = 0;
    len = ftstrlen(map[i]);
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

int countLines(char *file) 
{
    int     count;
    char    c;
    int fd;
    
    fd = open(file, O_RDONLY);
    count = 0;
    if (fd == -1)
        return(perror("Error opening file"), exit(0), -1);
    while (read(fd, &c, 1) == 1)
        if (c == '\n' || !c)
            count++;
    close(fd);
    return (count);
}

int count_first_line_length(char *file)
{
    char buffer[1024];
    int len;
    int fd;

    len = 0;
    fd = open(file, O_RDONLY);
     if (fd == -1)
        return(perror("Error opening file"), exit(0), -1);
    while (1) 
    {
        char c;
        int bytes_read = read(fd, &c, 1);
        if (bytes_read == 0)
            break ;
        else if (bytes_read < 0)
            exit (-1);
        buffer[len] = c;
        len++;
        if (c == '\n')
            break;
    }
    close(fd);
    return (len);
}

int is_equal_lines(char **map, int len_line, int len)
{
    int i;

    i = 0;
    while (i <= len)
        if (len_line != ftstrlen(map[i++]))
            return (0);
    return (1);
}

int check_content(char **map, char c)
{
    int i;
    int j;
    int count;

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

int check_Col(char **map)
{
    int i;
    int j;
    int count;

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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	putnbr(int number)
{
	if (number > 9)
		putnbr(number / 10);
	write(1, &"0123456789"[number % 10], 1);
}

char	*ft_strdup(char *src)
{
    char *dest;
	int		i;

	i = 0;
	dest = (char *)malloc(ftstrlen(src) + 1);
	if (!dest)
		exit(0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void    dupp(t_var *p)
{
    int		i;
    int		j;

	i = 0;
    p->fd = open(p->filename, O_RDONLY);
    if (p->fd == -1)
        exit(-1);
	while (p->map[i])
	{
        p->dest[i] = get_next_line(p->fd);
		i++;
	}
	p->dest[i] = NULL;
}

void    print_moves(t_var *p)
{
    putstrr("move => ");
    putnbr(p->moves);
    putstrr("\n");
}