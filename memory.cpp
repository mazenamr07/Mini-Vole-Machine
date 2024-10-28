#include <bits/stdc++.h>

using namespace std;

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
public:
    vector<string> data;
    Memory mem1;
    Register reg;
//    Methods
    void getData(const string& fileName) {
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
        //mem1.set_cell(data);
        // cout << mem1.get_cell(0) << endl;
        // reg.set_cellreg("11" , 2);
        // cout << reg.get_cell(2);
    }
};
// int main(){
//     Machine test1; 
//     test1.getData("input-file.txt");
// }