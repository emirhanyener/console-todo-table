#include <iostream>
#include <fstream>

using namespace std;

class FileManager{
	private:
	string text = "";
	string filetext = "";
	char * filename;
	
	public:
	FileManager(char * filename){
		this->filename = filename;
		ifstream file(filename);
		if(file == NULL){
			ofstream file(filename);
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
	void InsertText(string value, bool isNewLine = false){
		if(isNewLine)
			filetext += "\n";
		filetext += value;
	}
	
	void SaveFile(){
		ofstream file(filename);
		file << filetext;
		file.close();
	}
};
