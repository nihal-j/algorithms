#include "DCSC.h"

void DCSC::desc(int i, std::map<int, int> &valid)
{
	d[i] = 1;
    std::vector<int>& e = g.get_outgoing_edges(i);
	for (int child: e)
		if (d.count(child) == 0 && valid.count(child) != 0)
			desc(child, valid);
	return;
}

void DCSC::pred(int i, std::map<int, int> &valid)
{
	p[i] = 1;
    std::vector<int>& e = gT.get_outgoing_edges(i);
	for (int child: e)
		if (p.count(child) == 0 && valid.count(child) != 0)
			pred(child, valid);
	return;
}

void DCSC::dcsc(std::map<int, int> &valid)
{	
	if (valid.size() <= 1)
	{
		for (auto &i: valid)
			components.push_back({i.first});
		return;
	}

	int vertex = (*valid.begin()).first;

	d.clear();
	p.clear();
	desc(vertex, valid);
	pred(vertex, valid);

	std::vector<int> component;
	std::map<int, int> validP, validR, validD;
	for (auto &i: valid)
	{
		int D = d.find(i.first) != d.end();
		int P = p.find(i.first) != p.end();
		if (P && D)
			component.push_back(i.first);
		if (!D && P)
			validP[i.first] = 1;
		if (D && !P)
			validD[i.first] = 1;
		if (!D && !P)
			validR[i.first] = 1;
	}

	components.push_back(component);
	valid.clear();
	component.clear();
	dcsc(validP);
	dcsc(validD);
	dcsc(validR);
}

std::vector<std::vector<int>> DCSC::get_scc(Graph& g, Graph &gT)
{
    this -> g = g;
    this -> gT = gT;

    std::map<int, int> valid;
    for (int i: g.vertices)
        valid[i] = 1;
    
    dcsc(valid);

    return components;
}