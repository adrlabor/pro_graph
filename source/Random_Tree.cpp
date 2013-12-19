#include "../include/Random_Tree.h"
#include <time.h>
#include <cstdlib>
#include <cmath>

RandomTree::RandomTree(int nbVertex) : Graph()
{
        generateRandomTree(nbVertex);
}

void
RandomTree::generateRandomTree(int nbVertex) {
        srand(time(NULL));
        if (nbVertex < 1)
                return;
        int current;
        int i = current = addVertex();
        int sons;

        while (i < nbVertex-1) {
                sons = min(rand() % (nbVertex - i), nbVertex / 4);

                for (int j = 0; j < sons; j++) {
                        i = addVertex();
                        addEdge(current, i);
                }
                current++;
        }
}
