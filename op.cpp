#include "memory.cpp"
#include "CPU.cpp"
#include "CPU.h"
#include <bits/stdc++.h>

using namespace std;
class CU{
    public:
        void load_content(int registerindex, int memoryindex, Memory &memo, Register &reg){
            string content = memo.get_cell(memoryindex);
            reg.set_cellreg(content, registerindex);
        }
        void load(int registerindex, string data, Register &reg){
            reg.set_cellreg(data, registerindex);
        }
        void jump(int registerindex, int data, Register &reg, int &counter){
            string contentR = reg.get_cell(registerindex);
            string content0 = reg.get_cell(0);
            if(contentR == content0){
                counter = data;
            }
        }
};