#include <bitset>
#include <fstream>
#include <iostream>

#include "addac_4_gm.hpp"

int main() {
  std::fstream vectorFile("../simulation/modelsim/addac4.tv",
                          std::fstream::out);

  const int res = 4;
  ADDACFull addac(res);

  int S, cout, a, sel0, sel1, clk, reset, cin;

  // TESTANDO FUNÇÃO S = a (sel0=0, sel1=0)
  // clk_sel0_sel1_a3a2a1a0_cin_s3s2s1s0_cout
  std::cout << "// TESTANDO FUNÇÃO S = a(sel0 = 0, sel1 = 0)" << std::endl;
  vectorFile << "// TESTANDO FUNÇÃO S = a(sel0 = 0, sel1 = 0)" << std::endl;
  std::cout << "// clk_sel0_sel1_a3a2a1a0_cin_s3s2s1s0_cout" << std::endl;
  vectorFile << "// clk_sel0_sel1_a3a2a1a0_cin_s3s2s1s0_cout" << std::endl;
  clk = 0;
  sel0 = 0, sel1 = 0, a = 0b0000;
  std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
  std::cout << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
            << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
            << std::endl;
  vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
             << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
             << std::endl;

  clk = ~clk & 0x1;  // clk = 1
  sel0 = 0, sel1 = 0, a = 0b0000;
  std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
  std::cout << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
            << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
            << std::endl;
  vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
             << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
             << std::endl;

  clk = ~clk & 0x1;  // clk = 0
  sel0 = 0, sel1 = 0, a = 0b1111;
  std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
  std::cout << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
            << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
            << std::endl;
  vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
             << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
             << std::endl;

  clk = ~clk & 0x1;  // clk = 1
  sel0 = 0, sel1 = 0, a = 0b1111;
  std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
  std::cout << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
            << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
            << std::endl;
  vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
             << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
             << std::endl;

  // TESTANDO FUNÇÃO S = a (sel0=1, sel1=0)
  // clk_sel0_sel1_a3a2a1a0_cin_s3s2s1s0_cout
  std::cout << "// TESTANDO FUNÇÃO S = ~a(sel0 = 1, sel1 = 0)" << std::endl;
  vectorFile << "// TESTANDO FUNÇÃO S = ~a(sel0 = 1, sel1 = 0)" << std::endl;
  std::cout << "// clk_sel0_sel1_a3a2a1a0_cin_s3s2s1s0_cout" << std::endl;
  vectorFile << "// clk_sel0_sel1_a3a2a1a0_cin_s3s2s1s0_cout" << std::endl;
  clk = 0;
  sel0 = 1, sel1 = 0, a = 0b0000;
  std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
  std::cout << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
            << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
            << std::endl;
  vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
             << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
             << std::endl;

  clk = ~clk & 0x1;  // clk = 1
  sel0 = 1, sel1 = 0, a = 0b0000;
  std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
  std::cout << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
            << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
            << std::endl;
  vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
             << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
             << std::endl;

  clk = ~clk & 0x1;  // clk = 0
  sel0 = 1, sel1 = 0, a = 0b1111;
  std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
  std::cout << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
            << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
            << std::endl;
  vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
             << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
             << std::endl;

  clk = ~clk & 0x1;  // clk = 1
  sel0 = 1, sel1 = 0, a = 0b1111;
  std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
  std::cout << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
            << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
            << std::endl;
  vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
             << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
             << std::endl;

  // TESTANDO FUNÇÃO S = ACC + a (sel0=0, sel1=1)
  // clk_sel0_sel1_a3a2a1a0_cin_s3s2s1s0_cout
  std::cout << "// TESTANDO FUNÇÃO S = ACC + a(sel0 = 0, sel1 = 1)"
            << std::endl;
  vectorFile << "// TESTANDO FUNÇÃO S = ACC + a(sel0 = 0, sel1 = 1)"
             << std::endl;
  std::cout << "// clk_sel0_sel1_a3a2a1a0_cin_s3s2s1s0_cout" << std::endl;
  clk = 0;
  sel0 = 0, sel1 = 1, a = 0b0000;
  std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
  std::cout << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
            << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
            << std::endl;
  vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
             << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
             << std::endl;

  clk = ~clk & 0x1;  // clk = 1
  sel0 = 0, sel1 = 1, a = 0b0000;
  std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
  std::cout << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
            << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
            << std::endl;
  vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
             << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
             << std::endl;

  clk = ~clk & 0x1;  // clk = 1
  sel0 = 0, sel1 = 1, a = 0b0001;
  std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
  std::cout << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
            << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
            << std::endl;
  vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
             << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
             << std::endl;

  clk = ~clk & 0x1;  // clk = 1
  sel0 = 0, sel1 = 1, a = 0b0001;
  std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
  std::cout << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
            << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
            << std::endl;
  vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
             << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
             << std::endl;

  vectorFile << "// ZERANDO" << std::endl;
  std::cout << "// ZERANDO" << std::endl;

  clk = 0;
  sel0 = 0, sel1 = 0, a = 0b0000;
  std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
  std::cout << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
            << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
            << std::endl;
  vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
             << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
             << std::endl;

  clk = ~clk & 0x1;  // clk = 1
  sel0 = 0, sel1 = 0, a = 0b0000;
  std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
  std::cout << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
            << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
            << std::endl;
  vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
             << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
             << std::endl;

  vectorFile << "// VARIACAO 1 A 1: S = ACC + a(sel0 = 0, sel1 = 1)"
             << std::endl;
  std::cout << "// VARIACAO 1 A 1: S = ACC + a(sel0 = 0, sel1 = 1)"
            << std::endl;
  std::cout << "// clk_sel0_sel1_a3a2a1a0_cin_s3s2s1s0_cout" << std::endl;
  vectorFile << "// clk_sel0_sel1_a3a2a1a0_cin_s3s2s1s0_cout" << std::endl;
  clk = 0;  // clk = 0
  sel0 = 0, sel1 = 1;
  a = 0b0001;
  for (int i = 1; i < 18; i++) {
    std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
    std::cout << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
              << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
              << std::endl;
    vectorFile << clk << "_" << sel0 << "_" << sel1 << "_"
               << std::bitset<res>(a) << "_" << cin << "_"
               << std::bitset<res>(S) << "_" << cout << std::endl;
    clk = ~clk & 0x1;  // clk = 1

    std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);

    std::cout << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
              << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
              << std::endl;

    vectorFile << clk << "_" << sel0 << "_" << sel1 << "_"
               << std::bitset<res>(a) << "_" << cin << "_"
               << std::bitset<res>(S) << "_" << cout << std::endl;
    clk = ~clk & 0x1;  // clk = 0
  }

  // clk = ~clk & 0x1; // clk = 0
  // sel0 = 0, sel1 = 1, a = 0b1111;
  // std::ti S0, cout) = addac4.solve(a, sel0, sel1, clk, reset,
  // cin); std::cout << clk << "_" << sel0 << "_" << sel1 << "_" <<
  // std::bitset<res>(a) << "_" << cin << "_" <<
  // std::bitset<res>(S) << "_" << cout << std::endl; vectorFile << clk
  // << "_" << sel0 << "_" << sel1 << "_"
  // << std::bitset<res>(a) << "_" << cin << "_" <<
  // std::bitset<res>(S) << "_" << cout << std::endl;

  // clk = ~clk & 0x1; // clk = 1
  // sel0 = 0, sel1 = 1, a = 0b1111;
  // std::ti S0, cout) = addac4.solve(a, sel0, sel1, clk, reset,
  // cin); std::cout << clk << "_" << sel0 << "_" << sel1 << "_" <<
  // std::bitset<res>(a) << "_" << cin << "_" <<
  // std::bitset<res>(S) << "_" << cout << std::endl; vectorFile << clk
  // << "_" << sel0 << "_" << sel1 << "_"
  // << std::bitset<res>(a) << "_" << cin << "_" <<
  // std::bitset<res>(S) << "_" << cout << std::endl;

  // TESTANDO FUNÇÃO S = a (sel0=1, sel1=1)
  // clk_sel0_sel1_a3a2a1a0_cin_s3s2s1s0_cout
  std::cout << "// TESTANDO FUNÇÃO S = ACC - a(sel0 = 1, sel1 = 1)"
            << std::endl;
  vectorFile << "// TESTANDO FUNÇÃO S = ACC - a(sel0 = 1, sel1 = 1)"
             << std::endl;
  std::cout << "// clk_sel0_sel1_a3a2a1a0_cin_s3s2s1s0_cout" << std::endl;
  vectorFile << "// clk_sel0_sel1_a3a2a1a0_cin_s3s2s1s0_cout" << std::endl;
  clk = 0;
  sel0 = 1, sel1 = 1, a = 0b0000;
  std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
  std::cout << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
            << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
            << std::endl;
  vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
             << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
             << std::endl;

  clk = ~clk & 0x1;  // clk = 1
  sel0 = 1, sel1 = 1, a = 0b0000;
  std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
  std::cout << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
            << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
            << std::endl;
  vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
             << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
             << std::endl;

  vectorFile << "// ZERANDO" << std::endl;
  std::cout << "// ZERANDO" << std::endl;

  clk = 0;
  sel0 = 0, sel1 = 0, a = 0b0000;
  std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
  std::cout << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
            << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
            << std::endl;
  vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
             << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
             << std::endl;

  clk = ~clk & 0x1;  // clk = 1
  sel0 = 0, sel1 = 0, a = 0b0000;
  std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
  std::cout << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
            << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
            << std::endl;
  vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
             << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
             << std::endl;

  vectorFile << "// VARIACAO 1 A 1: S = ACC - a(sel0 = 1, sel1 = 1)"
             << std::endl;
  std::cout << "// VARIACAO 1 A 1: S = ACC - a(sel0 = 1, sel1 = 1)"
            << std::endl;
  std::cout << "// clk_sel0_sel1_a3a2a1a0_cin_s3s2s1s0_cout" << std::endl;
  vectorFile << "// clk_sel0_sel1_a3a2a1a0_cin_s3s2s1s0_cout" << std::endl;
  clk = 0;  // clk = 0
  sel0 = 1, sel1 = 1;
  a = 0b0001;
  for (int i = 1; i < 18; i++) {
    std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
    std::cout << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
              << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
              << std::endl;
    vectorFile << clk << "_" << sel0 << "_" << sel1 << "_"
               << std::bitset<res>(a) << "_" << cin << "_"
               << std::bitset<res>(S) << "_" << cout << std::endl;
    clk = ~clk & 0x1;  // clk = 1

    std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
    std::cout << clk << "_" << sel0 << "_" << sel1 << "_" << std::bitset<res>(a)
              << "_" << cin << "_" << std::bitset<res>(S) << "_" << cout
              << std::endl;
    vectorFile << clk << "_" << sel0 << "_" << sel1 << "_"
               << std::bitset<res>(a) << "_" << cin << "_"
               << std::bitset<res>(S) << "_" << cout << std::endl;
    clk = ~clk & 0x1;  // clk = 0
  }

  // clk = ~clk & 0x1; // clk = 0
  // sel0 = 1, sel1 = 1, a = 0b1111;
  // std::ti S0, cout) = addac4.solve(a, sel0, sel1, clk, reset,
  // cin); std::cout << clk << "_" << sel0 << "_" << sel1 << "_" <<
  // std::bitset<res>(a) << "_" << cin << "_" <<
  // std::bitset<res>(S) << "_" << cout << std::endl; vectorFile << clk
  // << "_" << sel0 << "_" << sel1 << "_"
  // << std::bitset<res>(a) << "_" << cin << "_" <<
  // std::bitset<res>(S) << "_" << cout << std::endl;

  // clk = ~clk & 0x1; // clk = 1
  // sel0 = 1, sel1 = 1, a = 0b1111;
  // std::ti S0, cout) = addac4.solve(a, sel0, sel1, clk, reset,
  // cin); std::cout << clk << "_" << sel0 << "_" << sel1 << "_" <<
  // std::bitset<res>(a) << "_" << cin << "_" <<
  // std::bitset<res>(S) << "_" << cout << std::endl; vectorFile << clk
  // << "_" << sel0 << "_" << sel1 << "_"
  // << std::bitset<res>(a) << "_" << cin << "_" <<
  // std::bitset<res>(S) << "_" << cout << std::endl;
}