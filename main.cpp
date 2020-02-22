#include <algorithm>
#include <iostream>
#include <stack>
#include <string.h>
#include <vector>

#include "graph.h"

int visited[(int)1e5];
std::vector<int> order;
std::vector<int> component;
std::vector<std::vector<int>> components;

void dfs_finish_order(Graph* g, int i)
{
    visited[i] = 1;
    std::vector<int> edges = g -> get_outgoing_edges(i);
    for (int j = 0; j < edges.size(); j++)
        if (!visited[edges[j]])
            dfs_finish_order(g, edges[j]);
    order.push_back(i);
}

void dfsT(Graph* gT, int i)
{
    visited[i] = 1;
    component.push_back(i);
    std::vector<int> edgesT = gT -> get_outgoing_edges(i);
    for (int j = 0; j < edgesT.size(); j++)
        if (!visited[edgesT[j]])
            dfsT(gT, edgesT[j]);
}

int main()
{
    freopen("input.txt", "r", stdin);
    
    int v, e;
    std::cin >> v >> e;

    Graph g(v, e), gT(v, e);

    for (int i = 0; i < e; i++)
    {
        int a, b;
        std::cin >> a >> b;
        g.insert_edge(a, b);
        gT.insert_edge(b, a);
    }

    memset(visited, 0, sizeof visited);
    for (int i = 1; i <= v; i++)
        if (!visited[i])
            dfs_finish_order(&g, i);
    
    std::reverse(order.begin(), order.end());
    memset(visited, 0, sizeof visited);
    for (int i = 0; i < order.size(); i++)
    {
        if (!visited[order[i]])
        {
            dfsT(&gT, order[i]);
            components.push_back(component);
            component.clear();
        }
    }

    std::cout << components.size() << "\n";
    for (int i = 0; i < components.size(); i++)
    {
        for (int j = 0; j < components[i].size(); j++)
            std::cout << components[i][j] << " ";
        std::cout << "\n";
        
    }

    return 0;
}