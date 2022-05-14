/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xel <xel@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 03:14:32 by xel               #+#    #+#             */
/*   Updated: 2022/05/14 03:14:32 by xel              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(char **map)
{
	size_t	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void    ft_print_map(char **map)
{
    //for(int i = 0; map[i]; i++)
	//	printf("%s", map[i]);

	printf("%s", map[0]);
	printf("%s", map[2]);
	printf("%s", map[3]);
}