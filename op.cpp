#include "memory.cpp"
#include "CPU.cpp"
#include "CPU.h"
#include <bits/stdc++.h>

using namespace std;
class CU{
    public:
        void load_content(int registerindex, int memoryindex, Memory &memo, Register &reg){
            string content = memo.get_cell(memoryindex);
            reg.set_cell(content, registerindex);
        }
        void load(int registerindex, string data, Register &reg){
            reg.set_cell(data, registerindex);
        }
        void jump(int registerindex, int data, Register &reg, int &counter){
            string contentR = reg.get_cell(registerindex);
            string content0 = reg.get_cell(0);
            if(contentR == content0){
                counter = data;
            }
        }
        void store(int registerindex, int memoryaddress, Register &reg, Memory &memo){
            string content = reg.get_cell(registerindex);
            memo.set_cell(content, memoryaddress);
        }
        void move(int registerindex1, int registerindex2, Register &reg){
            string content = reg.get_cell(registerindex1);
            reg.set_cell(content, registerindex2);
        }
       
};