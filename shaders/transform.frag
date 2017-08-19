struct s_transform
{
	int		parent_index;
	vec3	pos;
	vec3	rot;
	vec3	scl;
	vec4	qtn;
};


layout (std140) uniform transforms		{s_transform	transform[512];};
uniform	int				n_transforms;


vec4			quaternion_inv(vec4 qtn)
{
	return qtn * vec4(vec3(-1), 1);
}

vec3			vec3_apply_quaternion(vec3 v, vec4 q)
{
	vec4	v4;

	v4.x = dot(q.wyz * vec3(1,1,-1), v.xzy);
	v4.y = dot(q.wzx * vec3(1,1,-1), v.yxz);
	v4.z = dot(q.wxy * vec3(1,1,-1), v.zyx);
	v4.w = dot(q.xyz * vec3(-1), v);
	v.x = dot(v4.xwyz * vec4(1,-1,-1,1), q.wxzy);
	v.y = dot(v4.ywzx * vec4(1,-1,-1,1), q.wyxz);
	v.z = dot(v4.zwxy * vec4(1,-1,-1,1), q.wzyx);
	return (v);
}

vec3			transform_apply_inv(int index, vec3 pos)
{
	vec3			trs_pos;	//transformed ray position (origin)
	vec4			q;			//inverted quaternion

	q = quaternion_inv(transform[index].qtn);
	trs_pos = pos - transform[index].pos;
	trs_pos = vec3_apply_quaternion(trs_pos, q);
	return (trs_pos / transform[index].scl);
}

float			transform_get_dir_scale(int index, vec3 dir)
{
	vec4			q;

	q = quaternion_inv(transform[index].qtn);
	dir = vec3_apply_quaternion(dir, q);
	return (length(dir / transform[index].scl));
}

vec3			transform_apply_inv_dir(int index, vec3 dir)
{
	vec3			trs_dir;	//transformed ray direction
	vec4			q;			//inverted quaternion

	q = quaternion_inv(transform[index].qtn);
	trs_dir = vec3_apply_quaternion(dir, q);
	return (normalize(trs_dir / transform[index].scl));
}

vec3			transform_apply(int index, vec3 v)
{
	v *= transform[index].scl;
	v = vec3_apply_quaternion(v, transform[index].qtn);
	v += transform[index].pos;
	return (v);
}

vec3			transform_apply_normal(int index, vec3 normal)
{
	normal /= transform[index].scl;
	normal = vec3_apply_quaternion(normal, transform[index].qtn);
	return (normalize(normal));
}
