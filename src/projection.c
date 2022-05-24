#include "rt.h"

#include <math.h>
#include <stdio.h>

static t_vec
	project_rotate(t_vec v, FLOAT yaw, FLOAT pitch)
{
	FLOAT	vx;
	FLOAT	vy;
	FLOAT	vz;

	vy = v.v[Y] * cos(pitch) - v.v[Z] * sin(pitch);
	vz = v.v[Y] * sin(pitch) + v.v[Z] * cos(pitch);
	vx = vy * cos(yaw) - v.v[X] * sin(yaw);
	vy = vy * sin(yaw) + v.v[X] * cos(yaw);
	return (vec(vx, vy, vz, v.v[W]));
}

static void
	project_angles(t_vec v, FLOAT *yaw, FLOAT *pitch)
{
	*yaw = atan2(v.v[Y], v.v[X]);
	*pitch = atan2(v.v[Z], v.v[X] * sin(*yaw) + v.v[Y] * cos(*yaw));
}

t_ray
	project_frustrum(t_camera *cam, FLOAT x, FLOAT y)
{
	FLOAT	yaw;
	FLOAT	pitch;
	FLOAT	tmp;
	t_ray	ray;

	project_angles(cam->dir, &yaw, &pitch);
	tmp = cam->fov / 180 * RT_PI;
	ray.pos = cam->pos;
	ray.dir = vec(x * 2, cos(tmp / 2) / sin(tmp / 2), y * 2, 0);
	ray.dir = vec_norm(project_rotate(ray.dir, yaw, pitch));
	return (ray);
}

t_ray
	project_cone(t_camera *cam, FLOAT x, FLOAT y)
{
	FLOAT	yaw;
	FLOAT	pitch;
	FLOAT	tmp;
	t_ray	ray;

	project_angles(cam->dir, &yaw, &pitch);
	tmp = cam->fov / 180 * RT_PI;
	yaw += x * tmp;
	pitch += y * tmp;
	ray.pos = cam->pos;
	ray.dir = vec(0, 1, 0, 0);
	ray.dir = project_rotate(ray.dir, yaw, pitch);
	return (ray);
}

t_ray
	project_ray(t_rt_state *state, FLOAT x, FLOAT y)
{
	FLOAT	aspect;

	aspect = (FLOAT) state->img.height / state->img.width;
	x = x / state->img.width - 0.5;
	y = (y / state->img.height - 0.5) * -aspect;
	if (state->use_conic)
		return (project_cone(state->scene.camera, x, y));
	else
		return (project_frustrum(state->scene.camera, x, y));
}
