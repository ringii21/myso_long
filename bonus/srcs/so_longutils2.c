/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_longutils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <abonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:55:16 by abonard           #+#    #+#             */
/*   Updated: 2022/05/25 15:49:13 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/libft.h"
#include "../includes/ft_printf.h"
#include "../../minilibx-linux/mlx.h"

int	ft_check_ber(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (file[i - 1] == 'r' && file[i - 2] == 'e' && file[i - 3] == 'b')
		return (0);
	return (1);
}

int	ft_charge_img(t_map *game, char *img)
{
	char	**path;
	char	*fpath;
	int		i;

	i = 0;
	fpath = ft_strjoin(ASSETS, img);
	path = ft_split(fpath, ' ');
	if (fpath)
		free(fpath);
	while (i < 7)
	{
		game->img[i] = mlx_xpm_file_to_image(game->mlix,
				path[i], &game->x[i], &game->y[i]);
		if (!game->img[i])
			return (ft_error("Cannot load images", game));
		i++;
	}
	ft_free_tabs(path);
	ft_charge_number(game);
	return (0);
}

int	touch_keys(int keycode, t_map *game)
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

int	exit_game(t_map *game)
{
	ft_free_tabs(game->map);
	mlx_destroy_window(game->mlix, game->window);
	free(game->mlix);
	exit(0);
	return (0);
}

void	ft_show_the_rest(t_map *game, int i, int j)
{
	if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlix, game->window,
			game->img[3], j * 32, i * 32);
	else if (i == game->pos_x && j == game->pos_y)
		mlx_put_image_to_window(game->mlix, game->window,
			game->img[2], j * 32, i * 32);
}
