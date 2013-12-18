#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

using namespace std;

class Graph
{
    private:
        vector<vector<int> > g_vertex;
    public:
        Graph();
        Graph(vector<vector<int> > g_vertex);
        virtual ~Graph();

        int getNbVertex() const;
        int addVertex();
        void delVertex(int vertex);

        int getNbEdge(int vertex) const;
        virtual void addEdge(int vertex, int vertex2);
        virtual void delEdge(int vertex1, int vertex2);

        bool haveEdge(int vertex1, int vertex2);
        string toString();
};

#endif // GRAPH_H
