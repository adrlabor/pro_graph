#include "../include/Random_Tree.h"
#include <time.h>
#include <cstdlib>
#include <cmath>

RandomTree::RandomTree(int nbVertex,int min,int max) : Graph()
{
        generateRandomTree(nbVertex,min,max);
	
}



void
RandomTree::generateRandomTree(int nbVertex,int nbMinChild,int nbMaxChild) {
        srand(time(NULL));
	if (nbVertex < 1)
                return;

	int nbNodesCreated = 1;
	int cursor = addVertex();

	while (nbNodesCreated < (nbVertex)) {
		
		int maxRand;

		if (nbMaxChild > (nbVertex - (nbNodesCreated - 1)))
			maxRand = (nbVertex - (nbNodesCreated - 1));
		else
			maxRand = nbMaxChild;
		int nbChildren = rand() % (maxRand - nbMinChild) + nbMinChild;

		if (nbChildren > 0) {
			for (int i = 0; i < nbChildren; i++) {
				nbNodesCreated=addVertex();
				addEdge(cursor, nbNodesCreated);
				nbNodesCreated++;
			}
			cursor++;
		}
	}

/*
        if (nbVertex < 1)
                return;
        int current;
        int i = current = addVertex();
        //int sons;
	

        while (i < nbVertex-1) {

		int maxRand;

		if (nbMaxChild > (nbVertex - (i - 1)))
			maxRand = (nbVertex - (i - 1));
		else
			maxRand = nbMaxChild;
		int nbChildren = rand() % (maxRand - nbMinChild) + nbMinChild;
                //sons = min(nbMinChild,nbMaxChild);//min(rand() % (nbVertex - i), nbVertex / 4);

                for (int j = 0; j < nbChildren; j++) {
                        i = addVertex();
                        addEdge(current, i);
			
                }
                current++;
        }

*/
}

