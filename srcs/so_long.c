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
	(void)argc;
	char	**map;
	
	printf("ici");

	if (argc != 2)
		return (1);
	map = ft_fill_map(argv[1]);
	//ft_check_wall(map);
	ft_print_map(map);
	ft_free_map(map);
}