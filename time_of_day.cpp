#include "time_of_day.h"

#include <stdexcept>

Time::Time() : hours_(0), minutes_(0) {}

Time::Time(short int hours) : hours_(0), minutes_(0) { set_hours(hours); }

Time::Time(short int hours, short int minutes) : hours_(0), minutes_(0) {
  set_hours(hours);
  set_minutes(minutes);
}

short int Time::hours() const { return hours_; }

short int Time::minutes() const { return minutes_; }

void Time::set_hours(short int hours) {
  if (hours < 0 || hours >= kHoursPerDay) {
    throw std::invalid_argument("Часы должны быть в диапазоне 0..23");
  }
  hours_ = hours;
}

void Time::set_minutes(short int minutes) {
  if (minutes < 0 || minutes >= kMinutesPerHour) {
    throw std::invalid_argument("Минуты должны быть в диапазоне 0..59");
  }
  minutes_ = minutes;
}

Time Time::SubtractMinutes(unsigned int minutes_to_subtract) const {
  int current_total_minutes = hours_ * kMinutesPerHour + minutes_;
  int minutes_within_day =
      static_cast<int>(minutes_to_subtract % kMinutesPerDay);
  int result_total_minutes =
      (current_total_minutes - minutes_within_day + kMinutesPerDay) %
      kMinutesPerDay;
  return Time(static_cast<short int>(result_total_minutes / kMinutesPerHour),
              static_cast<short int>(result_total_minutes % kMinutesPerHour));
}

Time& Time::operator-() {
  hours_ = 0;
  minutes_ = 0;
  return *this;
}

Time& Time::operator--() {
  minutes_ = 0;
  return *this;
}

Time::operator short int() const { return hours_; }

Time::operator bool() const { return hours_ != 0 || minutes_ != 0; }

bool Time::operator==(const Time& other) const {
  return hours_ == other.hours_ && minutes_ == other.minutes_;
}

bool Time::operator!=(const Time& other) const { return !(*this == other); }

std::ostream& operator<<(std::ostream& out, const Time& time) {
  if (time.hours() < 10) {
    out << '0';
  }
  out << time.hours() << ':';
  if (time.minutes() < 10) {
    out << '0';
  }
  out << time.minutes();
  return out;
}
