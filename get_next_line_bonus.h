/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapanciu <dapanciu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:07:23 by dapanciu          #+#    #+#             */
/*   Updated: 2022/06/07 13:43:00 by dapanciu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS
# define GET_NEXT_LINE_BONUS

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

# ifndef BUFFER_SIZE		
#  define BUFFER_SIZE BUFSIZ	
# endif

/*-----------------GNL-------------------------*/
char *get_next_line(int fd);
/*--------------Other functions---------------*/
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *str1, char *str2);
/*--------------END--GNL------------------------*/
#endif