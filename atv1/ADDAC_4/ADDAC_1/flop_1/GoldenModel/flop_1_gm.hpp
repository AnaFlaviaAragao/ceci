#ifndef FLOP_H
#define FLOP_H

class FLOP {
 private:
  int q, previousClk;

 public:
  /**
   * Latch.
   *
   * @param a Input A pin
   * @param reset Async rest pin
   * @param clk Clock pin
   * @return "a" for clk going down->up; last "a" for clk going up->down; or "0"
   * of reset = 1
   */
  int solve(int a, int reset, int clk);
};

#endif  // FLOP_H