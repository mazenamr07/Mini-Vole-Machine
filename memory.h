#ifndef MEMORY_H
#define MEMORY_H

#include <bits/stdc++.h>
using namespace std;

class Memory {
protected:
    int size = 256;
    std::string arr[256];
public:
    Memory() ;
    string get_cell(int address);
    void set_cell(vector<string> &data);
    void set_cell(string value, int address);
};
class Register: public Memory {
    Register();
};
#endif