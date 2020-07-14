#include <fstream>
#include <iostream>

#include "soma_1_gm.hpp"

int main() {
  std::fstream vectorFile("../simulation/modelsim/soma_1.tv",
                          std::fstream::out);

  int cout = 0;
  int a = 0, b = 0, cin = 0;

  vectorFile << "//a_b_cin_S_cout" << std::endl;

  for (int a = 0; a < 2; a++)
    for (int b = 0; b < 2; b++)
      for (int cin = 0; cin < 2; cin++) {
        int S = soma(a, b, cin);
        int carryValue = carry(a, b, cin);
        vectorFile << a << "_" << b << "_" << cin << "_" << S << "_"
                   << carryValue << std::endl;
      }
}