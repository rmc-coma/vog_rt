/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 08:44:02 by calemany          #+#    #+#             */
/*   Updated: 2015/03/23 12:36:45 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OUTPUT_H
# define FT_OUTPUT_H

# include <stdlib.h>
# include <stdarg.h>

void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
void	ft_putnbr(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnchar(char c, size_t n);
void	ft_putnchar_fd(char c, size_t n, int fd);
void	ft_putline_fd(char const *s, int fd);
void	ft_putnstr(char const *s, ...);
void	ft_putnstr_list(va_list list);
void	ft_putnstr_fd(int fd, ...);
void	ft_putnstr_fd_list(int fd, va_list list);
void	ft_put_fd(int fd, char const *s, ...);
void	ft_put_fd_list(int fd, char const *s, va_list list);
void	ft_put(char const *s, ...);
void	ft_putuint_fd(unsigned int u, int fd);
void	ft_putint_fd(int n, int fd);
void	ft_putint(int i);
void	ft_putuint(unsigned int u);
void	ft_putaddr(void const *i);
void	ft_putaddr_fd(void const *i, int fd);
void	ft_puthex(unsigned int i);
void	ft_puthex_fd(unsigned int i, int fd);

#endif
