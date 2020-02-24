#include <algorithm>
#include <iostream>
#include <stack>
#include <string.h>
#include <vector>

#include "graph.h"

Graph g, gT;
std::vector<std::vector<int>> SCC;

void desc(int i, std::map<int, int> &visited, std::map<int, int> &valid)
{
	visited[i] = 1;
    std::vector<int> e = g.get_outgoing_edges(i);
	for (int child: e)
		if (visited.find(child) == visited.end() && valid.count(child) != 0)
			desc(child, visited, valid);
	return;
}

void pred(int i, std::map<int, int> &visited, std::map<int, int> &valid)
{
	visited[i] = 1;
    std::vector<int> e = gT.get_outgoing_edges(i);
	for (int child: e)
		if (visited.find(child) == visited.end() && valid.count(child) != 0)
			pred(child, visited, valid);
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

	std::map<int, int> d, p;

	desc(vertex, d, valid);
	pred(vertex, p, valid);

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
	d.clear();
	p.clear();
	scc.clear();
	dcsc(validP);
	dcsc(validD);
	dcsc(validR);
}

int main()
{
    freopen("data/input2.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
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
        g.vertex.insert(a);
        g.vertex.insert(b);
        gT.vertex.insert(a);
        gT.vertex.insert(b);
        valid[a] = 1;
		valid[b] = 1;
    }

    dcsc(valid);

    std::cout << SCC.size() << "\n";
	for (int i = 0; i < SCC.size(); i++)
	{
		for (int j: SCC[i])
        {
            g.scc[j] = i;
			std::cout << j << " ";
        }
		std::cout << "\n";
	}

    // g.visualize();

    return 0;
}