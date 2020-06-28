#include "flop_1.hpp"

int flop(int set, int reset, int pQ)
{
    if ((set and !reset) or (!reset and pQ))
        return 1;
    return 0;
}
