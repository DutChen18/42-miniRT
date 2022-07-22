#include "parser.h"

#include "util.h"
#include "world_impl.h"

void
	rt_exec_tex_def(t_world *world, t_parse_ctx *ctx)
{
	t_tex	tex;
	char	*keyword;
	char	*path;
	char	*content;
	char	*error;
	size_t	size;

	texture_init(&tex);
	keyword = rt_keyword(ctx, "tex_");
	path = rt_word(ctx);
	content = rt_readfile(path, &error, &size);
	rt_assert(content != NULL, error);
	world_load_ppm(world, &tex, (unsigned char *) content, size);	
	rt_free(keyword);
	rt_free(path);
	rt_free(content);
}
