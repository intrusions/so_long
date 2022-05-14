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
	char	**map;

	if (argc != 2)
		return (1);
	if (ft_parse_name(argv[1]))
	{
		map = ft_fill_map(argv[1]);
		if (ft_check_wall(map))
			printf("map is bueno");
		else
			printf("no bueno senior");
		//ft_print_map(map);
		//ft_free_map(map);
	}
}