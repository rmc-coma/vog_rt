/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 03:23:31 by jleu              #+#    #+#             */
/*   Updated: 2017/03/02 01:34:09 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img_parsing.h"

t_img		*img_parse(t_img *const img, const char *const path)
{
	img->type = img_get_type(path);
	if (img->type == IMG_BMP)
		img->value.bmp = img_parse_bmp(img_new_bmp(), path);
	return (img);
}

t_img		*img_glprep(t_img *const img)
{
	return (img_argb_to_rgba(img_rgb_to_rgba(img_hrev(img))));
}
