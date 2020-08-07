#ifndef ALUDECODER
#define ALUDECODER

#include "Instruction.hpp"
#include "values.hpp"

class ALUDecoder {
 private:
  int something;

 public:
  ALUDecoder();
  ALU::ALUInput decode(Instruction ins);
};

#endif /* ALUDECODER */
