#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <vector>
#include <string.h>
#include <stack>
#include <set>
#include <iostream>
#include <fstream>
#define int long long

class Graph 
{ 
    public:
        Graph() {}
        Graph(int x, int y);
        void insert_edge(int src, int dest);
        std::vector<int>& get_outgoing_edges(int v);
        std::set<int> vertex;
        std::map<int, int> scc;
        void visualize();

    private:
        int vCount, eCount;
        std::map<int, std::vector<int>> edges;
};

#endif