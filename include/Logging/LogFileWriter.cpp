#include <iostream>
#include "../Utils/FileManager.h"
#include "LogType.h"

using namespace std;

class LogFileWriter{
	public:
	LogFileWriter(){
		
	}
	
	void AddLog(ILog log){
		FileManager manager("log.txt");
		manager.InsertText(log.getLog());
	}
};
