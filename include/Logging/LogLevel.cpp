#include <iostream>
using namespace std;

class LogLevel{
	public:
	static string const LOG;
	static string const AUTH;
	static string const WARNING;

};

string const LogLevel::LOG = "[LOG] ";
string const LogLevel::AUTH = "[AUTH] ";
string const LogLevel::WARNING = "[WARNING] ";
