#ifndef UTILS
#define UTILS

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Instruction.hpp"
#include "values.hpp"

std::vector<Instruction> getInstructions(std::string file);

#endif /* UTILS */
