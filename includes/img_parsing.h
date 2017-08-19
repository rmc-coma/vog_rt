/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_parsing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:45:12 by jleu              #+#    #+#             */
/*   Updated: 2017/02/28 18:48:24 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_PARSING_H
# define IMG_PARSING_H

# define BMP_ID			0x00
# define BMP_SIZE		0x02
# define BMP_OFFSET		0x0A
# define BMP_DIB_SIZE	0x0E
# define BMP_WIDTH		0x12
# define BMP_HEIGHT		0x16
# define BMP_BPP		0x1C
# define BMP_MASK_R		0x36
# define BMP_MASK_G		0x3A
# define BMP_MASK_B		0x3E
# define BMP_MASK_A		0x42
# define BMP_ENDIAN		0x46

typedef	unsigned char		t_byte;
typedef	unsigned short int	t_word;
typedef unsigned int		t_dword;

typedef enum				e_img_type
{
	IMG_INVALID,
	IMG_BMP
}							t_img_type;

typedef struct				s_img_bmp
{
	t_byte		*data;
	t_dword		width;
	t_dword		height;
	t_dword		size;
	t_dword		offset;
	t_word		id;
	t_dword		dib_size;
	t_word		bpp;
	t_dword		mask_r;
	t_dword		mask_g;
	t_dword		mask_b;
	t_dword		mask_a;
	t_dword		endian;
}							t_img_bmp;

typedef union				u_img_value
{
	t_img_bmp				*bmp;
}							t_img_value;

typedef struct				s_img
{
	t_img_type				type;
	t_img_value				value;
}							t_img;

t_img_type					img_get_type(const char *const path);
t_img						*img_new(void);
t_img						*img_parse(t_img *const img,
										const char *const path);
t_img						*img_hrev(t_img *const img);
t_img						*img_rgb_to_rgba(t_img *const img);
t_img						*img_argb_to_rgba(t_img *const img);
t_img						*img_glprep(t_img *const img);

t_img_bmp					*img_new_bmp(void);
t_img_bmp					*img_parse_bmp(t_img_bmp *const img,
											const char *const path);
t_img_bmp					*img_hrev_bmp(t_img_bmp *const img);
t_img_bmp					*img_rgb_to_rgba_bmp(t_img_bmp *const img);
t_img_bmp					*img_argb_to_rgba_bmp(t_img_bmp *const img);

#endif
