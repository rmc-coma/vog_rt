/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 14:18:01 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/28 18:37:10 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H

# include "parameters.h"
# include "window.h"
# include "input.h"

typedef struct			s_environment
{
	t_window	window;
	t_input		input;
}						t_environment;

t_environment			*environment_new(void);
int						environment_init(t_environment *const env);

#endif
