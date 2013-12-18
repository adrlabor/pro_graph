#include <iostream>

#include "include/Graph.h"
#include "include/Random_graph.h"
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
    g1->addEdge(0,1);g1->addEdge(0,2);g1->addEdge(1,2);g1->addEdge(1,3);g1->addEdge(3,4);

    cout << "Graph 1 :\n" << g->toString() << endl;

    /*//Suppression d'une arrête
    g.delEdge(0,2);
    cout << "Suppression arrête 1-3 :\n" << g.toString() << endl;

    //Suppression d'un sommet
    //g.delVertex(2);
    //cout << "Suppression sommet 3 :\n" << g.toString() << endl;

    //Ajout de deux sommets
    g.addVertex();
    g.addVertex();
    cout << "Ajout de deux sommets :\n" << g.toString() << endl;

    //Ajout d'arrêtes
    g.addEdge(2,3);
    g.addEdge(0,3);
    g.addEdge(1,3);
    cout << "Ajout de 3 arrêtes :\n" << g.toString() << endl;*/

    vector<int> cover = glouton(g);
    displayVector(cover);

    vector<int> cover2 = twoAppr_neighbourhood(g);
    displayVector(cover2);

    vector<int> cover3 = twoAppr_deepSearch(g1);
    displayVector(cover3);

    return 0;
}
