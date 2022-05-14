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
                printf("Sur la ligne %ld, le char [%d] est present a l'index %ld et la ligne fais %ld de taille \n", i, map[i][j], j, ft_strlen(map[i]));
                if ((i == 0 && (map[i][j] != '1' && map[i][j] != '\r'))
                || (!map[i + 1] && (map[i][j] != '1' && map[i][j] != '\r')))
                    return (0);
                else if ((j == 0 || j == ft_strlen(map[i])) 
                && (map[i][j] != '1' && map[i][j] != '\r'))
                    return (0);
                j++;
        }
        i++;
    }
    printf("map bonne");
    return (1);
}