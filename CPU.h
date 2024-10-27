#ifndef TASK_3___VOLE_MACHINE_CPU_H
#define TASK_3___VOLE_MACHINE_CPU_H

#include <iostream>
#include <bitset>

class Register;

class ALU {
public:
//    Hexadecimal
    int hexToDec(const std::string &hex, bool isTwosComplement, bool isFloatNotation);

    std::string decToHex(int dec, bool isTwosComplement, bool isFloatNotation);

//    Binary
    int binToDec(const std::string &bin, bool isTwosComplement, bool isFloatNotation);

    std::string decToBin(int dec, bool isTwosComplement, bool isFloatNotation);

//    Validation
    bool isValidInstruction(std::string instruction);

//    Arithmetic
    std::string binaryAdd(std::string bin_1, std::string bin_2, bool isTwosComplement);
};

class CU {

};

class CPU {

};

#endif //TASK_3___VOLE_MACHINE_CPU_H
