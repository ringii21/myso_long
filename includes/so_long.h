/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <abonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:54:58 by abonard           #+#    #+#             */
/*   Updated: 2022/05/25 15:52:06 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"

# define ASSETS "./as/f.xpm ./as/w.xpm ./as/p.xpm ./as/c.xpm ./as/e.xpm"

typedef struct s_map
{
	char	**map;
	int		size;
	int		len;
	int		pos_x;
	int		pos_y;
	int		num_c;
	int		num_comb;
	int		res_x;
	int		res_y;
	void	*mlix;
	void	*window;
	void	*img[5];
	int		x[5];
	int		y[5];
}t_map;

int		ft_parcing(t_map *game, char *file);
int		ft_check_ber(char *file);
int		ft_error(char *str, t_map *game);
int		ft_strlen_map(char **map);
int		ft_check_char(char **map, t_map *game);
int		ft_charge_img(t_map *game);
int		touch_keys(int keycode, t_map *game);
int		exit_game(t_map *game);
void	ft_free_tabs(char **map);
void	ft_move_left(t_map *game);
void	ft_move_right(t_map *game);
void	ft_move_up(t_map *game);
void	ft_move_down(t_map *game);
#endif
