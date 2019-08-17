ITERATE_MIRRORS
{
	//mirror the camera

	#include "visibility_culling.txt"

	surface_set_target(surfaces[MIRROR_MRT]);

	SET_UNIFORM_I(vertex_mode, VERTEX_REGULAR)
	SET_UNIFORM_I(fragment_mode, FRAGMENT_REGULAR)

	ITERATE_STATIC
	{
	    #include "mrt_static.txt"
	}

	ITERATE_DYNAMIC
	{
	    #include "mrt_dynamic.txt"
	}

	surface_reset_target();
}
