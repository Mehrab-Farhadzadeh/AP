#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define STARTING_HOUR 7
#define NUM_OF_TIME_PRIODS 27

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

typedef int timeline_index_t;
typedef int group_t, course_id_t;

struct Session
{
    timeline_index_t start;
    timeline_index_t end;
    weekday day;
    course_id_t id;
    group_t group;
};

typedef vector<Session> timeline_t;
typedef vector<timeline_t> day_t;
typedef vector<day_t> week_t;

void read_and_store_week(week_t &week);
void add_weekday_to_session(Session &session, string weekday_name);
void read_and_add_time_to_session(Session &session);
void add_session_to_proper_timeline(day_t &day, Session session);
bool is_there_confliction(Session session, timeline_t timeline);
timeline_t make_new_timeline();

void visualize_week(week_t week);
void visualize_day(day_t day);
void visualize_timeline(timeline_t timeline);

int main()
{
    week_t week(7);
    read_and_store(week);
    visualize_week(week);

    return 0;
}

void read_and_store(week_t &week)
{
    int session_id, session_group;
    char delimiter;
    while (cin >> session_id >> delimiter >> session_group)
    {
        string weekday_name;
        while (cin >> weekday_name)
        {
            Session session;
            session.id = session_id;
            session.group = session_group;

            add_weekday_to_session(session, weekday_name);
            read_and_add_time_to_session(session);
            add_session_to_proper_timeline(week[session.day], session);
        }
    }
}

void add_weekday_to_session(Session &session, string weekday_name)
{
    if (weekday_name == "SAT")
        session.day = Saturday;
    else if (weekday_name == "SUN")
        session.day = Sunday;
    else if (weekday_name == "MON")
        session.day = Monday;
    else if (weekday_name == "TUE")
        session.day = Tuesday;
    else if (weekday_name == "WED")
        session.day = Wednesday;
    else if (weekday_name == "THU")
        session.day = Thursday;
    else if (weekday_name == "FRI")
        session.day = Friday;
    else
        cerr << "ERROR: Can't assign weekday!" << endl;
}

void read_and_add_time_to_session(Session &session)
{
    int hour, min;
    char delimiter;
    cin >> hour >> delimiter >> min;
    session.start = 2 * (hour - STARTING_HOUR);
    if (min == 30)
        session.start++;

    cin >> delimiter >> hour >> delimiter >> min;
    session.end = 2 * (hour - STARTING_HOUR);
    if (min == 30)
        session.end++;
}

void add_session_to_proper_timeline(day_t &day, Session session)
{
    int current_timeline, last_timeline = day.size() - 1;
    for (current_timeline = last_timeline; current_timeline >= 0; current_timeline--)
    {
        if (!is_there_confliction(session, day[current_timeline]))
            break;
    }
    current_timeline++; // Now the current_timline's value is the first place below the confliction.
    if (current_timeline > last_timeline)
        day.push_back(make_new_timeline());

    for (timeline_index_t time_index = session.start; time_index < session.end; time_index++)
        day[current_timeline][time_index] = session;
}

bool is_there_confliction(Session session, timeline_t timeline)
{
    return true;
}

timeline_t make_new_timeline()
{
    timeline_t timeline(NUM_OF_TIME_PRIODS);
    return timeline;
}

void visualize_week(week_t week)
{
    for (int day = Saturday; day <= Friday; day++)
    {
        visualize_day(week[day]);
    }
}

void visualize_day(day_t day)
{

}

void visualize_timeline(timeline_t timeline)
{
    
}