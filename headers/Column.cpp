#include <iostream>
#include "Node.h"

using namespace std;

class Column : public Node<Column>{
	private:
	string _header;
	
	public:
	Column(){
		
	}
		
	Column(string header){
		_header = header;
	}
	
	static Column * CreateNode(string header){
		Column * newNode = new Column(header);
		newNode -> Init();
		return newNode;
	}
	
	void Delete(string header){
		Column * temp = this -> first;
		
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
		delete temp;
	}
	
	void Print(){
		cout << _header << endl;
	}
	
	string Getheader(){
		return _header;
	}
	
	void Setheader(string header){
		_header = header;
	}
};
