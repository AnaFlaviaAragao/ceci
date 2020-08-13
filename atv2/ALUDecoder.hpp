#ifndef ALUDECODER
#define ALUDECODER

#include <bitset>
#include <iostream>

#include "Instruction.hpp"
#include "values.hpp"

/**
 * ALUDecoder is a basic unit for decoding instructions for the
 * RISC-V ULA unit.
 */
class ALUDecoder {
 public:
  ALUDecoder();

  /**
   * decode uses data from state machine for defining the
   * ULA control input.
   *
   * @param op OPCode for ula decoder
   * @param ins RISC-V basic instruction
   *
   * @return ULA input type {AND, OR, ADD, SUBTRACT}
   */
  ALU::ALUInput decode(ALU::ALUOp op, Instruction ins);
};

#endif /* ALUDECODER */
