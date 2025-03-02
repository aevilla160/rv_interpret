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

int Funct3(string funct3) {
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
  return 0;
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

string Operation(string opcodeStr, string type, string funct3) {
  if (type == "R-Type" && opcodeStr == "0110011" && funct3 == "000") {
    return "add";
  }
  return "";
}

void PrintOutInstructions(string OpcodeStr, string rd, string funct3,
                          string rs1, string rs2, string funct7,
                          string operation, string type) {
  cout << "Instruction Type: " << type << endl;
  cout << "Operation: " << operation << endl;
  cout << "Rd: " << Rd(rd, type) << endl;
  cout << "Rs1: " << Rs1(rs1) << endl;
  cout << "Rs2: " << Rs2(rs2) << endl;
  cout << "Funct3: " << Funct3(funct3) << endl;
  cout << "Funct7: " << Funct7(funct7) << endl;
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
  string rd;
  string function3;
  string rs1;
  string rs2;
  string funct7;

  // Ask for user input
  cout << "Enter the BitString: ";

  // Get user input
  cin >> BitString;

  OpcodeStr = BitString.substr(25, 7);

  cout << endl << endl << endl;

  string type = OpcodeType(OpcodeStr);
  /*
    if (type == "R-Type") {
      cout << "Instruction Type: R" << endl;
    }

    cout << endl << endl;
  */
  rd = BitString.substr(20, 5);

  // int rdValue = Rd(rd, type);
  //  cout << "Rd: x" << rdValue << endl;
  cout << endl << endl;

  function3 = BitString.substr(17, 3);
  // cout << "Funct3 before function: " << function3 << endl;

  // int funct3Value = Funct3(function3);
  // cout << "Funct3: " << funct3Value << endl;

  rs1 = BitString.substr(12, 5);
  // cout << "Rs1 before function: " << rs1 << endl;
  // int rs1Value = Rs1(rs1);
  // cout << "Rs1: x" << rs1Value << endl;

  rs2 = BitString.substr(7, 5);
  // cout << "Rs2 before function: " << rs2 << endl;
  // int rs2Value = Rs2(rs2);
  // cout << "Rs2: x" << rs2Value << endl;

  funct7 = BitString.substr(0, 7);
  // cout << "Funct7: " << funct7 << endl;
  // int funct7Value = Funct7(funct7);
  // cout << "Funct7: " << funct7Value << endl;
  // cout << endl << endl;

  string operation = Operation(OpcodeStr, type, function3);
  // cout << "Operation: " << operation << endl;

  PrintOutInstructions(OpcodeStr, rd, function3, rs1, rs2, funct7, operation,
                       type);

  return 0;
}
