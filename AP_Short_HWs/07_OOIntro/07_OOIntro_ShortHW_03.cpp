#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;

class Date
{
public:
    Date(int d, int m, int y);
    void set_date(int d, int m, int y);
    void print_date();
    void inc_one_day();
    bool equals(Date d);
    int compare(Date d);
    string day_of_week();

    int get_day() { return day; }
    int get_month() { return month; }
    int get_year() { return year; }

private:
    int day;
    int month;
    int year;
};

Date::Date(int d, int m, int y)
{
    set_date(d, m, y);
}

bool is_leap_year(int year)
{
    if (year == 1)
        return false;
    int r = year % 33;
    return r == 1 || r == 5 || r == 9 || r == 13 || r == 17 || r == 22 || r == 26 || r == 30;
}

int days_of_month(int m, int y)
{
    if (m < 7)
        return 31;
    else if (m < 12)
        return 30;
    else if (m == 12)
        return is_leap_year(y) ? 30 : 29;
    else
        abort();
}

void Date::set_date(int d, int m, int y)
{
    if (y < 0 || m < 1 || m > 12 || d < 1 || d > days_of_month(m, y))
        abort();

    day = d;
    month = m;
    year = y;
}

void Date::inc_one_day()
{
    day++;
    if (day > days_of_month(month, year))
    {
        day = 1;
        month++;
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
}

void Date::print_date()
{
    cout << day << '/' << month << '/' << year << endl;
}

bool Date::equals(Date d)
{
    return day == d.day && month == d.month && year == d.year;
}

Date str_to_date(string s)
{
    // TODO: Handle formatting errors
    int slash_pos = s.find('/');
    int d = atoi(s.substr(0, slash_pos).c_str());
    s = s.substr(slash_pos + 1);
    slash_pos = s.find('/');
    int m = atoi(s.substr(0, slash_pos).c_str());
    int y = atoi(s.substr(slash_pos + 1).c_str());

    return Date(d, m, y);
}
int Date::compare(Date d)
{
    if (year < d.year)
        return -1;
    else if (year == d.year)
    {
        if (month < d.month)
            return -1;
        else if (month == d.month)
        {
            if (day < d.day)
                return -1;
            else if (day == d.day)
                return 0;
            else // day > d.day
                return 1;
        }
        else // month > d.month
            return 1;
    }
    else // year > d.year
        return 1;
}

enum Weekday
{
    FRI,
    SAT,
    SUN,
    MON,
    TUE,
    WED,
    THU
};

map<Weekday, string> get_weekday_dict()
{
    static map<Weekday, string> weekday_dict;
    if (!weekday_dict.size())
    {
        weekday_dict[SAT] = "sat";
        weekday_dict[SUN] = "sun";
        weekday_dict[MON] = "mon";
        weekday_dict[TUE] = "tue";
        weekday_dict[WED] = "wed";
        weekday_dict[THU] = "thu";
        weekday_dict[FRI] = "fri";
    }
    return weekday_dict;
}

int days_between(Date d1, Date d2)
{
    if (d1.compare(d2) > 0)
        swap(d1, d2);

    int count = 0;
    while (!d1.equals(d2))
    {
        d1.inc_one_day();
        count++;
    }
    return count;
}

string Date::day_of_week()
{
    map<Weekday, string> weekday_dict = get_weekday_dict();
    string weekday_name = weekday_dict.at((Weekday)(days_between(Date(day, month, year), Date(1, 1, 1)) % 7));
    return weekday_name;
}

class Person
{
public:
    Person(string n, int d, int m, int y);
    Date get_bdate() { return bdate; }
    string get_name() { return name; }

private:
    string name;
    Date bdate;
};

Person::Person(string n, int d, int m, int y)
    : bdate(d, m, y)
{
    if (n == "")
        abort();
    name = n;
}

int main()
{
    vector<Person> vp;
    vp.push_back(Person("gholam", 2, 7, 1370));
    vp.push_back(Person("ghamar", 3, 12, 1368));
    vp.push_back(Person("alaleh", 12, 2, 1360));
    vp.push_back(Person("hossein", 12, 2, 1380));
    vp.push_back(Person("abdollah", 28, 12, 1375));

    // cout << "Hello my friend!" << endl
    //      << "May I ask your name? ";
    // string user_name;
    // cin >> user_name;
    // cout << "And, your birthday? \n";
    // string birthday;
    // cin >> birthday;
    // Date bd = str_to_date(birthday);
    // Person new_guy(user_name, bd.get_day(), bd.get_month(), bd.get_year());
    // for (int i = 0; i < (int)vp.size(); i++)
    // {
    //     int diff = vp[i].get_bdate().compare(new_guy.get_bdate());
    //     if (diff == 0)
    //         cout << "Wow! You and " << vp[i].get_name() << " are as old as eachother." << endl;
    //     else if (diff > 0)
    //         cout << vp[i].get_name() << " is younger than you." << endl;
    //     else
    //         cout << vp[i].get_name() << " is older than you." << endl;
    // }

    // **************************************************************************
    cout << "Today? ";
    string today_str;
    cin >> today_str;
    Date today = str_to_date(today_str);
    cout << "Today is " << today.day_of_week() << endl;
    for (int i = 0; i < (int)vp.size(); i++)
        cout << vp[i].get_name() << " born at " << vp[i].get_bdate().day_of_week() << endl;
}