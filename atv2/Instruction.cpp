#include "Instruction.hpp"

Instruction::Instruction(std::string name, int f7, int f3, Instrucao inst)
    : funct7(f7), funct3(f3), opcode(inst), name(name) {}