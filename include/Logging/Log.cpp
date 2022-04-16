#include <iostream>
#include "Ilog.h"
#include "LogLevel.h"

using namespace std;

class Log : public ILog{
	public:
	Log(string content){
		this -> content = content;
	}
		
	string getLog(){
		return LogLevel::LOG + this -> content;
	}
};
