/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solong_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <abonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:22:19 by abonard           #+#    #+#             */
/*   Updated: 2022/05/24 16:26:02 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/libft.h"
#include "../includes/ft_printf.h"

int ft_check_char(char **map)
{
    int i;
    int j;
    
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P'
                && map[i][j] != 'C' && map[i][j] != 'E')
                return (ft_error("INVALID CHAR IN MAP"));
            j++;
        }
        i++;
    }
    return (0);
}

void    ft_free_tabs(char **map)
{
    int i;

    i = 0;
    while(map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

int ft_strlen_map(char **map)
{
    int i;

    i = 0;
    while(map[i])
        i++;
    return (i);
}

int ft_error(char *str)
{
    ft_printf("Error: %s\n", str);
    exit(1);
    return (1);
}