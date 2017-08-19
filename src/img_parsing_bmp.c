/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_parsing_bmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 07:59:35 by jleu              #+#    #+#             */
/*   Updated: 2017/03/02 03:18:49 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "img_parsing.h"
#include "ft_mem.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define ENDIAN_LITTLE	0x206E6957

static t_dword	rev_hex4(t_byte *ptr)
{
	return ((t_dword)(ptr[0] + (ptr[1] << 8) +
		(ptr[2] << 16) + (ptr[3] << 24)));
}

static t_word	rev_hex2(t_byte *ptr)
{
	return ((t_word)(ptr[0] + (ptr[1] << 8)));
}

static void		img_parse_bmp_stuff(t_img_bmp *const img, t_byte *const header)
{
	if (img->bpp > 4)
		img->bpp >>= 3;
	if (img->dib_size >= 108)
	{
		img->mask_r = header[BMP_MASK_R];
		img->mask_g = header[BMP_MASK_G];
		img->mask_b = header[BMP_MASK_B];
		img->mask_a = header[BMP_MASK_A];
		img->endian = header[BMP_ENDIAN];
		if (img->endian == ENDIAN_LITTLE)
		{
			img->width = rev_hex4(&header[BMP_WIDTH]);
			img->height = rev_hex4(&header[BMP_HEIGHT]);
			img->bpp = rev_hex2(&header[BMP_BPP]);
			img->size = rev_hex4(&header[BMP_DIB_SIZE]);
		}
	}
	else
	{
		img->mask_a = 0xFF000000;
		img->mask_r = 0x00FF0000;
		img->mask_g = 0x0000FF00;
		img->mask_b = 0x000000FF;
	}
}

t_img_bmp		*img_parse_bmp(t_img_bmp *const img, const char *const path)
{
	int			fd;
	t_byte		tmp[18];
	t_byte		*header;

	if (!(img && (fd = open(path, O_RDONLY)) && read(fd, &(tmp[0]), 18) == 18 &&
				ft_strncmp((char *)(&(tmp[0])), "BM", 2) == 0))
		return ((void *)0);
	img->id = tmp[BMP_ID] == 0x42 ? 0x424D : 0x4D42;
	img->size = rev_hex4(&tmp[BMP_SIZE]);
	img->offset = rev_hex4(&tmp[BMP_OFFSET]);
	img->dib_size = rev_hex4(&tmp[BMP_DIB_SIZE]);
	header = (t_byte *)ft_memalloc(img->dib_size + 14);
	ft_memcpy(header, &tmp[0], 18);
	read(fd, &(header[18]), img->dib_size - 4);
	img->width = rev_hex4(&header[BMP_WIDTH]);
	img->height = rev_hex4(&header[BMP_HEIGHT]);
	img->bpp = rev_hex2(&header[BMP_BPP]);
	img_parse_bmp_stuff(img, header);
	if (!(img->data = (t_byte *)ft_memalloc(img->size - img->offset)))
		return ((void *)0);
	read(fd, img->data, img->size - img->offset);
	close(fd);
	return (img);
}
