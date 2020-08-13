#ifndef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H

#include <iostream>

#include "ALUDecoder.hpp"
#include "Instruction.hpp"
#include "values.hpp"

class MainController {
 private:
  Estado state, nextState;
  int reset, clkA;

  int IorD, ALUSrcA, ALUSrcB, ALUOp, PCSrc, RegDst, MemtoReg;
  bool IRWrite, PCWrite, RegWrite, MemWrite, BranchEQ, BranchNE;

  ALUDecoder aluDecoder;

  /**
   * defineNextState changes MainController states based on clock and
   * instructions.
   *
   * @return the next state based on actual state.
   */
  Estado defineNextState(int clk, Instruction instrucao);

 public:
  MainController();

  /**
   * run emulates a complete run with a predefined instruction.
   *
   * @param instrucao instruction to be fetched.
   * @param reset async reset pin.
   *
   */
  void run(Instruction inst, int reset);
  void printState();

  Estado getState();
  Estado getNextState();
};

#endif  // MAIN_CONTROLLER_H