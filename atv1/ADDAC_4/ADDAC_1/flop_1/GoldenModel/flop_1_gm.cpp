#include "flop_1_gm.hpp"

int FLOP::solve(int a, int reset, int clk)
{
    if (!reset)
    {
        if (clk > previousClk)
        {
            q = a;
            previousClk = clk;
            return a;
        }
        else
        {
            previousClk = clk;
            return q;
        }
    }
    previousClk = 1;
    q = 0;
    return q;
}
