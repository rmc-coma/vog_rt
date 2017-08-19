/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 05:15:37 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/03/01 07:14:00 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "camera.h"

t_ray	ray_from_coords(const t_ivec2 coords, t_camera *const camera,
		const float ratio)
{
	t_vec2	vps;
	t_vec3	ctvp;
	float	cdl;
	t_vec3	ncd;
	t_ray	ray;

	vps.y = camera->near * tan(RAD(0.5f * camera->fov));
	vps.x = vps.y * ratio;
	cdl = sqrt(camera->dir.x * camera->dir.x + camera->dir.y * camera->dir.y
			+ camera->dir.z * camera->dir.z);
	ncd = vec3(camera->dir.x / cdl, camera->dir.y / cdl, camera->dir.z / cdl);
	ctvp = vec3(camera->near * ncd.x, camera->near
			* ncd.y, camera->near * ncd.z);
	ray.pos = vec3(camera->pos.x + ctvp.x, camera->pos.y
			+ ctvp.y, camera->pos.z + ctvp.z);
	ray.dir = vec3(ctvp.x + coords.x * camera->right.x + coords.y
			* camera->up.x, ctvp.y + coords.x * camera->right.y
			+ coords.y * camera->up.y, ctvp.z + coords.x * camera->right.z
			+ coords.y * camera->up.z);
	cdl = sqrt(ray.dir.x * ray.dir.x + ray.dir.y * ray.dir.y
			+ ray.dir.z * ray.dir.z);
	ray.dir = vec3(ray.dir.x / cdl, ray.dir.y / cdl, ray.dir.z / cdl);
	return (ray);
}
