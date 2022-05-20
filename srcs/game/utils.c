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

void	ft_swap(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_ready_to_exit(t_data *data)
{
	size_t	i;
	size_t	j;
	
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_clean_before_exit(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_image(data->mlx, data->collec_ptr);
	mlx_destroy_image(data->mlx, data->exit_ptr);
	mlx_destroy_image(data->mlx, data->log_ptr);
	mlx_destroy_image(data->mlx, data->wall_ptr);
	mlx_destroy_image(data->mlx, data->player_ptr);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}