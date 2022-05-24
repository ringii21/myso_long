/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <abonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:54:58 by abonard           #+#    #+#             */
/*   Updated: 2022/05/24 20:03:30 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../../minilibx-linux/mlx.h"

#define ASSETS "./as/f.xpm ./as/w.xpm ./as/p.xpm ./as/c.xpm ./as/e.xpm "

typedef struct  s_map
{
    char    **map;
    int     size;
    int     len;
    int     pos_x;
    int     pos_y;
    int     num_c;
    int     num_comb;
    int     res_x;
    int     res_y;
    void    *mlix;
    void    *window;
    void    *img[7];
    int		x[7];
	int		y[7];
    int     dx[10];
    int     dy[10];
    void    *score[10];
}t_map;

int     ft_parcing(t_map *game, char *file);
int     ft_check_ber(char *file);
int     ft_error(char *str);
int     ft_strlen_map(char **map);
int     ft_check_char(char **map);
int     exit_game(t_map *game);
int     ft_charge_number(t_map *game);
void    ft_put_digit(t_map *game);
void    ft_free_tabs(char **map);
void    ft_move_left(t_map *game);
void    ft_move_right(t_map *game);
void    ft_move_up(t_map *game);
void    ft_move_down(t_map *game);
char	*ft_strjoinfree(char const *s1, char *s2, int nb);
#endif

