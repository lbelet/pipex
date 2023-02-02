/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_basics.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelet <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 08:57:41 by lbelet            #+#    #+#             */
/*   Updated: 2021/12/07 09:01:34 by lbelet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	size_t			i;

	i = 0;
	d = dst;
	while (i < n)
	{
		if (d + i == src)
			break ;
		d[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (start > ft_strlen(s))
		len = 0;
	else if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	str = malloc(len + 1);
	if (!str || !s)
		return (NULL);
	ft_memcpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}

int	ft_get_nbr_word(const char *str, char c)
{
	int	nbr;
	int	verif;

	verif = 0;
	nbr = 0;
	while (*str != '\0')
	{
		if (*str == c)
		{
			verif = 0;
			str++;
			continue ;
		}
		if (!verif)
		{
			verif = 1;
			nbr++;
		}
		str++;
	}
	return (nbr);
}

void	ft_free_tab(char **tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
