#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum weekday
{
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

enum hour
{
    seven = 7,
    eight,
    nine,
    ten,
    eleven,
    twelve,
    thirteen,
    fourteen,
    fifteen,
    sixteen,
    seventeen,
    eighteen,
    nineteen,
    twenty
};

enum minute
{
    zero = 0,
    thirty = 30
};

struct Time
{
    hour h;
    minute m;
};

struct Session
{
    Time start;
    Time end;
    weekday day;
    course_t course;
    group_t group;
};

typedef int group_t;
typedef string course_t;
typedef vector<Session> timeline_t;
typedef vector<timeline_t> day_t;
typedef vector<day_t> week_t;

int main()
{

    return 0;
}