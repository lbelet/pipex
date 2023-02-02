/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelet <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 08:15:52 by lbelet            #+#    #+#             */
/*   Updated: 2021/12/07 09:37:23 by lbelet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_process_one(int fdone, int fdtwo, char **argv, char **envp)
{
	int		fd1;
	char	**cmd1;
	char	*path_cmd1;

	fd1 = open(argv[1], O_RDONLY);
	ft_error_fd(fd1, argv[1]);
	if (access(argv[1], R_OK) != 0)
		ft_printf("Probleme d'access au fichier: %s\n", argv[1]);
	cmd1 = ft_split(argv[2], ' ');
	path_cmd1 = ft_strjoin("/bin/", cmd1[0]);
	if (open(path_cmd1, O_RDONLY) < 0)
	{
		path_cmd1 = ft_strjoin("/usr/bin/", cmd1[0]);
		if (open(path_cmd1, O_RDONLY) < 0)
		{
			ft_printf("zsh: %s: %s\n", "command not found", cmd1[0]);
			exit(0);
		}
	}
	dup2(fd1, STDIN_FILENO);
	dup2(fdtwo, STDOUT_FILENO);
	close(fd1);
	close(fdone);
	close(fdtwo);
	execve(path_cmd1, cmd1, envp);
}

void	ft_process_two(int fdone, int fdtwo, char **argv, char **envp)
{
	int		fd2;
	char	**cmd2;
	char	*path_cmd2;

	fd2 = open(argv[4], O_WRONLY | O_CREAT, 0777);
	if (access(argv[4], W_OK) != 0)
		ft_printf("Probleme d'access au fichier: %s\n", argv[4]);
	ft_error_fd(fd2, argv[4]);
	cmd2 = ft_split(argv[3], ' ');
	path_cmd2 = ft_strjoin("/bin/", cmd2[0]);
	if (open(path_cmd2, O_RDONLY) < 0)
	{
		path_cmd2 = ft_strjoin("/usr/bin/", cmd2[0]);
		if (open(path_cmd2, O_RDONLY) < 0)
		{
			ft_printf("zsh: %s: %s\n", "command not found", cmd2[0]);
			exit(0);
		}
	}
	dup2(fdone, STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
	close(fdone);
	close(fdtwo);
	close(fd2);
	execve(path_cmd2, cmd2, envp);
}
