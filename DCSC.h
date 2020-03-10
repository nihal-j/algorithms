#ifndef DCSC_H
#define DCSC_H

#include "graph.h"

class DCSC
{
    public:
        /**
         * @brief Modifies `valid` to indicate which vertices are descendants of vertex `i` by performing dfs on `g`
         * 
         * @param i current vertex
         * @param valid indicator of descendants. valid[j] = 1 if `j` is a descendant of `i`, 0 otherwise
         */
        void desc(int i, std::map<int, int> &valid);
        /**
         * @brief Modifies `valid` to indicate which vertices are predecessors of vertex `i` by performing dfs on `gT`. Descendants of `i` in `gT` are predecessors of `i` in `g`
         * 
         * @param i current vertex
         * @param valid indicator of predecssors. valid[j] = 1 if `j` is a predecessor of `i`, 0 otherwise
         */
        void pred(int i, std::map<int, int> &valid);
        /**
         * @brief Find the strongly connected components in the graph induced by `valid` on `g`
         * 
         * @param valid indicator of valid vertices in the current induced subgraph of `g`. `valid[i]` = 1 if `i` is present the current induced subgraph, 0 otherwise
         */
        void dcsc(std::map<int, int> &valid);
        /**
         * @brief Get the scc object. Returns `components`
         * 
         * @param g reference to Graph object
         * @param gT reference to transpose of `g`
         * @return std::vector<std::vector<int>>& list of strongly connected components in `g`
         */
        std::vector<std::vector<int>> get_scc(Graph& g, Graph &gT);

    private:
        std::map<int, int> d, p;
        /**
         * @brief list of strongly connected components
         * 
         */
        std::vector<std::vector<int>> components;
        /**
         * @brief references to graphs of which strongly connected components have to be found
         * 
         */
        Graph g, gT;
};

#endif