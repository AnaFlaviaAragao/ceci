#ifndef VALUES_H
#define VALUES_H

/*
// R-TYPE
const int ADD = 0b011001100100000, SUB = 0b011001100, AND = 0b01100111110,
          OR = 0b01100111100, XOR = 0b01100111000;

// L-TYPE
const int LW = 0b00000110100;

// I-TYPE
const int ADDI = 0b0010011000, XORI = 0b0010011100, ORI = 0b0010011110;

// S-TYPE
const int SW = 0b01000110100;

// SB-TYPE
const int BEQ = 0b11001110000, BNE = 0b11001110010;
*/

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

const std::string InstructionsNames[] = {"ADD", "SUB",  "AND",  "OR",  "XOR",
                                         "LW",  "ADDI", "XORI", "ORI", "SW",
                                         "BEQ", "BNE",  "JAL"};

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