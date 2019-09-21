if(identity[VBO] != -1)
{
    vertex_submit(identity[VBO].lod[LOD_RENDER], pr_trianglelist, 0);
}

#ifdef SHOW_USE
//uses_vbo_tag, uses_lod
#endif
