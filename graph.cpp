#include "graph.h"

Graph::Graph(int x, int y) 
{
    vCount = x;
    eCount = y;
    edges.resize((int)1e5);
}

void Graph::insert_edge(int src, int dest)
{
    edges[src].push_back(dest);
}

std::vector<int>& Graph::get_outgoing_edges(int v)
{
    return edges[v];
}