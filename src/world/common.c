#include "world.h"

uint32_t
	prim_type(const GLOBAL t_primitive *prim)
{
	return (prim->data & 0xFF);
}

uint32_t
	prim_mat(const GLOBAL t_primitive *prim)
{
	return (prim->data >> 8);
}


const GLOBAL t_primitive
	*get_prim_const(const GLOBAL t_world *world, uint32_t index)
{
	return ((const GLOBAL t_primitive *) ((const GLOBAL char *) world->primitives + (uint64_t) index * RT_PRIMITIVE_ALIGN));
}

GLOBAL t_primitive
	*get_prim(GLOBAL t_world *world, uint32_t index)
{
	return ((GLOBAL t_primitive *) ((GLOBAL char *) world->primitives + (uint64_t) index * RT_PRIMITIVE_ALIGN));
}

const GLOBAL t_material
	*get_mat_const(const GLOBAL t_world *world, uint32_t index)
{
	return ((const GLOBAL t_material *) ((const GLOBAL char *) world->materials + (uint64_t) index * RT_MATERIAL_ALIGN));
}

GLOBAL t_material
	*get_mat(GLOBAL t_world *world, uint32_t index)
{
	return ((GLOBAL t_material *) ((GLOBAL char *) world->materials + (uint64_t) index * RT_MATERIAL_ALIGN));
}

t_vec
	get_vertex(const t_world *world, uint32_t index)
{
	return (world->vertices[index].pos);
}

