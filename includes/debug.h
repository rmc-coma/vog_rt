/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:32:09 by jleu              #+#    #+#             */
/*   Updated: 2017/02/28 18:32:15 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

void	debug_put_str(const char *const str);
void	debug_put_int(const int nbr);
void	debug_put_str_int(const char *const str, const int nbr);
void	debug_put_str_str(const char *const str1, const char *const str2);

#endif
