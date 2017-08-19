/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 01:32:38 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/02 01:34:12 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img_parsing.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

t_img		*img_new(void)
{
	return ((t_img *)ft_memalloc(sizeof(t_img)));
}

t_img_type	img_get_type(const char *const path)
{
	int			fd;
	t_byte		tmp[2];
	t_img_type	type;

	if ((fd = open(path, O_RDONLY)) < 1)
		return (IMG_INVALID);
	type = IMG_INVALID;
	if (read(fd, &(tmp[0]), 2) == 2)
	{
		if (ft_strncmp((char *)(&tmp[0]), "BM", 2) == 0)
			type = IMG_BMP;
	}
	close(fd);
	return (type);
}

t_img		*img_hrev(t_img *const img)
{
	if (img->type == IMG_BMP)
		img_hrev_bmp(img->value.bmp);
	return (img);
}

t_img		*img_rgb_to_rgba(t_img *const img)
{
	if (img->type == IMG_BMP)
		img_rgb_to_rgba_bmp(img->value.bmp);
	return (img);
}

t_img		*img_argb_to_rgba(t_img *const img)
{
	if (img->type == IMG_BMP)
		img_argb_to_rgba_bmp(img->value.bmp);
	return (img);
}
