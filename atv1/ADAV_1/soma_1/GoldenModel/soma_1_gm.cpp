#include "soma_1_gm.hpp"

int soma(int a, int b, int ci)
{
    return (a + b + ci) & 0x1;
}

int carry(int a, int b, int ci)
{
    if ((a + b + ci) > 1)
        return 1 & 0x1;
    else
        return 0;
}
