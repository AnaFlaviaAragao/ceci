#include "Instruction.hpp"

Instruction::Instruction(ALU::ALUOp op, int f7, int f3)
    : AOp(op), funct7(f7), funct3(f3) {}