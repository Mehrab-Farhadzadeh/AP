#include "Employee.hpp"
#include "functions.hpp" //for error
#include <sstream>
using namespace std;

Employee::Employee(string id, string n)
{
    if (id == "" || n == "")
        error("Employee ID and name cannot be empty");
    emp_id = id;
    name = n;
    bedehi = 0;
}
string Employee::get_id() { return emp_id; }

int Employee::get_bedehi() { return bedehi; }

void Employee::charge(int amount)
{
    bedehi += amount;
}

string Employee::to_string()
{
    ostringstream os;
    os << '[' << emp_id << "] " << name;
    return os.str();
}