#include <map>
#include <vector>
#include <string.h>
#include <stack>
#include <set>

class Graph 
{ 
    public:
        Graph() {}
        Graph(int x, int y);
        void insert_edge(int src, int dest);
        std::vector<int>& get_outgoing_edges(int v);
        std::set<int> vertex;

    private:
        int vCount, eCount;
        std::map<int, std::vector<int>> edges;
};