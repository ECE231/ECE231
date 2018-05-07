/***
  Copyright 2018 J. West
 */
#include "homework14/employee.h"
#include <fstream>
#include <sstream>
#include <string>
#include <set>

Employee::Employee(std::string name) : name_(name) {}

std::string Employee::getName(void) const {
  return name_;
}

double HourlyEmployee::getPay(void) const {
  return hourly_rate_ * hours_worked_;
}
std::ostream &operator<<(std::ostream &os, const Employee &e) {
  return os  << e.toString();
}

std::string Employee::toString() const {
  return std::string("Name = " + name_);
}

void HourlyEmployee::setHourlyRate(double rate) {
  hourly_rate_ = rate;
}

void HourlyEmployee::setHoursWorked(double hours) {
  hours_worked_ = hours;
}
std::ostream &operator<<(std::ostream &os, const HourlyEmployee &e) {
  return os  << e.toString();
}
std::string HourlyEmployee::toString() const {
  return std::string(Employee::toString() +
    " : Hourly Rate = " + std::to_string(hourly_rate_) +
    " : Hours Worked = " + std::to_string(hours_worked_));
}

double CommissionedEmployee::getPay(void) const {
  return base_salary_ + commission_rate_ * sales_volume_;
}

void CommissionedEmployee::setBaseSalary(double salary) {
  base_salary_ = salary;
}

void CommissionedEmployee::setCommissionRate(double rate) {
  commission_rate_ = rate;
}

void CommissionedEmployee::setSalesVolume(double sales) {
  sales_volume_ = sales;
}

std::ostream &operator<<(std::ostream &os, const CommissionedEmployee &e) {
  return os  << e.toString();
}

std::string CommissionedEmployee::toString() const {
  return std::string( Employee::toString() +
  " : Base Salary = " + std::to_string(base_salary_) +
  " : Commission Rate = " + std::to_string(commission_rate_) +
  " : Sales Volume = " + std::to_string(sales_volume_));
}

