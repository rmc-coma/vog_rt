/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 08:41:10 by calemany          #+#    #+#             */
/*   Updated: 2016/07/25 18:29:22 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdlib.h>

void	ft_bzero(void *str, size_t n);
void	*ft_memset(void *str, int val, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t n);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_islower(int c);
int		ft_isupper(int c);
int		ft_isdigit(int c);
int		ft_isxdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strsub2(char const *begin, char const *end);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strappend(char **dst, char const *to_append);
char	*ft_strtrim(char const *s);
char	**ft_strsplit(char const *s, char c);
char	**ft_strsplit_str(char const *s, char const *c);
char	*ft_itoa(int n);
int		ft_isblank(int c);
int		ft_isquote(int c);
char	*ft_strclean(char const *s, int(*to_del)(char));
char	*ft_strassign(char **dst, char *s);
int		ft_strisnbr(char const *str);
char	*ft_strsum(char const *first, ...);
int		ft_strcount(char const *s, char c);
void	ft_strfree(char *s);
void	ft_strtabfree(char **tab);
int		ft_strcountend(char const *s, char const *end, char c);
int		ft_strtoint(char const *s, int *n);
int		ft_strtouns(char const *s, unsigned int *n);
int		ft_strhextoint(char const *s, int *n);
int		ft_strhextouns(char const *s, unsigned int *n);
char	*ft_strsep(char **stringp, const char *delim);

#endif
