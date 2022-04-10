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
		ifstream filet("todo.dat");
		if(filet == NULL){
			cout << "file not exist";
			ofstream filet("todo.dat");
			filet.close();
		}
		else{
			while(getline(filet, text)){
				Todo * node = Todo::CreateNode();
				
				int column = 0;
				for(int i = 0; text[i] != '\0'; i++){
					temp += text[i];
					
					if(text[i] != ',' && text[i+1] != '\0')
						continue;
						
					if(column == 1){
						node -> Setdescription(temp);
					}
					if(column == 0){
						node -> Setheader(temp);
					}
					
					column++;
					temp = "";
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
		
		ifstream filec("column.dat");
		if(filec == NULL){
			cout << "file not exist";
			ofstream filec("column.dat");
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
			cout << tempt -> Getheader() << "," << tempt -> Getdescription() << endl;
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
	
	void AddTodo(string header, string description){
		bool control = true;
		if(todoList -> first == NULL && todoList -> last == NULL){
			Todo * newNode = Todo::CreateNode(header, description);
			todoList -> first = newNode;
			todoList -> last = newNode;
			return;
		}
		tempt = todoList -> first;
		
		while(tempt != NULL){
			if(tempt -> Getheader() == header)
				control = false;
			tempt = tempt -> next;
		}
		
		if(control){
			Todo * newNode = Todo::CreateNode(header, description);
			todoList -> last -> next = newNode;
			todoList -> last = newNode;
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
			cout << "this header exist" << endl;
		}
		
	}
	
	void WriteTodoList(){
		ofstream file("todo.dat");
		tempt = todoList -> first;
		while(tempt != NULL){
			file << tempt -> Getheader() << "," << tempt -> Getdescription() << endl;
			tempt = tempt -> next;
		}
		file.close();
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
};
