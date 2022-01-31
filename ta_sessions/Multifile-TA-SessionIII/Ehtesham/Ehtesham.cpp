#include "Ehtesham.hpp"
#include "functions.hpp"
#include <sstream>
using namespace std;

Ehtesham::Ehtesham(vector<Catering> c, vector<Employee> e)
{
    caterings = c;
    employees = e;
}

string Ehtesham::to_string()
{
    ostringstream os;
    os << "Employees:" << endl;
    for (Employee employee : employees)
        os << employee.to_string() << endl;
    os << endl;
    for (Catering catering : caterings)
        os << catering.to_string() << endl;
    return os.str();
}

void Ehtesham::add_employee_request(string empid, string catering_name, string item)
{
    Catering *cat = find_catering_by_name(catering_name);
    Employee *emp = find_employee_by_id(empid);
    cat->add_employee_request(emp, item);
}

CateringOrder Ehtesham::gen_catering_order(string catering_name)
{
    Catering *cat = find_catering_by_name(catering_name);
    return cat->gen_catering_order();
}

void Ehtesham::delivery_from(string catering_name, int delivery_cost)
{
    Catering *cat = find_catering_by_name(catering_name);
    cat->delivered(delivery_cost);
}

string Ehtesham::bedehi_report()
{
    ostringstream os;
    for (Employee emp : employees)
    {
        os << emp.to_string() << "\t" << emp.get_bedehi() << endl;
    }
    return os.str();
    
}

Employee *Ehtesham::find_employee_by_id(string empid)
{
    for (int i = 0; i < employees.size(); i++)
        if (employees[i].get_id() == empid)
            return &employees[i];
    error("cannot find employee");
    return NULL;
}

Catering *Ehtesham::find_catering_by_name(string name)
{
    for (int i = 0; i < caterings.size(); i++)
        if (caterings[i].get_name() == name)
            return &caterings[i];
    error("cannot find catering");
    return NULL;
}
