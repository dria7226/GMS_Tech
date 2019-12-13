#define STARTUP_VISIBLES visibles = array_create(0);
#define CLEAR_VISIBLES visibles = 0;
#define CLEAR_AND_STARTUP_VISIBLES visibles = 0; visibles = array_create(0);

#define ITERATE_STATIC for(var i = 0; i < visibles_static_count; i++)
#define ITERATE_DYNAMIC var no_of_visibles = array_length_1d(visibles); for(var i = visibles_static_count; i < no_of_visibles; i++)
#define ITERATE_VISIBLES var no_of_visibles = array_length_1d(visibles); for(var i = 0; i < no_of_visibles; i++)

#define ADD_IDENTITY_TO_VISIBLES(identity) visibles[array_length_1d(visibles)] = identity; \
set_tags(identity, [Visible]); \
identity[Visible] = identity;
