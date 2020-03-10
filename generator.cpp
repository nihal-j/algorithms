#include <iostream>
#include <fstream>

double edge_exists()
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