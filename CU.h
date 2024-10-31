
#ifndef OP_H
#define OP_H
#include "memory.h"

class CU {
public:
    void load_content(int registerindex, int memoryindex, Memory &memo, Register &reg);
    void load(int registerindex, string data, Register &reg);
    void jump(int registerindex, int data, Register &reg, int &counter);
    void store(int registerindex, int memoryaddress, Register &reg, Memory &memo);
    void move(int registerindex1, int registerindex2, Register &reg);
    void CU::store_to_screen(int registerIndex, int memoryAddress, Register &reg, Memory &memo);
};
#endif //OP_H
