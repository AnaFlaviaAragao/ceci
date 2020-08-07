#include "ALUDecoder.hpp"

ALU::ALUInput ALUDecoder::decode(Instruction ins) {
  ALU::ALUInput input;

  switch (ins.AOp) {
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

  return input;
}