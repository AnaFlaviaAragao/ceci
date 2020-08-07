#include "utils.hpp"

using namespace std;

vector<Instrucao> getInstructions(string file) {
  fstream instructionsFile(file, fstream::in);
  vector<Instrucao> instructions;
  string instruction;

  int arraySize = sizeof(InstructionsNames) / sizeof(InstructionsNames[0]);

  while (instructionsFile >> instruction) {
    auto itr =
        find(InstructionsNames, InstructionsNames + arraySize, instruction);

    if (itr != end(InstructionsNames))
      instructions.push_back((Instrucao)distance(InstructionsNames, itr));
  }

  return instructions;
}