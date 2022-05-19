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

int	ft_parse_name(char *argv, t_error *errors)
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
			return (0);
		i++;
	}
	return (errors->parse_name = 1, 1);
}

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
	close(fd);
	return (count);
}

char	**ft_remove_nl(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n' || map[i][j] == '\r')
				map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (map);
}

char	**ft_fill_map(char *argv, t_error *errors)
{
	char	**map;
	size_t	size;
	size_t	i;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (errors->invalid_fd = 1, NULL);
	size = ft_count_line(argv);
	map = malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	i = -1;
	while (++i < size)
		map[i] = get_next_line(fd);
	map[i] = 0;
	close(fd);
	return (ft_remove_nl(map));
}
