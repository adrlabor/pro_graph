#include "Graph.h"

class ReaderFile {
	public:
	ReaderFile();
	~ReaderFile();
	Graph* fileToGraph(char* file);
	bool isNeighbour(int sommet,int sommet2,Graph* g);


};
