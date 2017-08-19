/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 17:15:05 by rmc-coma          #+#    #+#             */
/*   Updated: 2017/02/28 19:43:54 by jleu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "camera.h"
# include "object.h"
# include "transform.h"
# include "light.h"
# include "mesh.h"
# include "geometry.h"
# include "sphere.h"
# include "ellipsoid.h"
# include "plane.h"
# include "cylinder.h"
# include "cone.h"
# include "material.h"
# include "hardware.h"
# include "ubuffer.h"
# include "torus.h"
# include "box.h"
# include "hyperboloid.h"
# include "paraboloid.h"
# include "libftxml.h"

# define N_SCENE_UBUFFERS	12

struct s_context;
struct s_input;
struct s_gui;

typedef struct		s_scene
{
	t_ubufferlist	cameras;
	t_ubufferlist	objects;
	t_ubufferlist	lights;
	t_ubufferlist	transforms;
	t_ubufferlist	meshes;
	t_ubufferlist	geometries;
	t_ubufferlist	planes;
	t_ubufferlist	materials;
	t_ubufferlist	tori;
	t_ubufferlist	boxes;
	t_ubufferlist	mobius;
	t_ubufferlist	quadrics;
	t_ubufferlist	cubics;
	int				current_cam_index;
	int				current_cam_loc;
	t_ubuffernode	*current_obj;
	t_ubuffernode	*current_cam;
}					t_scene;

t_scene				*scene_init(t_scene *scene,
					struct s_context *context);
t_scene				*scene_bind_ubuffers(t_scene *scene,
					struct s_context *context);
t_scene				*scene_init_cameras(t_scene *scene,
					struct s_context *context);
t_scene				*scene_init_objects(t_scene *scene,
					struct s_context *context);
t_scene				*scene_init_transforms(t_scene *scene,
					struct s_context *context);
t_scene				*scene_init_lights(t_scene *scene,
					struct s_context *context);
t_scene				*scene_init_meshes(t_scene *scene,
					struct s_context *context);
t_scene				*scene_init_geometries(t_scene *scene,
					struct s_context *context);
t_scene				*scene_init_planes(t_scene *scene,
					struct s_context *context);
t_scene				*scene_init_materials(t_scene *scene,
					struct s_context *context);
t_scene				*scene_init_tori(t_scene *scene,
					struct s_context *context);
t_scene				*scene_init_boxes(t_scene *scene,
					struct s_context *context);
t_scene				*scene_init_mobius(t_scene *scene,
					struct s_context *context);
t_scene				*scene_init_quadrics(t_scene *scene,
					struct s_context *context);
t_scene				*scene_init_cubics(t_scene *scene,
					struct s_context *context);
t_scene				*scene_add_camera(t_scene *scene, t_camera *camera,
					t_ubuffernode *parent, GLuint parent_slot);
t_scene				*scene_add_object(t_scene *scene, t_object *object,
					t_ubuffernode *parent, GLuint parent_slot);
t_scene				*scene_add_transform(t_scene *scene, t_transform *transform,
					t_ubuffernode *parent, GLuint parent_slot);
t_scene				*scene_add_light(t_scene *scene, t_light *light,
					t_ubuffernode *parent, GLuint parent_slot);
t_scene				*scene_add_mesh(t_scene *scene, t_mesh *mesh,
					t_ubuffernode *parent, GLuint parent_slot);
t_scene				*scene_add_geometry(t_scene *scene, t_geometry *geometry,
					t_ubuffernode *parent, GLuint parent_slot);
t_scene				*scene_add_sphere(t_scene *scene, t_sphere *sphere,
					t_ubuffernode *parent, GLuint parent_slot);
t_scene				*scene_add_ellipsoid(t_scene *scene, t_ellipsoid *ellipsoid,
					t_ubuffernode *parent, GLuint parent_slot);
t_scene				*scene_add_plane(t_scene *scene, t_plane *planes,
					t_ubuffernode *parent, GLuint parent_slot);
t_scene				*scene_add_cylinder(t_scene *scene, t_cylinder *cylinders,
					t_ubuffernode *parent, GLuint parent_slot);
t_scene				*scene_add_cone(t_scene *scene, t_cone *cones,
					t_ubuffernode *parent, GLuint parent_slot);
t_scene				*scene_add_material(t_scene *scene, t_material *material,
					t_ubuffernode *parent, GLuint parent_slot);
t_scene				*scene_add_torus(t_scene *scene, t_torus *torus,
					t_ubuffernode *parent, GLuint parent_slot);
t_scene				*scene_add_box(t_scene *scene, t_box *box,
					t_ubuffernode *parent, GLuint parent_slot);
t_scene				*scene_add_mobius(t_scene *scene, t_mobius *mobius,
					t_ubuffernode *parent, GLuint parent_slot);
t_scene				*scene_add_hyperboloid(t_scene *scene,
					t_hyperboloid *hyperboloid,
					t_ubuffernode *parent, GLuint parent_slot);
t_scene				*scene_add_paraboloid(t_scene *scene,
					t_paraboloid *paraboloid, t_ubuffernode *parent,
					GLuint parent_slot);
t_scene				*scene_add_cubic(t_scene *scene, t_cubic *cubic,
					t_ubuffernode *parent, GLuint parent_slot);

t_scene				*scene_update_camera(t_scene *scene, t_camera *camera);
t_scene				*scene_update_object(t_scene *scene, t_object *object);
t_scene				*scene_update_transform(t_scene *scene,
					t_transform *transform);
t_scene				*scene_update_light(t_scene *scene, t_light *light);
t_scene				*scene_update_mesh(t_scene *scene, t_mesh *mesh);
t_scene				*scene_update_geometry(t_scene *scene,
					t_geometry *geometry);
t_scene				*scene_update_sphere(t_scene *scene, t_sphere *sphere);
t_scene				*scene_update_ellipsoid(t_scene *scene,
					t_ellipsoid *ellipsoid);
t_scene				*scene_update_plane(t_scene *scene, t_plane *plane);
t_scene				*scene_update_cylinder(t_scene *scene,
					t_cylinder *cylinder);
t_scene				*scene_update_cone(t_scene *scene, t_cone *cone);
t_scene				*scene_update_material(t_scene *scene,
					t_material *material);
t_scene				*scene_update_torus(t_scene *scene, t_torus *torus);
t_scene				*scene_update_box(t_scene *scene, t_box *box);
t_scene				*scene_update_mobius(t_scene *scene, t_mobius *mobius);
t_scene				*scene_update_hyperboloid(t_scene *scene,
					t_hyperboloid *hyperboloid);
t_scene				*scene_update_paraboloid(t_scene *scene,
					t_paraboloid *paraboloid);
t_scene				*scene_update_cubic(t_scene *scene, t_cubic *cubic);

t_scene				*scene_bind_trs2obj(t_scene *scene, t_transform *transform,
					t_object *object);
t_scene				*scene_bind_mat2msh(t_scene *scene, t_material *material,
					t_mesh *mesh);
t_scene				*scene_bind_geo2msh(t_scene *scene, t_geometry *geometry,
					t_mesh *mesh);
t_scene				*scene_bind_msh2obj(t_scene *scene, t_mesh *mesh,
					t_object *object);
t_scene				*scene_bind_sph2geo(t_scene *scene, t_sphere *sphere,
					t_geometry *geometry);
t_scene				*scene_bind_ell2geo(t_scene *scene, t_ellipsoid *ellipsoid,
					t_geometry *geometry);
t_scene				*scene_bind_pln2geo(t_scene *scene, t_plane *plane,
					t_geometry *geometry);
t_scene				*scene_bind_cyl2geo(t_scene *scene, t_cylinder *cylinder,
					t_geometry *geometry);
t_scene				*scene_bind_con2geo(t_scene *scene, t_cone *cone,
					t_geometry *geometry);
t_scene				*scene_bind_tor2geo(t_scene *scene, t_torus *torus,
					t_geometry *geometry);
t_scene				*scene_bind_box2geo(t_scene *scene, t_box *box,
					t_geometry *geometry);
t_scene				*scene_bind_mob2geo(t_scene *scene, t_mobius *mobius,
					t_geometry *geometry);
t_scene				*scene_bind_hyp2geo(t_scene *scene,
					t_hyperboloid *hyperboloid, t_geometry *geometry);
t_scene				*scene_bind_par2geo(t_scene *scene,
					t_paraboloid *paraboloid, t_geometry *geometry);
t_scene				*scene_bind_cub2geo(t_scene *scene, t_cubic *cubic,
					t_geometry *geometry);

t_scene				*scene_change_current(t_scene *const scene,
					struct s_input *const input,
					struct s_gui *const gui, void *const clicked);
int					scene_parse(t_scene *scene, t_xml_element const *elem);

#endif
