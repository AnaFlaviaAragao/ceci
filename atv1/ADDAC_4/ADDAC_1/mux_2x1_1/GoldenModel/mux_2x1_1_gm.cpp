#include "mux_2x1_1_gm.hpp"

int mux(int a, int b, int selector) { return selector ? b : a; }