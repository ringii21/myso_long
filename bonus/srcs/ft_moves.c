/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <abonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:55:16 by abonard           #+#    #+#             */
/*   Updated: 2022/05/24 19:37:59 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/libft.h"
#include "../includes/ft_printf.h"
#include "../../minilibx-linux/mlx.h"

void    ft_move_right(t_map *game)
{
    if (game->map[game->pos_x][game->pos_y + 1] == '1'
        || (game->map[game->pos_x][game->pos_y + 1] == 'E' && game->num_c > 0))
        return ;
    if (game->map[game->pos_x][game->pos_y + 1] == 'C')
    {
        game->map[game->pos_x][game->pos_y + 1] = '0';
        game->num_c--;
    }
    if (game->map[game->pos_x][game->pos_y+ 1] == 'E' && game->num_c == 0)
    {
       game->pos_y++;
       game->num_comb++;
       ft_printf("Nombre de mouvements: %d\n", game->num_comb);
       ft_printf("OK.");
       exit_game(game);
    }
    ft_printf("Nombre de mouvements: %d\n", game->num_comb);
    ft_printf("nombre de collectibles restant:%d\n", game->num_c);
    game->pos_y++;
    game->num_comb++;
}

void    ft_move_left(t_map *game)
{
  if (game->map[game->pos_x][game->pos_y - 1] == '1'
        || (game->map[game->pos_x][game->pos_y - 1] == 'E' && game->num_c > 0))
        return ;
    if (game->map[game->pos_x][game->pos_y - 1] == 'C')
    {
        game->map[game->pos_x][game->pos_y - 1] = '0';
        game->num_c--;
    }
    if (game->map[game->pos_x][game->pos_y - 1] == 'E' && game->num_c == 0)
    {
       game->pos_y--;
       game->num_comb++;
       ft_printf("Nombre de mouvements: %d\n", game->num_comb);
       ft_printf("OK.");
       exit_game(game);
    }
    ft_printf("Nombre de mouvements: %d\n", game->num_comb);
    ft_printf("nombre de collectibles restant:%d\n", game->num_c);
    game->pos_y--;
    game->num_comb++;
}

void    ft_move_down(t_map *game)
{
    if (game->map[game->pos_x + 1][game->pos_y] == '1'
        || (game->map[game->pos_x + 1][game->pos_y] == 'E' && game->num_c > 0))
        return ;
    if (game->map[game->pos_x + 1][game->pos_y] == 'C')
    {
        game->map[game->pos_x + 1][game->pos_y] = '0';
        game->num_c--;
    }
    if (game->map[game->pos_x + 1][game->pos_y] == 'E' && game->num_c == 0)
    {
       game->pos_x++;
       game->num_comb++;
       ft_printf("Nombre de mouvements: %d\n", game->num_comb);
       ft_printf("OK.");
       exit_game(game);
    }
    ft_printf("Nombre de mouvements: %d\n", game->num_comb);
    ft_printf("nombre de collectibles restant:%d\n", game->num_c);
    game->pos_x++;
    game->num_comb++;
}

void    ft_move_up(t_map *game)
{
   if (game->map[game->pos_x - 1][game->pos_y] == '1'
        || (game->map[game->pos_x - 1][game->pos_y] == 'E' && game->num_c > 0))
        return ;
    if (game->map[game->pos_x - 1][game->pos_y] == 'C')
    {
        game->map[game->pos_x - 1][game->pos_y] = '0';
        game->num_c--;
    }
    if (game->map[game->pos_x - 1][game->pos_y] == 'E' && game->num_c == 0)
    {
       game->pos_x--;
       game->num_comb++;
       ft_printf("Nombre de mouvements: %d\n", game->num_comb);
       ft_printf("OK.");
       exit_game(game);
    }
       ft_printf("Nombre de mouvements: %d\n", game->num_comb);
        ft_printf("nombre de collectibles restant:%d\n", game->num_c);
    game->pos_x--;
    game->num_comb++;
}

