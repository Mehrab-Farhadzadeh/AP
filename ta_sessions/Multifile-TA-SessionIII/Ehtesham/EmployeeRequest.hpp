#ifndef EMPLOYEE_REQ_H
#define EMPLOYEE_REQ_H "EMPLOYEE_REQ_H"

#include <string>

class MenuItem;
class Employee;

class EmployeeRequest
{
public:
    EmployeeRequest(Employee *e, MenuItem *m);
    MenuItem *get_item();
    Employee *get_employee();
    std::string to_string();

private:
    Employee *emp;
    MenuItem *item;
};

 #endif