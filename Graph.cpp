#include "../include/Graph.h"
#include <sstream>

//Constructeur par défaut
Graph::Graph()
{
    g_vertex = vector<vector<int> >();
}

Graph::Graph(vector<vector<int> > vertex_list) {
        g_vertex = vertex_list;
}

Graph::~Graph()
{
    //dtor
}

//Gestion des sommets (vertex)
int Graph::getNbVertex() const{
    return g_vertex.size();
}

int Graph::addVertex(){
    g_vertex.push_back(vector<int>());
    // on renvoit l'addresse du nouveau vertex
    return g_vertex.size() - 1;
}

void Graph::delVertex(int vertex) {
    vector<int> v = g_vertex[vertex];

    //Suppression des arrêtes
    for (int i = 0; i < (signed)v.size(); i++) {
            delEdge(vertex, v[i]);
    }

    //Suppression du sommet - marche pas!
    //g_vertex.resize(g_vertex.size()-1);

}

// Gestion des arrêtes (edge)
int Graph::getNbEdge(int vertex) const {
    return g_vertex[vertex].size();
}

void Graph::addEdge(int vertex, int vertex2) {
    g_vertex[vertex].push_back(vertex2);
    g_vertex[vertex2].push_back(vertex);

}

void Graph::delEdge(int vertex1, int vertex2) {
    vector<int> v1 = g_vertex[vertex1];
    vector<int> v2 = g_vertex[vertex2];

    //Suppression de vertex 2 dans vertex 1
  for(int i = 0; i < (signed)v1.size(); i++){
    if(v1[i]==vertex2){
        g_vertex[vertex1].erase(g_vertex[vertex1].begin()+i);
        break;
    }
  }
    //Suppression de vertex 1 dans vertex 2
  for(int i = 0; i < (signed)v2.size(); i++){
    if(v2[i]==vertex1){
        g_vertex[vertex2].erase(g_vertex[vertex2].begin()+i);
        break;
    }
  }
}

string Graph::toString(){
    std::ostringstream s;
    for (unsigned int i = 0; i < g_vertex.size(); i++) {
            s << i + 1 << ":";
            for (unsigned int j = 0; j < g_vertex[i].size(); j++) {
                    s << " " << g_vertex[i][j] + 1;
            }
            s << "\n";
    }
    return s.str();
}
