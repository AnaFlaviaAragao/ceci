#include "flop_1_gm.hpp"

#include <iostream>
#include <fstream>

int main()
{
    std::fstream vectorFile("../simulation/modelsim/flop_1.tv", std::fstream::out);
    vectorFile << "//set_reset_clk_S" << std::endl;

    int set = 0, reset = 0, clk = 0, clkA = 1, S = 0;

    S = flop(set, S, reset, clk, &clkA);
    vectorFile << set << "_" << reset << "_" << clk << "_" << S << std::endl;

    set = 1;
    clk = ~clk & 0x1;
    S = flop(set, S, reset, clk, &clkA);
    vectorFile << set << "_" << reset << "_" << clk << "_" << S << std::endl;

    set = 0;
    clk = ~clk & 0x1;
    S = flop(set, S, reset, clk, &clkA);
    vectorFile << set << "_" << reset << "_" << clk << "_" << S << std::endl;

    set = 0;
    clk = ~clk & 0x1;
    S = flop(set, S, reset, clk, &clkA);
    vectorFile << set << "_" << reset << "_" << clk << "_" << S << std::endl;

    set = 1;
    reset = 1;
    clk = ~clk & 0x1;
    S = flop(set, S, reset, clk, &clkA);
    vectorFile << set << "_" << reset << "_" << clk << "_" << S << std::endl;
}