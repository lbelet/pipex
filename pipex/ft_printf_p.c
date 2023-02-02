/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelet <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:13:54 by lbelet            #+#    #+#             */
/*   Updated: 2021/11/08 11:36:09 by lbelet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_pointeur(va_list args)
{
	unsigned long	adresse;
	int				i;

	adresse = va_arg(args, unsigned long);
	i = ft_putstr("0x");
	i += ft_putnbr_p(adresse);
	return (i);
}

int	ft_itoc_min(int i)
{
	if (i >= 0 && i <= 9)
		return (i + '0');
	if (i >= 10 && i <= 36)
		return (i + 'a' - 10);
	return (i);
}

int	ft_putnbr_p(unsigned long nbr)
{
	int	i;

	i = 0;
	if (nbr >= 16)
	{
		i = ft_putnbr_p(nbr / 16);
		i += ft_putchar(ft_itoc_min(nbr % 16));
	}
	else
		i += ft_putchar(ft_itoc_min(nbr % 16));
	return (i);
}
