#include <bits/stdc++.h>

//#include "course/complexNumber.h"
//#include "course/stack.h"
#include "memory.h"
#include "Alu.h"
#include "CU.h"

using namespace std;


class CPU {
private:
//    Attributes
   int programCounter = 0;
   string instructionRegister;
   string operation, registerIndex, dataIndex;
   ALU C_ALU;
   CU C_CU;
   Memory mem;
   Register r;
   int memoDecIndex, regDecIndex, regindex1, regindex2;
   

////    Methods
   void fetch() {
       instructionRegister += "156C"; // mem[progCount, progCount+1]
       programCounter += 2;
   }

   void decode() {
       // Operation
       operation += instructionRegister[0];

       // Register Index
       registerIndex += instructionRegister[1];

       // Data Index
       dataIndex += instructionRegister[2];
       dataIndex += instructionRegister[3];

       
   }

   void execute() {
        if (operation == "1") {
            regDecIndex = C_ALU.hexToUnsignedDec(registerIndex);
            memoDecIndex = C_ALU.hexToUnsignedDec(dataIndex);
            C_CU.load_content(regDecIndex, memoDecIndex, mem, r);
        } 
        else if (operation == "2") {
            regDecIndex = C_ALU.hexToUnsignedDec(registerIndex);
            C_CU.load(regDecIndex, dataIndex, r);
        }

        else if (operation == "3") {
            regDecIndex = C_ALU.hexToUnsignedDec(registerIndex);
            memoDecIndex = C_ALU.hexToUnsignedDec(dataIndex);
            C_CU.store(regDecIndex, memoDecIndex, r, mem);
        }
        else if (operation == "4") {
            regindex1 = C_ALU.hexToDecChar(instructionRegister[2]);
            regindex2 = C_ALU.hexToDecChar(instructionRegister[3]);
            C_CU.move(regindex1, regindex2, r);
        } 
//else if (operation == "5") {
//
//        } else if (operation == "6") {
//
       //} 
        else if (operation == "B") {
            C_CU.jump(regDecIndex, memoDecIndex, r, programCounter);
        }
//        } else if (operation == "C") {
//
//        }
    }
};
//public:
////    Methods
//    void runNextStep() {
//
//    }
//};



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
    Machine test;
    test.loadData("input-file.txt");
//    test.printData();
//    test.outputState();

}
