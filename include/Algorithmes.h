#ifndef ALGORITHMES_H
#define ALGORITHMES_H

#include "../include/Graph.h"

vector<int> glouton(const Graph *graph);
vector<int> twoAppr_neighbourhood(const Graph *graph);
vector<int> twoAppr_depthSearch(const Graph *graph);
vector<int> opti_bipartis(const Graph *graph);
vector<int> OptimalTreeVertexCover(const Graph* g);
vector<int> opti_para_minCoverGraph(const Graph* g);
#endif // ALGORITHMES_H
