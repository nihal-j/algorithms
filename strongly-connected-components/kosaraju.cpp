#include "kosaraju.h"

void Kosaraju::dfs(int i, int flag, Graph &g)
{
    visited[i] = 1;
    if (flag)
        component.push_back(i);

    std::vector<int>& e = g.get_outgoing_edges(i);
    for (int j = 0; j < e.size(); j++)
        if (visited.find(e[j]) == visited.end())
            dfs(e[j], flag, g);

    if (!flag)
        s.push(i);
}

std::vector<std::vector<int>>& Kosaraju::get_scc(Graph &g, Graph &gT)
{
    for (auto i: g.vertices)
        if (visited.find(i) == visited.end())
            dfs(i, 0, g);
        
    visited.clear();

    while (!s.empty())
    {
        if (visited.find(s.top()) == visited.end())
        {
            visited[s.top()] = 1;
            dfs(s.top(), 1, gT);
            components.push_back(component);
            component.clear();
        }
        s.pop();
    }

    return components;
}