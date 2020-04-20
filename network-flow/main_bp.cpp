/**
 * @file main.cpp
 * @brief driver file for maximum bipartite matching using Ford Fulkerson algorithm
 */
#include <iostream>
#include "fordfulkerson.hpp"

int main(int argc, char* argv[])
{
    char* path = (char*)"data/bp2.txt";
    if (argc > 1)
        path = argv[1];
    freopen(path, "r", stdin);

    FordFulkerson handle = FordFulkerson();
    int l, r;
    std::cin >> l >> r;
    std::cin >> handle.m;

    std::set<int> A, B;

    for (int i = 1; i <= handle.m; i++)
	{
		int a, b;
		std::cin >> a >> b;
        b += l;
		handle.graph[a][b] = 1;
		handle.residual[a][b] = 1;
        handle.n = std::max(handle.n, std::max(a, b));
        A.insert(a);
        B.insert(b);
	}

    handle.s = ++handle.n;
    handle.t = ++handle.n;

    for (int nd: A)
    {
        handle.graph[handle.s][nd] = 1;
		handle.residual[handle.s][nd] = 1;
    }
    for (int nd: B)
    {
        handle.graph[nd][handle.t] = 1;
		handle.residual[nd][handle.t] = 1;
    }

    // calculating max flow in the modified graph
    handle.calculate_flows();
    std::cout << "Maximum number of matchings (value of max flow): ";
    std::cout << handle.get_max_flow() << "\n";

    // printing the matchings found in the flow network
    std::cout << "Matchings: \n";
    for (auto &i: handle.flow[handle.s])
    {
        std::cout << i.first << ": ";
        for (auto &j: handle.flow[i.first])
            std::cout << j.first - l << " ";
        std::cout << "\n";
    }
}