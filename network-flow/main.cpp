#include <iostream>
#include "fordfulkerson.hpp"

int main(int argc, char* argv[])
{

    char* path = (char*)"data/test1.txt";
    if (argc > 1)
        path = argv[1];
    freopen(path, "r", stdin);

    FordFulkerson handle = FordFulkerson();
    std::cin >> handle.n >> handle.m >> handle.s >> handle.t;
    for (int i = 1; i <= handle.m; i++)
	{
		int a, b, c;
		std::cin >> a >> b >> c;
		handle.graph[a][b] = c;
		handle.residual[a][b] = c;
	}

    handle.calculate_flows();
    std::cout << handle.get_max_flow() << "\n";
    std::cout << handle.get_min_st_cut() << "\n";
}