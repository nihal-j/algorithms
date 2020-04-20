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
        /// flow network graph
        std::map<int, std::map<int, int>> flow;
        /// residual graph
        std::map<int, std::map<int, int>> residual;
        /// original graph
        std::map<int, std::map<int, int>> graph;
        /// number of edges
        int m;
        /// number of vertices
        int n;
        /// source vertex
        int s;
        /// sink vertex
        int t;
        
        /**
         * @brief DFS subroutine to find an augmenting path
         * 
         * @param i current node
         * @param visited `visited[j]` = 1 if jth node is seen already; 0 otherwise
         * @param parent  `parent[j]` = k if k is a successor of j in the current DFS tree
         * @return int 1 `if `t` is visited; 0 otherwise
         */
        int dfs(int i, std::vector<int> &visited, std::vector<int>& parent);

        /**
         * @brief Driver routine to find augmenting path; update flow and residual graphs; repeat until residual graph has an augmenting path
         */
        void calculate_flows();

        /**
         * @brief Get the max flow value by adding all flow capacities on edges outgoing from `s`
         * @return int value of max flow
         */
        int get_max_flow();

        /**
         * @brief Get the min st cut value by traversing residual graph; also populates `S` and `T`
         * @return int value of the min st cut
         */
        int get_min_st_cut();

        /// S partition of st cut
        std::set<int> S;
        /// T partition of st cut
        std::set<int> T;
};

#endif