/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <abonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:22:19 by abonard           #+#    #+#             */
/*   Updated: 2022/05/24 18:23:35 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/libft.h"
#include "../includes/ft_printf.h"

int ft_count_element(t_map *game, int p, int c, int e)
{
    if (p > 1 || p == 0)
        return(ft_error("Only one player should be in this mofo map"));
    if (c < 1)
        return (ft_error("MORE COINS, WE ARE GREEDY"));
    game->num_c = c;
    if (e < 1)
        return (ft_error("Dont you wanna end the game?"));
    return (0);
}

int ft_element(t_map *game, int p, int c, int e)
{
    int i;
    int v;

    i = 1;
    while(game->map[i])
    {
        v = 1;
        while(game->map[i][v])
        {
            if (game->map[i][v] == 'P')
            {
                game->map[i][v] = '0';
                game->pos_x = i;
                game->pos_y = v;
                p++;
            }
            if (game->map[i][v] == 'E')
                e++;
            if (game->map[i][v] == 'C')
                c++;
            v++;
        }
        i++;
    }
    return (ft_count_element(game, p, c, e));
}

int ft_is_rectangle(t_map *game)
{
    int i;
    int b;
    
    i = 0;
    b = 0;
    game->size = ft_strlen_map(game->map) - 1;
    game->len = ft_strlen(game->map[0]);
    while (game->map && game->map[i])
    {
        b = ft_strlen(game->map[i]);
        if (game->len != b)
            return (1);
        i++;
    }
    return (0);
}

int ft_surrounded_walls(t_map *game)
{
    int i;

    i = 0;
    while (game->map[0][i])
    {
        if (game->map[0][i] != '1')
            return(1);
        i++;
    }
    i = 0;
    while (game->map[game->size][i])
    {
        if (game->map[game->size][i] != '1')
            return(1);
        i++;
    }
    i = 0;
    while (game->map[i])
    {
        if (game->map[i][0] != '1' || game->map[i][ft_strlen(game->map[i]) - 1] != '1')
            return (1);
        i++;
    }
    return (0);
}

int ft_parcing(t_map *game, char *file)
{  
    int fd;
    char buff[5000];
    int lire;

    ft_bzero(buff, 5000);
    if (ft_check_ber(file) == 1)
        return(ft_error("this is not a ber file you mofo"));
    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (ft_error("Cannot open the file"));
    lire = read(fd, buff, 5000);
    if (lire < 0 || lire > 5000)
        return(ft_error("Cannot read the file"));
    game->map = ft_split(buff, '\n');
    if (ft_is_rectangle(game) == 1 || ft_surrounded_walls(game) == 1)
        return(ft_error("Map is not closed or rectangle"));
    ft_check_char(game->map);
    ft_element(game, 0, 0, 0);
    return (0);
}