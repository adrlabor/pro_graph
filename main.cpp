#include <iostream>

#include "include/Graph.h"
#include "include/Random_graph.h"
#include "include/Random_bipartis.h"
#include "include/Random_Tree.h"
#include "include/Random_Binary_Tree.h"
#include "include/Random_minCoverGraph.h"
#include "include/Algorithmes.h"
#include "include/ReaderFile.h"
#include "include/Minisat.h"
#include <vector>

using namespace std;

void displayVector(vector<int> v) {
    vector<int>::iterator it;
    cout << " ";
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

    cout <<endl;
    cout<<endl;
    cout << "Graph normal :\n" << g->toString() << endl;

    vector<int> cover = glouton(g);
    cout <<">Glouton : ";displayVector(cover);

    vector<int> cover2 = twoAppr_neighbourhood(g);
    cout <<">2approché kill voisin :";displayVector(cover2);

    vector<int> cover3 = twoAppr_depthSearch(g);
    cout<<">2approché parcours profondeur :";displayVector(cover3);

    cout <<endl;
    cout <<endl;
    Graph* g2 = new Random_bipartis(10, 1);
    cout << "Graph bipartis :\n" << g2->toString() << endl;




    cout<<endl;
    cout<<endl;
    Graph* g3 = new RandomBinaryTree(10);
    cout << "Arbre aléatoire binaire:\n" << g3->toString() << endl;
    vector<int> cover41 = GetTreeOptimalVertexCover(g3);
    cout << ">Arbre optimal :";displayVector(cover41);

    cout<<endl;
    cout<<endl;
    Graph* g4 = new RandomTree(10,1,5);
    cout << "Arbre aléatoire:\n" << g4->toString() << endl;
    vector<int> cover51 = GetTreeOptimalVertexCover(g4);
    cout << ">Arbre optimal :";displayVector(cover51);

    Graph *g7 = new Random_minCoverGraph(3,2,0.8);
    cout << "Graphe minCover :\n" << g7->toString() << endl;

    vector<int> cover_para = opti_para_minCoverGraph(g7, 3);
    cout << "Algo para:" << endl;
    displayVector(cover_para);


    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    ReaderFile* reader = new ReaderFile();
    Graph *grapheFile = new Graph();
    grapheFile = reader->fileToGraph("source/fileTest.txt");
	
    cout << "Graph normal :\n" << grapheFile->toString() << endl;


    
    Minisat minsat = Minisat();
    minsat.VertexCoverToSat(grapheFile);
    minsat.SatToVertexCover();


	
    return 0;

}
