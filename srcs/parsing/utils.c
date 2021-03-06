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

void	ft_initialyze(t_error *errors)
{
	errors->empty_map = 0;
	errors->open_error = 0;
	errors->parse_file = 0;
	errors->parse_name = 0;
	errors->invalid_fd = 0;
	errors->check_wall = 0;
	errors->check_char_map = 0;
	errors->check_collectible = 0;
	errors->check_wall_size = 0;
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

void	ft_putnbr(int nb)
{
	long long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = nbr * -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + 48);
}

int	ft_print_errors(t_error *errors)
{
	ft_putstr("Error\n");
	if (errors->empty_map)
		ft_putstr("- Map is empty\n");
	if (errors->open_error)
		ft_putstr("- File can't be open\n");
	if (errors->parse_file)
		ft_putstr("- File doesn't exist or is a folder\n");
	if (errors->parse_name)
		ft_putstr("- File names are not ending by a \".ber\"\n");
	if (errors->invalid_fd)
		ft_putstr("- File name does not exist or is not a file\n");
	if (errors->check_wall)
		ft_putstr("- Walls need to completely frame the map\n");
	if (errors->check_char_map)
		ft_putstr("- Unauthorized characters are present in themap\n");
	if (errors->check_collectible)
		ft_putstr("- Collectibles/Players are not/most present in the map\n");
	if (errors->check_wall_size)
		ft_putstr("- Map are not rectangle\n");
	return (0);
}
