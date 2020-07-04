#ifndef ADDAC_H
#define ADDAC_H

#include <utility>

class ADDAC
{
private:
    int cout, acc, S, cinLocal;

public:
    ADDAC();

    /**
    * Main solution for ADDAC using paralel COUT in more than 1 bit structure.
    * 
    * @param a Input A pin
    * @param sel0 Selector 0 pin
    * @param sel1 Selector 1 pin
    * @param clk Clock pin
    * @param reset Reset pin
    * @param cin Cin pin
    * @return result S and Carry Out values
    */
    std::tuple<int, int> solve(int a, int sel0, int sel1, int clk, int reset, int cin);

    /**
    * Inclusion of ordem parameter as only one instance of addac should use sel0 as cin input
    * 
    * @param a Input A pin
    * @param sel0 Selector 0 pin
    * @param sel1 Selector 1 pin
    * @param clk Clock pin
    * @param reset Reset pin
    * @param cin Cin pin
    * @param ordem Boolean value for using sel0 pin as Cin
    * @return result S and Carry Out values
    */
    std::tuple<int, int> solve(int a, int sel0, int sel1, int clk, int reset, int cin, int ordem);

    int getCin();
    int getAcc();
};

#endif // ADDAC_H