#ifndef TASK_3___VOLE_MACHINE_CPU_H
#define TASK_3___VOLE_MACHINE_CPU_H

#include <iostream>
#include <bitset>

// 1- Take numbers as Hex
// 2- turn them into decimal for searching the memory
// 3- and into binary for arithmetic operations
// 4- convert binary to decimal after two's complement

// Two's Complement
// 5 -> 0000 0101, -2 -> 0000 0010 = 1111 1101 + 1 = 1111 1110
// 0000 0101
// 1111 1110 +
// 1 0000 0011 =
// if first bit = 0 -> convert to decimal normally,
//      else if first bit = 1 -> apply two's complement and return (-) at the end

// Floating Point Notation
// 2.4 -> 10.0110 -> 1.00110 -> sign: 0, exp: 4, mantissa: 0011
// 2.4 -> 0 100 0011

class Register;

class ALU {
public:
//    Hexadecimal
    int hexToDec(const std::string& hex);
    std::bitset<8> hexToBin(const std::string& hex);

//    Binary


//    Validation
    bool isValidInstruction(std::string instruction);


//    Arithmetic
};

class CU {

};

class CPU {

};

#endif //TASK_3___VOLE_MACHINE_CPU_H
