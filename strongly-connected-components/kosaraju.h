#ifndef KOSARAJU_H
#define KOSARAJU_H

#include "graph.h"

class Kosaraju
{
    public:
        /**
         * @brief list to store the vertices in the current stronly connected component
         * 
         */
        std::vector<int> component;
        /**
         * @brief list of strongly connected components
         * 
         */
        std::vector<std::vector<int>> components;
        /**
         * @brief stack to be used in Kosaraju's algorithm
         * 
         */
        std::stack<int> s;
        /**
         * @brief map to store information about already visited vertices when performing depth first search
         * 
         */
        std::map<int, int> visited;
        /**
         * @brief set of vertices to perform depth first search on
         * 
         */
        std::set<int> vertices;

        /**
         * @brief depth first search as desribed in Kosaraju's algorithm. This version is used to perform both the passes from the algorithm.
         * If `flag` = 1, then the depth first search is being performed on the transpose of the graph and is can be used to store the current component information.
         * 
         * @param i index of current vertex
         * @param flag indicator variable to know whether dfs is on transpose (set to 1 in that case)
         * @param g reference to Graph object on which dfs is being performed
         */
        void dfs(int i, int flag, Graph &g);

        /**
         * @brief Get the scc object. Returns `components`
         * 
         * @param g reference to Graph object
         * @param gT reference to transpose of `g`
         * @return std::vector<std::vector<int>>& list of strongly connected components in `g`.
         */
        std::vector<std::vector<int>>& get_scc(Graph &g, Graph &gT);
};

#endif