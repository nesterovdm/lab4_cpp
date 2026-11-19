#ifndef TIME_OF_DAY_H_
#define TIME_OF_DAY_H_

#include <iostream>

class Time {
 public:
  static constexpr int kMinutesPerHour = 60;
  static constexpr int kHoursPerDay = 24;
  static constexpr int kMinutesPerDay = kMinutesPerHour * kHoursPerDay;

  Time();
  explicit Time(short int hours);
  Time(short int hours, short int minutes);
  Time(const Time& other) = default;
  Time& operator=(const Time& other) = default;

  short int hours() const;
  short int minutes() const;
  void set_hours(short int hours);
  void set_minutes(short int minutes);

  Time SubtractMinutes(unsigned int minutes_to_subtract) const;

  Time& operator-();
  Time& operator--();

  operator short int() const;
  explicit operator bool() const;

  bool operator==(const Time& other) const;
  bool operator!=(const Time& other) const;

 private:
  short int hours_;
  short int minutes_;
};

std::ostream& operator<<(std::ostream& out, const Time& time);

#endif