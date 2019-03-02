//NOTES
//account for mirrors too
//account for lights too

//clear visibles
visibles = 0;

#include "frustum_culling.txt"

switch(Options.occlusion_culling)
{
	case 0: break;

	case 1: //GPU occlusion culling
	{
		#include "gpu_occlusion_culling.txt"
	}
	break;

	case 2: //CPU occlusion culling
	{
		#include "cpu_occlusion_culling.txt"
	}
	break;
}
