#include <vector>
#include <string.h>
#include <stack>

class Graph 
{ 
    public:
        Graph(int x, int y);
        void insert_edge(int src, int dest);
        std::vector<int>& get_outgoing_edges(int v);

    private:
        int vCount, eCount;
        std::vector<std::vector<int>> edges;
};