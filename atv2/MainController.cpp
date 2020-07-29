#include "MainController.hpp"

MainController::MainController() : state(S0) {}

Estado MainController::defineNextState(int reset, int clk, int opcode) {
  if (reset == 1) {
    state = S0;
    return state;
  }

  const int algo = 0b111;
  int a = 0b1;

  switch (state) {
    case S0:
      nextState = S1;
      break;
    case S1:
      switch (opcode) {
        case SW:
        case LW:
          nextState = S2;
          break;
        case ADD:
        case SUB:
        case AND:
        case OR:
        case XOR:
          nextState = S6;
          break;
        case BEQ:
          nextState = S8;
          break;
        case ADDI:
        case ORI:
        case XORI:
          nextState = S9;
          break;
        // case J:
        //   nextState = S11;
        //   break;
        case BNE:
          nextState = S12;
          break;
        default:
          throw 1;
          break;
      }
      break;
    case S2:
      switch (opcode) {
        case LW:
          nextState = S3;
          break;
        case SW:
          nextState = S5;
          break;
        default:
          break;
      }
      break;
    case S3:
      nextState = S4;
      break;
    case S4:
      nextState = S0;
      break;
    case S5:
      nextState = S0;
      break;
    case S6:
      nextState = S7;
      break;
    case S7:
      nextState = S0;
      break;
    case S8:
      nextState = S0;
      break;
    case S9:
      nextState = S10;
      break;
    case S10:
      nextState = S0;
      break;
    case S11:
      nextState = S0;
      break;
    case S12:
      nextState = S0;
      break;
    default:
      nextState = S0;
      break;
  };

  if (clk > clkA) {
    state = nextState;
  }

  clkA = clk;
  return state;
}

Estado MainController::getState() { return state; }