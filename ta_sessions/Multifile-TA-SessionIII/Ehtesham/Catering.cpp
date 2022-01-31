#include "Catering.hpp"
#include "Employee.hpp"
#include "functions.hpp"
#include <sstream>
#include <set>
using namespace std;

Catering::Catering(string n, vector<MenuItem> m)
{
    name = n;
    menu = m;
}
string Catering::get_name() { return name; }
string Catering::to_string()
{
    ostringstream os;
    os << "Requests placed for catering " << name << endl;
    for (EmployeeRequest request : requests)
        os << request.to_string() << endl;
    return os.str();
}
void Catering::add_employee_request(Employee *emp, string item_title)
{
    requests.push_back(EmployeeRequest(emp, find_item_by_title(item_title)));
}

CateringOrder Catering::gen_catering_order()
{
    CateringOrder order;
    for (EmployeeRequest req : requests)
    {
        order.add_employee_request(req);
    }
    return order;
}

void Catering::delivered(int delivery_cost)
{
    set<Employee *> employees;
    for (EmployeeRequest request : requests)
    {
        Employee *emp = request.get_employee();
        emp->charge(request.get_item()->get_price());
        employees.insert(emp);
    }
    for (Employee *emp : employees)
        emp->charge(delivery_cost / employees.size());
}

MenuItem* Catering::find_item_by_title(string item_title)
{
    for (int i = 0; i < menu.size(); i++)
        if (menu[i].get_title() == item_title)
            return &menu[i];
    error("cannot find menu item");
    return NULL;
}