#ifndef INSTRUCTION
#define INSTRUCTION

#include <string>

#include "values.hpp"

struct Instruction {
  int funct7, funct3;

  Instrucao opcode;
  std::string name;

  Instruction(std::string name, int f7, int f3, Instrucao inst);
};
#endif /* INSTRUCTION */
