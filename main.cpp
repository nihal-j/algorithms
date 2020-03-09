#include "DCSC.h"
#include "kosaraju.h"

int main(int argc, char* argv[])
{
    freopen(argv[1], "r", stdin);
    std::ofstream file;
    file.open(argv[2]);
    
    int v, e;
    std::cin >> v >> e;

    Graph g(v, e), gT(v, e);
    Kosaraju kosaraju;
    DCSC dcsc;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        std::cin >> a >> b;
        g.insert_edge(a, b);
        gT.insert_edge(b, a);
        g.vertices.insert(a), g.vertices.insert(b);
    }

    // std::vector<std::vector<int>> components = kosaraju.get_scc(g, gT);
    std::vector<std::vector<int>> components = dcsc.get_scc(g, gT);
    std::cout << "Number of SCC: ";
    std::cout << components.size() << "\n";


    for (int i = 0; i < components.size(); i++)
        std::sort(components[i].begin(), components[i].end());
    std::sort(components.begin(), components.end());
    
    for (int i = 0; i < components.size(); i++)
    {
        for (int j = 0; j < components[i].size(); j++)
        {
            g.scc[components[i][j]] = i;
            file << components[i][j] << " ";
        }
        file << "\n";
    }

    // g.visualize();
    return 0;
}