/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solong_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <abonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:22:19 by abonard           #+#    #+#             */
/*   Updated: 2022/05/25 15:25:48 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/libft.h"
#include "../includes/ft_printf.h"

int	ft_check_char(char **map, t_map *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P'
				&& map[i][j] != 'C' && map[i][j] != 'E')
				return (ft_error("INVALID CHAR IN MAP", game));
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_free_tabs(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	ft_strlen_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	ft_error(char *str, t_map *game)
{
	if (game->map)
		ft_free_tabs(game->map);
	ft_printf("Error: %s\n", str);
	exit(1);
	return (1);
}

char	*ft_strjoinfree(char const *s1, char *s2, int nb)
{
	char	*str;
	char	*to_free1;
	char	*to_free2;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == 0)
		return (NULL);
	to_free1 = (char *)s1;
	to_free2 = (char *)s2;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = (char *)malloc(len_s1 + len_s2 + 1);
	if (!str)
		return (0);
	ft_memcpy(str, s1, len_s1);
	ft_memcpy(str + ft_strlen(s1), s2, len_s2 + 1);
	if (to_free1 && (nb == 0 || nb == 2) && nb != -1)
		free(to_free1);
	if (to_free2 && (nb == 1 || nb == 2) && nb != -1)
		free(to_free2);
	to_free1 = 0;
	to_free2 = 0;
	return (str);
}
