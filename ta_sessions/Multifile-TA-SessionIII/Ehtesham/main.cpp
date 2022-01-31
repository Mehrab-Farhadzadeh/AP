#include "Ehtesham.hpp"
#include <iostream>
using namespace std;

int main() {
	Ehtesham ehtesham(
		{
			Catering("Farsi", { MenuItem("Kabab", 50000), MenuItem("Jooj", 30000) }),
			Catering("Alaa", { MenuItem("Kabab", 40000), MenuItem("Maahi", 35000) })
		},
		{
			Employee("1001", "Jamshid"),
			Employee("1002", "Mahvash"),
			Employee("1003", "Hooshang")
		}
	);

	string command;
	while (cin >> command) {
		if (command == "request") {
			string empid;
			string catering;
			string item;

			cin >> empid >> catering >> item;
			ehtesham.add_employee_request(empid, catering, item);

			cout << "Request from employee " << empid << " handled!" << endl << endl;

		} else if (command == "catorder") {
			string catering_name;
			cin >> catering_name;
			CateringOrder order = ehtesham.gen_catering_order(catering_name);
			cout << "Order for catering " << catering_name << ":\n";
			cout << order.to_string() << endl;

		} else if (command == "delivery") {
			string catering_name;
			int delivery_cost;

			cin >> catering_name;
			cin >> delivery_cost;
			ehtesham.delivery_from(catering_name, delivery_cost);
			cout << "Delivery from " << catering_name << " handled!" << endl << endl;
		} else if (command == "bedehi") {
			cout << "Bedehi Report: " << endl << ehtesham.bedehi_report() << endl;
		} else if (command == "dump") {
			cout << ehtesham.to_string() << endl;
		} else {
			cerr << "unknown command\n";
			abort();
		}
	}
}