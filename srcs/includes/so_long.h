/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xel <xel@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:47:56 by xel               #+#    #+#             */
/*   Updated: 2022/05/14 00:47:56 by xel              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define BUFFER_SIZE 100


// gnl part
size_t	ft_strlen(const char *s);
int		ft_have_newline(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_line(char *stash);
char	*ft_get_stash(char *stash);
char	*get_next_line(int fd);
char	*ft_free(char *str);

// parsing part
char	**ft_fill_map(char *argv);
size_t	ft_count_line(char *argv);
int		ft_check_wall(char **map);
int		ft_check_wall_size(char **map);
int		ft_parse_name(char *argv);
char	**ft_remove_nl(char **map);

//test part
void	ft_free_map(char **map);
void    ft_print_map(char **map);




#endif
