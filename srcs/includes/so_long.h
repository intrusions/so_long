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
# include <mlx.h>
# define BUFFER_SIZE 1

// struct to manage parsing error
typedef struct s_error
{
	int		parse_name;
	int		invalid_fd;
	int		check_wall;
	int		check_char_map;
	int		check_collectible;
	int		check_wall_size;
	int		width_map;
	int		height_map;
}	t_error;

// struct to manage gamers
typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*collec_ptr;
	void	*exit_ptr;
	void	*log_ptr;
	void	*wall_ptr;
	void	*player_ptr;
	int		width;
	int		height;
	int		width_map;
	int		height_map;
	char	**map;
}	t_data;

// gnl part
size_t	ft_strlen(const char *s);
int		ft_have_newline(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_line(char *stash);
char	*ft_get_stash(char *stash);
char	*get_next_line(int fd);
char	*ft_free(char *str);

// parsing part
char	**ft_fill_map(char *argv, t_error *errors);
size_t	ft_count_line(char *argv);
int		ft_check_wall(char **map, t_error *errors);
int		ft_check_wall_size(char **map);
int		ft_parse_name(char *argv, t_error *errors);
char	**ft_remove_nl(char **map);
int		char_is_good(char c);
int		ft_check_char_map(char **map, t_error *errors);
int		ft_check_collectible(char **map, t_error *errors);
int		ft_check_in_tab(char c, char *tab);
int		ft_check_collectible_tab(char *tab);
int		ft_print_errors(t_error *errors);
void	ft_initialyze(t_error *errors);

// utils
void	ft_putstr(char *str);
void	ft_free_map(char **map);
void	ft_swap(char *a, char *b);
int		ft_one_player(char **map);
int		ft_ready_to_exit(t_data *data);
int		ft_clean_before_exit(t_data *data);

// play game
int		start_game(char **map, t_error *errors);
void	ft_display_map(t_data *data);
void	ft_display_map_choice(t_data *data, size_t i, size_t j);
void	ft_initialyze_img(t_data *data, t_error *errors);
int		ft_loop_move(int keycode, t_data *data);
void	ft_move_right(t_data *data);
void	ft_move_left(t_data *data);
void	ft_move_top(t_data *data);
void	ft_move_bot(t_data *data);

#endif
