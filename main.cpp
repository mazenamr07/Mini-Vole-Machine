#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>

//#include "course/complexNumber.h"
//#include "course/stack.h"
#include "CPU.h"

using namespace std;
//
//class ALU {
//public:
//    double hexToDec(string hex) { // 5D
//        double result = 0;
//
//        for (int i = 0; i < hex.size(); ++i) {
//            char ch = hex[i];
//
//            if (ch >= '0' and ch <= '9') {
//                result += (ch - '0') * pow(16, hex.size() - i - 1);
//            } else if (ch >= 'A' and ch <= 'F') {
//                result += (ch - 'A' + 10) * pow(16, hex.size() - i - 1);
//            }
//        }
//
//        return result;
//    }
//
//    string decToHex(string dec) {
//
//    }
//
//    bool isValid(string operation) {
//        string validOperations = "123456BC";
//        return validOperations.find(operation) != string::npos;
//    }
//
//    void add() {
//
//    }
//};
//
//class CU {
//
//};
//
//class CPU {
//private:
////    Attributes
//    int programCounter = 0;
//    string instructionRegister;
//    string operation, registerIndex, dataIndex;
//    ALU C_ALU;
//    CU C_CU;
//    // Reg, ALU, CU
//
////    Methods
//    void fetch() {
//        instructionRegister += "156C"; // mem[progCount, progCount+1]
//        programCounter += 2;
//    }
//
//    void decode() {
//        // Operation
//        operation += instructionRegister[0];
//
//        // Register Index
//        registerIndex += instructionRegister[1];
//
//        // Data Index
//        dataIndex += instructionRegister[2];
//        dataIndex += instructionRegister[3];
//
//        // using ALU to turn hex "5C" to dec for index
//        double dataDecIndex = C_ALU.hexToDec(dataIndex);
//    }
//
//    void execute() {
//        if (operation == "1") {
////            registers[registerIndex] = Mem[dataIndex]
//        } else if (operation == "2") {
//
//        } else if (operation == "3") {
//
//        } else if (operation == "4") {
//
//        } else if (operation == "5") {
//
//        } else if (operation == "6") {
//
//        } else if (operation == "B") {
//
//        } else if (operation == "C") {
//
//        }
//    }
//
//public:
////    Methods
//    void runNextStep() {
//
//    }
//};

class Memory
{
protected:
    int size = 256;
    string arr[256];
public:
    Memory() {
        fill(begin(arr), end(arr), "00");
    }
    string get_cell(int address){
        return arr[address];
    }
    void set_cell(vector<string> &data){
        int index = 0;
        for (const string& str : data) {
            int mid = str.length() / 2;
            arr[index] = str.substr(0, mid);
            arr[index + 1] = str.substr(mid, str.length() - mid);
            index += 2; 
        }
    }
};

class Register : public Memory
{
public:
    Register(){
        fill(begin(arr), begin(arr) + 16, "00");
    }
    void set_cellreg( string s, int index){
        arr[index] = s;
    }
};

class Machine {
private:
//    Attributes
//    CPU centralUnit;
    Memory mainMemory;

public:
//    Attributes
    vector<string> data;
    vector<pair<string, string>> outputs;

//    Methods
    void loadData(const string &fileName) {
        ifstream inFile(fileName);

        if (inFile.is_open()) {
            string dataLine;
            while (getline(inFile, dataLine)) {
                stringstream ss(dataLine);
                string datum;

                while (ss >> datum) {
                    data.push_back(datum);
                }
            }
            inFile.close();
        } else {
            cerr << "Error: Couldn't load file: " << fileName << endl;
        }
        mainMemory.set_cell(data);
    }

    void printData() {
        for (const auto &datum: data) {
            cout << datum << endl;
        }
    }

    void outputState() {
        for (const auto &pair: outputs) {
            cout << pair.first << ": " << pair.second << endl;
        }
    }
};

int main() {
//    Machine test;
//    test.loadData("../text-files/input-file.txt");
//    test.printData();
//    test.outputState();
}
