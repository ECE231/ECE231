/***
  Copyright 2018 J. West
 */
#include <iostream>
#include <vector>
#include "homework14/employee.h"
int main(int argc, char **argv) {
  std::vector<Employee *> employees;

  SalariedEmployee S("Salary Sam");
  S.setSalary(1000);
  employees.push_back(&S);

  HourlyEmployee H("Hourly Hal");
  H.setHourlyRate(15);
  H.setHoursWorked(40);
  employees.push_back(&H);

  CommissionedEmployee C("Commissioned Carl");
  C.setBaseSalary(1000);
  C.setCommissionRate(0.05);
  C.setSalesVolume(1e6);
  employees.push_back(&C);

  for (auto e : employees) {
    std::cout << *e << " earned " << e->getPay() << std::endl;
  }
  return 0;
}
