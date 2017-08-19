/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 05:29:59 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/28 18:26:22 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOOL_H
# define BOOL_H

# ifndef FALSE
#  define FALSE (t_bool)(0)
# endif
# ifndef TRUE
#  define TRUE  (t_bool)(!FALSE)
# endif

typedef unsigned char	t_bool;

#endif
