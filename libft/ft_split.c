/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <abonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:42:36 by abonard           #+#    #+#             */
/*   Updated: 2021/12/09 11:46:47 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(const char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			word++;
		i++;
	}
	return (word);
}

void	ft_copy(char *dest, const char *src, char c)
{
	int	i;

	i = 0;
	while (src[i] && (src[i] != c))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	ft_free(char **dest, int i)
{
	while (i)
	{
		free(dest[i]);
		i--;
	}
	free(dest);
}

void	ft_transfert(char **tab, const char *str, char c)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			j = 0;
			while (str[i + j] != c && str[i + j] != '\0')
				j++;
			tab[word] = malloc(sizeof(char) * j + 1);
			if (tab[word] == NULL)
				return (ft_free(tab, word));
			ft_copy(tab[word], str + i, c);
			i = i + j;
			word++;
		}
	}
}

char	**ft_split(const char *str, char c)
{
	char	**tab;
	int		word;

	if (str == NULL)
		return (NULL);
	word = count_word(str, c);
	tab = malloc(sizeof(char *) * (word + 1));
	if (tab == NULL)
		return (NULL);
	tab[word] = 0;
	ft_transfert(tab, str, c);
	return (tab);
}
