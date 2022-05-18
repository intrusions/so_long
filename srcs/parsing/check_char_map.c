/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:28:00 by jucheval          #+#    #+#             */
/*   Updated: 2022/05/18 23:28:30 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	char_is_good(char c)
{
	char	*collectible;
	size_t	i;

	i = 0;
	collectible = "01CEP";
	while (collectible[i])
	{
		if (c == collectible[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_char_map(char **map, t_error *errors)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(char_is_good(map[i][j])))
				return (errors->check_char_map = 1, 1);
			j++;
		}
		i++;
	}
	return (0);
}
