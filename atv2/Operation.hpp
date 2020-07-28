#ifndef OPERATIONS_H
#define OPERATIONS_H

struct Operation {
  int OPCODE;
  int FUNCT3;
  int FUNCT67;

  Operation(int opcode, int funct3, int funct67);
  bool operator==(const Operation& op);
};

#endif  // OPERATIONS_H