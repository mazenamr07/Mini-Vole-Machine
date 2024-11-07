#include <bits/stdc++.h>
#include "Machine.h"

using namespace std;


int main() {
    cout << "Welcome to Mini Vole Machine!\n";
    Machine machine;
    Memory mainMemory;
    Register r;
    CPU cpu{10}; // Default CPU with program counter 0A
    ALU alu;
    string fileName;
    cout << "Enter the name of the file:";
    cin >> fileName;
    machine.loadData(fileName, mainMemory, cpu, alu);

    while (true) {
        int choice;
        cout << "1) Load file\n2) Display status\n3) Execute next step\n4) Exit\n";
        cin >> choice;

        if (choice == 1) {
            Machine machine1;
            Memory memory;
            Register reg;
            CPU c{10}; // Default CPU with program counter 0A
            ALU a;
            machine = machine1;
            mainMemory = memory;
            r = reg;
            cpu = c;
            alu = a;
            fileName = "";
            cout << "Enter the name of the file:";
            cin >> fileName;
            machine1.loadData(fileName, mainMemory, cpu, alu);
        } else if (choice == 2) {
            machine.outputState(mainMemory, r, cpu, alu);
        } else if (choice == 3) {
            machine.runNextStep(mainMemory, r, cpu); // Run one step
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice\n";
        }
    }
    return 0;
}
