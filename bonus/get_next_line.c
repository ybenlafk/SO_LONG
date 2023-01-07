/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenlafk <ybenlafk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:51:13 by ybenlafk          #+#    #+#             */
/*   Updated: 2023/01/07 15:43:51 by ybenlafk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char *get_next_line(int fd)
{
    int 	i = 0;
    int 	rd = 0;
    char	c;
    char 	*buffer;

    buffer = malloc(100000);
    if (!buffer)
        exit(0);
    while ((rd = read(fd, &c, 1)) > 0)
    {
        buffer[i++] = c;
        if (c == '\n')
            break;
    }
    if ((!buffer[i - 1] && !rd) || rd == -1)
    {
        free(buffer);
        return (NULL);
    }
    buffer[i] =  '\0';
    return(buffer);
}