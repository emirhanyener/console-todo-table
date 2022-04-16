#include <iostream>
#include "Ilog.h"
#include "LogLevel.h"

using namespace std;

class AuthLog : public ILog{
	public:
	AuthLog(string user, string content){
		this -> content = user + " " + content;
	}
		
	string getLog(){
		return LogLevel::AUTH + this -> content;
	}
};
