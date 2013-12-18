#include <iostream>

#include "include/Graph.h"
#include "include/Random_graph.h"
#include "include/Random_bipartis.h"
#include "include/Algorithmes.h"
#include <vector>

using namespace std;

void displayVector(vector<int> v) {
    vector<int>::iterator it;
    cout << "Covers : ";
    for (it = v.begin(); it != v.end(); ++it) {
            cout << *it + 1 << "  ";
    }
    cout << endl;
}

int main()
{
    Graph* g = new Random_graph(5, 0.5);
    Graph* g1 = new Graph();
    g1->addVertex();g1->addVertex();g1->addVertex();g1->addVertex();g1->addVertex();
    g1->addEdge(0,1);g1->addEdge(0,2);g1->addEdge(1,2);g1->addEdge(2,3);g1->addEdge(3,4);

    cout << "Graph normal :\n" << g->toString() << endl;

    vector<int> cover = glouton(g);
    displayVector(cover);

    vector<int> cover2 = twoAppr_neighbourhood(g);
    displayVector(cover2);

    vector<int> cover3 = twoAppr_depthSearch(g);
    displayVector(cover3);

    Graph* g2 = new Random_bipartis(10, 1);
    cout << "Graph bipartis :\n" << g2->toString() << endl;

    return 0;

}
