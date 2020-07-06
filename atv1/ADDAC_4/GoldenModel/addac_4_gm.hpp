#include "../ADDAC_1/GoldenModel/addac_1_gm.hpp"
#include <tuple>

class ADDAC4
{
private:
    int cout, acc, S0, S1, S2, S3, cout0, cout1, cout2, S;
    ADDAC addac_0, addac_1, addac_2, addac_3;

    int setBitAt(int value, int position);
    bool getBitAt(int value, int position);
    int solution();

public:
    int getBitAt(int position);

    ADDAC4();
    std::tuple<int, int, int, int, int> solve(int a, int sel0, int sel1, int clk, int reset, int cin);
};