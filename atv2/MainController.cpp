#include "MainController.hpp"

MainController::MainController() : state(S0) {}

Estado MainController::defineNextState(int reset, int clk, int opcode) {
  if (reset == 1) {
    state = S0;
    return state;
  }

  switch (state) {
    case S0:
      nextState = S1;
      break;
    case S1:
      nextState = S0;
      break;
    default:
      nextState = S0;
  };

  if (clk > clkA) {
    state = nextState;
  }

  clkA = clk;
  return state;
}

Estado MainController::getState() { return state; }