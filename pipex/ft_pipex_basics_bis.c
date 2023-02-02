/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_basics_bis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelet <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 09:10:58 by lbelet            #+#    #+#             */
/*   Updated: 2021/12/07 09:18:31 by lbelet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_get_words(char **tab, const char *str, char c, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (*str == c)
			str++;
		while (*(str + j) && *(str + j) != c)
			j++;
		tab[i] = ft_substr(str, 0, j);
		if (!tab[i])
		{
			ft_free_tab(tab, i - 1);
			return ;
		}
		str += j;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		n;
	char	**tab;

	if (!s)
		return (NULL);
	n = ft_get_nbr_word(s, c);
	tab = malloc(n + 1);
	if (!tab)
		return (NULL);
	tab[n] = malloc(0);
	tab[n] = NULL;
	ft_get_words(tab, s, c, n);
	return (tab);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dst = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}
