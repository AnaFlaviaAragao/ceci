#include "mux_2x1_1.hpp"

int mux(int a, int b, int selector)
{
    return selector ? a : b;
}