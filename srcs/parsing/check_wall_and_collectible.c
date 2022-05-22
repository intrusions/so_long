/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collectible.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:52:42 by jucheval          #+#    #+#             */
/*   Updated: 2022/05/19 00:49:38 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_collectible_tab(char *tab)
{
	size_t	i;
	size_t	r;

	i = 0;
	r = 0;
	while (tab[i])
	{
		if (tab[i] == 'C' || tab[i] == 'E' || tab[i] == 'P')
			r += tab[i];
		i++;
	}
	if (r == 216)
		return (1);
	return (0);
}

int	ft_check_in_tab(char c, char *tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		if (c == tab[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_collectible(char **map, t_error *errors)
{
	char	tab[127];
	size_t	i;
	size_t	j;
	size_t	k;

	tab[0] = 0;
	i = 0;
	k = -1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_check_in_tab(map[i][j], tab))
			{
				tab[++k] = map[i][j];
				tab[k + 1] = 0;
			}
			j++;
		}
		i++;
	}
	if (ft_check_collectible_tab(tab) && ft_one_player(map))
		return (0);
	return (errors->check_collectible = 1, 1);
}

int	ft_check_wall_size(char **map)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (map[size])
		size++;
	if (ft_strlen(map[0]) < size)
		return (0);
	i = -1;
	while (++i < (size - 1))
		if (ft_strlen(map[i]) != ft_strlen(map[i + 1]))
			return (0);
	return (1);
}

int	ft_check_wall(char **map, t_error *errors)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (((i == 0 || !map[i + 1]) && (map[i][j] != '1'))
			|| ((j == 0 || !map[i][j + 1]) && (map[i][j] != '1')))
				errors->check_wall = 1;
			j++;
		}
		i++;
	}
	if (!map || !map[0] || !map[0][0])
		return (errors->empty_map = 1, 0);
	errors->width_map = i;
	errors->height_map = j;
	if (ft_check_wall_size(map) && errors->check_wall == 0)
		return (0);
	else if (ft_check_wall_size(map) && errors->check_wall == 1)
		return (1);
	return (errors->check_wall_size = 1, 1);
}
