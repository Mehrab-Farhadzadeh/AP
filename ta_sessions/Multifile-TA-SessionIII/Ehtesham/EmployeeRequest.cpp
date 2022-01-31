#include "EmployeeRequest.hpp"
#include "MenuItem.hpp"
#include "Employee.hpp"
#include "functions.hpp"
#include <sstream>

using namespace std;

EmployeeRequest::EmployeeRequest(Employee *e, MenuItem *m)
{
    if (e == NULL || m == NULL)
        error("Employee request parameters must be non-null");
    item = m;
    emp = e;
}

MenuItem* EmployeeRequest::get_item() { return item; }

Employee* EmployeeRequest::get_employee() { return emp; }

string EmployeeRequest::to_string()
{
    ostringstream os;
    os << emp->to_string() << '\t' << item->to_string();
    return os.str();
}