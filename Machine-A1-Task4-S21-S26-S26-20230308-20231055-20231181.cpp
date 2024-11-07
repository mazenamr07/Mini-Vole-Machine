#include "Machine.h"

void Machine::loadData(const string &fileName, Memory &mainMemory, CPU &cpu, ALU &alu) {
    ifstream inFile(fileName);
    if (inFile.is_open()) {
        cout << fileName << " Loaded Successfully!\n";
        string dataLine;
        while (getline(inFile, dataLine)) {
            string capData;
            for (char ch: dataLine) {
                capData += toupper(ch);
            }
            if (!alu.isValidInstruction(capData)) {
                continue;
            }
            stringstream ss(capData);
            string datum;
            while (ss >> datum) {
                data.push_back(datum);
            }
        }
        inFile.close();

        int choiceIndex;
        cout << "Do you want to set a Program Counter to start from:\n"
                "1) Set Program Counter\n"
                "2) Use Default Counter (0A = 10)\n";
        cin >> choiceIndex;
        if (choiceIndex == 1) {
            cout << "Enter Program Counter (HEX) to start from:";
            cin >> index;
        } else if (choiceIndex == 2) {
            index = "0A";
        }
        int indexDec = alu.hexToUnsignedDec(index);
        cpu = CPU(indexDec); // Reinitialize CPU with new program counter
        mainMemory.set_cell(data, indexDec); // Load data starting from index
    } else {
        cerr << "Error: Couldn't load file: " << fileName << endl;
    }
}

void Machine::outputState(Memory &mainMemory, Register &reg, CPU &cpu, ALU &alu) {
    cout << "Memory:\n";
    for (int i = 0; i < 256; i++) {
        cout << setw(4) << mainMemory.get_cell(i);
        if ((i + 1) % 16 == 0) {
            cout << endl;
        }
    }
    cout << "\nProgram Counter\n";
    cout << cpu.getProgramCounter() << endl;

    cout << "\nRegisters:\n";
    for (int i = 0; i < 16; ++i) {
        cout << "Register " << setw(2) << alu.decToHex(i) << ": " << reg.get_cell(i) << endl;
    }

}

void Machine::runNextStep(Memory &mainMemory, Register &reg, CPU &cpu) {
    cpu.runNextStep(mainMemory, reg);
}
