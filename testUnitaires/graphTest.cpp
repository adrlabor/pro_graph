#include "easyunit/test.h"
#include "../include/Graph.h"
#include "../include/Random_graph.h"

using namespace easyunit;

DECLARE(Graph)

        Graph *g1;
        
END_DECLARE

SETUP(Graph)
{

        g1 = new Random_graph(5, 1);

}

TEARDOWN(Graph)
{
}


TESTF(Graph, numberVertex)
{

        ASSERT_TRUE(g1->getNbVertex() == 5);

}
