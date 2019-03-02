if(identity[VBO] != -1)
{
    var lod_index = 0;

    //lod_index = (visibles.distance[i] + Options.lod_offset)/MAX_DISTANCE*2);

    vertex_submit(identity[VBO].lod[lod_index], pr_trianglelist, 0);
}

#ifdef SHOW_USE
//uses_vbo_tag, uses_lod
#endif
