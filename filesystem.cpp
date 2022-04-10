#include <iostream>
#include <fstream>
#include "todo.cpp"

using namespace std;

class FileSystem{
	public:
	Todo * todoList;
	Todo * tempt;
	
	FileSystem(){
		tempt = Todo::CreateNode();
		todoList = Todo::CreateNode();
		string text;
		string temp;
		ifstream file("db.dat");
		while(getline(file, text)){
			Todo * node = Todo::CreateNode();
			
			int column = 0;
			for(int i = 0; text[i] != '\0'; i++){
				if(text[i] != ',' && text[i+1] != '\0'){
					temp += text[i];
					continue;
				}
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
	
	void ReadTodoList(){
		tempt = todoList -> first;
		while(tempt != NULL){
			cout << tempt -> Getheader() << ", " << tempt -> Getdescription() << endl;
			tempt = tempt -> next;
		}
	}
	
	void AddTodo(string header, string description){
		Todo * newNode = Todo::CreateNode(header, description);
		todoList -> last -> next = newNode;
		todoList -> last = newNode;
	}
	
	void WriteTodoList(){
		ofstream file ("ext.dat");
		
		tempt = todoList -> first;
		while(tempt != NULL){
			file << tempt -> Getheader() << ", " << tempt -> Getdescription() << endl;
			tempt = tempt -> next;
		}
	}
};



