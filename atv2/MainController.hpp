#ifndef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H

#include <iostream>

#include "values.hpp"

class MainController {
 private:
  Estado state, nextState;
  Instrucao instrucao;
  int reset, clkA;

  /**
   * defineNextState changes MainController states based on clock and
   * instructions.
   *
   * @return the next state based on actual state.
   */
  Estado defineNextState(int clk);

 public:
  MainController();

  /**
   * run emulates a complete run with a predefined instruction.
   *
   * @param instrucao instruction to be fetched.
   * @param reset async reset pin.
   *
   */
  void run(Instrucao instrucao, int reset);

  Estado getState();
  Estado getNextState();
};

#endif  // MAIN_CONTROLLER_H