#ifndef KOSARAJU_H
#define KOSARAJU_H

#include "graph.h"

class Kosaraju
{
    public:
        std::vector<int> component;
        std::vector<std::vector<int>> components;
        std::stack<int> s;
        std::map<int, int> visited;
        std::set<int> vertices;

        void dfs(int i, int flag, Graph &g);
        std::vector<std::vector<int>>& get_scc(Graph &g, Graph &gT);
};

#endif