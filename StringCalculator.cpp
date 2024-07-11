#include "StringCalculator.h"
#include <string>

bool StringCalculator::IsNullOrEmpty(const std::string* numbers) {
    return numbers == nullptr || numbers->empty();
}

void StringCalculator::ReplaceNewlinesWithCommas(std::string& numbers) {
    for (char& ch : numbers) {
        if (ch == '\n') {
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
    // Add the last number if there is one
    sum = AddNumber(sum, currentNumber);

    return sum;
}

int StringCalculator::add(const std::string& numbers) {
    if (IsNullOrEmpty(&numbers)) {
        return 0;
    }

    std::string processedNumbers = numbers;
    ReplaceNewlinesWithCommas(processedNumbers);

    return SumNumbers(processedNumbers);
}
