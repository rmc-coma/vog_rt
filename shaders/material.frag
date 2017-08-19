struct s_material
{
	int		parent_index;
	float	ambiant;
	float	diffuse;
	float	specular;
	float	specular_radius;
	float	reflection_indice;
	float	refraction;
	float	roughness;
	vec3	color;
};

layout (std140) uniform materials		{s_material			material[512];};
				uniform int				n_materials;
