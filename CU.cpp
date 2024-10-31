#include "CU.h"
#include "memory.h"




void CU::load_content(int registerindex, int memoryindex, Memory &memo, Register &reg){
    string content = memo.get_cell(memoryindex);
    reg.set_cell(content, registerindex);
}
void CU::load(int registerindex, string data, Register &reg){
    reg.set_cell(data, registerindex);
}
void CU::jump(int registerindex, int data, Register &reg, int &counter){
    string contentR = reg.get_cell(registerindex);
    string content0 = reg.get_cell(0);
    if(contentR == content0){
        counter = data;
    }
}
void CU::store(int registerindex, int memoryaddress, Register &reg, Memory &memo){
    string content = reg.get_cell(registerindex);
    memo.set_cell(content, memoryaddress);
}
void CU::move(int registerindex1, int registerindex2, Register &reg){
    string content = reg.get_cell(registerindex1);
    reg.set_cell(content, registerindex2);
}
void CU::store_to_screen(int registerIndex, int memoryAddress, Register &reg, Memory &memo) {
    // get the content of the specified register
    string content = reg.get_cell(registerIndex);

    // check if memory address is 0, representing the screen
    if (memoryAddress == 0) {
        cout << "output to screen: " << content << "\n";
    } else {
        // store the register content in the specified memory location
        memo.set_cell(content, memoryAddress);
    }
}