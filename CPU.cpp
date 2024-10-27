#include "CPU.h"

//    Hexadecimal
int ALU::hexToDec(const std::string &hex, bool isTwosComplement) {
    if (isTwosComplement) {
        return 0;
    }

    int result = 0;

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

std::string ALU::decToHex(int dec, bool isTwosComplement) {
    if (isTwosComplement) {
        return {};
    }

    std::string hexDigits = "0123456789ABCDEF";
    std::string result;

    while (dec > 0) {
        int remainder = dec % 16;
        result.insert(0, 1, hexDigits[remainder]);
        dec /= 16;
    }
    while (result.size() < 2) {
        result.insert(0, 1, '0');
    }

    return result;
}

//    Binary
int ALU::binToDec(const std::string &bin, bool isTwosComplement, bool isFloatNotation) {
    if (!isTwosComplement && !isFloatNotation) {
        int result = 0;

        for (char digit: bin) {
            result = result * 2 + (digit - '0');
        }

        return result;
    } else if (isTwosComplement) {
        return 0;
    }
    return 0;
}

std::string ALU::decToBin(int dec, bool isTwosComplement, bool isFloatNotation) {
    if (!isTwosComplement && !isFloatNotation) {
        std::string binDigits = "01";
        std::string result;

        while (dec > 0) {
            int remainder = dec % 2;
            result.insert(0, 1, binDigits[remainder]);
            dec /= 2;
        }
        while (result.size() < 8) {
            result.insert(0, 1, '0');
        }

        return result;
    } else if (isTwosComplement) {
        return {};
    }
    return {};
}

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

