#include "flop_1_gm.hpp"

#include <iostream>
#include <fstream>

int main()
{
    std::fstream vectorFile("../simulation/modelsim/flop_1.tv", std::fstream::out);
    vectorFile << "//clk_reset_a_S" << std::endl;

    int reset = 0;
    int a = 0, clk = 0, S;
    S = flop(a, reset, clk); // clk=0
    vectorFile << clk << "_" << reset << "_" << a << "_" << S << std::endl;
    clk = ~clk & 0x1; // clk=1

    a = 0;
    S = flop(a, reset, clk);
    vectorFile << clk << "_" << reset << "_" << a << "_" << S << std::endl;
    clk = ~clk & 0x1; // clk=0

    a = 1;
    S = flop(a, reset, clk);
    vectorFile << clk << "_" << reset << "_" << a << "_" << S << std::endl;
    clk = ~clk & 0x1; // clk=1

    a = 1;
    S = flop(a, reset, clk);
    vectorFile << clk << "_" << reset << "_" << a << "_" << S << std::endl;
    clk = ~clk & 0x1; // clk=0

    a = 1;
    S = flop(a, reset, clk);
    vectorFile << clk << "_" << reset << "_" << a << "_" << S << std::endl;
    clk = ~clk & 0x1; // clk=1

    reset = 1;
    S = flop(a, reset, clk);
    vectorFile << clk << "_" << reset << "_" << a << "_" << S << std::endl;
    clk = ~clk & 0x1; // clk=0

    a = 0;
    S = flop(a, reset, clk);
    vectorFile << clk << "_" << reset << "_" << a << "_" << S << std::endl;
    clk = ~clk & 0x1; // clk=1

    a = 0;
    S = flop(a, reset, clk);
    vectorFile << clk << "_" << reset << "_" << a << "_" << S << std::endl;
}