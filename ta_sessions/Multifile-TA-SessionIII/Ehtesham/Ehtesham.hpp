#ifndef EHTESHAM_H
#define EHTESHAM_H "EHTESHAM_H"

#include "Employee.hpp"
#include "Catering.hpp"
#include "CateringOrder.hpp"

class Ehtesham {
public:
	Ehtesham(std::vector<Catering> c, std::vector<Employee> e);
	std::string to_string();
	void add_employee_request(std::string empid, std::string catering_name, std::string item);
	CateringOrder gen_catering_order(std::string catering_name);
	void delivery_from(std::string catering_name, int delivery_cost);
	std::string bedehi_report();

private:
	Employee* find_employee_by_id(std::string empid);
	Catering* find_catering_by_name(std::string name);

	std::vector<Catering> caterings;
	std::vector<Employee> employees;
};


#endif