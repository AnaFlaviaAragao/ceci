#include <iostream>
#include <string>

#include "MainController.hpp"
#include "values.hpp"

using namespace std;

int main() {
  MainController controller;
  Instrucao instrucao;

  int reset = 0;

  Instrucao instrucoes[] = {LW, SW};

  for (Instrucao instrucao : instrucoes) {
    cout << InstructionsNames[instrucao] << endl;
    controller.run(instrucao, reset);
  }
}
