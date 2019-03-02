format_size = 0;
vertex_format_begin();
vertex_format_add_position_3d(); format_size += 3;
vertex_format_add_color(); format_size += 1;
vertex_format_add_texcoord(); format_size += 2;
format = vertex_format_end();

gpu_set_blendenable(false);
gpu_set_tex_repeat(true);
gpu_set_ztestenable(true);
//gpu_set_tex_filter(true);
