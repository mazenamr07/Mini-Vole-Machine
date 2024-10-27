#ifndef TASK_3___VOLE_MACHINE_CPU_H
#define TASK_3___VOLE_MACHINE_CPU_H

#include <iostream>

class Register;

class ALU {
public:
//    Hexadecimal
    double hexToDec(const std::string &hex);
    std::string decToHex(int dec);
//    Binary


    bool isValidInstruction(std::string instruction);

//    Arithmetic
    int add(int number_1, int number_2);
};

class CU {

};

class CPU {

};

#endif //TASK_3___VOLE_MACHINE_CPU_H
