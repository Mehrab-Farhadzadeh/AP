#ifndef CATERING_ORDER_H
#define CATERING_ORDER_H "CATERING_ORDER_H"

#include <string>
#include <vector>
#include "EmployeeRequest.hpp"

class MenuItem;

class CateringOrderLine
{
public:
    CateringOrderLine(MenuItem *m, int q);
    MenuItem *get_item();
    void increase_quantity(int q);
    std::string to_string();

private:
    MenuItem *item;
    int quantity;
};

class CateringOrder {
public:
	void add_employee_request(EmployeeRequest req);
	std::string to_string();
private:
	std::vector<CateringOrderLine> orderLines;
};

#endif