#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum weekday
{
    Saturday,
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday
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
    course_id_t id;
    group_t group;
};

typedef int group_t;
typedef string course_id_t;
typedef vector<Session> timeline_t;
typedef vector<timeline_t> day_t;
typedef vector<day_t> week_t;

void read_and_store(week_t week);
void visualize(week_t week);

void add_day_to_session(Session session, string weekday_name);
void read_and_add_date_to_session(Session session);
void add_session_to_timeline(day_t day,Session session);

int main()
{
    week_t week;
    read_and_store(week);
    visualize(week);

    return 0;
}

void read_and_store(week_t week)
{
    Session session;
    char delimiter;
    cin >> session.id >> delimiter >> session.group;
    string weekday_name;
    while (cin >> weekday_name)
    {
        add_day_to_session(session, weekday_name);
        read_and_add_date_to_session(session);
        add_session_to_timeline(week[session.day], session);
    }
}

void add_day_to_session(Session session, string weekday_name);
void read_and_add_date_to_session(Session session);
void add_session_to_timeline(day_t day, Session session);

void visualize(week_t week)
{
    
}