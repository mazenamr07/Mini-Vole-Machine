#include "CPU.h"

//    Hexadecimal Conversion
int ALU::hexToUnsignedDec(const std::string &hex) {
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

std::string ALU::binToHex(std::bitset<8> bin) {
    std::string result;
    std::bitset<4> left, right;

    for (int i = 0; i < 4; ++i) {
        left[i] = bin[i + 4];
        right[i] = bin[i];
    }

    int array[2];
    array[0] = left.to_ulong();
    array[1] = right.to_ulong();

    for (int i: array) {
        if (i >= 0 && i <= 9) {
            result += char(i + '0');
        } else if (i >= 10 && i <= 15) {
            result += char(i + 'A' - 10);
        }
    }

    return result;
}


//    Binary Conversion
float ALU::floatBinToDec(std::bitset<8> bin) {
    int sign = bin[7];
    int exponent = (bin[6] << 2) | (bin[5] << 1) | bin[4];
    int mantissaBits = (bin[3] << 3) | (bin[2] << 2) | (bin[1] << 1) | bin[0];

    int bias = 3;
    int actualExponent = exponent - bias;

    float mantissa = 1.0f;
    for (int i = 0; i < 4; ++i) {
        if (mantissaBits & (1 << (3 - i))) {
            mantissa += std::pow(2, -(i + 1));
        }
    }

    float decimalValue = std::pow(-1, sign) * mantissa * std::pow(2, actualExponent);

    return decimalValue;
}

std::bitset<8> ALU::floatDecToBin(float dec) {
    if (dec == 0) {
        return {0};
    }

    std::string result;
    int sign = 0;

    if (dec < 0) {
        sign = 1;
        dec *= -1;
    }


    int intPart = int(dec);
    float fractionPart = dec - float(intPart);

    std::string intString;

    while (intPart > 0) {
        int remainder = intPart % 2;
        intString.insert(0, 1, char(remainder + '0'));
        intPart /= 2;
    }

    std::string fractionString;
    int count = 0;

    while (fractionPart > 0 && count < 64) {
        fractionPart *= 2;
        int bit = static_cast<int>(fractionPart);

        fractionString += std::to_string(bit);

        fractionPart -= float(bit);
        count++;
    }

    result += intString + '.' + fractionString;

    int normalizeCount = 0;
    int bias = 3;

    if (dec < 1) {
        while (result[0] != '1') {
            int index = result.find('.');

            char temp = result[index];
            result[index] = result[index + 1];
            result[index + 1] = temp;

            if (result[0] != '1') {
                result = result.substr(1, result.size() - 1);
            }

            normalizeCount--;
        }
    } else {
        while (result[1] != '.') {
            int index = result.find('.');
            char temp = result[index - 1];
            result[index - 1] = result[index];
            result[index] = temp;

            normalizeCount++;
        }
    }


    int exponent = normalizeCount + bias;
    std::string mantissa = result.substr(2, 4);

    while (mantissa.size() < 4) {
        mantissa += '0';
    }

    std::string binExponent;

    while (exponent > 0) {
        int remainder = exponent % 2;
        binExponent.insert(0, 1, char(remainder + '0'));
        exponent /= 2;
    }
    std::string finalExponent = binExponent.substr(0, 3);

    while (finalExponent.size() < 3) {
        finalExponent.insert(0, 1, '0');
    }

    std::string finalResult = char(sign + '0') + finalExponent + mantissa;
    return std::bitset<8>(finalResult);
}

int ALU::twosBinToDec(std::bitset<8> bin) {
    int MSB = bin[7]; // Most Significant Bit
    int result = 0;

    if (MSB == 0) { // Positive
        return bin.to_ulong();
    }

    // Negative
    bin = ~bin;
    std::bitset<8> binAdded = binFullAdder(bin, 1);

    result = binAdded.to_ulong();
    return -result;
}

std::bitset<8> ALU::twosDecToBin(int dec) {
    if (dec == 0) {
        return {0};
    } else if (dec > 0) {
        return std::bitset<8>(dec);
    }

    // Negative
    int absDec = -dec;
    std::bitset<8> result(absDec);

    result = ~result;
    return binFullAdder(result, 1);
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
std::bitset<8> ALU::binFullAdder(std::bitset<8> bin_1, std::bitset<8> bin_2) {
    std::bitset<8> result;

    // Half Adder
    int LSB_1 = bin_1[0];
    int LSB_2 = bin_2[0];

    int sum = LSB_1 ^ LSB_2;
    int carryOut = LSB_1 & LSB_2;
    result[0] = sum;

    // Full Adder
    for (int i = 1; i < bin_2.size(); ++i) {
        int bit_1 = bin_1[i];
        int bit_2 = bin_2[i];
        int carryIn = carryOut;

        sum = bit_1 ^ bit_2 ^ carryIn;
        carryOut = (bit_1 & bit_2) | (carryIn & (bit_1 ^ bit_2));
        result[i] = sum;
    }

    return result;
}

std::string ALU::floatBinaryAdder(const std::string &hex_1, const std::string &hex_2) {
    std::bitset<8> bin_1 = hexToBin(hex_1);
    std::bitset<8> bin_2 = hexToBin(hex_2);

    float dec_1 = floatBinToDec(bin_1);
    float dec_2 = floatBinToDec(bin_2);

    float sum = dec_1 + dec_2;
    std::bitset<8> binSum = floatDecToBin(sum);
    return binToHex(binSum);
}

