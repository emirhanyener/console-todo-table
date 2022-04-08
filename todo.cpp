#include <iostream>
using namespace std;

class Todo{
	private:
	int _id;
	string _header;
	string _description;
	
	public:
	Todo(int id, string header, string description){
		_id = id;
		_header = header;
		_description = description;
	}
	
	void Print(){
		cout << _id << ", " << _header << ", " << _description;
	}
	
	int Getid(){
		return _id;
	}
	string Getheader(){
		return _header;
	}
	string Getdescription(){
		return _description;
	}
	
	void Setid(int id){
		_id = id;
	}
	void Setheader(string header){
		_header = header;
	}
	void Setdescription(string description){
		_description = description;
	}
};
