#include "console_input.h"

#include <iostream>
#include <limits>
#include <stdexcept>

namespace {

void SkipRestOfLine() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

}

long long ReadInteger(const std::string& prompt, long long min_value,
                      long long max_value) {
  while (true) {
    std::cout << prompt;
    long long value = 0;
    bool is_valid = static_cast<bool>(std::cin >> value) &&
                    value >= min_value && value <= max_value;
    if (std::cin.eof()) {
      throw std::runtime_error("Ввод данных прерван");
    }
    SkipRestOfLine();
    if (is_valid) {
      return value;
    }
    std::cout << "  Ошибка: введите целое число от " << min_value << " до "
              << max_value << ".\n";
  }
}

Time ReadTime(const std::string& prompt) {
  while (true) {
    std::cout << prompt;
    int hours = 0;
    int minutes = 0;
    char separator = '\0';
    bool is_valid = static_cast<bool>(std::cin >> hours >> separator >> minutes) &&
                    separator == ':' && hours >= 0 &&
                    hours < Time::kHoursPerDay && minutes >= 0 &&
                    minutes < Time::kMinutesPerHour;
    if (std::cin.eof()) {
      throw std::runtime_error("Ввод данных прерван");
    }
    SkipRestOfLine();
    if (is_valid) {
      return Time(static_cast<short int>(hours),
                  static_cast<short int>(minutes));
    }
    std::cout << "  Ошибка: введите время в формате ЧЧ:ММ "
              << "(часы 0..23, минуты 0..59), например 07:30.\n";
  }
}