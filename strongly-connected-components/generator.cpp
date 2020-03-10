/**
 * @file generator.cpp
 * @brief Generator program for generating random graphs.
 */

#include <iostream>
#include <fstream>

/**
 * @brief Utility function to get a decision value based on probability = 0.1.
 * 1 is returned with a probability 0.1, 0 otherwise.
 * 
 * @return int 0 or 1 as described above.
 */

int edge_exists()
{
    double prob = (double)std::rand() / RAND_MAX;
    if (prob <= 0.1)
        return 1;
    return 0;
}

int main(int argc, char* argv[])
{
    srand(time(NULL));
    int v = atoi(argv[1]);
    std::ofstream file;
    file.open(argv[2]);
    std::string output = "";
    int e = 0;

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (edge_exists())
            {
                e++;
                output += std::to_string(i) + " " + std::to_string(j) + "\n";
            }
        }
    }

    file << v << " " << e << "\n";
    file << output;

    return 0;
}