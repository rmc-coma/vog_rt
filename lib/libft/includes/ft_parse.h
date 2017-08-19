/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calemany <calemany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 11:26:14 by calemany          #+#    #+#             */
/*   Updated: 2015/02/18 12:59:51 by calemany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H

char	*ft_strskip(char const *s, char const *skip);
char	*ft_strreach(char const *s, char const *reach);
char	*ft_strsearch(char const *s, int (*f)(char));
char	*ft_strwordcmp(char const *str, char const *word);
char	*ft_strjoinpath(char const *path, char const *name);
char	*ft_strwordend(char const *s);
char	**ft_strwordsplit(char const *s);
char	*ft_strskipspaces(char const *s);
char	*ft_strworddup(char const *s, char const **end);
char	**ft_tokget(char const *s, char const **sep, char const **end);
char	*ft_tokdup(char const *s, char const **sep, char const **end);
char	*ft_toksearch(char const *s, char const **sep);
char	**ft_toksplit(char const *s, char const **sep);

#endif
