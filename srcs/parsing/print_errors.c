/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 22:29:42 by jucheval          #+#    #+#             */
/*   Updated: 2022/05/19 00:15:21 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initialyze(t_error *errors)
{
	errors->parse_name = 0;
	errors->check_wall = 0;
	errors->check_char_map = 0;
	errors->check_collectible = 0;
	errors->check_rectangle = 0;
}

int		ft_print_errors(t_error *errors)
{
	if (errors->parse_name)
		printf("- The file names are not ending by a \".ber\"\n");
	if (errors->check_wall)
		printf("- The walls need to completely frame the map\n");
	if (errors->check_char_map)
		printf("- One or more unauthorized characters are present in the map\n");
	if (errors->check_collectible)
		printf("- Collectibles are not present in the map\n");
	if (errors->check_rectangle)
		printf("- The map are not rectangle\n");
	return (0);
}
