surfaces[NO_OF_SURFACES - 1] = -1;

surface_texture_pointers[NO_OF_SURFACES - 1] = -1;

surface_info[MRT] = [2,2];
surface_info[MIRROR_MRT] = [2,2];
surface_info[BOOLEAN_DEPTH_B] = [2,1];
surface_info[OCCLUSION] = [0.1,0.1];
surface_info[NO_OF_SURFACES-1] = 0;

for(var i = 0; i < NO_OF_SURFACES; i++)
{
	surfaces[i] = -1;

	if(surface_info[i] == 0) surface_info[i] = [1,1];
}

var occlusion_buffer = buffer_create(1, buffer_grow, 1);
