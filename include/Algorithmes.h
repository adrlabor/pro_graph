#ifndef ALGORITHMES_H
#define ALGORITHMES_H

#include "../include/Graph.h"

vector<int> glouton(const Graph *graph);
vector<int> twoAppr_neighbourhood(const Graph *graph);
vector<int> twoAppr_deepSearch(const Graph *graph);

#endif // ALGORITHMES_H
