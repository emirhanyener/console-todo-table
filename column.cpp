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
	
	bool isExist(string header){
		Column * temp = this -> first;
		
		while(temp != NULL){
			if(temp -> Getheader() == header){
				delete temp;
				return true;
			}
			temp = temp -> next;
		}
		return false;
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
		cout << _header;
	}
	
	string Getheader(){
		return _header;
	}
	
	void Setheader(string header){
		_header = header;
	}
};
