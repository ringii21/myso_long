/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <abonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:55:16 by abonard           #+#    #+#             */
/*   Updated: 2022/05/25 15:50:59 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/libft.h"
#include "../includes/ft_printf.h"
#include "../minilibx-linux/mlx.h"

void	ft_show_the_rest(t_map *game, int i, int j)
{
	if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlix,
			game->window, game->img[3], j * 32, i * 32);
	else if (i == game->pos_x && j == game->pos_y)
		mlx_put_image_to_window(game->mlix, game->window,
			game->img[2], j * 32, i * 32);
}

void	ft_show_img(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->size)
	{
		j = 0;
		while (j < game->len)
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlix, game->window,
					game->img[1], j * 32, i * 32);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlix, game->window,
					game->img[4], j * 32, i * 32);
			else
				mlx_put_image_to_window(game->mlix, game->window,
					game->img[0], j * 32, i * 32);
			ft_show_the_rest(game, i, j);
			j++;
		}
		i++;
	}
}

int	play(t_map *game)
{
	ft_show_img(game);
	return (0);
}

int	ft_start_game(t_map *game)
{
	game->size++;
	game->res_x = 32 * game->len;
	game->res_y = 32 * game->size;
	game->mlix = mlx_init();
	ft_charge_img(game);
	if (game->mlix == NULL)
		return (ft_error("mlx is NULL", game));
	game->window = mlx_new_window(game->mlix, game->res_x,
			game->res_y, "So Long");
	if (game->window == NULL)
		return (ft_error("Cannot create window", game));
	mlx_hook(game->window, 2, 1L << 0, touch_keys, game);
	mlx_hook(game->window, 33, 1L << 5, exit_game, game);
	mlx_loop_hook(game->mlix, play, game);
	mlx_loop(game->mlix);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	game;

	if (argc != 2)
		return (ft_error("Wrong number of arguments", &game));
	if (ft_parcing(&game, argv[1]) == 1)
		return (1);
	ft_start_game(&game);
	return (0);
}
