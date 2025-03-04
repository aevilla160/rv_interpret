/*
1. Write a C program that decodes an input machine code. Your program should be
able to decode the R, I, S, SB, and UJ type instructions listed below. We will
only test the following instructions. You can find these instructions from the
RISC-V Reference Data sheet (download from CatCourse). add addi and andi beq bge
blt bne
jal jalr
lb lh
lw
or ori
sb sh
sll slli
slt slti
sltiu sltu
sra srai
srl srli
sub sw
xor xori
When the program is started, your program will print “Enter an instruction:” and
receive one 32-bit machine code from user. Then, the program will decode the
machine code and print the information (type and values of individual fields of
the instruction format) of the instruction. The following is the example
execution of the program. Your program must produce the following sample results
in the exact same format.

string R_Type[2] = {"0110011", "0111011"};
string I_Type[6] = {"0000011", "0001111", "0010011",
                    "0011011", "1100111", "1110011"};
string S_Type[1] = {"0100011"};
string SB_Type[1] = {"1100011"};
string U_Type[2] = {"0010111", "0110111"};
string UJ_Type[1] = {"1101111"};


Enter an instruction:
00000000001100100000001010110011

Enter an instruction:
00000000101001100111011010010011

000000001010 0110011101101 0010011

Enter an instruction:
11111110001100100000100000100011

1111111 00011 00100 000 10000 0100011

1111111                 10000
7                        5
111111110000
step 1 flip
000000001111
step 2 add 1 to binary number
000000010000
this number is 16 since you did two complements you add a - in front


Enter an instruction:
00000001111000101001001101100011



Enter an instruction:
00000000101000000000000011101111
00000000101000000000 00001 1101111
  */
#include <iostream>
#include <string>
using namespace std;

