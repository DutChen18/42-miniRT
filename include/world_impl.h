#ifndef WORLD_IMPL_H
# define WORLD_IMPL_H

# include "world.h"
# include "state.h"
# include "vector.h"
# include "aabb.h"
# include "pool.h"

# include <stddef.h>

/* TODO set these values to something good */
# define RT_INTERSECT_COST 80
# define RT_TRAVERSAL_COST 80
# define RT_EMPTY_BONUS (FLOAT) 0.3
# define RT_MAX_PRIMITIVES 20

# define ACCEL_BELOW 0
# define ACCEL_ABOVE 1

typedef struct s_edge			t_edge;
typedef	struct s_split_axis		t_split_axis;
typedef struct s_split			t_split;
typedef struct s_node_info		t_node_info;

typedef enum e_edge_type {
	EDGE_START,
	EDGE_END
}	t_edge_type;

typedef enum e_axis {
	AXIS_X = 0,
	AXIS_Y = 1,
	AXIS_Z = 2,
	AXIS_NONE= 3
}	t_axis;

struct s_split_axis {
	t_axis	axis;
	FLOAT	offset;
};

struct s_split {
	FLOAT		offset;
	FLOAT		cost;
	uint32_t	prim_count[2];
	uint64_t	edge_count;
	int32_t		axis;
};

struct s_node_info {
	t_world		*world;
	t_pool		*pool;
	uint32_t	offset;
	uint32_t	depth;
	t_vector	indices;
	t_bounds	bounds;
	t_vector	edges[3];
};

struct s_edge {
	FLOAT		offset;
	uint32_t	index;
	t_edge_type	type;
};

void		world_create(t_world *world);
void		world_destroy(t_world *world);

uint32_t	world_add_material(t_world *world, void *material, size_t size);
uint32_t	world_add_primitive(t_world *world, void *shape, size_t size);
uint32_t	world_add_vertex(t_world *world, t_vertex *vertex);
uint32_t	world_add_accel_node(t_world *world, t_accel_node *accel_node);
uint32_t	world_add_accel_index(t_world *world, uint32_t *accel_index);

#endif
