#include <iostream>
#include "Ilog.h"
#include "LogLevel.h"

using namespace std;

class WarningLog : public ILog{
	public:
	WarningLog(string content){
		this -> content = content;
	}
		
	string getLog(){
		return LogLevel::WARNING + this -> content;
	}
};
