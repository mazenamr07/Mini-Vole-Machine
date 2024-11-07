#include "memory.h"


Memory::Memory() {
    fill(begin(arr), end(arr), "00");
}
string Memory::get_cell(int address){
    return arr[address];
}
void Memory::set_cell(vector<string> &data, int index){
    for (const string& str : data) {
        int mid = str.length() / 2;
        arr[index] = str.substr(0, mid);
        arr[index + 1] = str.substr(mid, str.length() - mid);
        index += 2;
    }
}
void Memory::set_cell(string data, int address){
    arr[address] = data;
}
Register::Register(){
    fill(begin(arr), begin(arr) + 16, "00");
}
