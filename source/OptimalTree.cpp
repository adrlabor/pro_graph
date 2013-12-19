#include "../include/Algorithmes.h"

static bool
depth_search(const Graph *graph, vector<int> * coverVertexes, int vertex,bool is_root){
  bool attrib_vertex = true;
  int i;
  if(is_root==true){
    i=0;
  }
  else{
    i=1;
  }
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


