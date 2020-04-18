#ifndef FORDFULKERSON_HPP
#define FORDFULKERSON_HPP

#include <vector>
#include <map>
#include <iostream>
#include <set>
#include <queue>

class FordFulkerson
{
    public:
        std::map<int, std::map<int, int>> flow;
        std::map<int, std::map<int, int>> residual;
        std::map<int, std::map<int, int>> graph;
        int m;
        int n;
        int s;
        int t;
        int dfs(int i, std::vector<int> &visited, std::vector<int>& parent);
        void calculate_flows();
        int get_max_flow();
        int get_min_st_cut();
};

#endif