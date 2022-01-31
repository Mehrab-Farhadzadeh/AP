#ifndef CATERING_H
#define CATERING_H "CATERING_H"

#include <string>
#include <vector>
#include "MenuItem.hpp"
#include "EmployeeRequest.hpp"
#include "CateringOrder.hpp"

class Employee;

class Catering {
public:
	Catering(std::string n, std::vector<MenuItem> m);
	std::string get_name();
	std::string to_string();
	void add_employee_request(Employee* emp, std::string item_title);
	CateringOrder gen_catering_order();
	void delivered(int delivery_cost);

private:
	MenuItem* find_item_by_title(std::string item_title);
	std::string name;
	std::vector<MenuItem> menu;
	std::vector<EmployeeRequest> requests;
};

#endif