#include "addac_1_gm.hpp"

#include <iostream>
#include <tuple>
#include <fstream>

int main()
{

    std::fstream vectorFile("../simulation/modelsim/addac_1.tv", std::fstream::out);

    ADDAC addac(0);
    int clk, sel0, sel1, a, cin, reset, S, cout;

    reset = 0;

    vectorFile << "// clk_sel0_sel1_a_cin_S_cout_acc" << std::endl;

    // TESTANDO FUNÇÃO S = a (sel0=0, sel1=0)
    vectorFile << "// TESTANDO FUNÇÃO S = a (sel0=0, sel1=0) " << std::endl;
    //clk_sel0_sel1_a_cin_S_cout
    clk = 0;
    sel0 = 0, sel1 = 0, a = 0;
    std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
    vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << addac.getCin() << "_" << S << "_" << cout << "_" << addac.getAcc() << std::endl;

    clk = ~clk & 0x1; // clk = 1
    sel0 = 0, sel1 = 0, a = 0;
    std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
    vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << addac.getCin() << "_" << S << "_" << cout << "_" << addac.getAcc() << std::endl;

    clk = ~clk & 0x1; // clk = 0
    sel0 = 0, sel1 = 0, a = 1;
    std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
    vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << addac.getCin() << "_" << S << "_" << cout << "_" << addac.getAcc() << std::endl;

    clk = ~clk & 0x1; // clk = 1
    sel0 = 0, sel1 = 0, a = 1;
    std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
    vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << addac.getCin() << "_" << S << "_" << cout << "_" << addac.getAcc() << std::endl;

    vectorFile << "// TESTANDO FUNÇÃO S = ~a (sel0=1, sel1=0) " << std::endl;
    vectorFile << "// clk_sel0_sel1_a_cin_S_cout_acc" << std::endl;

    clk = ~clk & 0x1; // clk = 0
    sel0 = 1, sel1 = 0, a = 0;
    std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
    vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << addac.getCin() << "_" << S << "_" << cout << "_" << addac.getAcc() << std::endl;

    clk = ~clk & 0x1; // clk = 1
    sel0 = 1, sel1 = 0, a = 0;
    std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
    vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << addac.getCin() << "_" << S << "_" << cout << "_" << addac.getAcc() << std::endl;

    clk = ~clk & 0x1; // clk = 0
    sel0 = 1, sel1 = 0, a = 1;
    std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
    vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << addac.getCin() << "_" << S << "_" << cout << "_" << addac.getAcc() << std::endl;

    clk = ~clk & 0x1; // clk = 1
    sel0 = 1, sel1 = 0, a = 1;
    std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
    vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << addac.getCin() << "_" << S << "_" << cout << "_" << addac.getAcc() << std::endl;

    clk = 0;
    sel0 = 0, sel1 = 0, a = 0;
    std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
    // vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << addac.getCin() << "_" << S << "_" << cout << "_" << addac.getAcc() << std::endl;

    clk = ~clk & 0x1; // clk = 1
    sel0 = 0, sel1 = 0, a = 0;
    std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
    // vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << addac.getCin() << "_" << S << "_" << cout << "_" << addac.getAcc() << std::endl;

    vectorFile << "// TESTANDO FUNÇÃO S = ACC + a (sel0=0, sel1=1) " << std::endl;
    vectorFile << "// clk_sel0_sel1_a_cin_S_cout_acc" << std::endl;

    clk = ~clk & 0x1; // clk = 0
    sel0 = 0, sel1 = 1, a = 0;
    std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
    vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << addac.getCin() << "_" << S << "_" << cout << "_" << addac.getAcc() << std::endl;

    clk = ~clk & 0x1; // clk = 1
    sel0 = 0, sel1 = 1, a = 0;
    std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
    vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << addac.getCin() << "_" << S << "_" << cout << "_" << addac.getAcc() << std::endl;

    clk = ~clk & 0x1; // clk = 0
    sel0 = 0, sel1 = 1, a = 1;
    std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
    vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << addac.getCin() << "_" << S << "_" << cout << "_" << addac.getAcc() << std::endl;

    clk = ~clk & 0x1; // clk = 1
    sel0 = 0, sel1 = 1, a = 1;
    std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
    vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << addac.getCin() << "_" << S << "_" << cout << "_" << addac.getAcc() << std::endl;

    clk = 0;
    sel0 = 0, sel1 = 0, a = 0;
    std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
    // vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << addac.getCin() << "_" << S << "_" << cout << "_" << addac.getAcc() << std::endl;

    clk = ~clk & 0x1; // clk = 1
    sel0 = 0, sel1 = 0, a = 0;
    std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
    // vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << addac.getCin() << "_" << S << "_" << cout << "_" << addac.getAcc() << std::endl;

    vectorFile << "// TESTANDO FUNÇÃO S = ACC - a (sel0=1, sel1=1) " << std::endl;
    vectorFile << "// clk_sel0_sel1_a_cin_S_cout_acc" << std::endl;

    clk = ~clk & 0x1; // clk = 0
    sel0 = 1, sel1 = 1, a = 0;
    std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
    vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << addac.getCin() << "_" << S << "_" << cout << "_" << addac.getAcc() << std::endl;

    clk = ~clk & 0x1; // clk = 1
    sel0 = 1, sel1 = 1, a = 0;
    std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
    vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << addac.getCin() << "_" << S << "_" << cout << "_" << addac.getAcc() << std::endl;

    clk = ~clk & 0x1; // clk = 0
    sel0 = 1, sel1 = 1, a = 1;
    std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
    vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << addac.getCin() << "_" << S << "_" << cout << "_" << addac.getAcc() << std::endl;

    clk = ~clk & 0x1; // clk = 1
    sel0 = 1, sel1 = 1, a = 1;
    std::tie(S, cout) = addac.solve(a, sel0, sel1, clk, reset, cin);
    vectorFile << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << addac.getCin() << "_" << S << "_" << cout << "_" << addac.getAcc() << std::endl;
}