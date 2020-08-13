#ifndef ALUDECODER
#define ALUDECODER

#include <bitset>
#include <iostream>

#include "Instruction.hpp"
#include "values.hpp"

class ALUDecoder {
 public:
  ALUDecoder();
  ALU::ALUInput decode(ALU::ALUOp op, Instruction ins);
};

#endif /* ALUDECODER */
