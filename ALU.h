#ifndef TASK_3___VOLE_MACHINE_CPU_H
#define TASK_3___VOLE_MACHINE_CPU_H

#include <bits/stdc++.h>



class ALU {
public:
//    Hexadecimal
    double hexToDec(const std::string &hex);
//    Binary

    double hexToDecChar(const char &hex);
    std::string decToHex(int dec);
    bool isValidInstruction(std::string instruction);

//    Arithmetic
    int add(int number_1, int number_2);
};



#endif //TASK_3___VOLE_MACHINE_CPU_H
