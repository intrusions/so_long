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

int	ft_loop_move(int keycode, t_data *data)
{
	int	previous_step;

	previous_step = data->step;
	if (keycode == 'w' || keycode == 'W')
		ft_move_top(data);
	else if (keycode == 's' || keycode == 'S')
		ft_move_bot(data);
	else if (keycode == 'a' || keycode == 'A')
		ft_move_left(data);
	else if (keycode == 'd' || keycode == 'D')
		ft_move_right(data);
	else if (keycode == 65307)
		ft_clean_before_exit(data);
	if (data->step != previous_step)
	{
		ft_putnbr(data->step);
		ft_putchar('\n');
		previous_step = data->step;
	}
	return (0);
}

void	ft_move_right(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (data->map[i + 1])
	{
		j = 1;
		while (data->map[i][j + 1])
		{
			if (data->map[i][j] == 'P' && data->map[i][j + 1] != '1'
			&& data->map[i][j + 1] != 'E' && ++data->step)
			{
				if (data->map[i][j + 1] == 'C')
					data->map[i][j + 1] = '0';
				ft_swap(&data->map[i][j], &data->map[i][j + 1]);
				ft_display_map(data);
				return ;
			}
			else if (data->map[i][j] == 'P' && data->map[i][j + 1] == 'E'
			&& ft_ready_to_exit(data) && ++data->step)
				ft_clean_before_exit(data);
			j++;
		}
		i++;
	}
}

void	ft_move_left(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (data->map[i + 1])
	{
		j = 1;
		while (data->map[i][j + 1])
		{
			if (data->map[i][j] == 'P' && data->map[i][j - 1] != '1'
			&& data->map[i][j - 1] != 'E' && ++data->step)
			{
				if (data->map[i][j - 1] == 'C')
					data->map[i][j - 1] = '0';
				ft_swap(&data->map[i][j], &data->map[i][j - 1]);
				ft_display_map(data);
				return ;
			}
			else if (data->map[i][j] == 'P' && data->map[i][j - 1] == 'E'
			&& ft_ready_to_exit(data) && ++data->step)
				ft_clean_before_exit(data);
			j++;
		}
		i++;
	}
}

void	ft_move_top(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (data->map[i + 1])
	{
		j = 1;
		while (data->map[i][j + 1])
		{
			if (data->map[i][j] == 'P' && data->map[i - 1][j] != '1'
			&& data->map[i - 1][j] != 'E' && ++data->step)
			{
				if (data->map[i - 1][j] == 'C')
					data->map[i - 1][j] = '0';
				ft_swap(&data->map[i][j], &data->map[i - 1][j]);
				ft_display_map(data);
				return ;
			}
			else if (data->map[i][j] == 'P' && data->map[i - 1][j] == 'E'
			&& ft_ready_to_exit(data) && ++data->step)
				ft_clean_before_exit(data);
			j++;
		}
		i++;
	}
}

void	ft_move_bot(t_data *data)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (data->map[i + 1])
	{
		j = 1;
		while (data->map[i][j + 1])
		{
			if (data->map[i][j] == 'P' && data->map[i + 1][j] != '1'
			&& data->map[i + 1][j] != 'E' && ++data->step)
			{
				if (data->map[i + 1][j] == 'C')
					data->map[i + 1][j] = '0';
				ft_swap(&data->map[i][j], &data->map[i + 1][j]);
				ft_display_map(data);
				return ;
			}
			else if (data->map[i][j] == 'P' && data->map[i + 1][j] == 'E'
			&& ft_ready_to_exit(data) && ++data->step)
				ft_clean_before_exit(data);
			j++;
		}
		i++;
	}
}
