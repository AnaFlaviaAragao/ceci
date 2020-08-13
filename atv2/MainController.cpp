#include "MainController.hpp"

MainController::MainController() : state(S0), aluDecoder() {
  IorD = 0b0;
  ALUSrcA = 0b0;
  ALUSrcB = 0b0;
  ALUOp = 0b0;
  PCSrc = 0b0;
  RegDst = 0b0;
  MemtoReg = 0b0;

  IRWrite = false;
  PCWrite = false;
  RegWrite = false;
  MemWrite = false;
  BranchEQ = false;
  BranchNE = false;
}

Estado MainController::getNextState() { return nextState; }

Estado MainController::defineNextState(int clk, Instruction instrucao) {
  if (reset == 1) {
    state = S0;
    return state;
  }

  switch (state) {
    case S0:
      IorD = 0b0;
      ALUSrcA = 0b0;
      ALUSrcB = 0b01;
      ALUOp = 0b00;
      PCSrc = 0b00;

      nextState = S1;
      break;
    case S1:
      ALUSrcA = 0b0;
      ALUSrcB = 0b11;
      ALUOp = 0b00;

      switch (instrucao.opcode) {
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
        case JAL:
          nextState = S11;
          break;
        case BNE:
          nextState = S12;
          break;
        default:
          throw 1;
          break;
      }
      break;
    case S2:
      ALUSrcA = 0b1;
      ALUSrcB = 0b10;
      ALUOp = 0b00;

      switch (instrucao.opcode) {
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
      IorD = 0b1;

      nextState = S4;
      break;
    case S4:
      RegDst = 0b0;
      MemtoReg = 0b1;
      RegWrite = true;

      nextState = S0;
      break;
    case S5:
      IorD = 0b1;
      MemWrite = true;

      nextState = S0;
      break;
    case S6:
      ALUSrcA = 0b1;
      ALUSrcB = 0b00;
      ALUOp = 10;

      nextState = S7;
      break;
    case S7:
      RegDst = 0b1;
      MemtoReg = 0b0;
      RegWrite = true;

      nextState = S0;
      break;
    case S8:
      ALUSrcA = 0b1;
      ALUSrcB = 0b00;
      ALUOp = 0b01;
      PCSrc = 0b01;
      BranchEQ = true;

      nextState = S0;
      break;
    case S9:
      ALUSrcA = 0b1;
      ALUSrcB = 0b10;
      ALUOp = 0b11;

      nextState = S10;
      break;
    case S10:
      RegDst = 0b0;
      MemtoReg = 0b0;
      RegWrite = true;

      nextState = S0;
      break;
    case S11:
      PCSrc = 0b10;
      PCWrite = true;

      nextState = S0;
      break;
    case S12:
      ALUSrcA = 0b1;
      ALUSrcB = 0b00;
      ALUOp = 0b01;
      PCSrc = 0b01;
      BranchNE = true;

      nextState = S0;
      break;
    default:
      nextState = S0;
      break;
  };

  if (clk > clkA) {
    state = nextState;

    printState();
    aluDecoder.decode((ALU::ALUOp)ALUOp, instrucao);
  }

  clkA = clk;
  return state;
}

void MainController::run(Instruction inst, int res) {
  int clk = 0;

  reset = res;

  do {
    defineNextState(clk, inst);
    clk = ~clk & 0x1;
  } while (nextState != S0);
  defineNextState(clk, inst);
}

Estado MainController::getState() { return state; }

void MainController::printState() {
  std::cout << "State S" << state << "\n"
            << "IorD " << IorD << "\n"
            << "ALUSrcA " << ALUSrcA << "\n"
            << "ALUSrcB " << ALUSrcB << "\n"
            << "ALUOp " << ALUOp << "\n"
            << "PCSrc " << PCSrc << "\n"
            << "RegDst " << RegDst << "\n"
            << "MemtoReg " << MemtoReg << "\n"
            << "IRWrite " << IRWrite << "\n"
            << "PCWrite " << PCWrite << "\n"
            << "RegWrite " << RegWrite << "\n"
            << "MemWrite " << MemWrite << "\n"
            << "BranchEQ " << BranchEQ << "\n"
            << "BranchNE " << BranchNE << std::endl;
}