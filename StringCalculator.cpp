#include "StringCalculator.h"
#include <string>

bool StringCalculator::IsNullOrEmpty(const std::string* numbers) {
    return numbers == nullptr || numbers->empty();
}

int StringCalculator::add(const std::string& numbers) {
    if (IsNullOrEmpty(numbers)) {
        return 0;
    }
    return -1;
}


}
