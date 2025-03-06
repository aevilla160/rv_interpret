//Homework 3 - CSE 140
//Authors: Albert Ma, Alex Villa
//Date: 3-04-2025
#include <iostream>
#include <string>
using namespace std;


//Funtion to determine RISC-V Opcode Type.
//Function designed and implemented by Albert and Alex
//Albert took lead of handling R and I type
//Alex handled SB, S, U, and UJ type
string OpcodeType(string opcodeStr) {
  const string R_Type[2] = {"0110011", "0111011"};
  const string I_Type[6] = {"0000011", "0001111", "0010011",
                            "0011011", "1100111", "1110011"};
  const string S_Type[1] = {"0100011"};
  const string SB_Type[1] = {"1100011"};
  const string U_Type[2] = {"0010111", "0110111"};
  const string UJ_Type[1] = {"1101111"};

  // cout << "<Opcode is <Type>" << endl;
  for (int i = 0; i < 2; i++) {
    if (opcodeStr == R_Type[i]) {
      return "R-Type";
    }
  }
  for (int i = 0; i < 6; i++) {
    if (opcodeStr == I_Type[i]) {
      return "I-Type";
    }
  }
  for (int i = 0; i < 1; i++) {
    if (opcodeStr == S_Type[i]) {
      return "S-Type";
    }
  }
  for (int i = 0; i < 1; i++) {
    if (opcodeStr == SB_Type[i]) {
      return "SB-Type";
    }
  }
  for (int i = 0; i < 2; i++) {
    if (opcodeStr == U_Type[i]) {
      return "U-Type";
    }
  }
  for (int i = 0; i < 1; i++) {
    if (opcodeStr == UJ_Type[i]) {
      return "UJ-Type";
    }
  }

  return 0; // Return 0 if no type matches
}
int Rd(string rd, string type) {

  int num = stoi(rd);
  int dec_value = 0;

  // Initializing base value to 1, i.e 2^0
  //May need to intialize to properly handle float values
  int base = 1;

  int temp = num;
  while (temp) {
    int last_digit = temp % 10;
    temp = temp / 10;

    dec_value += last_digit * base;

    base = base * 2;
  }

  return dec_value;
}

int Funct3(string funct3, string Type) {
  int num = stoi(funct3);

  return num;
}

