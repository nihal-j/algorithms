#ifndef DCSC_H
#define DCSC_H

#include "graph.h"

class DCSC
{
    public:
        void desc(int i, std::map<int, int> &valid);
        void pred(int i, std::map<int, int> &valid);
        void dcsc(std::map<int, int> &valid);
        std::vector<std::vector<int>> get_scc(Graph& g, Graph &gT);

    private:
        std::map<int, int> d, p;
        std::vector<std::vector<int>> components;
        Graph g, gT;
};

#endif