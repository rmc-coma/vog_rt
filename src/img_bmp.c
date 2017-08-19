/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_bmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 02:33:21 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/02 03:10:04 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img_parsing.h"
#include "ft_mem.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

t_img_bmp	*img_new_bmp(void)
{
	return ((t_img_bmp *)ft_memalloc(sizeof(t_img_bmp)));
}

t_img_bmp	*img_hrev_bmp(t_img_bmp *const img)
{
	t_byte	*tmp;
	int		i;
	int		j;
	int		k;
	int		l;

	if (!(tmp = (t_byte *)ft_memalloc(img->size - img->offset)))
		return ((void *)0);
	i = 0;
	while (i < (int)(img->height))
	{
		j = 0;
		k = (img->height - i - 1) * img->width;
		l = i * img->width;
		while (j < (int)(img->width))
		{
			((t_dword *)tmp)[l + j] = ((t_dword *)(img->data))[k + j];
			++j;
		}
		++i;
	}
	free(img->data);
	img->data = tmp;
	return (img);
}

t_byte		*img_rgb_to_rgba_bmp_iterate(t_byte *tmp, t_img_bmp *const img)
{
	int		i;
	int		j;
	int		k;
	int		l;

	i = 0;
	k = 0;
	while (i < ((int)(img->height) << 2))
	{
		j = 0;
		l = 0;
		while (j < ((int)(img->width) << 2))
		{
			tmp[i * img->width + j] = img->data[k * img->width + l];
			tmp[i * img->width + j + 1] = img->data[k * img->width + l + 1];
			tmp[i * img->width + j + 2] = img->data[k * img->width + l + 2];
			l += 3;
			j += 4;
		}
		k += 3;
		i += 4;
	}
	return (tmp);
}

t_img_bmp	*img_rgb_to_rgba_bmp(t_img_bmp *const img)
{
	t_byte	*tmp;

	if (img->bpp >= 4)
		return (img);
	img->size += ((img->size - img->offset) >> 2);
	if (!(tmp = (t_byte *)ft_memalloc(img->size)))
		return ((void *)0);
	tmp = img_rgb_to_rgba_bmp_iterate(tmp, img);
	free(img->data);
	img->data = tmp;
	img->bpp = 4;
	return (img);
}

t_img_bmp	*img_argb_to_rgba_bmp(t_img_bmp *const img)
{
	int			i;
	int			j;
	int			max_i;
	int			max_j;
	t_byte		tmp;

	if (img->bpp == 3 || (img->mask_a == 0x000000FF && img->mask_r ==
		0xFF000000 && img->mask_g == 0x00FF0000 && img->mask_b == 0x0000FF00))
		return (img);
	max_i = (int)(img->height) * 4;
	max_j = (int)(img->width) * 4;
	i = 0;
	while (i < max_i)
	{
		j = 0;
		while (j < max_j)
		{
			tmp = img->data[i * img->width + j];
			img->data[i * img->width + j] = img->data[i * img->width + j + 3];
			img->data[i * img->width + j + 3] = tmp;
			j += 4;
		}
		i += 4;
	}
	return (img);
}
