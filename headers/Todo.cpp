#include <iostream>
#include "Node.h"

using namespace std;

class Todo : public Node<Todo>{
	private:
	string _header;
	string _description;
	string _column;
	
	public:
	
	Todo(){
		
	}
		
	Todo(string header, string description, string column){
		_header = header;
		_description = description;
		_column = column;
	}
	
	static Todo * CreateNode(string header, string description, string column){
		Todo * newNode = new Todo(header, description, column);
		newNode -> Init();
		return newNode;
	}

	void Delete(string header){
		Todo * temp = this -> first;
		
		while(temp != NULL){
			if(this -> first -> Getheader() == header){
				this -> first = this -> first -> next;
				break;
			}
			if(temp -> next -> Getheader() == header){
				if(temp -> next == this -> last)
					this -> last = temp;
				temp -> next = temp -> next -> next;
				cout << "deleted" << endl;
				break;
			}
			temp = temp -> next;
		}
	}
	
	void Print(){
		cout << _header << ", " << _description << ", " << _column << endl;
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
