#include "Operation.hpp"

Operation::Operation(int opcode, int funct3, int funct67)
    : OPCODE(opcode), FUNCT3(funct3), FUNCT67(funct67) {}

bool Operation::operator==(const Operation& op) {
  return (OPCODE == op.OPCODE) && (FUNCT3 == op.FUNCT3) &&
         (FUNCT67 == op.FUNCT67);
}