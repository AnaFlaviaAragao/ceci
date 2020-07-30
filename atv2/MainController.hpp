#ifndef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H

#include <iostream>

#include "values.hpp"

class MainController {
 private:
  Estado state, nextState;
  int clkA;

 public:
  MainController();
  Estado defineNextState(int reset, int clk, Instrucao instrucao);
  void run(Instrucao instrucao, int reset);

  Estado getState();
  Estado getNextState();
};

#endif  // MAIN_CONTROLLER_H