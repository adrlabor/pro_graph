#include "../include/Random_bipartis.h"

#include <time.h>
#include <cstdlib>
#include <iostream>
Random_bipartis::Random_bipartis()
{
    generateRandomBipartis(5, 0.5);
}

Random_bipartis::Random_bipartis(int nbVertex, float probaEdge)
{
    generateRandomBipartis(nbVertex, probaEdge);
}

Random_bipartis::~Random_bipartis()
{
    //dtor
}

void Random_bipartis::generateRandomBipartis(int nbVertex, float probaEdge){

    srand(time(NULL));
    //quantité max de sommet dans la 1ère des deux parties
    int sizeFirstSet = rand() % (nbVertex - 1) + 1;

    for (int i = 0; i <nbVertex; i++)
        addVertex();

	for (int i = 0; i < sizeFirstSet; i++) {
		for (int j = sizeFirstSet; j < nbVertex; j++) {
			double randomNumber = rand()/(double)RAND_MAX;
            if(randomNumber < probaEdge){
                addEdge(i,j);
			}
		}
	}
}
