#ifndef VALUES_H
#define VALUES_H

#include "Operation.hpp"

inline Operation ADD(0b0110011, 0, 0b0100000), SUB(0b0110011, 0, 0),
    AND(0b0110011, 0b111, 0), OR(0b0110011, 0b110, 0), XOR(0b0110011, 0b100, 0);

enum Estado {
  S0,   // Fetch
  S1,   // Decode
  S2,   // MemAdr
  S3,   // MemRead
  S4,   // Mem Writeback
  S5,   // MemWrite
  S6,   // R-type Execute
  S7,   // ALU Writeback
  S8,   // Branch EQ
  S9,   // I-Type Execute = S7
  S10,  // I-Type Writeback
  S11,  // Jump
  S12   // Branch NE
};

#endif  // VALUES_H