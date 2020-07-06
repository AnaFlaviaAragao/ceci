#include "flop_1_gm.hpp"

//TODO: transformar em classe

int clkA = 1;
int q;

int flop(int a, int reset, int clk)
{
    if (!reset)
    {
        if (clk > clkA)
        {
            q = a;
            clkA = clk;
            return a;
        }
        else
        {
            clkA = clk;
            return q;
        }
    }
    clkA = 1;
    q = 0;
    return q;
}
