#include "scene.h"

#include <math.h>
#include <stdlib.h>

const t_entity_vt
	*plane_vt(void)
{
	static const t_entity_vt	vt = {
		plane_hit,
		plane_destroy
	};

	return (&vt);
}

/* http://lousodrome.net/blog/light/2020/07/03/intersection-of-a-ray-and-a-plane/ */
/* http://wscg.zcu.cz/wscg2002/Papers_2002/A83.pdf */
int
	plane_hit(t_entity *ent, t_ray ray, t_hit *hit)
{
	t_plane	*plane;
	FLOAT	dividend;
	FLOAT	divisor;

	plane = (t_plane *) ent;
	divisor = vec_dot(ray.dir, plane->dir);
	if (float_eq(divisor, 0, 0.001))
		return (0);
	dividend = vec_dot(vec_sub(plane->pos, ray.pos), plane->dir);
	hit->t = dividend / divisor;
	if (hit->t <= 0.0)
		return (0);
	hit->pos = vec_add(ray.pos, vec_scale(ray.dir, hit->t));
	hit->normal = plane->dir;
	hit->mat = plane->mat;
	return (1);
}

void
	plane_destroy(t_entity *ent)
{
	t_plane	*plane;

	plane = (t_plane *) ent;
	plane->mat->vt->destroy(plane->mat);
	rt_free(ent);
}
