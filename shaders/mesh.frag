struct s_mesh
{
	int		parent_index;
	int		geometry_index;
	int		material_index;
};

layout (std140) uniform meshes			{s_mesh			mesh[512];};
uniform	int				n_meshes;
