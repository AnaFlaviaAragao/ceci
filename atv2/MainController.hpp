#ifndef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H

#include "values.hpp"

class MainController {
 private:
  Estado state, nextState;
  int clkA;

 public:
  MainController();
  Estado defineNextState(int reset, int clk, int opcode);
  Estado getState();
};

#endif  // MAIN_CONTROLLER_H