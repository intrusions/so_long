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

int	ft_check_wall_size(char **map)
{
	size_t	i;
	size_t	size;
	int		*tab;

	i = 0;
	size = 0;
	while (map[size])
		size++;
	if (ft_strlen(map[0]) <= size)
		return (0);
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (0);
	i = -1;
	while (++i < size)
		tab[i] = ft_strlen(map[i]);
	i = -1;
	while (++i < (size - 1))
		if (ft_strlen(map[i]) != ft_strlen(map[i + 1]))
			return (0);
	return (1);
}

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
			if (((i == 0 || !map[i + 1]) && (map[i][j] != '1'))
			||((j == 0 || !map[i][j + 1]) && (map[i][j] != '1')))
				return (0);
			j++;
		}
		i++;
	}
	if (ft_check_wall_size(map))
		return (1);
	return (0);
}