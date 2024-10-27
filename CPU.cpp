#include "CPU.h"

//    Hexadecimal
double ALU::hexToDec(const std::string &hex) {
    double result = 0;

    for (char i: hex) {
        if (i >= '0' && i <= '9') {
            result = result * 16 + (i - '0');
        } else if (i >= 'A' && i <= 'F') {
            result = result * 16 + (i - 'A' + 10);
        } else if (i >= 'a' && i <= 'f') {
            result = result * 16 + (i - 'a' + 10);
        }
    }

    return result;
}

std::string ALU::decToHex(int dec) {
    std::string hexDigits = "0123456789ABCDEF";
    std::string result;

    while (dec > 0) {
        int remainder = dec % 16;
        result.insert(0, 1, hexDigits[remainder]);
        dec /= 16;
    }

    return result.empty() ? "0" : result;
}

//    Binary
double ALU::binToDec(const std::string &bin) {
    double result;

    for (char i: bin) {
        result = result * 2 + (i - '0');
    }
    return result;
}

std::string ALU::decToBin(int dec) {
    std::string binDigits = "01";
    std::string result;

    while (dec > 0) {
        int remainder = dec % 2;
        result.insert(0, 1, binDigits[remainder]);
        dec /= 2;
    }

    return result.empty() ? "0" : result;
}

bool ALU::isValidInstruction(std::string instruction) {
    for (const auto &hex: instruction) {
        if (hex < '0' || hex > 'F') {
            return false;
        }
    }
    std::string validOperations = "123456BC";
    if (validOperations.find(instruction[0]) == std::string::npos) {
        return false;
    }

    return true;
}

//    Arithmetic
int ALU::add(int number_1, int number_2) {
    return 0;
}
