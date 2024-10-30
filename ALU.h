#ifndef TASK_3___VOLE_MACHINE_CPU_H
#define TASK_3___VOLE_MACHINE_CPU_H

#include <bits/stdc++.h>



class ALU {
public:


    double hexToDecChar(const char &hex);
    std::string decToHex(int dec);
    bool isValidInstruction(std::string instruction);

//    Arithmetic
    int hexToUnsignedDec(const std::string &hex);
    std::bitset<8> hexToBin(const std::string &hex);
    std::string binToHex(std::bitset<8> bin);
    float floatBinToDec(std::bitset<8> bin);
    std::bitset<8> floatDecToBin(float dec);
    int twosBinToDec(std::bitset<8> bin);
    std::bitset<8> twosDecToBin(int dec);
    std::bitset<8> binFullAdder(std::bitset<8> bin_1, std::bitset<8> bin_2);
    std::string floatBinaryAdder(const std::string &hex_1, const std::string &hex_2);
};

#endif //TASK_3___VOLE_MACHINE_CPU_H
