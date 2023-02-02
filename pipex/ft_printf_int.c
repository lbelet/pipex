/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelet <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:26:05 by lbelet            #+#    #+#             */
/*   Updated: 2021/11/08 12:34:58 by lbelet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_putnbr(int nb)
{
	int				i;
	unsigned int	ui;

	i = 0;
	ui = 0;
	if (nb < 0)
	{
		ui = (unsigned int)(-nb);
		ft_putchar('-');
		i++;
	}
	else
		ui = (unsigned int)nb;
	if (ui > 9)
	{
		i += ft_putnbr(ui / 10);
		i += ft_putnbr(ui % 10);
	}
	else
		i += ft_putchar(ui + '0');
	return (i);
}

int	ft_putnbr_arg(va_list args)
{
	int	i;
	int	nb;

	nb = va_arg(args, int);
	i = ft_putnbr(nb);
	return (i);
}

int	ft_put_unsigned(unsigned int unb)
{
	int	i;

	i = 0;
	if (unb > 9)
	{
		i += ft_put_unsigned(unb / 10);
		i += ft_put_unsigned(unb % 10);
	}
	else
		i += ft_putchar(unb + '0');
	return (i);
}

int	ft_put_unsigned_arg(va_list args)
{
	unsigned int	unb;
	int				i;

	unb = va_arg(args, unsigned int);
	i = ft_put_unsigned(unb);
	return (i);
}
