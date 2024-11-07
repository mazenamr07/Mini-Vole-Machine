#include "CPU.h"


CPU::CPU(int index) : programCounter(index) {

}

void CPU::fetch(Memory &mem, Register &r) {
    string instructionRegister = mem.get_cell(programCounter);
    instructionRegister += mem.get_cell(programCounter + 1);
    decode(instructionRegister, mem, r);
}

void CPU::decode(string instructionRegister, Memory &mem, Register &r) {
    string operation(1, instructionRegister[0]);
    string registerIndex(1, instructionRegister[1]);
    string dataIndex = instructionRegister.substr(2, 2);

    execute(operation, registerIndex, dataIndex, mem, r);
}

void CPU::execute(string operation, string registerIndex, string dataIndex, Memory &mem, Register &r) {
    int memoDecIndex, regDecIndex, regindex1, regindex2;

    if (operation == "1") {
        regDecIndex = C_ALU.hexToUnsignedDec(registerIndex);
        memoDecIndex = C_ALU.hexToUnsignedDec(dataIndex);
        C_CU.load_content(regDecIndex, memoDecIndex, mem, r);
        programCounter += 2;
    } else if (operation == "2") {
        regDecIndex = C_ALU.hexToUnsignedDec(registerIndex);
        C_CU.load(regDecIndex, dataIndex, r);
        programCounter += 2;
    } else if (operation == "3") {
        regDecIndex = C_ALU.hexToUnsignedDec(registerIndex);
        memoDecIndex = C_ALU.hexToUnsignedDec(dataIndex);

        if (dataIndex == "00") {
            C_CU.store_to_screen(regDecIndex, memoDecIndex, r, mem, contentHEX, contentASC);
            programCounter += 2;
        } else {
            C_CU.store(regDecIndex, memoDecIndex, r, mem);
            programCounter += 2;
        }
    } else if (operation == "4") {
        regindex1 = C_ALU.hexToDecChar(dataIndex[0]);
        regindex2 = C_ALU.hexToDecChar(dataIndex[1]);
        C_CU.move(regindex1, regindex2, r);
        programCounter += 2;
    } else if (operation == "5") {
        regindex1 = C_ALU.hexToDecChar(dataIndex[0]);
        regindex2 = C_ALU.hexToDecChar(dataIndex[1]);
        int regindex3 = C_ALU.hexToDecChar(registerIndex[0]);
        C_CU.add_twos_complement(regindex1, regindex2, regindex3, r);
        programCounter += 2;
    } else if (operation == "6") {
        regindex1 = C_ALU.hexToDecChar(dataIndex[0]);
        regindex2 = C_ALU.hexToDecChar(dataIndex[1]);
        int regindex3 = C_ALU.hexToDecChar(registerIndex[0]);
        C_CU.add_float_binary(regindex1, regindex2, regindex3, r);
        programCounter += 2;
    } else if (operation == "B") {
        int temp = programCounter;
        regDecIndex = C_ALU.hexToUnsignedDec(registerIndex);
        memoDecIndex = C_ALU.hexToUnsignedDec(dataIndex);
        C_CU.jump(regDecIndex, memoDecIndex, r, programCounter);

        if (temp == programCounter) {
            programCounter += 2;
        }
    } else if (operation == "C" or operation == "0") {
        C_CU.halt();
    }
}

void CPU::runNextStep(Memory &mem, Register &r) {
    if (!C_CU.isHalted()) {
        fetch(mem, r);
    } else {
        cout << "Cannot execute next step. CPU is halted." << endl;
        cout << "Output to screen in hexadecimal: " << contentHEX << endl;
        cout << "Output to ASCII: " << contentASC << endl;
    }
}

string CPU::getProgramCounter() {
    return C_ALU.decToHex(programCounter);
}

