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

  int reset = 0;

  for (auto instrucao : instrucoes) {
    cout << InstructionsNames[instrucao] << endl;
    controller.run(instrucao, reset);
  }
}
