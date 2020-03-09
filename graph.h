#ifndef GRAPH_H
#define GRAPH_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string.h>
#include <vector>

class Graph 
{ 
    public:
        Graph() {};
        Graph(int x, int y);
        void insert_edge(int src, int dest);
        std::vector<int>& get_outgoing_edges(int v);
        void visualize();

        std::map<int, int> scc;
        std::set<int> vertices;

    private:
        int vCount, eCount;
        std::map<int, std::vector<int>> edges;
};

#endif