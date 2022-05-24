/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <abonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:55:16 by abonard           #+#    #+#             */
/*   Updated: 2022/05/24 20:11:13 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/libft.h"
#include "../includes/ft_printf.h"
#include "../../minilibx-linux/mlx.h"

char	**set_digits_path(void)
{
	char	*path;
	char	**s_path;

	path = NULL;
	s_path = NULL;
	path = ft_strdup("./as/0.xpm ");
	path = ft_strjoinfree(path, "./as/1.xpm ./as/2.xpm ./as/3.xpm ", 0);
	path = ft_strjoinfree(path, "./as/4.xpm ./as/5.xpm ./as/6.xpm ", 0);
	path = ft_strjoinfree(path, "./as/7.xpm ./as/8.xpm ./as/9.xpm", 0);
	if (path == NULL)
		return (NULL);
	s_path = ft_split(path, ' ');
	if (s_path == NULL)
		return (NULL);
	free(path);
	return (s_path);
}

int ft_charge_number(t_map *game)
{
    char **path;
    int i;

    i = 0;  
    path = set_digits_path();
    while (i < 10)
    {
        game->score[i] = mlx_xpm_file_to_image(game->mlix, path[i], &game->dx[i], &game->dy[i]);
        if (!game->score[i])
            return(ft_error("Cannot load images"));
        i++;
    }
    ft_free_tabs(path);
    return (0);
}

int ft_get_dixaine(int nb)
{
	int	nbr;
	int	i;

	nbr = nb;
	i = 0;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

void    ft_put_digit(t_map *game)
{
    int dixaine;

    dixaine = ft_get_dixaine(game->num_comb);
    if (dixaine == 1)
        mlx_put_image_to_window(game->mlix, game->window, game->score[game->num_comb], 0, 0);
    else if (dixaine == 2)
    {
        mlx_put_image_to_window(game->mlix, game->window, game->score[game->num_comb / 10], 0, 0);
        mlx_put_image_to_window(game->mlix, game->window, game->score[game->num_comb % 10], 1 * 32, 0);
    }
    else if (dixaine == 3)
    {
        mlx_put_image_to_window(game->mlix, game->window, game->score[game->num_comb / 100], 0, 0);
        dixaine = game->num_comb % 100;
        mlx_put_image_to_window(game->mlix, game->window, game->score[dixaine / 10], 1 * 32, 0);
        mlx_put_image_to_window(game->mlix, game->window, game->score[dixaine % 10], 2 * 32, 0);
    }
}