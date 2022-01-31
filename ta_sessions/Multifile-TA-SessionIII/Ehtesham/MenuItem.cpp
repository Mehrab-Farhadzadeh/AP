#include "MenuItem.hpp"
#include "functions.hpp"
#include <sstream>

using namespace std;

MenuItem::MenuItem(string t, int p)
{
    if (t == "")
        error("Menu item title cannot be empty");
    if (p <= 0)
        error("Menu item price must be positive");
    title = t;
    price = p;
}

string MenuItem::get_title() { return title; }

int MenuItem::get_price() { return price; }

string MenuItem::to_string()
{
    ostringstream os;
    os << title << '(' << price << ')';
    return os.str();
}