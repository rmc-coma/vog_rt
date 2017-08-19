/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:49:21 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/28 18:49:18 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H

# include "environment.h"
# include <pthread.h>

t_scene			*loop_start(t_context *const context, t_gui *const gui,
							t_scene *const scene, t_input *const input);
void			*loop_thread(void *arg);

#endif
