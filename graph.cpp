#include "graph.h"
#include "visualize.h"

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
    file.open("graph.gdf");
    
    file << "nodedef>name VARCHAR,label VARCHAR\n";
    for (auto i: scc)
        file << i.first << "," << i.first << "\n";
    file << "edgedef>node1 VARCHAR,node2 VARCHAR,directed BOOLEAN\n";

    std::string def = "\'0,0,0\'";
    std::map<int, std::string> color;
    for (int i = 0; i < scc.size(); i++)
    {
        int r = rand() % 256;
        int g = rand() % 256;
        int b = rand() % 256;
        color[i] = "\'"+std::to_string(r)+","+std::to_string(g)+","+std::to_string(b)+"\'";
    }

    for (auto &i: edges)
    {
        int v1 = i.first;
        for (auto j: i.second)
        {
            int v2 = j;
            file << v1 << "," << v2 << "," << "true,";
            if (scc[v1] == scc[v2])
                file << color[scc[v1]] << "\n";
            else
                file << def << "\n";
        }
    }
}