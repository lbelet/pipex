/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelet <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:27:07 by lbelet            #+#    #+#             */
/*   Updated: 2021/11/08 12:21:51 by lbelet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_x(va_list args)
{
	int				i;
	unsigned int	nbr;

	i = 0;
	nbr = va_arg(args, unsigned int);
	i = ft_putnbr_x(nbr);
	return (i);
}

int	ft_putnbr_x(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr >= 16)
	{
		i = ft_putnbr_x(nbr / 16);
		i += ft_putchar(ft_itoc_min(nbr % 16));
	}
	else
		i += ft_putchar(ft_itoc_min(nbr % 16));
	return (i);
}

int	ft_itoc_maj(int i)
{
	if (i >= 0 && i <= 9)
		return (i + '0');
	if (i >= 10 && i <= 36)
		return (i + 'A' - 10);
	return (i);
}

int	ft_x_maj(va_list args)
{
	int				i;
	unsigned int	nbr;

	i = 0;
	nbr = va_arg(args, unsigned int);
	i = ft_putnbr_x_maj(nbr);
	return (i);
}

int	ft_putnbr_x_maj(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr >= 16)
	{
		i = ft_putnbr_x_maj(nbr / 16);
		i += ft_putchar(ft_itoc_maj(nbr % 16));
	}
	else
		i += ft_putchar(ft_itoc_maj(nbr % 16));
	return (i);
}
