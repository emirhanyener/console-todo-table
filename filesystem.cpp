#include <iostream>
#include <fstream>
#include "todo.cpp"
#include "column.cpp"

using namespace std;

class FileSystem{
	public:
	Todo * todoList;
	Column * columnList;
	Todo * tempt;
	Column * tempc;
	
	FileSystem(){
		tempt = Todo::CreateNode();
		todoList = Todo::CreateNode();
		tempc = Column::CreateNode();
		columnList = Column::CreateNode();
		string text;
		string temp;
		ifstream filet("src/todo.dat");
		if(filet == NULL){
			cout << "file not exist";
			ofstream filet("src/todo.dat");
			filet.close();
		}
		else{
			while(getline(filet, text)){
				Todo * node = Todo::CreateNode();
				
				int column = 0;
				temp = "";
				for(int i = 0; text[i] != '\0'; i++){
					if(text[i] == ','){
						if(column == 0)
							node -> Setheader(temp);
						if(column == 1)
							node -> Setdescription(temp);
						column++;
						temp = "";
						continue;
					}
					if(text[i+1] == '\0'){
						temp += text[i];
						node -> Setcolumn(temp);
						continue;
					}
					temp += text[i];
				}
				if(todoList -> last == NULL){
					todoList -> first = node;
					todoList -> last = node;
				}
				else{
					todoList -> last -> next = node;
					todoList -> last = node;
				}
			}
		}
		filet.close();
		
		ifstream filec("src/column.dat");
		if(filec == NULL){
			cout << "file not exist";
			ofstream filec("src/column.dat");
			filec.close();
		}
		else{
			while(getline(filec, text)){
				Column * node = Column::CreateNode();
				node -> Setheader(text);
				
				if(columnList -> last == NULL){
					columnList -> first = node;
					columnList -> last = node;
				}
				else{
					columnList -> last -> next = node;
					columnList -> last = node;
				}
			}
		}
		filec.close();
	}
	
	void ReadTodoList(){
		tempt = todoList -> first;
		while(tempt != NULL){
			cout << tempt -> Getheader() << "," << tempt -> Getdescription() << "," << tempt -> Getcolumn() << endl;
			tempt = tempt -> next;
		}
		cout << endl;
		cout << endl;
	}
	void ReadColumnList(){
		tempc = columnList -> first;
		while(tempc != NULL){
			cout << tempc -> Getheader() <<  endl;
			tempc = tempc -> next;
		}
		cout << endl;
		cout << endl;
	}
	
	void AddTodo(string header, string description, string column){
		bool controlt = true;
		bool controlc = true;
		if(todoList -> first == NULL && todoList -> last == NULL){
			Todo * newNode = Todo::CreateNode(header, description, column);
			todoList -> first = newNode;
			todoList -> last = newNode;
			return;
		}
		tempt = todoList -> first;
		
		while(tempt != NULL){
			if(tempt -> Getheader() == header)
				controlt = false;
			tempt = tempt -> next;
		}
		tempc = columnList -> first;
		
		while(tempc != NULL){
			if(tempc -> Getheader() == header)
				controlc = false;
			tempc = tempc -> next;
		}
		
		if(controlt){
			if(!controlc){
				Todo * newNode = Todo::CreateNode(header, description, column);
				todoList -> last -> next = newNode;
				todoList -> last = newNode;
			}
			else{
				cout << "column not exist" << endl;
			}
		}
		else{
			cout << "this header exist" << endl;
		}
	}
	
	void AddColumn(string header){
		bool control = true;
		if(columnList -> first == NULL && columnList -> last == NULL){
			Column * newNode = Column::CreateNode(header);
			columnList -> first = newNode;
			columnList -> last = newNode;
			return;
		}
		tempc = columnList -> first;
		
		while(tempc != NULL){
			if(tempc -> Getheader() == header)
				control = false;
			tempc = tempc -> next;
		}
		
		if(control){
			Column * newNode = Column::CreateNode(header);
			columnList -> last -> next = newNode;
			columnList -> last = newNode;
		}
		else{
			cout << "this column exist" << endl;
		}
	}
	
	void WriteTodoList(){
		ofstream filet("src/todo.dat");
		tempt = todoList -> first;
		while(tempt != NULL){
			filet << tempt -> Getheader() << "," << tempt -> Getdescription() << "," << tempt -> Getcolumn() << endl;
			tempt = tempt -> next;
		}
		filet.close();
	}
	void WriteColumnList(){
		ofstream filec("src/column.dat");
		tempc = columnList -> first;
		while(tempc != NULL){
			filec << tempc -> Getheader() << endl;
			tempc = tempc -> next;
		}
		filec.close();
	}
	
	void DeleteTodo(string header){
		tempt = todoList -> first;
		
		while(tempt != NULL){
			if(todoList -> first -> Getheader() == header){
				todoList -> first = todoList -> first -> next;
				break;
			}
			if(tempt -> next -> Getheader() == header){
				if(tempt -> next == todoList -> last)
					todoList -> last = tempt;
				tempt -> next = tempt -> next -> next;
				cout << "deleted" << endl;
				break;
			}
			tempt = tempt -> next;
		}
	}
	void DeleteColumn(string header){
		tempc = columnList -> first;
		
		while(tempc != NULL){
			if(columnList -> first -> Getheader() == header){
				columnList -> first = columnList -> first -> next;
				break;
			}
			if(tempc -> next -> Getheader() == header){
				if(tempc -> next == columnList -> last)
					columnList -> last = tempc;
				tempc -> next = tempc -> next -> next;
				cout << "deleted" << endl;
				break;
			}
			tempc = tempc -> next;
		}
	}
};
