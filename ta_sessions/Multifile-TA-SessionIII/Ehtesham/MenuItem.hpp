#ifndef MENU_ITEM_H
#define MENU_ITEM_H "MENU_ITEM_H"

#include <string>

class MenuItem {
public:
	MenuItem(std::string t, int p);
	std::string get_title();
	int get_price();
	std::string to_string();
	

private:
	std::string title;
	int price;
};

#endif