#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

#include "console_input.h"
#include "time_of_day.h"

void PrintTitle(const std::string& title) {
  std::cout << "\n==== " << title << " ====\n";
}

std::string BoolToText(bool value) { return value ? "true" : "false"; }

void RunTask1() {
  PrintTitle("ЗАДАНИЕ 1: класс Time, вычитание минут");

  Time input_time = ReadTime("Введите время (ЧЧ:ММ): ");
  unsigned int minutes_to_subtract = static_cast<unsigned int>(
      ReadInteger("Сколько минут вычесть (0..4294967295): ", 0,
                  std::numeric_limits<unsigned int>::max()));

  std::cout << "\n-- Конструкторы --\n";
  Time default_time;
  std::cout << "По умолчанию: " << default_time << "\n";

  Time hours_only_time(input_time.hours());
  std::cout << "Только часы: " << hours_only_time << "\n";

  Time full_time(input_time.hours(), input_time.minutes());
  std::cout << "Часы и минуты: " << full_time << "\n";

  Time copied_time(full_time);
  std::cout << "Копирования: " << copied_time << "\n";
  
  std::cout << "\n-- Свойства --\n";
  Time time_from_setters;
  time_from_setters.set_hours(input_time.hours());
  time_from_setters.set_minutes(input_time.minutes());
  std::cout << "hours() = " << time_from_setters.hours()
            << ", minutes() = " << time_from_setters.minutes()
            << ", время: " << time_from_setters << "\n";

  std::cout << "\n-- Вычитание минут --\n";
  Time result = input_time.SubtractMinutes(minutes_to_subtract);
  std::cout << input_time << " - " << minutes_to_subtract << " мин = "
            << result << "\n";
}

void RunTask2() {
  PrintTitle("ЗАДАНИЕ 2: перегруженные операции класса Time");

  Time first_time = ReadTime("Введите первое время (ЧЧ:ММ): ");
  Time second_time = ReadTime("Введите второе время (ЧЧ:ММ): ");

  std::cout << "\n-- Унарные операции (для первого времени) --\n";
  Time time_without_minutes(first_time);
  --time_without_minutes;
  std::cout << "--(" << first_time << ") обнуляет минуты: "
            << time_without_minutes << "\n";

  Time zero_time(first_time);
  -zero_time;
  std::cout << "-(" << first_time << ") обнуляет часы и минуты: " << zero_time
            << "\n";

  std::cout << "\n-- Приведение типов (для первого времени) --\n";
  short int hours = first_time;
  std::cout << "short int (неявно), количество часов: " << hours << "\n";
  bool is_not_zero = static_cast<bool>(first_time);
  std::cout << "bool (явно): " << BoolToText(is_not_zero) << "\n";

  std::cout << "\n-- Сравнение --\n";
  std::cout << first_time << " == " << second_time << " : "
            << BoolToText(first_time == second_time) << "\n";
  std::cout << first_time << " != " << second_time << " : "
            << BoolToText(first_time != second_time) << "\n";
}

void PrintMenu() {
  std::cout << "\n========== МЕНЮ ==========\n"
            << "1 - Задание 1 (конструкторы, свойства, вычитание минут)\n"
            << "2 - Задание 2 (унарные операции, приведение типов, сравнение)\n"
            << "0 - Выход\n";
}

int main() {
  std::cout << "Лабораторная работа №4. Класс Time (вариант 12)\n";
  try {
    while (true) {
      PrintMenu();
      long long choice = ReadInteger("Выберите задание: ", 0, 2);
      if (choice == 0) {
        break;
      }
      if (choice == 1) {
        RunTask1();
      } else {
        RunTask2();
      }
    }
  } catch (const std::exception& error) {
    std::cout << "Ошибка: " << error.what() << "\n";
    return 1;
  }
  std::cout << "Программа завершена.\n";
  return 0;
}