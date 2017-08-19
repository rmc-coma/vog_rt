float			light_get_diffuse_and_specular(int index, int mat, vec3 point,
		vec3 normal, vec3 ray_dir)
{
	vec3		target_to_light;
	vec3		reflected;
	float		dist_sq;
	float		intensity;
	float		diffuse;
	float		specular;
	float		coef;

	target_to_light = point_to_light_vec(index, point);
	dist_sq = max(dot(target_to_light, target_to_light), 0.01f);
	target_to_light = normalize(target_to_light);
	reflected = normalize(reflect(ray_dir, normal));

	intensity = light_dir_intensity(index, -target_to_light);
	
	diffuse = material[mat].diffuse / mix(dist_sq, 1, light[index].parallel)
		* max(intensity * dot(target_to_light, normal), 0.f);

	coef = dot(target_to_light, reflected);
	intensity *= mix(1, LIGHT_PARALLEL_INTENSITY, light[index].parallel);
	specular = material[mat].specular * intensity
		* pow(abs(coef), material[mat].specular_radius) * float(coef > 0);
	return (diffuse + specular);
}
