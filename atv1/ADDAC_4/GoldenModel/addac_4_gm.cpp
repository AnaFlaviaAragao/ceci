#include "addac_4_gm.hpp"

#include <bitset>
#include <iostream>
#include <tuple>

ADDAC4::ADDAC4() : addac_0(0), addac_1(1), addac_2(2), addac_3(3), S(0) {}

bool ADDAC4::getBitAt(int value, int position) {
  return value & (1 << position);
}

int ADDAC4::setBitAt(int value, int position) {
  int mask = 1 << position;
  return value | mask;
}

int ADDAC4::solution() {
  S = 0b0000;
  S = S | (S0 << 0);
  S = S | (S1 << 1);
  S = S | (S2 << 2);
  S = S | (S3 << 3);

  return S;
}

std::tuple<int, int> ADDAC4::solve(int a, int sel0, int sel1, int clk,
                                   int reset, int cin) {
  std::tie(S0, cout) =
      addac_0.solve(getBitAt(a, 0), sel0, sel1, clk, reset, cin);

  std::tie(S1, cout) =
      addac_1.solve(getBitAt(a, 1), sel0, sel1, clk, reset, cout);

  std::tie(S2, cout) =
      addac_2.solve(getBitAt(a, 2), sel0, sel1, clk, reset, cout);

  std::tie(S3, cout) =
      addac_3.solve(getBitAt(a, 3), sel0, sel1, clk, reset, cout);

  return {solution(), cout};
}