#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#define DATE_OK 1
#define DATE_INVALID_SEPARATOR -1
#define DATE_READING_FAILURE -2
#define STUDENT_NAME_EMPTY -3

using namespace std;

class Date
{
public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
    void print() { cout << day << '/' << month << '/' << year; }

private:
    int day, month, year;
};

class Student
{
public:
    Student(string n, Date bd, int &result) : name(n), bdate(bd)
    {
        if (name == "")
            result = STUDENT_NAME_EMPTY;
    }
    void print()
    {
        cout << name << '\t';
        bdate.print();
    }

private:
    string name;
    Date bdate;
};

Date read_date(ifstream &input, int &result)
{
    int d, m, y;
    char ch;
    input >> d;
    if (!input)
    {
        result = DATE_READING_FAILURE;
    }
    input >> ch;
    if (ch != '/')
    {
        result = DATE_INVALID_SEPARATOR;
        return Date(1, 1, 1);
    }
    input >> m;
    if (!input)
    {
        result = DATE_READING_FAILURE;
    }
    input >> ch;
    if (ch != '/')
    {
        result = DATE_INVALID_SEPARATOR;
        return Date(1, 1, 1);
    }
    input >> y;
    if (!input)
    {
        result = DATE_READING_FAILURE;
    }
    result = DATE_OK;
    return Date(d, m, y);
}

Student read_student(ifstream &input, int &result)
{
    string name;
    int std_cnstrctr_res;
    int std_result;
    int result;
    input >> name;
    Date bdate = read_date(input, result);
    if (std_result == STUDENT_NAME_EMPTY)
    {
        result == STUDENT_NAME_EMPTY;
        return Student("What I suppose to name?", Date(1, 1, 1), std_cnstrctr_res);
    }
    else
        return Student(name, bdate, std_result);
}

void read_student_info(char *filename, vector<Student> &v)
{
    ifstream input(filename);
    int std_res;
    int count;
    input >> count;
    for (int i = 0; i < count; i++)
    {
        Student s = read_student(input, std_res);
        if (std_res == STUDENT_NAME_EMPTY)
            break;
        v.push_back(s);
    }
    input.close();
}

void do_some_processing(vector<Student> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        v[i].print();
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    vector<Student> students;
    read_student_info(argv[1], students);
    do_some_processing(students);
}