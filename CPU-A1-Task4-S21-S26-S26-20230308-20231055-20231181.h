#ifndef CPU_H
#define CPU_H

#include <bits/stdc++.h>
#include "ALU.h"
#include "CU.h"

using namespace std;

class CPU {
private:
    int programCounter = 0;
    ALU C_ALU;
    CU C_CU;
    string contentHEX, contentASC;
public:
    CPU(int index);

    void fetch(Memory &mem, Register &r);

    void decode(string instructionRegister, Memory &mem, Register &r);

    void execute(string operation, string registerIndex, string dataIndex, Memory &mem, Register &r);

    void runNextStep(Memory &mem, Register &r);

    string getProgramCounter();
};

#endif
