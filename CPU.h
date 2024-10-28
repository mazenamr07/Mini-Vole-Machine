#ifndef TASK_3___VOLE_MACHINE_CPU_H
#define TASK_3___VOLE_MACHINE_CPU_H

#include <iostream>
#include <bitset>

// 1- Take numbers as Hex
// 2- turn them into decimal for searching the memory
// 3- and into binary for arithmetic operations
// 4- convert binary to decimal after two's complement

// Two's Complement
// 62 -> 0011 1110, -105 -> 0110 1001 = 1001 0110 + 1 = 1001 0111
// 0011 1110
// 1001 0111 +
// 1101 0101 =
// adding is done normally with ignoring the carry if present
// if first bit = 0 -> convert to decimal normally,
//      else if first bit = 1 -> apply two's complement and return (-) at the end

// Floating Point Notation
// 2.4 -> 10.0110 -> 1.00110 -> sign: 0, exp: 4, mantissa: 0011
// 2.4 -> 0 100 0011
// we split it (e.g. 1 101 0101)
// sign: 1, exponent: 101, mantissa: 0101, bias: 3
// Value = (-1)^sign * mantissa * 2^(exponent - bias)

class Register;

class ALU {
public:
//    Hexadecimal Conversion
    int hexToUnsignedDec(const std::string& hex);
    std::bitset<8> hexToBin(const std::string& hex);
    std::string binToHex(std::bitset<8> bin);

//    Validation
    bool isValidInstruction(std::string instruction);


//    Arithmetic
};

class CU {

};

class CPU {

};

#endif //TASK_3___VOLE_MACHINE_CPU_H
