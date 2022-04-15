#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include "Column.h"
#include "Todo.h"
#include "FileManager.h"

using namespace std;

class NodeManager{
	public:
	Todo * todoList;
	Column * columnList;
	Todo * tempt;
	Column * tempc;
	
	FileSystem(){
		tempt = Node<Todo>::CreateNode();
		todoList = Node<Todo>::CreateNode();
		tempc = Node<Column>::CreateNode();
		columnList = Node<Column>::CreateNode();
		string text = "";
		string temp = "";
		FileManager managerTodo("src/todo.dat");
		istringstream str(managerTodo.GetText());
		while(getline(str, text)){
			Todo * node = Node<Todo>::CreateNode();
			
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
		
		FileManager managerColumn("src/column.dat");
		istringstream strclm(managerColumn.GetText());
		while(getline(strclm, text)){
			Column * node = Node<Column>::CreateNode();
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
	
	void ReadTodoList(){
		tempt = todoList -> first;
		while(tempt != NULL){
			tempt -> Print();
			tempt = tempt -> next;
		}
		cout << endl;
	}
	void ReadColumnList(){
		tempc = columnList -> first;
		while(tempc != NULL){
			tempc -> Print();
			tempc = tempc -> next;
		}
		cout << endl;
	}
	
	void AddTodo(string header, string description, string column){
		bool controlt = false;
		bool controlc = false;
		
		controlt = todoList -> isExist(header);
		controlc = columnList -> isExist(column);
		
		
		if(!controlt){
			if(controlc){
				if(todoList -> first == NULL && todoList -> last == NULL){
					Todo * newNode = Todo::CreateNode(header, description, column);
					todoList -> first = newNode;
					todoList -> last = newNode;
					return;
				}
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
		todoList -> Delete(header);
	}
	
	void DeleteColumn(string header){
		bool controlt = true;
		tempc = columnList -> first;
		tempt = todoList -> first;
		
		while(tempt != NULL){
			if(tempt -> Getcolumn() == header)
				controlt = false;
			tempt = tempt -> next;
		}
		
		if(!controlt){
			cout << "this column has a todo" << endl;
			return;
		}
		
		columnList -> Delete(header);
	}
};
