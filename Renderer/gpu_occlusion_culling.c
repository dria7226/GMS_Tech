SET_UNIFORM_I(vertex_mode, VERTEX_REGULAR);
SET_UNIFORM_I(fragment_mode, FRAGMENT_DIFFUSE);

surface_set_target(occlusion);
draw_clear(c_white);

SET_UNIFORM_F("scale", 0.62408,0.5436,0.62796);
//draw bounding volumes
ITERATE_STATICS
{
  SET_UNIFORM_F("object_id", PACK_32_BITS(i))

  vertex_submit(cube, pr_trianglelist, -1);
}
surface_reset_target();

//post processing
surface_set_target(occlusion_first_pass);
draw_clear(c_white);
SET_UNIFORM_I(vertex_mode, 1)
SET_UNIFORM_I(fragment_mode, 3)

draw_surface(occlusion, 0, 0);

surface_reset_target();

surface_set_target(occlusion_second_pass);
draw_clear(c_white);
SET_UNIFORM_I(fragment_mode, 4)

draw_surface(occlusion_first_pass, 0, 0);

surface_reset_target();

//read surface and build visible array
var occlusion_buffer = buffer_create(surface_get_width(occlusion)*surface_get_height(occlusion)*4, buffer_grow, 1);
buffer_get_surface(occlusion_buffer, occlusion_second_pass, 0, 0, 0); //formatted as BGRA
var occlusion_buffer_size = buffer_get_size(occlusion_buffer)/4;

//refresh visibles
visibles = 0;
for(var i = 0; i < occlusion_buffer_size; i++)
{
  var visible_index = [0,0,0];
  visible_index[2] = buffer_read(occlusion_buffer, buffer_u8);
  visible_index[1] = buffer_read(occlusion_buffer, buffer_u8);
  visible_index[0] = buffer_read(occlusion_buffer, buffer_u8);	//formatted as BGRA
  buffer_read(occlusion_buffer, buffer_u8);

  //show_debug_message("r: " + string(visible_index[2]) + ", g: " + string(visible_index[1]) + ", b: " + string(visible_index[0]));

  if(	visible_index[0] == 255 &&
    visible_index[1] == 255 &&
    visible_index[2] == 255)
    break;
  else
  {
    //decode visible index
    visibles[i] = visible_index[2] + visible_index[1]*256 + visible_index[0]*256*256;
  }

  //show_debug_message(string(i) + " : " + string(visibles[i]));
}
