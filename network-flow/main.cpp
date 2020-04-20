/**
 * @file main.cpp
 * @brief driver file for Ford Fulkerson algorithm and calculation of min st cut
 */
#include <iostream>
#include "fordfulkerson.hpp"

int main(int argc, char* argv[])
{
    char* path = (char*)"data/test1.txt";
    // the path to the data can also be passed as an argument
    if (argc > 1)
        path = argv[1];
    // stdin is reopened as the file
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

    // value of the max flow
    std::cout << "Value of max flow: ";
    std::cout << handle.get_max_flow() << "\n";

    // value of the st cut
    std::cout << "Value of min st cut: ";
    std::cout << handle.get_min_st_cut() << "\n";

    // printing the st cut
    std::cout << "Set A: ";
    for (int nd: handle.S)
        std::cout << nd << " ";
    std::cout << "\n";
    std::cout << "Set B: ";
    for (int nd: handle.T)
        std::cout << nd << " ";
    std::cout << "\n";
}