#include <algorithm>
#include <iostream>
#include <stack>
#include <string.h>
#include <vector>
#include "graph.h"

Graph g, gT;
std::vector<std::vector<int>> SCC;
std::map<int, int> d, p;

void desc(int i, std::map<int, int> &valid)
{
	d[i] = 1;
    std::vector<int>& e = g.get_outgoing_edges(i);
	for (int child: e)
		if (d.count(child) == 0 && valid.count(child) != 0)
			desc(child, valid);
	return;
}

void pred(int i, std::map<int, int> &valid)
{
	p[i] = 1;
    std::vector<int>& e = gT.get_outgoing_edges(i);
	for (int child: e)
		if (p.count(child) == 0 && valid.count(child) != 0)
			pred(child, valid);
	return;
}

void dcsc(std::map<int, int> &valid)
{	
	if (valid.size() <= 1)
	{
		for (auto &i: valid)
			SCC.push_back({i.first});
		return;
	}

	int vertex = (*valid.begin()).first;

	d.clear();
	p.clear();
	desc(vertex, valid);
	pred(vertex, valid);

	std::vector<int> scc;
	std::map<int, int> validP, validR, validD;
	for (auto &i: valid)
	{
		int D = d.find(i.first) != d.end();
		int P = p.find(i.first) != p.end();
		if (P && D)
			scc.push_back(i.first);
		if (!D && P)
			validP[i.first] = 1;
		if (D && !P)
			validD[i.first] = 1;
		if (!D && !P)
			validR[i.first] = 1;
	}

	SCC.push_back(scc);
	valid.clear();
	scc.clear();
	dcsc(validP);
	dcsc(validD);
	dcsc(validR);
}

int32_t main(int argc, char* argv[])
{
    freopen(argv[1], "r", stdin);
    
    std::map<int, int> valid;
    int v, e;
    std::cin >> v >> e;
    g = Graph(v, e);
    gT = Graph(v, e);

    for (int i = 0; i < e; i++)
    {
        int a, b;
        std::cin >> a >> b;
        g.insert_edge(a, b);
        gT.insert_edge(b, a);
        valid[a] = 1;
		valid[b] = 1;
    }
    dcsc(valid);

	std::ofstream file;
	file.open("output.txt");
    std::cout << "Number of components: " << SCC.size() << "\n";
	for (int i = 0; i < SCC.size(); i++)
	{
		for (int j: SCC[i])
        {
            g.scc[j] = i;
			file << j << " ";
        }
		file << "\n";
	}
    // g.visualize();

    return 0;
}