#ifndef VALUES_H
#define VALUES_H

#include <string>
// Instrucao enumeares some possible instructions in multiple formats.
enum Instrucao {
  // R-TYPE
  ADD,
  SUB,
  AND,
  OR,
  XOR,

  // L-TYPE
  LW,

  // I-TYPE
  ADDI,
  XORI,
  ORI,

  // S-TYPE
  SW,

  // SB-TYPE
  BEQ,
  BNE,

  // UJ-TYPE
  JAL
};

enum Format { Rtype, Itype, Stype, SBtype, Utype, UJtype };

// InstructionsNames for printing
const std::string InstructionsNames[] = {"ADD", "SUB",  "AND",  "OR",  "XOR",
                                         "LW",  "ADDI", "XORI", "ORI", "SW",
                                         "BEQ", "BNE",  "JAL"};

// Estado defines each possible state for MainController
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

namespace ALU {

enum ALUInput { AND = 0b0000, OR = 0b0001, ADD = 0b0010, SUB = 0b0110 };

enum ALUOp { LS = 0b00, BEQ = 0b01, R = 0b10 };

};  // namespace ALU

#endif  // VALUES_H