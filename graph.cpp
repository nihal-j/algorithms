#include "graph.h"

Graph::Graph(int x, int y) 
{
    vCount = x;
    eCount = y;
    edges.clear();
}

void Graph::insert_edge(int src, int dest)
{
    edges[src].push_back(dest);
}

std::vector<int>& Graph::get_outgoing_edges(int v)
{
    return edges[v];
}

void Graph::visualize()
{
    std::ofstream file;
    file.open("nodes.txt");
    for (auto &i: scc)
        file << i.first << " " << i.second << "\n";

    std::ofstream file1;
    file1.open("edges.txt");
    for (auto &i: edges)
        for (int j: i.second)
            file1 << i.first << " " << j << "\n";
}