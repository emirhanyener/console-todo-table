#include <iostream>
#include <fstream>
#include <string>
#include <direct.h>

using namespace std;

class FileManager{
	private:
	string text;
	string filetext;
	string filename;
	const char * filenameConverted;
	
	public:
	FileManager(string filename){
		mkdir("src");
		text = "";
		filenameConverted = filename.c_str();
		this->filename = filename;
		ifstream file(filenameConverted);
		if(!file){
			ofstream file(filenameConverted);
		}
		while(getline(file, text)){
			filetext = text;
		}
		file.close();
	}
	
	string GetText(){
		return filetext;
	}
	
	void SetText(string value){
		filetext = value;
	}
	void InsertText(string value, bool isNewLine = true){
		if(isNewLine)
			filetext += "\n";
		filetext += value;
	}
	
	void SaveFile(){
		ofstream file(filenameConverted);
		file << filetext;
		file.close();
	}
};
