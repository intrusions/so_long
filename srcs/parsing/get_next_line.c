/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:19:37 by jucheval          #+#    #+#             */
/*   Updated: 2022/05/05 14:19:37 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_get_line(char *stash)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	tmp = malloc((i + 2) * sizeof(char));
	if (!tmp)
		return (NULL);
	while (j <= i)
	{
		tmp[j] = stash[j];
		j++;
	}
	tmp[j] = 0;
	return (tmp);
}

char	*ft_get_stash(char *stash)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*tmp;

	i = 0;
	k = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (ft_free(stash));
	int O = (ft_strlen(stash) - i);
	printf("-> %d |%d| - %s", O, ft_have_newline(stash), stash);
	tmp = malloc(O * sizeof(char));
	if (!tmp)
		return (ft_free(stash));
	j = i + 1;
	while (stash[j])
		tmp[k++] = stash[j++];
	tmp[k] = 0;
	return (free(stash), tmp);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*buffer;
	int				readed;
	char			*line_to_return;

	readed = 1;
	if (BUFFER_SIZE <= 0 || (fd < 0 && fd > 1024))
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (readed && !ft_have_newline(stash))
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
			return (ft_free(buffer));
		buffer[readed] = 0;
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (ft_free(buffer));
	}
	line_to_return = ft_get_line(stash);
	stash = ft_get_stash(stash);
	return (free(buffer), line_to_return);
}
