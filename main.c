/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:08:31 by dapanciu          #+#    #+#             */
/*   Updated: 2022/06/06 13:54:08 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int main (int argc, char **argv)
{
    int         fd;
    char        *line;

    (void)argc;
    line = "";
    
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        ft_printf("Error - No files to read !!!!");
    while (line != NULL)
    {
        line = get_next_line(fd);
        ft_printf("%s", line);
    }
    close(fd);
    return (0);
}