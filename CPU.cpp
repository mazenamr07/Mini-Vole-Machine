#include "CPU.h"

//    Hexadecimal
int ALU::hexToDec(const std::string &hex) {
    int result = 0;

    for (char digit: hex) {
        if (digit >= '0' && digit <= '9') {
            result = result * 16 + (digit - '0');
        } else if (toupper(digit) >= 'A' && toupper(digit) <= 'F') {
            result = result * 16 + (toupper(digit) - 'A' + 10);
        }
    }

    return result;
}

std::bitset<8> ALU::hexToBin(const std::string &hex) {
    std::string sResult;

    for (char digit: hex) {
        std::string miniResult;
        int number = 0;

        if (digit >= '0' && digit <= '9') {
            number = digit - '0';
        } else if (toupper(digit) >= 'A' && toupper(digit) <= 'F') {
            number = toupper(digit) - 'A' + 10;
        }

        while (number > 0) {
            int remainder = number % 2;
            miniResult.insert(0, 1, char(remainder + '0'));
            number /= 2;
        }
        while (miniResult.size() < 4) {
            miniResult.insert(0, 1, '0');
        }

        sResult.append(miniResult);
    }

    if (sResult.size() < 8) {
        sResult.insert(0, 8 - sResult.size(), '0');
    }
    return std::bitset<8>(sResult);
}

//    Binary


//    Validation
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
