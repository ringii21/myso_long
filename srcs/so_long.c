/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <abonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:55:16 by abonard           #+#    #+#             */
/*   Updated: 2022/05/24 18:56:36 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/libft.h"
#include "../includes/ft_printf.h"
#include "../minilibx-linux/mlx.h"

int ft_check_ber(char *file)
{
    int i;

    i = 0;
    while (file[i])
        i++;
    
    if (file[i - 1] == 'r' && file[i - 2] == 'e' && file[i - 3] == 'b')
        return (0);
    
    return (1);
}

int ft_charge_img(t_map *game)
{
    char **path;
    int i;
    (void)game;

    path = ft_split(ASSETS, ' ');
    i = 0;
    while (i < 5)
    {
        game->img[i] = mlx_xpm_file_to_image(game->mlix, path[i], &game->x[i], &game->y[i]);
        if (!game->img[i])
            return(ft_error("Cannot load images"));
        i++;
    }
    ft_free_tabs(path);
    return (0);
}

int touch_keys(int  keycode, t_map *game)
{
    if (keycode == 97)
        ft_move_left(game);
    if (keycode == 119)
        ft_move_up(game);
    if (keycode == 115)
        ft_move_down(game);
    if (keycode == 100)
        ft_move_right(game);
    if (keycode == 65307)
        exit_game(game);
    return (0);
}

int exit_game(t_map *game)
{
    (void)game;
    exit(1);
    return (0);
}

void    ft_show_the_rest(t_map *game, int i, int j)
{
     if (game->map[i][j] == 'C')
                mlx_put_image_to_window(game->mlix, game->window, game->img[3], j * 32 , i * 32);
     else if (i == game->pos_x && j == game->pos_y)
                mlx_put_image_to_window(game->mlix, game->window, game->img[2], j * 32 , i * 32);
}

void    ft_show_img(t_map *game)
{
    int i;
    int j;
    
    i = 0;
    while(i < game->size)
    {
        j = 0;
        while (j < game->len)
        {
            if (game->map[i][j] == '1')
                mlx_put_image_to_window(game->mlix, game->window, game->img[1], j * 32 , i * 32);
            else if (game->map[i][j] == 'E')
                mlx_put_image_to_window(game->mlix, game->window, game->img[4], j * 32 , i * 32);
            else
                mlx_put_image_to_window(game->mlix, game->window, game->img[0], j * 32 , i * 32);
            ft_show_the_rest(game, i, j);
            j++;
       }
       i++;
    }
    
}

int play(t_map *game)
{
  /*  ft_printf("nombre de mouvements:%d\n", game->num_comb);
    ft_printf("nombre de collectibles restant:%d\n", game->num_c);*/
    ft_show_img(game);
    return(0);
}

int    ft_start_game(t_map *game)
{
    game->size++;
    game->res_x = 32 * game->len;
    game->res_y = 32 * game->size;
    game->mlix = mlx_init();
    ft_charge_img(game);
    if (game->mlix == NULL)
        return(ft_error("mlx is NULL"));
    game->window = mlx_new_window(game->mlix, game->res_x, game->res_y, "Smack my ass like a drum");
    if (game->window == NULL)
        return(ft_error("Cannot create window"));
    mlx_hook(game->window, 2, 1L << 0, touch_keys, game);
	mlx_hook(game->window, 33, 1L << 5, exit_game, game);
	mlx_loop_hook(game->mlix, play, game);
	mlx_loop(game->mlix);
    return (0);
}

int main (int argc, char **argv)
{
    t_map   game;
    
    if (argc != 2)
        return(ft_error("Wrong number of arguments"));
    if (ft_parcing(&game, argv[1]) == 1)
        return (1);
    ft_start_game(&game);
    return (0);
}