#include "StringCalculator.h"
#include <string>

bool StringCalculator::IsNullOrEmpty(const std::string* numbers) {
    return numbers == nullptr || numbers->empty();
}

char StringCalculator::GetCustomDelimiter(std::string& numbers) {
    if (numbers.substr(0, 2) == "//") {
        char delimiter = numbers[2];
        numbers = numbers.substr(4); // Remove the custom delimiter line
        return delimiter;
    }
    return ','; // Default delimiter
}

void StringCalculator::ReplaceDelimitersWithCommas(std::string& numbers, char delimiter) {
    for (char& ch : numbers) {
        if (ch == delimiter || ch == '\n') {
            ch = ',';
        }
    }
}

int StringCalculator::ConvertToInt(const std::string& number) {
    return std::stoi(number);
}

int StringCalculator::AddNumber(int sum, const std::string& number) {
    if (!number.empty()) {
        sum += ConvertToInt(number);
    }
    return sum;
}

int StringCalculator::SumNumbers(const std::string& numbers) {
    int sum = 0;
    std::string currentNumber;
    for (char ch : numbers) {
        if (ch == ',') {
            sum = AddNumber(sum, currentNumber);
            currentNumber.clear();
        } else {
            currentNumber += ch;
        }
    }
    sum = AddNumber(sum, currentNumber); // Add the last number if there is one
    return sum;
}

int StringCalculator::add(const std::string& numbers) {
    if (IsNullOrEmpty(&numbers)) {
        return 0;
    }

    std::string processedNumbers = numbers;
    char delimiter = GetCustomDelimiter(processedNumbers);
    ReplaceDelimitersWithCommas(processedNumbers, delimiter);

    return SumNumbers(processedNumbers);
}

