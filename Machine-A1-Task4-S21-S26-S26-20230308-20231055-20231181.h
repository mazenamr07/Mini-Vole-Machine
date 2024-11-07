#ifndef MACHINE_H
#define MACHINE_H

#include <bits/stdc++.h>
#include "CPU.h"

using namespace std;

class Machine {
private:
    string index;
public:
    vector<string> data;

    void loadData(const string &fileName, Memory &mainMemory, CPU &cpu, ALU &alu);

    void outputState(Memory &mainMemory, Register &reg, CPU &cpu, ALU &alu);

    void runNextStep(Memory &mainMemory, Register &reg, CPU &cpu);
};

#endif //MACHINE_H
