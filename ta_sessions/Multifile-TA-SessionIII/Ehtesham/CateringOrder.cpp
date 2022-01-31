#include "CateringOrder.hpp"
#include "MenuItem.hpp"
#include <sstream>
using namespace std;

CateringOrderLine::CateringOrderLine(MenuItem *m, int q = 1)
{
    item = m;
    quantity = q;
    
}
MenuItem *CateringOrderLine::get_item() { return item; }

void CateringOrderLine::increase_quantity(int q = 1) { quantity += q; }

string CateringOrderLine::to_string()
{
    ostringstream os;
    os << item->to_string() << " " << quantity;
    return os.str();
}

void CateringOrder::add_employee_request(EmployeeRequest req)
{
    for (CateringOrderLine &line : orderLines)
        if (line.get_item() == req.get_item())
        {
            line.increase_quantity();
            return;
        }
    orderLines.push_back(CateringOrderLine(req.get_item()));
}

string CateringOrder::to_string()
{
    ostringstream os;
    for (CateringOrderLine line : orderLines)
        os << '\t' << line.to_string() << endl;
    return os.str();
}
