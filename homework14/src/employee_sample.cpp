/***
  Copyright 2018 J. West
 */
#include "homework14/employee.h"
#include <string>

double SalariedEmployee::getPay(void) const {
  return salary_;
}

void SalariedEmployee::setSalary(double salary) {
  salary_ = salary;
}

std::ostream &operator<<(std::ostream &os, const SalariedEmployee &e) {
  return os  << e.toString();
}

std::string SalariedEmployee::toString() const {
  return std::string(Employee::toString() +
  " : Salary = " + std::to_string(salary_));
}

