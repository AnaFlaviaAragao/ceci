#include <fstream>

#include "mux_2x1_1_gm.hpp"

int main() {
  std::fstream vectorFile("../simulation/modelsim/mux_2x1_1_1.tv",
                          std::fstream::out);
  vectorFile << "//selector_a_b_S" << std::endl;

  int a0, a1, selector;

  // a0=0, a1=1, selector=0
  a0 = 0;
  a1 = 1;
  selector = 0;
  int S = mux(a0, a1, selector);
  vectorFile << selector << "_" << a0 << "_" << a1 << "_" << S << std::endl;

  // a0=1, a1=0, selector=0
  a0 = 1;
  a1 = 0;
  selector = 0;
  S = mux(a0, a1, selector);
  vectorFile << selector << "_" << a0 << "_" << a1 << "_" << S << std::endl;

  // a0=0, a1=1, selector=1
  a0 = 0;
  a1 = 1;
  selector = 1;
  S = mux(a0, a1, selector);
  vectorFile << selector << "_" << a0 << "_" << a1 << "_" << S << std::endl;

  // a0=1, a1=0, selector=1
  a0 = 1;
  a1 = 0;
  selector = 1;
  S = mux(a0, a1, selector);
  vectorFile << selector << "_" << a0 << "_" << a1 << "_" << S << std::endl;

  vectorFile.close();
}