//2x2x2 miles
#define MAX_WORLD_WIDTH 10560.0
#define MAX_OFFSET MAX_WORLD_WIDTH/2.0
#define MIN_OFFSET -MAX_WORLD_WIDTH/2.0

#define pi 3.1415926
#define MAX_ANGLE pi
#define MIN_ANGLE -pi

#define MAX_COLOR_AND_GS 99.0

#define COMPRESSED_NORMAL_POSITION 10.0
#define COMPRESSED_UNIFORM_POSITION 100000.0
#define GET_SIGN(number) s = sign(number); \
s += (s==0);
#define COMPRESS_COORDINATE(position, normal)  s*(floor((normal + 1)/2*byte)*COMPRESSED_NORMAL_POSITION + abs(position))

#define ENCODE_COLOR(NAME, R, G, B, A)\
var color_buffer = buffer_create(4,buffer_fixed,1);\
buffer_write(color_buffer, buffer_u8, R);\
buffer_write(color_buffer, buffer_u8, G);\
buffer_write(color_buffer, buffer_u8, B);\
buffer_write(color_buffer, buffer_u8, A);\
buffer_seek(color_buffer, buffer_seek_start,0);\
var NAME = buffer_read(color_buffer, buffer_f32);\
buffer_delete(color_buffer);

#define WRITE_VERTEX_TO_ARRAY(ARRAY, X,Y,Z,NX,NY,NZ,COLOR, U, V)\
array[array_index++] = X;\
array[array_index++] = Y;\
array[array_index++] = Z;\
\
array[array_index++] = NX;\
array[array_index++] = NY;\
array[array_index++] = NZ;\
\
array[array_index++] = COLOR;\
\
array[array_index++] = U;\
array[array_index++] = V;
