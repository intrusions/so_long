/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xel <xel@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 03:24:04 by xel               #+#    #+#             */
/*   Updated: 2022/05/14 03:24:04 by xel              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_check_wall(char **map)
{
    size_t  i;
    size_t  j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
                if (i == 0 && map[i][j] != '1') {
                    printf("ici");
                    return (0);
                }
                if ((j == 0 || j == ft_strlen(map[i])) && map[i][j] != '1') {
                    printf("ou peut etre la");
                    return (0);
                }
                j++;
        }
        i++;
    }
    printf("LES MUR SONT BON");
    return (1);
}