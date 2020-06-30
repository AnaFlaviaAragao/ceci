#include "inv_1_gm.hpp"

int inversor(int value)
{
    return ~value & 0x1;
}

// 0b110101