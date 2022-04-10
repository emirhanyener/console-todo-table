#include <iostream>
using namespace std;

class Column{
	private:
	string _header;
	
	public:
	Column * next;	
	Column * first;	
	Column * last;	
	
	Column(){
		
	}
		
	Column(string header){
		_header = header;
	}
	
	Init(){
		next = NULL;
		first = NULL;
		last = NULL;
	}
	
	static Column * CreateNode(){
		Column * newNode = new Column();
		newNode -> Init();
		return newNode;
	}
	static Column * CreateNode(string header){
		Column * newNode = new Column(header);
		newNode -> Init();
		return newNode;
	}
	
	void Print(){
		cout << _header;
	}
	
	string Getheader(){
		return _header;
	}
	
	void Setheader(string header){
		_header = header;
	}
};
