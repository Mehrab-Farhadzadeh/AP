#include <iostream>
#include <string>
using namespace std;

#define MORNING Time(11, 59)
#define NOON Time(12, 0)
#define AFTERNOON Time(16, 59)
#define EVENING Time(19, 59)
#define NIGHT Time(23, 59)

class Time
{
public:
    Time(int h, int m = 0) { set_time(h, m); }
    void set_time(int h, int m);
    int get_hour() { return _h; }
    int get_minute() { return _m; }
    int compare(Time t);
    string time_of_day();

private:
    int _h;
    int _m;
};

Time get_time();

int main()
{
    cout << "Hello everyone!" << endl;

    while (true)
    {
        Time t = get_time();
        cout << t.time_of_day() << endl
             << endl;
    }
}

Time get_time()
{
    cout << "What time is it? \n";
    int h, m;
    cin >> h >> m;
    return Time(h, m);
}

void Time::set_time(int h, int m)
{
    if (h < 0 || h > 23 || m < 0 || m > 59)
        abort();
    _h = h;
    _m = m;
}

int Time::compare(Time t)
{
    if (_h < t._h)
        return -1;
    else if (_h == t._h)
    {
        if (_m < t._m)
            return -1;
        else if (_m == t._m)
            return 0;
        else
            return 1;
    }
    else
        return 1;
}

string Time::time_of_day()
{
    if (Time(_h, _m).compare(MORNING) <= 0)
        return "Morning";
    else if (Time(_h, _m).compare(NOON) <= 0)
        return "Noon";
    else if (Time(_h, _m).compare(AFTERNOON) <= 0)
        return "Afternoon";
    else if (Time(_h, _m).compare(EVENING) <= 0)
        return "Evening";
    else
        return "Night";
}
