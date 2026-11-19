#ifndef CONSOLE_INPUT_H_
#define CONSOLE_INPUT_H_

#include <string>

#include "time_of_day.h"

long long ReadInteger(const std::string& prompt, long long min_value,
                      long long max_value);

Time ReadTime(const std::string& prompt);

#endif 