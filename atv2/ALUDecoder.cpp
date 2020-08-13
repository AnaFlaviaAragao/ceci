#include "ALUDecoder.hpp"

ALUDecoder::ALUDecoder() {}

ALU::ALUInput ALUDecoder::decode(ALU::ALUOp op, Instruction ins) {
  ALU::ALUInput input;

  switch (op) {
    case ALU::LS:
      input = ALU::ADD;
      break;
    case ALU::BEQ:
      input = ALU::SUB;
      break;
    case ALU::R:
      switch (ins.funct3) {
        case 0b000:
          switch (ins.funct7) {
            case 0b0000000:
              input = ALU::ADD;
              break;
            case 0b0100000:
              input = ALU::SUB;
              break;
          }
          break;
        case 0b111:
          input = ALU::ADD;
          break;
        case 0b110:
          input = ALU::OR;
          break;
        default:
          break;
      }
  }
  std::cout << "ALU Control Input: " << std::bitset<4>(input) << "\n"
            << std::endl;
  return input;
}