#include "../inv_1/GoldenModel/inv_1_gm.hpp"
#include "../flop_1/GoldenModel/flop_1_gm.hpp"
#include "../mux_2x1_1/GoldenModel/mux_2x1_1_gm.hpp"
#include "../soma_1/GoldenModel/soma_1_gm.hpp"

#include <iostream>

// MAIN INPUTS
int S = 0, cout = 0, reset = 0, acc = 0, cinGlobal = 0;

void addac(int a, int sel0, int sel1, int clk, int cin, int ordem)
{
    int inv = 0, mux1 = 0, mux2 = 0, soma1 = 0;

    inv = inversor(a);
    mux1 = mux(a, inv, sel0);

    if (ordem == 0)
    {
        cin = sel0;
        cinGlobal = cin;
    }

    soma1 = soma(mux1, acc, cin);
    cout = carry(mux1, acc, cin);
    mux2 = mux(mux1, soma1, sel1);

    acc = flop(mux2, reset, clk);
    soma1 = soma(mux1, acc, cin);
    cout = carry(mux1, acc, cin);
    mux2 = mux(mux1, soma1, sel1);

    S = mux2;
}

int main()
{

    int clk, sel0, sel1, a, ordem, cin;
    std::cout << "// clk_sel0_sel1_a_cin_S_cout_acc" << std::endl;

    ordem = 0;

    // TESTANDO FUNÇÃO S = a (sel0=0, sel1=0)
    std::cout << "// TESTANDO FUNÇÃO S = a (sel0=0, sel1=0) " << std::endl;
    //clk_sel0_sel1_a_cin_S_cout
    clk = 0;
    sel0 = 0, sel1 = 0, a = 0;
    addac(a, sel0, sel1, clk, cin, ordem);
    std::cout << 1 << " " << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << cinGlobal << "_" << S << "_" << cout << "_" << acc << std::endl;

    clk = ~clk & 0x1; // clk = 1
    sel0 = 0, sel1 = 0, a = 0;
    addac(a, sel0, sel1, clk, cin, ordem);
    std::cout << 2 << " " << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << cinGlobal << "_" << S << "_" << cout << "_" << acc << std::endl;

    clk = ~clk & 0x1; // clk = 0
    sel0 = 0, sel1 = 0, a = 1;
    addac(a, sel0, sel1, clk, cin, ordem);
    std::cout << 3 << " " << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << cinGlobal << "_" << S << "_" << cout << "_" << acc << std::endl;

    clk = ~clk & 0x1; // clk = 1
    sel0 = 0, sel1 = 0, a = 1;
    addac(a, sel0, sel1, clk, cin, ordem);
    std::cout << 4 << " " << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << cinGlobal << "_" << S << "_" << cout << "_" << acc << std::endl;

    std::cout << "// TESTANDO FUNÇÃO S = ~a (sel0=1, sel1=0) " << std::endl;
    std::cout << "// clk_sel0_sel1_a_cin_S_cout_acc" << std::endl;

    clk = ~clk & 0x1; // clk = 0
    sel0 = 1, sel1 = 0, a = 0;
    addac(a, sel0, sel1, clk, cin, ordem);
    std::cout << 5 << " " << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << cinGlobal << "_" << S << "_" << cout << "_" << acc << std::endl;

    clk = ~clk & 0x1; // clk = 1
    sel0 = 1, sel1 = 0, a = 0;
    addac(a, sel0, sel1, clk, cin, ordem);
    std::cout << 6 << " " << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << cinGlobal << "_" << S << "_" << cout << "_" << acc << std::endl;

    clk = ~clk & 0x1; // clk = 0
    sel0 = 1, sel1 = 0, a = 1;
    addac(a, sel0, sel1, clk, cin, ordem);
    std::cout << 7 << " " << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << cinGlobal << "_" << S << "_" << cout << "_" << acc << std::endl;

    clk = ~clk & 0x1; // clk = 1
    sel0 = 1, sel1 = 0, a = 1;
    addac(a, sel0, sel1, clk, cin, ordem);
    std::cout << 8 << " " << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << cinGlobal << "_" << S << "_" << cout << "_" << acc << std::endl;

    std::cout << "// TESTANDO FUNÇÃO S = ACC + a (sel0=0, sel1=1) " << std::endl;
    std::cout << "// clk_sel0_sel1_a_cin_S_cout_acc" << std::endl;

    clk = ~clk & 0x1; // clk = 0
    sel0 = 0, sel1 = 1, a = 0;
    addac(a, sel0, sel1, clk, cin, ordem);
    std::cout << 9 << " " << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << cinGlobal << "_" << S << "_" << cout << "_" << acc << std::endl;

    clk = ~clk & 0x1; // clk = 1
    sel0 = 0, sel1 = 1, a = 0;
    addac(a, sel0, sel1, clk, cin, ordem);
    std::cout << 10 << " " << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << cinGlobal << "_" << S << "_" << cout << "_" << acc << std::endl;

    clk = ~clk & 0x1; // clk = 0
    sel0 = 0, sel1 = 1, a = 1;
    addac(a, sel0, sel1, clk, cin, ordem);
    std::cout << 11 << " " << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << cinGlobal << "_" << S << "_" << cout << "_" << acc << std::endl;

    clk = ~clk & 0x1; // clk = 1
    sel0 = 0, sel1 = 1, a = 1;
    addac(a, sel0, sel1, clk, cin, ordem);
    std::cout << 12 << " " << clk << "_" << sel0 << "_" << sel1 << "_" << a << "_" << cinGlobal << "_" << S << "_" << cout << "_" << acc << std::endl;
}