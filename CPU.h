#ifndef TASK_3___VOLE_MACHINE_CPU_H
#define TASK_3___VOLE_MACHINE_CPU_H

#include <iostream>
#include <bitset>
#include <cmath>

class ALU {
public:
//    Hexadecimal Conversion
    int hexToUnsignedDec(const std::string &hex);

    std::bitset<8> hexToBin(const std::string &hex);

    std::string binToHex(std::bitset<8> bin);


//    Binary Conversion
    float floatBinToDec(std::bitset<8> bin);

    int twosBinToDec(std::bitset<8> bin);

    std::bitset<8> floatDecToBin(float dec);

    std::bitset<8> twosDecToBin(int dec);


//    Validation
    bool isValidInstruction(std::string instruction);


//    Arithmetic
    std::bitset<8> binFullAdder(std::bitset<8> bin_1, std::bitset<8> bin_2);

    std::string floatBinaryAdder(const std::string &hex_1, const std::string &hex_2);
};

class CU {

};

class CPU {

};

#endif //TASK_3___VOLE_MACHINE_CPU_H
