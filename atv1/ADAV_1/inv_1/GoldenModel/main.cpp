#include "inv_1_gm.hpp"

#include <iostream>
#include <fstream>

int main()
{
    std::fstream vectorFile("../simulation/modelsim/inv_1.tv", std::fstream::out);

    int a = 0;

    vectorFile << "//a_S" << std::endl;

    for (int a = 0; a < 2; a++)
    {
        int S = inversor(a);
        vectorFile << a << "_" << S << std::endl;
    }
}