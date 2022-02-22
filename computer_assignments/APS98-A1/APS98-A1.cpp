#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

typedef string Name;
typedef vector<string> Operators;
typedef int LineNumber;
typedef int Value;

void interpret();
void interpret_line(stringstream &is, vector<string> &directives, map<Name, Value> &operands,
					map<LineNumber, Operators> &operators);
void extract_directive(stringstream &is, vector<string> &directives, map<Name, Value> &operands);
bool is_name_valid(string variable_name);
void extract_expression(stringstream &is, map<Name, Value> &operands, map<LineNumber, Operators> &operators);

int main()
{
	interpret();
	return 0;
}

void print_directives(vector <string> d)
{
	for (string s : d)
		cout << s << ", ";
	cout << endl;
}
void print_operands(map<Name, Value> operands)
{
	for (pair<Name, Value> o : operands)
		cout << o.first << "=" << o.second << ", ";
	cout << endl;
}

void interpret()
{
	string line;
	vector<string> directives;
	map<Name, Value> operands;
	map<LineNumber, Operators> operators;
	while (getline(cin, line))
	{
		stringstream is(line);
		interpret_line(is, directives, operands, operators);
		print_directives(directives);
		print_operands(operands);
	}
}

void interpret_line(stringstream &is,
					vector<string> &directives,
					map<Name, Value> &operands,
					map<LineNumber, Operators> &operators)
{
	extract_directive(is, directives, operands); // ?, !, =
	if (directives.back() == "=")
		extract_expression(is, operands, operators);
}

void extract_directive(stringstream &is, vector<string> &directives, map<Name, Value> &operands)
{
	string directive;
	is >> directive;
	if (directive == "?" || directive == "!")
	{
		directives.push_back(directive);
	}
	else if (is_name_valid(directive))
	{
		directives.push_back("=");
		operands[directive] = 0;
	}
	else
		directives.push_back("Syntax Error");
}

bool is_name_valid(string variable_name)
{
	for (char c : variable_name)
	{
		if (!(isalpha(c) || isdigit(c)))
			return false;
	}
	return true;
}
void extract_expression(stringstream &is, map<Name, Value> &operands, map<LineNumber, Operators> &operators)
{
	string operand, _operator;
	while (is >> operand)
	{
		cout << operand << ", ";
	}
	cout << endl;
}
