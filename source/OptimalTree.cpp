#include "../include/Algorithmes.h"

static bool
depth_search(const Graph *graph, vector<int> * coverVertexes, int vertex,bool is_root){
        if ( graph->getNbEdge(vertex) == 1)
        {
                return false;
        }
        bool attrib_vertex = true;
        int i=(is_root)?0:1;
        for(;i<graph->getNbEdge(vertex);i++)
                        attrib_vertex &= depth_search(graph, coverVertexes,graph->getNeighbours(vertex)[i],false);
        if(!attrib_vertex) {
                        coverVertexes->push_back(vertex);
                        return true;
        }
        return false;
}



vector<int> OptimalTreeVertexCover(const Graph *graph){
        vector<int> * coverVertexes = new vector<int>();
        depth_search(graph,coverVertexes,0,true);
        return *coverVertexes;
}


