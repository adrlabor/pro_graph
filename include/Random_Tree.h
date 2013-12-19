#ifndef RANDOMTREE_H_
#define RANDOMTREE_H_

#include "Graph.h"

class RandomTree : public Graph {
public:
        RandomTree(int nbVertex);

private:
        void generateRandomTree(int nbVertex);
};

#endif /* TREE_H_ */
