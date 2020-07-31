#ifndef VALUES_H
#define VALUES_H

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

#endif  // VALUES_H