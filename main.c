/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:08:31 by dapanciu          #+#    #+#             */
/*   Updated: 2022/05/31 12:09:13 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int main (void)
{
    char        buff[10];
    int         fd;
    ssize_t     nr_bytes;
    
    ft_printf("This is a test: %s Content: %d\n", "42", 5);
    fd = open("test1", O_RDONLY);
    if (fd == -1)
        ft_printf("Error - No files to read !!!!");
    else
        nr_bytes = read(fd, buff, 15);
            if (nr_bytes == 0)
                ft_printf("Looks like your file is empty !!!");
            else 
                ft_printf("Number of char found is: %d Content :%s\n", nr_bytes, buff);
    return (0);
}