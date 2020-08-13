#ifndef UTILS
#define UTILS

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Instruction.hpp"
#include "values.hpp"

/**
 * getInstructions read RISC-V instructions from file
 *
 * @param file file name
 *
 * @return a vector containing {Instruction} objects
 */
std::vector<Instruction> getInstructions(std::string file);

#endif /* UTILS */
