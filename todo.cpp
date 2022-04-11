#include <iostream>
using namespace std;

class Todo{
	private:
	string _header;
	string _description;
	string _column;
	
	public:
	Todo * next;	
	Todo * first;	
	Todo * last;	
	
	Todo(){
		
	}
		
	Todo(string header, string description, string column){
		_header = header;
		_description = description;
		_column = column;
	}
	
	Init(){
		next = NULL;
		first = NULL;
		last = NULL;
	}
	
	static Todo * CreateNode(){
		Todo * newNode = new Todo();
		newNode -> Init();
		return newNode;
	}
	static Todo * CreateNode(string header, string description, string column){
		Todo * newNode = new Todo(header, description, column);
		newNode -> Init();
		return newNode;
	}
	
	void Print(){
		cout << _header << ", " << _description << ", " << _column;
	}
	
	string Getheader(){
		return _header;
	}
	string Getdescription(){
		return _description;
	}
	string Getcolumn(){
		return _column;
	}
	
	void Setheader(string header){
		_header = header;
	}
	void Setdescription(string description){
		_description = description;
	}
	void Setcolumn(string column){
		_column = column;
	}
};
