#ifndef GRAPH_H
#define GRAPH_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string.h>
#include <vector>

class Graph 
{ 
    public:
        /**
         * @brief Construct a new Graph object
         * 
         */
        Graph() {};
        /**
         * @brief Construct a new Graph object
         * 
         * @param x number of vertices
         * @param y number of edges
         */
        Graph(int x, int y);
        /**
         * @brief Insert a new edge in graph from `src` to `dest`
         * 
         * @param src source vertex
         * @param dest destination vertex
         */
        void insert_edge(int src, int dest);
        /**
         * @brief Get the outgoing edges object
         * 
         * @param v vertex for which outgoing edges are required
         * @return std::vector<int>& reference to the list of outgoing edges of `v`
         */
        std::vector<int>& get_outgoing_edges(int v);
        /**
         * @brief Generate files for visualzing strongly connected components in the graph.
         * Two files are generated:
         *  - `nodes.txt`: Each line contains two integers v and i indicating that vertex v
         *     belongs to SCC number i.  
         *  - `edges.txt`: Each line contains two integers i and j indicating a directed edge
         *     from i to j.
         */
        void visualize();
        /**
         * @brief map between the vertex and its SCC label
         */
        std::map<int, int> scc;
        /**
         * @brief set of vertex labels in the graph
         */
        std::set<int> vertices;

    private:
        /**
         * @brief vertex and edge count respectively
         */
        int vCount, eCount;
        /**
         * @brief graph representation stored in adjacency list format.
         * `edges[i]` is a list of all the vertices that are reachable from vertex i
         * through a single edge
         */
        std::map<int, std::vector<int>> edges;
};

#endif