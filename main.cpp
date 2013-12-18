#include <iostream>

#include "include/Graph.h"

using namespace std;

int main()
{
    //Création de sommets
    vector<int> sommet1 = vector<int>();
    vector<int> sommet2 = vector<int>();
    vector<int> sommet3 = vector<int>();
    sommet1.push_back(1);sommet1.push_back(2);
    sommet2.push_back(0);sommet2.push_back(2);
    sommet3.push_back(0);sommet3.push_back(1);
    //Création d'un graphe
    vector<vector<int> > g1 = vector<vector<int> >();
    g1.push_back(sommet1);
    g1.push_back(sommet2);
    g1.push_back(sommet3);

    Graph g = Graph(g1);
    cout << "Graph 1 :\n" << g.toString() << endl;

    //Suppression d'une arrête
    g.delEdge(0,2);
    cout << "Suppression arrête 1-3 :\n" << g.toString() << endl;

    //Suppression d'un sommet
    /*g.delVertex(2);
    cout << "Suppression sommet 3 :\n" << g.toString() << endl;*/

    //Ajout de deux sommets
    g.addVertex();
    g.addVertex();
    cout << "Ajout de deux sommets :\n" << g.toString() << endl;

    //Ajout d'arrêtes
    g.addEdge(2,3);
    g.addEdge(0,3);
    g.addEdge(1,3);
    cout << "Ajout de 3 arrêtes :\n" << g.toString() << endl;

    return 0;
}
