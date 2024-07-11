#ifndef STRING_CALCULATOR_HPP
#define STRING_CALCULATOR_HPP

#include <string>

class StringCalculator {
public:
    static int add(const std::string& numbers);

private:
    static bool IsNullOrEmpty(const std::string* numbers);
    static char GetCustomDelimiter(std::string& numbers);
    static void ReplaceNewlinesWithCommas(std::string& numbers);
    static void ReplaceCustomDelimiterWithCommas(std::string& numbers, char delimiter);
    static int ConvertToInt(const std::string& number);
    static int AddNumber(int sum, const std::string& number);
    static int SumNumbers(const std::string& numbers);
    static bool ShouldIgnoreNumber(const std::string& number);
    static void CollectNegativeNumber(const std::string& number, std::string& negatives);
    static void CheckForNegatives(const std::string& numbers, std::string& negatives);
};

#endif // STRING_CALCULATOR_HPP
