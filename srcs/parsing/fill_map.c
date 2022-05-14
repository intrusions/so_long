/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xel <xel@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 03:09:30 by xel               #+#    #+#             */
/*   Updated: 2022/05/14 03:09:30 by xel              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_count_line(char *argv)
{
	char	*str;
	int		fd;
	size_t	count;

	count = 0;
	fd = open(argv, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
		count++;
	}
	printf("ici %ld", count);
	close(fd);
	return (count);
}

char	**ft_fill_map(char *argv)
{
	char	**map;
	size_t	size;
	size_t	i;
	int		fd;

	printf("ici");
	fd = open(argv, O_RDONLY);
	size = ft_count_line(argv);
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	i = -1;
	while (++i < size)
		map[i] = get_next_line(fd);
	map[i] = 0;
	close(fd);
	return (map);
}