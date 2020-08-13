#ifndef INSTRUCTION
#define INSTRUCTION

#include <string>

#include "values.hpp"

/**
 * Instruction is a common RISC-V instruction.
 */
struct Instruction {
  int funct7, funct3;

  Instrucao opcode;
  std::string name;

  /**
   * Instruction enables instantiation of RISC-V instructions.
   *
   * @param name instruction name
   * @param f7 funct7 field on instruction word
   * @param f3 funct3 field on instruction word
   * @param Instrucao basic instruction enum type for consistency
   */
  Instruction(std::string name, int f7, int f3, Instrucao inst);
};
#endif /* INSTRUCTION */
