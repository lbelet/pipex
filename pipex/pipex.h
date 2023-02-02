/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbelet <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 08:22:31 by lbelet            #+#    #+#             */
/*   Updated: 2021/12/07 08:24:34 by lbelet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdarg.h>

void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_get_nbr_word(const char *str, char c);
void	ft_free_tab(char **tab, int n);
void	ft_get_words(char **tab, const char *str, char c, int n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_printf(const char *str, ...);
int		ft_putnbr(int nb);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_put_unsigned(unsigned int unb);
int		ft_putnbr_p(unsigned long nbr);
int		ft_putnbr_x(unsigned int nbr);
int		ft_putnbr_x_maj(unsigned int nbr);
int		ft_ws(const char *str, int index);
int		ft_itoc_min(int i);
int		ft_itoc_maj(int i);
int		ft_x(va_list args);
int		ft_x_maj(va_list args);
int		ft_type(va_list args, char c);
int		ft_putchar_arg(va_list args);
int		ft_putstr_arg(va_list args);
int		ft_putnbr_arg(va_list args);
int		ft_put_unsigned_arg(va_list args);
int		ft_pointeur(va_list args);
void	ft_error_fd(int fd, char argv[0]);
void	ft_error_cmd(char *path_cmd, char *cmd);
void	ft_process_one(int fdone, int fdtwo, char **argv, char **envp);
void	ft_process_two(int fdone, int fdtwo, char **argv, char **envp);
int		ft_argc(int argc);

#endif
