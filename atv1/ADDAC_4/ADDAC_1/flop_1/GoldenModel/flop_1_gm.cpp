#include "flop_1_gm.hpp"

FLOP::FLOP() : previousClk(0) {}

int FLOP::getPreviousClk() { return previousClk; }

int FLOP::solve(int a, int reset, int clk) {
  if (!reset) {
    if (clk > previousClk) {
      this->q = a;
      previousClk = clk;
      return a;
    } else {
      previousClk = clk;
      return this->q;
    }
  }
  previousClk = 1;
  this->q = 0;
  return this->q;
}