string OpcodeType(string opcodeStr) {
  const string R_Type[2] = {"0110011", "0111011"};
  const string I_Type[6] = {"0000011", "0001111", "0010011",
                            "0011011", "1100111", "1110011"};
  const string S_Type[1] = {"0100011"};
  const string SB_Type[1] = {"1100011"};
  const string U_Type[2] = {"0010111", "0110111"};
  const string UJ_Type[1] = {"1101111"};

  for (int i = 0; i < 2; i++) {
    if (opcodeStr == R_Type[i]) {
      // cout << "Opcode is R-Type" << endl;
      return "R-Type";
    }
  }
  for (int i = 0; i < 6; i++) {
    if (opcodeStr == I_Type[i]) {
      // cout << "Opcode is I-Type" << endl;
      return "I-Type";
    }
  }
  for (int i = 0; i < 1; i++) {
    if (opcodeStr == S_Type[i]) {
      // cout << "Opcode is S-Type" << endl;
      return "S-Type";
    }
  }
  for (int i = 0; i < 1; i++) {
    if (opcodeStr == SB_Type[i]) {
      // cout << "Opcode is SB-Type" << endl;
      return "SB-Type";
    }
  }
  for (int i = 0; i < 2; i++) {
    if (opcodeStr == U_Type[i]) {
      // cout << "Opcode is U-Type" << endl;
      return "U-Type";
    }
  }
  for (int i = 0; i < 1; i++) {
    if (opcodeStr == UJ_Type[i]) {
      // cout << "Opcode is UJ-Type" << endl;
      return "UJ-Type";
    }
  }

  return 0; // Return 0 if no type matches
}
int Rd(string rd, string type) {

  int num = stoi(rd);
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
int Imm(string opcodeStr, string type, string funct3, string imm) {
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
void PrintOutInstructions(string OpcodeStr, string type, string rd,
                          string function3, string rs1, string rs2,
                          string funct7, string imm, string operation) {
  cout << "===================================================================="
          "===================================================================="
          "====="
       << endl;
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

/*
  // Example BitString
  // 00000000001100100000001010110011
  //  funct7       rs2                rs1            funct3      rd opcode
  // (7 bits)     (5 bits)          (5 bits)        (3 bits)   (5 bits)   (7
  bits)
  // 31     25     24   20           19    15        14 12      11   7     6 0
  //  0000000       00011              00100          000       00101 0110011
  //                                                                7 1
  //  1234567        89101112        1314151617       181920    2122232425
  26272829303132
  // 31 - 6 = 25           <-7
  //            str(, )
*/

int main() {

  // Declare Variables
  string BitString;

  string OpcodeStr;
  string type;

  string operation;

  string rs1;

  string rs2;

  string rd;

  string imm;

  string function3;

  // only R-type has function 7
  string funct7;

  // Ask for user input
  cout << "Enter the BitString: ";

  // Get user input
  cin >> BitString;
  cout << endl;

  // Get Opcode from bit string
  OpcodeStr = BitString.substr(25, 7);
  // cout << "The Opcode String: " << OpcodeStr << endl << endl;

  // display opcode type
  type = OpcodeType(OpcodeStr);

  if (type == "S-Type") {
    // cout << "Instruction Type: S" << endl << endl;
  }

  // get rd from bit string
  rd = BitString.substr(20, 5);
  // cout << "Rd: x" << Rd(rd, type) << endl << endl;

  // get funct3 from bit string
  function3 = BitString.substr(17, 3);
  // cout << "Funct3 bit before function: " << function3 << endl;
  // cout << "Funct3 after function: " << Funct3(function3, type)<< endl <<endl;

  // get rs1 from bit string
  rs1 = BitString.substr(12, 5);
  // cout << "Rs1 before function: " << rs1 << endl;
  // cout << "Rs1 after function: " << Rs1(rs1) << endl << endl;

  // get rs2 from bit string
  rs2 = BitString.substr(7, 5);
  // cout << "Rs2 before function: " << rs2 << endl;
  // cout << "Rs2 after function: " << Rs2(rs2) << endl << endl;

  // get funct7 from bit string
  funct7 = BitString.substr(0, 7);
  // cout << "Funct7 before function: " << funct7 << endl;
  // cout << "Funct7 after function: " << Funct7(funct7) << endl << endl;

  // get imm from bit string
  // imm = BitString.substr(0, 12);
  if (type == "I-Type") {
    imm = funct7 + rs2;
  } else if (type == "S-Type") {
    imm = funct7 + rd;
    // cout <<" for an S-Type instruction, the imm is the funct7 + rd:   " <<
    // imm << endl;
  } else if (type == "SB-Type") {

    imm = funct7.substr(0, 1) + rd.substr(4) + funct7.substr(1, 6) +
          rd.substr(0, 4) + '0';
    // cout << endl << endl << endl;
    // cout << funct7.substr(0,1) << rd.substr(4) << funct7.substr(1,6) <<
    // rd.substr(0,4) << '0' << endl;
    /*
        //  funct7                                    rd
        // imm[12|10:5]                            imm[4:1|11]
        //   0 000000           11110 00101   001     0011 0       1100011
        //
        // 0  0  000000 0011 0
        //12  11  10:5  4:1  fill
        //0000000000110 = 6
      */
  } else if (type == "UJ-Type") {
    string temp = funct7 + rs2 + rs1 + function3;
    imm = temp.substr(0, 1) + temp.substr(11, 8) + temp.substr(12, 1) +
          temp.substr(1, 10) + '0';
    /*
    cout << temp.substr(0, 1) << endl;  // 20
    cout << temp.substr(11, 8) << endl; // 12:19
    cout << temp.substr(12, 1) << endl; // 11
    cout << temp.substr(1, 10) << endl; // 10:1
    cout<< '0' << endl;                // fill

      00000000101000000000

      0  0000000101 0 00000000
      20   10:1      11  12:19

    after changing order
      0   00000000 0 0000000101 0
      20    12:19  11  10:1     fill
      */
  }
  //  cout << "The imm is before function: "<< imm << endl;
  // cout << "the Imm after the function: " << Imm(OpcodeStr, type, function3,
  // imm) << endl << endl;

  operation = Operation(OpcodeStr, type, function3, funct7);
  //  cout << "Operation: " << Operation(OpcodeStr, type, function3) <<
  //  endl<<endl;

  PrintOutInstructions(OpcodeStr, type, rd, function3, rs1, rs2, funct7, imm,
                       operation);

  return 0;
}
