#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

#define STARTING_HOUR 7
#define NUM_OF_TIME_BLOCKS 27
#define FIRST_TIMELINE 0
#define TIME_BLOCK_SIZE 10
#define GROUP_SIZE_IN_TIMELINE 4

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
typedef string course_name;

struct Session
{
    timeline_index_t start;
    timeline_index_t end;
    weekday day;
    course_id_t id;
    group_t group;
    course_name name;
};

typedef vector<Session> timeline_t;
typedef vector<timeline_t> day_t;
typedef vector<day_t> week_t;

void read_and_store_week(week_t &week);
course_name find_name_by_id(string file_path, course_id_t session_id);
void add_weekday_to_session(Session &session, string weekday_name);
void read_and_add_time_to_session(Session &session);
void add_session_to_proper_timeline(day_t &day, Session session);
bool are_in_conflict(Session session, timeline_t timeline);
timeline_t make_new_timeline();

void visualize_week(week_t week, char *argv[]);
void visualize_day(day_t day);
void visualize_timeline(timeline_t timeline);
void print_day_name(int day);

int main(int argc, char *argv[])
{
    week_t week(7);
    read_and_store_week(week);
    visualize_week(week, argv);

    return 0;
}

void read_and_store_week(week_t &week)
{
    string file_path = "./sample_testcases/big/courses.csv";
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
            session.name = find_name_by_id(file_path, session.id);

            add_weekday_to_session(session, weekday_name);
            read_and_add_time_to_session(session);
            add_session_to_proper_timeline(week[session.day], session);
            if (cin.get() == '\n')
                break;
        }
    }
}

course_name find_name_by_id(string file_path, course_id_t session_id)
{
    fstream courses_file(file_path);
    if (courses_file.is_open())
        cerr << "Unable to open file: " << file_path << endl;
    string line;
    getline(courses_file, line); // Skip first line
    while (true)
    {
        if (courses_file.eof())
            break;
        course_id_t id_in_file;
        course_name name_in_file;
        char delimiter;
        courses_file >> id_in_file >> delimiter >> name_in_file;
        if (id_in_file == session_id)
            return name_in_file;
    }
    return "ERROR FINDING NAME!";
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
    if (day.size() == 0)
        day.push_back(make_new_timeline());
    int proper_timeline, current_timeline, last_timeline = day.size() - 1;
    bool confliction = false;
    for (current_timeline = last_timeline; current_timeline >= FIRST_TIMELINE; current_timeline--)
    {
        if (are_in_conflict(session, day[current_timeline]))
        {
            confliction = true;
            break;
        }
    }
    confliction ? proper_timeline = current_timeline + 1 : proper_timeline = FIRST_TIMELINE;

    if (proper_timeline > last_timeline)
        day.push_back(make_new_timeline());

    for (timeline_index_t time_index = session.start; time_index < session.end; time_index++)
        day[proper_timeline][time_index] = session;
}

bool are_in_conflict(Session session, timeline_t timeline)
{
    for (timeline_index_t time_index = session.start; time_index < session.end; time_index++)
    {
        if (timeline[time_index].id != 0)
            return true;
    }
    return false;
}

timeline_t make_new_timeline()
{
    timeline_t timeline(NUM_OF_TIME_BLOCKS);
    return timeline;
}

void visualize_week(week_t week, char *argv[])
{
    // cout << argv[2] << endl; // Program's name
    for (int day = Saturday; day <= Friday; day++)
    {
        print_day_name(day);
        visualize_day(week[day]);
    }
}

void visualize_day(day_t day)
{
    for (int time_block = 0; time_block < NUM_OF_TIME_BLOCKS; time_block++)
    {
        int hour = (time_block / 2) + STARTING_HOUR;
        int min;
        time_block % 2 ? min = 30 : min = 00;
        if (hour < 10)
            cout << "0";
        cout << hour << ":";
        min == 30 ? cout << min : cout << "00";
        cout << string(5, ' ');
    }
    cout << "20:30" << endl;
    cout << string(275, '_') << endl;

    int num_of_timelines = day.size();
    for (int timeline = 0; timeline < num_of_timelines; timeline++)
        visualize_timeline(day[timeline]);
}

void visualize_timeline(timeline_t timeline)
{
    cout << endl;
    string empty_time_blocks = "";
    for (int time_block = 0; time_block < NUM_OF_TIME_BLOCKS; time_block++)
    {
        if (timeline[time_block].id == 0)
        {
            empty_time_blocks += string(10, ' ');
            continue;
        }
        int used_blocks = 1;
        while (timeline[time_block].id == timeline[++time_block].id)
            used_blocks++;
        time_block--;

        int field_width = used_blocks * TIME_BLOCK_SIZE;
        int spaces = (field_width - timeline[time_block].name.size()) / 2;
        string center_aligned_name = string(spaces, ' ') + timeline[time_block].name;
        cout << empty_time_blocks << center_aligned_name << " (" << timeline[time_block].group << ")";
        cout << string(field_width - spaces - timeline[time_block].name.size() - GROUP_SIZE_IN_TIMELINE, ' ');
        empty_time_blocks = "";
    }
    cout << endl;
    cout << endl;
}

void print_day_name(int day)
{
    cout << endl
         << "## ";
    if (day == 0)
        cout << "Saturday";
    else if (day == 1)
        cout << "Sunday";
    else if (day == 2)
        cout << "Monday";
    else if (day == 3)
        cout << "Tuesday";
    else if (day == 4)
        cout << "Wednesday";
    else if (day == 5)
        cout << "Thursday";
    else if (day == 6)
        cout << "Friday";
    else
        cerr << "ERROR: Can't print weekday!" << endl;

    cout << endl
         << endl;
}