int Rs1(string rs1) {
  int num = stoi(rs1);
  int dec_value = 0;
  int base = 1;

  int temp = num;
  while (temp) {
    int last_digit = temp % 10;
    temp = temp / 10;

    dec_value += last_digit * base;

    base = base * 2;
  }

  return dec_value;
}
int Rs2(string rs2) {
  int num = stoi(rs2);
  int dec_value = 0;
  int base = 1;

  int temp = num;
  while (temp) {
    int last_digit = temp % 10;
    temp = temp / 10;

    dec_value += last_digit * base;

    base = base * 2;
  }

  return dec_value;
  return 0;
}
int Funct7(string funct7) {
  int num = stoi(funct7);

  return num;
}
//Function operation designed by Alex and Albert. Albert took lead on overall function implementation
string Operation(string opcodeStr, string type, string funct3, string funct7) {
  if (type == "R-Type") {
    if (opcodeStr == "0110011") {

      if (funct3 == "000" && funct7 == "0000000") {
        return "add";
      } else if (funct3 == "000" && funct7 == "0100000") {
        return "sub";
      } else if (funct3 == "001" && funct7 == "0000000") {
        return "sll";
      } else if (funct3 == "010" && funct7 == "0000000") {
        return "slt";
      } else if (funct3 == "011" && funct7 == "0000000") {
        return "sltu";
      } else if (funct3 == "100" && funct7 == "0000000") {
        return "xor";
      } else if (funct3 == "101" && funct7 == "0000000") {
        return "srl";
      } else if (funct3 == "101" && funct7 == "0100000") {
        return "sra";
      } else if (funct3 == "110" && funct7 == "0000000") {
        return "or";
      } else if (funct3 == "111" && funct7 == "0000000") {
        return "and";
      }
    } else if (opcodeStr == "0111011") {
      if (funct3 == "000" && funct7 == "0000000") {
        return "addw";
      } else if (funct3 == "000" && funct7 == "0100000") {
        return "subw";
      } else if (funct3 == "001" && funct7 == "0000000") {
        return "sllw";
      } else if (funct3 == "010" && funct7 == "0000000") {
        return "slt";
      } else if (funct3 == "011" && funct7 == "0000000") {
        return "sltu";
      } else if (funct3 == "101" && funct7 == "0000000") {
        return "srlw";
      } else if (funct3 == "101" && funct7 == "0100000") {
        return "sraw";
      }
    }
    //Case designed and implemented by Albert
  } else if (type == "I-Type") {
    if (opcodeStr == "0000011") {
      if (funct3 == "000") {
        return "lb";
      } else if (funct3 == "001") {
        return "lh";
      } else if (funct3 == "010") {
        return "lw";
      } else if (funct3 == "011") {
        return "ld";
      } else if (funct3 == "100") {
        return "lbu";
      } else if (funct3 == "101") {
        return "lhu";
      } else if (funct3 == "110") {
        return "lwu";
      }
    } else if (opcodeStr == "0001111") {
      if (funct3 == "000") {
        return "fence";
      } else if (funct3 == "001") {
        return "fence.i";
      }
    } else if (opcodeStr == "0010011") {
      if (funct3 == "000") {
        return "addi";
      } else if (funct3 == "001" && funct7 == "0000000") {
        return "slli";
      } else if (funct3 == "010") {
        return "slti";
      } else if (funct3 == "100")
        return "xori";
      else if (funct3 == "101" && funct7 == "0000000") {
        return "srli";
      } else if (funct3 == "101" && funct7 == "0100000") {
        return "srai";
      } else if (funct3 == "110") {
        return "ori";
      } else if (funct3 == "111") {
        return "andi";
      }
    } else if (opcodeStr == "0011011") {
      if (funct3 == "000") {
        return "addiw";
      } else if (funct3 == "001" && funct7 == "0000000") {
        return "slliw";
      } else if (funct3 == "101" && funct7 == "0000000") {
        return "srliw";
      } else if (funct3 == "101" && funct7 == "0100000") {
        return "sraiw";
      }
    } else if (opcodeStr == "1100111") {
      if (funct3 == "000") {
        return "jalr";
      }

    } else if (opcodeStr == "1110011") {
      if (funct3 == "000" && funct7 == "000000000000") {
        return "ecall";
      } else if (funct3 == "000" && funct7 == "000000000001") {
        return "ebreak";
      } else if (funct3 == "001") {
        return "CSRRW";
      } else if (funct3 == "010") {
        return "CSRRS";
      } else if (funct3 == "011") {
        return "CSRRC";
      } else if (funct3 == "101") {
        return "CSRRWI";
      } else if (funct3 == "110") {
        return "CSRRSI";
      } else if (funct3 == "111") {
        return "CSRRCI";
      }
    }
    //Case designed and implemented by Alex
  } else if (type == "S-Type") {
    if (opcodeStr == "0100011") {
      if (funct3 == "000") {
        return "sb";
      } else if (funct3 == "001") {
        return "sh";
      } else if (funct3 == "010") {
        return "sw";
      } else if (funct3 == "011") {
        return "sd";
      }
    }
    //Case designed and implemented by Alex
  } else if (type == "SB-Type") {
    if (opcodeStr == "1100011") {
      if (funct3 == "000") {
        return "beq";
      } else if (funct3 == "001") {
        return "bne";
      } else if (funct3 == "100") {
        return "blt";
      } else if (funct3 == "101") {
        return "bge";
      } else if (funct3 == "110") {
        return "bltu";
      } else if (funct3 == "111") {
        return "bgeu";
      }
    }
    //Case designed and implemented by Alex
  } else if (type == "UJ-Type" && opcodeStr == "1101111") {
    return "jal";
  } else if (type == "U-Type") {
    if (opcodeStr == "0010111") {
      return "auipc";
    } else if (opcodeStr == "0110111") {
      return "lui";
    }
  }
  return "";
}
//Imm function designed and implemented by Albert and Alex
int Imm(string opcodeStr, string type, string funct3, string imm) {
  //Implemted if by Albert
  if (type == "I-Type" && opcodeStr == "0010011" && funct3 == "111") {

    int num = stoi(imm);
    int dec_value = 0;
    int base = 1;

    int temp = num;
    while (temp) {
      int last_digit = temp % 10;
      temp = temp / 10;

      dec_value += last_digit * base;

      base = base * 2;
    }
    // cout << endl << dec_value << endl;
    return dec_value;
  }
//Alex implemented
  if (type == "S-Type" && opcodeStr == "0100011" && funct3 == "000") {
    int n = imm.length();
    if (imm[0] == '1') {
      // Find the one's complement
      for (int i = 0; i < n; ++i) {
        imm[i] = (imm[i] == '0') ? '1' : '0';
      }

      // Add 1 to the one's complement
      int carry = 1;
      for (int i = n - 1; i >= 0; --i) {
        if (imm[i] == '1' && carry == 1) {
          imm[i] = '0';
        } else if (imm[i] == '0' && carry == 1) {
          imm[i] = '1';
          carry = 0;
        }
        if (carry == 0)
          break;
      }
      if (carry == 1) {
        imm = '1' + imm;
      }
    }

    int num = std::stoi(imm);
    int dec_value = 0;

    // Initializing base value to 1, i.e 2^0
    int base = 1;

    int temp = num;
    while (temp) {
      int last_digit = temp % 10;
      temp = temp / 10;

      dec_value += last_digit * base;

      base = base * 2;
    }

    return -dec_value;
  }
//Case designed and implemented by Alex
  if (type == "SB-Type" && opcodeStr == "1100011" && funct3 == "001") {

    int num = stoi(imm);
    int dec_value = 0;
    int base = 1;

    int temp = num;
    while (temp) {
      int last_digit = temp % 10;
      temp = temp / 10;

      dec_value += last_digit * base;

      base = base * 2;
    }
    // cout << endl << dec_value << endl;
    return dec_value;
  }
//Case designed and implemented by Alex inspired by Albert's work
  if (type == "UJ-Type" && opcodeStr == "1101111") {

    int num = stoi(imm);
    int dec_value = 0;
    int base = 1;

    int temp = num;
    while (temp) {
      int last_digit = temp % 10;
      temp = temp / 10;

      dec_value += last_digit * base;

      base = base * 2;
    }
    return dec_value;
  }

  return 0; // Provide a default return value if no condition is met
}
//Albert took lead on properly outputting the instructions
//Alex heled with test cases and feature proof
void PrintOutInstructions(string OpcodeStr, string type, string rd,
  string function3, string rs1, string rs2,
  string funct7, string imm, string operation) {
  cout << "The decoded instruction is: " << endl; //Steamline the output
  if (type == "R-Type") {
    cout << "Instruction Type: " << type << endl;
    cout << "Operation: " << operation << endl;
    cout << "Rs1: x" << Rs1(rs1) << endl;
    cout << "Rs2: x" << Rs2(rs2) << endl;
    cout << "Rd: x" << Rd(rd, type) << endl;
    cout << "Funct3: " << Funct3(function3, type) << endl;
    cout << "Funct7: " << Funct7(funct7) << endl;
  } else if (type == "I-Type") {
    cout << "Instruction Type: " << type << endl;
    cout << "Operation: " << operation << endl;
    cout << "Rs1: x" << Rs1(rs1) << endl;
    cout << "Rd: x" << Rd(rd, type) << endl;
    cout << "Immediate: " << Imm(OpcodeStr, type, function3, imm) << endl;
  } else if (type == "S-Type") {
    cout << "Instruction Type: " << type << endl;
    cout << "Operation: " << operation << endl;
    cout << "Rs1: x" << Rs1(rs1) << endl;
    cout << "Rs2: x" << Rs2(rs2) << endl;
    cout << "Immediate: " << Imm(OpcodeStr, type, function3, imm) << endl;
  } else if (type == "SB-Type") {
    cout << "Instruction Type: " << type << endl;
    cout << "Operation: " << operation << endl;
    cout << "Rs1: x" << Rs1(rs1) << endl;
    cout << "Rs2: x" << Rs2(rs2) << endl;
    cout << "Immediate: " << Imm(OpcodeStr, type, function3, imm) << endl;
  } else if (type == "UJ-Type") {
    cout << "Instruction Type: " << type << endl;
    cout << "Operation: " << operation << endl;
    cout << "Rd: x" << Rd(rd, type) << endl;
    cout << "Immediate: " << Imm(OpcodeStr, type, function3, imm) << endl;
  }
}
int main() {

  // Declaration of variables
  string BitString, OpcodeStr, type, operation, rs1, rs2, rd, imm, function3;
  // addition to accomdate R type having funct7
  string funct7;
  //input handled below
  cout << "Enter the BitString: ";
  cin >> BitString;
  cout << endl;
  OpcodeStr = BitString.substr(25, 7);
  type = OpcodeType(OpcodeStr);

  if (type == "S-Type") {
  }

  rd = BitString.substr(20, 5);
  function3 = BitString.substr(17, 3);
  rs1 = BitString.substr(12, 5);
  rs2 = BitString.substr(7, 5);
  funct7 = BitString.substr(0, 7);
  //Alex and Albert both took equal ownership of main function. 
  if (type == "I-Type") {
    imm = funct7 + rs2;
  } else if (type == "S-Type") {
    imm = funct7 + rd;
  } else if (type == "SB-Type") {

    imm = funct7.substr(0, 1) + rd.substr(4) + funct7.substr(1, 6) +
          rd.substr(0, 4) + '0';
  } else if (type == "UJ-Type") {
    string temp = funct7 + rs2 + rs1 + function3;
    imm = temp.substr(0, 1) + temp.substr(11, 8) + temp.substr(12, 1) +
          temp.substr(1, 10) + '0';
  }
  operation = Operation(OpcodeStr, type, function3, funct7);
  //  cout << "Operation: " << Operation(OpcodeStr, type, function3) <<
  //  endl<<endl;
  PrintOutInstructions(OpcodeStr, type, rd, function3, rs1, rs2, funct7, imm, operation);
  return 0;

}
