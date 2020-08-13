#include <iostream>
#include <string>
#include <vector>

#include "MainController.hpp"
#include "utils.hpp"
#include "values.hpp"

using namespace std;

int main() {
  MainController controller;

  auto instrucoes = getInstructions("instructions.txt");
  std::cout << instrucoes.size() << " INSTRUCTIONS FOUND.\n" << std::endl;

  int reset = 0;

  for (auto instrucao : instrucoes) {
    // cout << InstructionsNames[instrucao.opcode] << endl;
    cout << instrucao.name << endl;
    controller.run(instrucao, reset);
  }
}
