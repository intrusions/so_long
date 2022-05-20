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

void	ft_initialyze(t_error *errors)
{
	errors->parse_name = 0;
	errors->invalid_fd = 0;
	errors->check_wall = 0;
	errors->check_char_map = 0;
	errors->check_collectible = 0;
	errors->check_wall_size = 0;
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

int	ft_print_errors(t_error *errors)
{
	if (errors->parse_name)
		ft_putstr("- File names are not ending by a \".ber\"\n");
	if (errors->invalid_fd)
		ft_putstr("- File name does not exist or is not a file\n");
	if (errors->check_wall)
		ft_putstr("- Walls need to completely frame the map\n");
	if (errors->check_char_map)
		ft_putstr("- Unauthorized characters are present in themap\n");
	if (errors->check_collectible)
		ft_putstr("- Collectibles are not present in the map\n");
	if (errors->check_wall_size)
		ft_putstr("- Map are not rectangle\n");
	return (0);
}
