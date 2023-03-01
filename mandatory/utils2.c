/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:52:50 by ybenlafk          #+#    #+#             */
/*   Updated: 2023/01/08 22:16:27 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(ln(src) + 1);
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

void	dupp(t_var *p)
{
	int	i;

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

void	print_moves(t_var *p)
{
	putstrr("move => ");
	putnbr(p->moves);
	putstrr("\n");
}
