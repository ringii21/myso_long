/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <abonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:13:14 by abonard           #+#    #+#             */
/*   Updated: 2021/12/07 19:12:32 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_l;
	int		s2_l;
	int		i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1_l + s2_l + 1));
	if (str == NULL)
		return (NULL);
	str[s1_l + s2_l] = '\0';
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	i = 0;
	while (s2[i])
	{
		str[s1_l + i] = s2[i];
		i++;
	}
	return (str);
}
