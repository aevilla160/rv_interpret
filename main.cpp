// CSE 140 - Homework 3 
//C++ code that decodes an inputted machine code instruction 
//and prints out the decoded RISC-V instruction.
#include <iostream>
#include <string>
#include <vector>
//Authored Alex Villa, Albert Ma

std::string decode(long input) {
    std::string output = "";
    long opcode = input & 0x7F;
    long rd = (input >> 7) & 0x1F;
    long funct3 = (input >> 12) & 0x7;
    long rs1 = (input >> 15) & 0x1F;
    long rs2 = (input >> 20) & 0x1F;
    long funct7 = (input >> 25) & 0x7F;
    long imm = (input >> 20) & 0xFFF;

    //UJ type
    if(opcode == 0x6F){
        long imm1 = (input >> 20) & 0x7FE;
        long imm2 = (input >> 9) & 0x1;
        long imm3 = (input >> 10) & 0x3FF;
        long imm4 = (input >> 19) & 0x1;
        long imm = (imm1 | imm2 | imm3 | imm4) << 1;
        std::cout << "jal x" << rd << ", " << imm << std::endl;
    }
    //SB type
    else if(opcode == 0x63){
        long imm1 = (input >> 8) & 0xF;
        long imm2 = (input >> 25) & 0x3F;
        long imm3 = (input >> 7) & 0x1;
        long imm4 = (input >> 31) & 0x1;
        long imm = (imm1 | imm2 | imm3 | imm4) << 1;
        std::cout << "beq x" << rs1 << ", x" << rs2 << ", " << imm << std::endl;
    }

    //S type
    else if(opcode == 0x23){
        long imm1 = (input >> 7) & 0x1F;
        long imm2 = (input >> 25) & 0x7F;
        long imm = (imm1 | imm2) << 5;
        std::cout << "sw x" << rs2 << ", " << imm << "(x" << rs1 << ")" << std::endl;
    }
    return output;
}

int main() {
    long input; 
    std::cin >> input;
    decode(input);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}