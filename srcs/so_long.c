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

int	main(int argc, char **argv)
{
	char		**map;
	int			r;
	t_error		errors;

	r = 0;
	ft_initialyze(&errors);
	if (argc == 2)
	{
		r += ft_parse_name(argv[1], &errors);
		if (!r)
		{
			map = ft_fill_map(argv[1], &errors);
			if (!map)
				return (ft_print_errors(&errors), 0);
			r += ft_check_wall(map, &errors);
			r += ft_check_char_map(map, &errors);
			r += ft_check_collectible(map, &errors);
			if (r)
				return (ft_free_map(map), ft_print_errors(&errors));
			else
				start_game(map, &errors);
		}
	}
}
