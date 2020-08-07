#ifndef INSTRUCTION
#define INSTRUCTION

#include "values.hpp"

struct Instruction {
  ALU::ALUOp AOp;
  int funct7, funct3;

  Instruction(ALU::ALUOp op, int f7, int f3);
};
#endif /* INSTRUCTION */
