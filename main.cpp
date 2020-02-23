#include <algorithm>
#include <iostream>
#include <stack>
#include <string.h>
#include <vector>

#include "graph.h"

std::vector<int> order;

std::vector<int> component;
std::vector<std::vector<int>> components;

std::stack<int> s;
std::map<int, int> visited;

void dfs_kosarju(int i, int flag, Graph &g)
{
    visited[i] = 1;
    if (flag)
        component.push_back(i);

    std::vector<int> e = g.get_outgoing_edges(i);
    for (int j = 0; j < e.size(); j++)
        if (visited.find(e[j]) == visited.end())
            dfs_kosarju(e[j], flag, g);

    if (!flag)
        s.push(i);
}

int main()
{
    freopen("data/wiki-Vote.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int v, e;
    std::cin >> v >> e;

    Graph g(v, e), gT(v, e);

    for (int i = 0; i < e; i++)
    {
        int a, b;
        std::cin >> a >> b;
        g.insert_edge(a, b);
        gT.insert_edge(b, a);
        g.vertex.insert(a);
        g.vertex.insert(b);
        gT.vertex.insert(a);
        gT.vertex.insert(b);
    }

    for (auto i: g.vertex)
        if (visited.find(i) == visited.end())
            dfs_kosarju(i, 0, g);

    visited.clear();
    g = gT;

    int cnt = 0;
    while (!s.empty())
    {
        if (visited.find(s.top()) == visited.end())
        {
            visited[s.top()] = 1;
            dfs_kosarju(s.top(), 1, g);
            components.push_back(component);
            component.clear();
        }
        s.pop();
    }

    std::cout << components.size() << "\n";
    for (int i = 0; i < components.size(); i++)
    {
        for (int j = 0; j < components[i].size(); j++)
        {
            g.scc[components[i][j]] = i;
            std::cout << components[i][j] << " ";
        }
        std::cout << "\n";
    }

    g.visualize();
    return 0;
}