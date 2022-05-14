/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xel <xel@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:40:05 by xel               #+#    #+#             */
/*   Updated: 2022/05/14 12:40:05 by xel              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		ft_parse_name(char *argv)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	str = ".ber";
	while (argv[i])
	{
		j = 0;
		while (argv[i] == str[j] && str[j] && argv[i])
		{
			i++;
			j++;
		}
		if (!argv[i] && !str[j])
			return (1);
		i++;
	}
	return (0);
}