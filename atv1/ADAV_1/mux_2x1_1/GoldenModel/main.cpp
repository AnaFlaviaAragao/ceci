#include "mux_2x1_1_gm.hpp"
#include <fstream>

int main()
{
    std::fstream vectorFile("../simulation/modelsim/mux_2x1_1_1.tv", std::fstream::out);
    vectorFile << "//a_b_selector_S" << std::endl;

    for (int a = 0; a < 2; a++)
        for (int b = 0; b < 2; b++)
            for (int selector = 0; selector < 2; selector++)
            {
                int S = mux(a, b, selector);
                vectorFile << a << "_" << b << "_" << selector << "_" << S << std::endl;
            }

    vectorFile.close();
}