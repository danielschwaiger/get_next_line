/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:09:20 by dapanciu          #+#    #+#             */
/*   Updated: 2022/05/29 17:42:34 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main (void)
{
    char    *line;
    int     fd;
    
    fd = open("test.txt", O_RDONLY);
    if (!fd)
        return (NULL);    
    if (fd)
    {
        printf("%s", line);
    }
    return (0);
}