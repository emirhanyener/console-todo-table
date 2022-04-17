#include <iostream>
#include "../Utils/FileManager.h"
#include "ILog.h"

using namespace std;

class LogFileWriter{
	public:
	LogFileWriter(){
		
	}
	
	void AddLog(string context){
		FileManager manager("log.txt");
		manager.InsertText(context);
	}
};
