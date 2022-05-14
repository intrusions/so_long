/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collectible.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:52:42 by jucheval          #+#    #+#             */
/*   Updated: 2022/05/14 21:18:48 by jucheval         ###   ########.fr       */
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

int	ft_check_collectible(char **map)
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
				tab[++k] = map[i][j];
			j++;
		}
		i++;
	}
	tab[++k] = 0;
	if (ft_check_collectible_tab(tab))
		return (1);
	return (0);
}