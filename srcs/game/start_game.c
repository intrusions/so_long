/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:25:38 by jucheval          #+#    #+#             */
/*   Updated: 2022/05/15 22:34:29 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initialyze_img(t_data *data)
{
	// Inityalize our image
	data->collec_ptr = mlx_xpm_file_to_image(data->mlx, "./img/collec.xpm", &data->width, &data->height);
	data->exit_ptr = mlx_xpm_file_to_image(data->mlx, "./img/exit.xpm", &data->width, &data->height);
	data->log_ptr = mlx_xpm_file_to_image(data->mlx, "./img/log.xpm", &data->width, &data->height);
	data->wall_ptr = mlx_xpm_file_to_image(data->mlx, "./img/wall.xpm", &data->width, &data->height);
	data->player_ptr = mlx_xpm_file_to_image(data->mlx, "./img/player.xpm", &data->width, &data->height);
}

void	ft_display_map(t_data *data, char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall_ptr, (j * 64), (i * 64));
			else if (map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->log_ptr, (j * 64), (i * 64));
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit_ptr, (j * 64), (i * 64));
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->collec_ptr, (j * 64), (i * 64));
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_ptr, (j * 64), (i * 64));
			j++;
		}
		i++;
	}
}

int	start_game(char **map)
{
	t_data	data;

	// Inityalize mlx instance
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 1080, 720, "so_long");

	// Inityalize our image
	ft_initialyze_img(&data);

	// put image in our window
	// mlx_put_image_to_window(data.mlx, data.mlx_win, data.player_ptr, 64, 64);
	ft_display_map(&data, map);

	mlx_loop(data.mlx);
	return (0);
}
