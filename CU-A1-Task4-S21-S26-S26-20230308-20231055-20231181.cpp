#include "CU.h"
#include "memory.h"

ALU alu;

void CU::load_content(int registerindex, int memoryindex, Memory &memo, Register &reg) {
    string content = memo.get_cell(memoryindex);
    reg.set_cell(content, registerindex);
}

void CU::load(int registerindex, string data, Register &reg) {
    reg.set_cell(data, registerindex);
}

void CU::jump(int registerindex, int data, Register &reg, int &counter) {
    string contentR = reg.get_cell(registerindex);
    string content0 = reg.get_cell(0);
    if (contentR == content0) {
        counter = data;
    }
}

void CU::store(int registerindex, int memoryaddress, Register &reg, Memory &memo) {
    string content = reg.get_cell(registerindex);
    memo.set_cell(content, memoryaddress);
}

void CU::move(int registerindex1, int registerindex2, Register &reg) {
    string content = reg.get_cell(registerindex1);
    reg.set_cell(content, registerindex2);
}

void CU::store_to_screen(int registerIndex, int memoryAddress, Register &reg, Memory &memo, string &contentHEX, string &contentASC) {
    // get the content of the specified register
    string content = reg.get_cell(registerIndex);
    cout << "\noutput to screen: " << content << "\n";
    contentHEX += content;
    contentHEX += ' ';
    contentASC += char(alu.hexToUnsignedDec(content));
}

void CU::add_twos_complement(int registerindex1, int registerindex2, int registerindex3, Register &reg) {
    string register_1 = reg.get_cell(registerindex1); // 11
    string register_2 = reg.get_cell(registerindex2); // 2B

    bitset<8> result = alu.binFullAdder(alu.hexToBin(register_1), alu.hexToBin(register_2));
    string resultSTR = alu.binToHex(result);
    reg.set_cell(resultSTR, registerindex3);
}

void CU::add_float_binary(int registerindex1, int registerindex2, int registerindex3, Register &reg) {
    string register_1 = reg.get_cell(registerindex1); // 11
    string register_2 = reg.get_cell(registerindex2); // 2B

    string result = alu.floatBinaryAdder(register_1, register_2);
    reg.set_cell(result, registerindex3);
}

void CU::halt() {
    halted = true;
}

bool CU::isHalted() const {
    return halted;
}