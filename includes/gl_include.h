/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_include.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:39:13 by jleu              #+#    #+#             */
/*   Updated: 2017/02/28 18:39:15 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_INCLUDE_H
# define GL_INCLUDE_H

# if defined(__APPLE__) && defined(__MACH__)
#  include <OpenGL/gl3.h>
# elif defined(__linux__)
#  define GL_GLEXT_PROTOTYPES
#  include <GL/glcorearb.h>
# elif defined(_WIN32)

# endif

#endif
