/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 15:00:25 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/06 05:27:39 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H

# include <string.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strnew(size_t size);
char	*ft_itoa(int n);
char	*ft_itoal(int n, char *const str);
char	*ft_ftoal(float f, char *const str);
float	ft_atof(char *str);

#endif
