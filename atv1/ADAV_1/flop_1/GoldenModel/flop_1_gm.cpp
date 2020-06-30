#include "flop_1_gm.hpp"

int flop(int set, int previousS, int reset, int clk, int *clkA)
{
    if (!reset)
    {
        if (clk > *clkA)
        {
            *clkA = clk;
            return set;
        }
        else
        {
            *clkA = clk;
            return previousS;
        }
    }
    *clkA = clk;
    return 0;
}
