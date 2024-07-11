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

void StringCalculator::ReplaceNewlinesWithCommas(std::string& numbers) {
    for (char& ch : numbers) {
        if (ch == '\n') {
            ch = ',';
        }
    }
}

void StringCalculator::ReplaceCustomDelimiterWithCommas(std::string& numbers, char delimiter) {
    if (delimiter != ',') { // Only replace if the custom delimiter is not a comma
        for (char& ch : numbers) {
            if (ch == delimiter) {
                ch = ',';
            }
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
    ReplaceNewlinesWithCommas(processedNumbers);
    ReplaceCustomDelimiterWithCommas(processedNumbers, delimiter);

    return SumNumbers(processedNumbers);
}
