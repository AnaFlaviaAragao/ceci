#include "utils.hpp"

using namespace std;

vector<Instruction> getInstructions(string file) {
  fstream instructionsFile(file, fstream::in);
  vector<Instruction> instructions;
  string name, opcode, funct3, funct7;

  int arraySize = sizeof(InstructionsNames) / sizeof(InstructionsNames[0]);

  while (instructionsFile >> name >> opcode >> funct3 >> funct7) {
    auto itr = find(InstructionsNames, InstructionsNames + arraySize, name);

    if (itr != end(InstructionsNames))
      (Instrucao) distance(InstructionsNames, itr);

    instructions.push_back(
        Instruction(name, std::stoi(funct7), std::stoi(funct3),
                    (Instrucao)distance(InstructionsNames, itr)));
  }

  return instructions;
}