#include <tuple>

#include "../ADDAC_1/GoldenModel/addac_1_gm.hpp"

class ADDAC4 {
 private:
  int cout, acc, S0, S1, S2, S3, S;
  ADDAC addac_0, addac_1, addac_2, addac_3;

  /**
   * setBitAt sets a bit value from a specific position.
   *
   * @param position Bit position [0 until WordSize-1]
   * @return Initial value with a masked bit at selected position.
   */
  int setBitAt(int value, int position);

  /**
   * getBitAt returns a bit value from a specific position.
   *
   * @param position Bit position [0 until WordSize-1]
   * @return Bit value [0|1]
   */
  bool getBitAt(int value, int position);

  /**
   * Groups all 1 bit values into a single integer
   *
   * @return Word value
   */
  int solution();

 public:
  ADDAC4();

  /**
   * Main solution for ADDAC4 using paralel COUT in more than 1 bit structure.
   *
   * @param a Input A pin
   * @param sel0 Selector 0 pin
   * @param sel1 Selector 1 pin
   * @param clk Clock pin
   * @param reset Reset pin
   * @param cin Cin pin for sum module
   * @return result S and Carry Out values
   */
  std::tuple<int, int> solve(int a, int sel0, int sel1, int clk, int reset,
                             int cin);
};