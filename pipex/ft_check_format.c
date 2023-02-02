/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelet <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:54:00 by lbelet            #+#    #+#             */
/*   Updated: 2021/11/08 10:00:21 by lbelet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_type(va_list args, char c)
{
	int	add;

	add = 0;
	if (c == 'c')
		add = ft_putchar_arg(args);
	if (c == 's')
		add = ft_putstr_arg(args);
	if (c == 'd' || c == 'i')
		add = ft_putnbr_arg(args);
	if (c == 'u')
		add = ft_put_unsigned_arg(args);
	if (c == 'p')
		add = ft_pointeur(args);
	if (c == 'x')
		add = ft_x(args);
	if (c == 'X')
		add = ft_x_maj(args);
	if (c == '%')
		add = ft_putchar('%');
	return (add);
}
