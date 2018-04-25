/***
  Copyright 2018 J. West
  */
#ifndef HOMEWORK14_INCLUDE_HOMEWORK14_EMPLOYEE_H_
#define HOMEWORK14_INCLUDE_HOMEWORK14_EMPLOYEE_H_
#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <queue>

class Employee {
  public:
    /***
     * Constructor needs employee name
     */
    explicit Employee(std::string name);
    /***
     * return a copy of the name
     */
    std::string getName();
    /***
     * return the pay due
     */
    virtual double getPay() = 0;
    /***
     * create a string from employee information
     * should output
     * "Name = <name_>"
     */
    virtual std::string toString() const;

  private:
    /*** 
     * name of the employee
     */
    std::string name_;
    friend std::ostream &operator<<(std::ostream &, const Employee &e);
};
std::ostream &operator<<(std::ostream &, const Employee &e);

class HourlyEmployee : public Employee {
  using Employee::Employee;
  public:
    virtual double getPay();
    void setHourlyRate(double rate);
    void setHoursWorked(double hours);
    /***
     * create a string from employee information
     * should output
     * information as in the test result file "
     */
    std::string toString() const;

  private:
    double hourly_rate_;
    double hours_worked_;
    friend std::ostream &operator<<(std::ostream &, const HourlyEmployee &e);
};
std::ostream &operator<<(std::ostream &, const HourlyEmployee &e);

class CommissionedEmployee : public Employee {
  using Employee::Employee;
  public:
    virtual double getPay();
    void setBaseSalary(double dollars);
    void setCommissionRate(double rate);
    void setSalesVolume(double dollars);
    /***
     * create a string from employee information
     * should output
     * information as in the test result file "
     */
    std::string toString() const;

  private:
    double commission_rate_;
    double base_salary_;
    double sales_volume_;
    friend std::ostream &operator<<(std::ostream &,
        const CommissionedEmployee &e);
};
std::ostream &operator<<(std::ostream &, const CommissionedEmployee &e);

class SalariedEmployee : public Employee {
  using Employee::Employee;
  public:
  virtual double getPay();
  void setSalary(double salary);
  /***
   * create a string from employee information
   * should output
   * information as in the test result file "
   */
  std::string toString() const;
  private:
  double salary_;
  friend std::ostream &operator<<(std::ostream &, const SalariedEmployee &e);
};
std::ostream &operator<<(std::ostream &, const SalariedEmployee &e);

#endif  // HOMEWORK14_INCLUDE_HOMEWORK14_EMPLOYEE_H_
