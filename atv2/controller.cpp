#include <iostream>
#include <string>

#include "MainController.hpp"
#include "Operation.hpp"
#include "values.hpp"

using namespace std;

int main() {
  MainController controller;
  Estado state;

  int reset, clk, opcode = 0;

  reset = 1;
  clk = 0;
  state = controller.defineNextState(reset, clk, opcode);
  cout << "CLOCK: " << clk << " ESTADO: S" << state << endl;

  clk = ~clk & 0x1;
  state = controller.defineNextState(reset, clk, opcode);
  cout << "CLOCK: " << clk << " ESTADO: S" << state << endl;

  // É interessante forçar o estado a ir para 'S0' independente
  // de seu valor, quando reset passar 0 -> 1.

  reset = 0;

  clk = ~clk & 0x1;  // clk = 0;
  state = controller.defineNextState(reset, clk, opcode);
  cout << "CLOCK: " << clk << " ESTADO: S" << state << endl;

  clk = ~clk & 0x1;
  state = controller.defineNextState(reset, clk, opcode);
  cout << "CLOCK: " << clk << " ESTADO: S" << state << endl;
}
