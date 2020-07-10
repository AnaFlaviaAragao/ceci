#include "addac_4_gm.hpp"
#include <iostream>
#include <tuple>

ADDAC4::ADDAC4() : addac_0(0), addac_1(1), addac_2(2), addac_3(3), S(0) {}

bool ADDAC4::getBitAt(int value, int position)
{
    return value & (1 << position);
}

int ADDAC4::getBitAt(int position)
{
    return S & (1 << position);
}

int ADDAC4::setBitAt(int value, int position)
{
    int mask = 1 << position;
    return value | mask;
}

int ADDAC4::solution()
{
    S = S | (S0 << 0);
    S = S | (S1 << 1);
    S = S | (S2 << 2);
    S = S | (S3 << 3);

    return S;
}

std::tuple<int, int, int, int, int> ADDAC4::solve(int a, int sel0, int sel1, int clk, int reset, int cin)
{

    // 0b0001

    std::tie(S0, cout0) = addac_0.solve(getBitAt(a, 0), sel0, sel1, clk, reset, cin);
    // std::cout << "S0:" << S0 << " COUT0: " << cout0 << " ACC: " << addac_0.getAcc() << std::endl;

    std::tie(S1, cout1) = addac_1.solve(getBitAt(a, 1), sel0, sel1, clk, reset, cout0);
    // std::cout << "S1:" << S1 << " COUT1: " << cout1 << " ACC: " << addac_1.getAcc() << std::endl;

    std::tie(S2, cout2) = addac_2.solve(getBitAt(a, 2), sel0, sel1, clk, reset, cout1);
    // std::cout << "S2:" << S2 << " COUT2: " << cout2 << " ACC: " << addac_2.getAcc() << std::endl;

    std::tie(S3, cout) = addac_3.solve(getBitAt(a, 3), sel0, sel1, clk, reset, cout2);
    // std::cout << "S3:" << S3 << " COUT: " << cout << " ACC: " << addac_3.getAcc() << std::endl;

    return {S3, S2, S1, S0, cout};
}