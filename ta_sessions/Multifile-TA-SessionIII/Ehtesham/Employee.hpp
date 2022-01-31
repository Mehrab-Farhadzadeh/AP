#ifndef EMPLOYEE_H
#define EMPLOYEE_H "EMPLOYEE_H"

#include <string>

class Employee {
public:
	Employee(std::string id, std::string n);
	std::string get_id();
	int get_bedehi();
	void charge(int amount);
	std::string to_string();

private:
	int bedehi;
	std::string emp_id;
	std::string name;
};

#endif