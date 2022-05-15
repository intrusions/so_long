/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xel <xel@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:46:28 by xel               #+#    #+#             */
/*   Updated: 2022/05/14 00:46:28 by xel              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int	main(int argc, char **argv)
{
	char	**map;
	void	*mlx;
	void	*mlx_win;

	if (argc != 2)
		return (1);
	if (ft_parse_name(argv[1]))
	{
		map = ft_fill_map(argv[1]);
		if (ft_check_wall(map) && ft_check_char_map(map) && ft_check_collectible(map))
		{
			printf("bonne map");
			mlx = mlx_init();
			mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
			mlx_loop(mlx);
		}
		else
			printf("mauvaise map");
	}
	ft_free_map(map);
}
