
#ifndef OP_H
#define OP_H

#include "memory.h"
#include "ALU.h"

class CU {
    bool halted = false;

public:

    void load_content(int registerindex, int memoryindex, Memory &memo, Register &reg);

    void load(int registerindex, string data, Register &reg);

    void jump(int registerindex, int data, Register &reg, int &counter);

    void store(int registerindex, int memoryaddress, Register &reg, Memory &memo);

    void move(int registerindex1, int registerindex2, Register &reg);

    void store_to_screen(int registerIndex, int memoryAddress, Register &reg, Memory &memo, string &contentHEX, string &contentASC);

    void add_twos_complement(int registerindex1, int registerindex2, int registerindex3, Register &reg);

    void add_float_binary(int registerindex1, int registerindex2, int registerindex3, Register &reg);

    void halt();

    bool isHalted() const;
};

#endif //OP_H
