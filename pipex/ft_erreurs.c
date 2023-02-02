/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erreurs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelet <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 08:24:51 by lbelet            #+#    #+#             */
/*   Updated: 2021/12/07 09:25:16 by lbelet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_argc(int argc)
{
	if (argc == 5)
		return (1);
	else
	{
		ft_printf("lancer la commande de la facon suivante:\n");
		ft_printf("./prog file1 cmd1 cmd2 file2\n");
		return (0);
	}
}

void	ft_error_fd(int fd, char *argv)
{
	if (fd < 0)
	{
		ft_printf("zsh: %s: %s\n", strerror(errno), argv);
		exit(0);
	}
}

void	ft_error_cmd(char *path_cmd, char *cmd)
{
	if (open(path_cmd, O_RDONLY) < 0)
		ft_printf("zsh: %s: %s\n", "command not found", cmd);
}
