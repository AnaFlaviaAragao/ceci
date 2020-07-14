#include "addac_4_gm.hpp"

#include <bitset>
#include <iostream>
#include <tuple>

ADDACFull::ADDACFull(int resolution)
    : resolution(resolution), output(resolution, 0), addacs() {
  addacs.reserve(resolution);
  for (int i = 0; i < resolution; i++) addacs.push_back(ADDAC(i));
}

bool ADDACFull::getBitAt(int value, int position) {
  return value & (1 << position);
}

int ADDACFull::setBitAt(int value, int position) {
  int mask = 1 << position;
  return value | mask;
}

void ADDACFull::groupBits() {
  S = 0b0;
  for (int i = 0; i < resolution; i++) S = S | (output[i] << i);
}

std::tuple<int, int> ADDACFull::solve(int a, int sel0, int sel1, int clk,
                                      int reset, int cin) {
  for (int i = 0; i < resolution; i++) {
    std::tie(output[i], cout) =
        addacs[i].solve(getBitAt(a, i), sel0, sel1, clk, reset, cout);
  }

  groupBits();
  return {S, cout};
}